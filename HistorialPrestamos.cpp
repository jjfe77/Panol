#include "pch.h"
#include "HistorialPrestamos.h"

using namespace Panol;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Net;
using namespace System::Net::Security;
using namespace System::Security::Cryptography::X509Certificates;
using namespace System::Collections::Specialized; 

namespace Panol {

    HistorialPrestamos::HistorialPrestamos(void)
    {
        InitializeComponent();
        // inicialización básica
    }

    HistorialPrestamos::HistorialPrestamos(int idProfesor)
    {
        InitializeComponent();
        // acá más adelante podés cargar el DataGridView con los préstamos del profesor
    }

    HistorialPrestamos::~HistorialPrestamos()
    {
        if (components) {
            delete components;
        }
    }

}

System::Void HistorialPrestamos::HistorialPrestamos_Load(System::Object^ sender, System::EventArgs^ e)
{
    cargarDocentes();

   
}

void HistorialPrestamos::cargarDocentes()
{
    try
    {
        WebClient^ client = gcnew WebClient();
        client->Encoding = System::Text::Encoding::UTF8;

        String^ url = "http://localhost/panol_api/get_profesores.php";
        String^ json = client->DownloadString(url);

        DataTable^ dtDocentes = gcnew DataTable();
        dtDocentes->Columns->Add("id_profesor", int::typeid);
        dtDocentes->Columns->Add("docente", String::typeid);

        Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
        auto matches = rx->Matches(json);

        if (matches->Count == 0) {
            cmbDocente->DataSource = nullptr;
            cmbDocente->Items->Clear();
            MessageBox::Show("No se encontraron docentes o el JSON es inválido.");
            return;
        }

        for each (Match ^ m in matches) {
            String^ item = m->Value;
            String^ idStr = obtenerCampo(item, "id_profesor");
            String^ nombre = obtenerCampo(item, "docente");

            if (idStr != "" && nombre != "")
                dtDocentes->Rows->Add(Int32::Parse(idStr), nombre);
        }
       // MessageBox::Show(json);

        cmbDocente->DisplayMember = "docente";
        cmbDocente->ValueMember = "id_profesor";
        cmbDocente->DataSource = dtDocentes;
        cmbDocente->SelectedIndex = -1;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error al cargar docentes: " + ex->Message);
    }
}

String^ HistorialPrestamos::obtenerCampo(String^ jsonItem, String^ campo)
{
    String^ patron = "\\\"" + campo + "\\\"\\s*:\\s*\\\"([^\\\"]*)\\\"";
    Regex^ rx = gcnew Regex(patron);
    Match^ m = rx->Match(jsonItem);
    return m->Success ? m->Groups[1]->Value : "";
}


void HistorialPrestamos::cargarPrestamosPorDocente(int idProfesor) {
    try {
        // --- 1. LIMPIEZA INICIAL ---
        // Limpiamos el detalle para que no queden datos del docente anterior
        dataGridView2->Rows->Clear();

        // Limpiamos la tabla principal de préstamos
        dataGridView1->Rows->Clear();
        WebClient^ client = gcnew WebClient();
        client->Encoding = System::Text::Encoding::UTF8;
        String^ url = "http://localhost/panol_api/get_prestamos.php?id_profesor=" + idProfesor;
        String^ json = client->DownloadString(url);

        // Limpiar filas previas
        dataGridView1->Rows->Clear();

        // Ver el JSON crudo para confirmar que trae "fecha_retiro"
        //MessageBox::Show(json);

        Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
        auto matches = rx->Matches(json);
        /*
        for each (Match ^ m in matches) {
            String^ item = m->Value;
            String^ fechaRetiro = obtenerCampo(item, "fecha_retiro");
            String^ idStr = obtenerCampo(item, "id_prestamo");

            if (fechaRetiro != "" && idStr != "") {
                int rowIndex = dataGridView1->Rows->Add();
                // Asignar explícitamente a la columna fechaPrestamo
                dataGridView1->Rows[rowIndex]->Cells["fechaPrestamo"]->Value = fechaRetiro;
                // Guardar el id para usarlo después
                dataGridView1->Rows[rowIndex]->Tag = idStr;
            }
        }*/

        for each(Match ^ m in matches) {
            String^ item = m->Value;
            String^ fechaRetiro = obtenerCampo(item, "fecha_retiro");
            String^ idStr = obtenerCampo(item, "id_prestamo");
            String^ esPendiente = obtenerCampo(item, "pendiente"); // El nuevo campo

            if (fechaRetiro != "" && idStr != "") {
                int rowIndex = dataGridView1->Rows->Add();
                dataGridView1->Rows[rowIndex]->Cells["fechaPrestamo"]->Value = fechaRetiro;
                dataGridView1->Rows[rowIndex]->Tag = idStr;

                // Aplicamos el color según la lógica del PHP
                if (esPendiente == "SI") {
                    // Fondo rojo claro para indicar que falta devolver herramientas
                    dataGridView1->Rows[rowIndex]->DefaultCellStyle->BackColor = Color::LightCoral;
                }
                else {
                    // Fondo verde claro para indicar que todo está devuelto
                    dataGridView1->Rows[rowIndex]->DefaultCellStyle->BackColor = Color::LightGreen;
                }
            }
        }
        // 1. Quitamos el foco de la celda (el recuadro punteado)
        dataGridView1->CurrentCell = nullptr;

        // 2. Quitamos el color azul de selección
        dataGridView1->ClearSelection();


    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al cargar préstamos: " + ex->Message);
    }
}

System::Void HistorialPrestamos::cmbDocente_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    if (cmbDocente->SelectedValue != nullptr) {
        int idProfesor = safe_cast<int>(cmbDocente->SelectedValue);
        cargarPrestamosPorDocente(idProfesor);
    }
}

void HistorialPrestamos::cargarDetallePrestamo(int idPrestamo) {
    try {
        WebClient^ client = gcnew WebClient();
        client->Encoding = System::Text::Encoding::UTF8;
        String^ url = "http://localhost/panol_api/get_detalle_prestamo.php?id_prestamo=" + idPrestamo;
        String^ json = client->DownloadString(url);
        //MessageBox::Show(json);
        dataGridView2->Rows->Clear();

        Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
        auto matches = rx->Matches(json);

        for each (Match ^ m in matches) {
            String^ item = m->Value;
            String^ herramienta = obtenerCampo(item, "herramienta");
            String^ cantRet = obtenerCampo(item, "cantidad_retirada");
            String^ cantDev = obtenerCampo(item, "cantidad_devuelta");
            String^ idHerramienta = obtenerCampo(item, "id_herramienta");

            int rowIndex = dataGridView2->Rows->Add();
            dataGridView2->Rows[rowIndex]->Cells["Elemento"]->Value = herramienta;
            dataGridView2->Rows[rowIndex]->Cells["cantRet"]->Value = cantRet;
            dataGridView2->Rows[rowIndex]->Cells["cantDev"]->Value = cantDev;
            dataGridView2->Rows[rowIndex]->Cells["id_herramienta"]->Value = idHerramienta; // oculta

        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al cargar detalle: " + ex->Message);
    }
}



System::Void HistorialPrestamos::dataGridView1_CellClick(
    System::Object^ sender,
    System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex >= 0) {
        DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex];

        // Verificamos que la fila tenga datos y que el Tag no sea nulo
        if (row != nullptr && row->Tag != nullptr) {
            String^ idPrestamo = safe_cast<String^>(row->Tag);

            if (!String::IsNullOrEmpty(idPrestamo)) {
                cargarDetallePrestamo(Int32::Parse(idPrestamo));
            }
            else {
                MessageBox::Show("Seleccione una fila válida.");
            }
        }
        else {
            MessageBox::Show("Seleccione una fila válida.");
        }
    }
}


System::Void HistorialPrestamos::buttonDevolver_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        // Obtener valores de la fila seleccionada
        int cantidadRetirada = Convert::ToInt32(
            dataGridView2->CurrentRow->Cells["cantRet"]->Value);

        int cantidadDevuelta = Convert::ToInt32(
            dataGridView2->CurrentRow->Cells["cantDev"]->Value);
        //int idPrestamo = Convert::ToInt32(dataGridView2->CurrentRow->Cells["id_prestamo"]->Value);
        DataGridViewRow^ rowPrestamo = dataGridView1->CurrentRow;
        int idPrestamo = Int32::Parse(safe_cast<String^>(rowPrestamo->Tag));

        int idHerramienta = Convert::ToInt32(dataGridView2->CurrentRow->Cells["id_herramienta"]->Value);



        if (cantidadDevuelta <= cantidadRetirada) {
            // Llamada al PHP con parámetros
            HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create("http://localhost/panol_api/devolver.php");
            request->Method = "POST";

            String^ postData = "id_prestamo=" + idPrestamo +
                "&id_herramienta=" + idHerramienta +
                "&cantidad_devuelta=" + cantidadDevuelta;


            //String^ postData = "id_prestamo=" + idPrestamo + "&cantidad_devuelta=" + cantidadDevuelta;
            array<Byte>^ byteArray = Encoding::UTF8->GetBytes(postData);
            request->ContentType = "application/x-www-form-urlencoded";
            request->ContentLength = byteArray->Length;

            Stream^ dataStream = request->GetRequestStream();
            dataStream->Write(byteArray, 0, byteArray->Length);
            dataStream->Close();

            WebResponse^ response = request->GetResponse();
            StreamReader^ reader = gcnew StreamReader(response->GetResponseStream());
            String^ responseFromServer = reader->ReadToEnd();

            reader->Close();
            response->Close();

            MessageBox::Show(responseFromServer);
            //cargarPrestamos(); // refrescar DataGridView
     
        }
        else {
            MessageBox::Show("La cantidad devuelta no puede ser mayor a la cantidad retirada.");
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }
    
    cmbDocente_SelectedIndexChanged(cmbDocente, nullptr);

}


