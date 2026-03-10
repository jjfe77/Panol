#include "pch.h"
#include "prestamos.h"
#include "HistorialPrestamos.h"
#include "menuPrincipal.h"

using namespace Panol;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Net;
using namespace System::Net::Security;
using namespace System::Security::Cryptography::X509Certificates;
using namespace System::Collections::Specialized; // para NameValueCollection


prestamos::prestamos(void)
{
    InitializeComponent();
    this->Load += gcnew System::EventHandler(this, &prestamos::prestamos_Load);
    // -------------------
   // INICIALIZAR EL TIMER
   // -------------------
    timerActualizar = gcnew System::Windows::Forms::Timer();  // crear el Timer
    timerActualizar->Interval = 30000;                          // 30 segundos
    timerActualizar->Tick += gcnew System::EventHandler(this, &prestamos::timerActualizar_Tick);  // asociar evento
    timerActualizar->Start();
 
}

prestamos::~prestamos()
{
    if (components)
        delete components;
}

System::Void prestamos::prestamos_Load(System::Object^ sender, System::EventArgs^ e)
{
    cargarDocentes();
	cargarHerramientas();
}

void prestamos::cargarDocentes()
{
    try
    {
        WebClient^ client = gcnew WebClient();
        client->Encoding = System::Text::Encoding::UTF8;

        String^ url = "http://localhost/panol_api/get_profesores.php";
        //String^ url = "http://juanjo.gt.tc/panol_api/get_profesores.php?";
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

        for each(Match ^ m in matches) {
            String^ item = m->Value;
            String^ idStr = obtenerCampo(item, "id_profesor");
            String^ nombre = obtenerCampo(item, "docente");

            if (idStr != "" && nombre != "")
                dtDocentes->Rows->Add(Int32::Parse(idStr), nombre);
        }

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

String^ prestamos::obtenerCampo(String^ jsonItem, String^ campo)
{
    String^ patron = "\\\"" + campo + "\\\"\\s*:\\s*\\\"([^\\\"]*)\\\"";
    Regex^ rx = gcnew Regex(patron);
    Match^ m = rx->Match(jsonItem);
    return m->Success ? m->Groups[1]->Value : "";
}

void prestamos::cargarHerramientas()
{
    try
    {
        // Descargar JSON desde la API
        WebClient^ client = gcnew WebClient();
        client->Encoding = System::Text::Encoding::UTF8;
        String^ url = "http://localhost/panol_api/get_herramientas.php";
        String^ json = client->DownloadString(url);

        // Crear DataTable para las herramientas
        DataTable^ dtHerramientas = gcnew DataTable();
        dtHerramientas->Columns->Add("id_herramienta", int::typeid);
        dtHerramientas->Columns->Add("nombre", String::typeid);

        // Suponiendo que ya existe la columna "cantidad" en el DataGridView
        DataGridViewTextBoxColumn^ colCantidad =
            safe_cast<DataGridViewTextBoxColumn^>(dataGridViewPrestamos->Columns["cantidad"]);

        // Centrar el texto en la celda
        colCantidad->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;

        // Opcional: mostrar formato numérico (ejemplo sin decimales)
        colCantidad->DefaultCellStyle->Format = "N0";


        // Parsear JSON con Regex simple
        Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
        auto matches = rx->Matches(json);

        for each (Match ^ m in matches) {
            String^ item = m->Value;
            String^ idStr = obtenerCampo(item, "id_herramienta");
            String^ nombre = obtenerCampo(item, "nombre");

            if (idStr != "" && nombre != "")
                dtHerramientas->Rows->Add(Int32::Parse(idStr), nombre);
        }

        // Verificar que la columna "elementoRetirado" sea ComboBox
        DataGridViewComboBoxColumn^ colHerramienta =
            dynamic_cast<DataGridViewComboBoxColumn^>(dataGridViewPrestamos->Columns["elementoRetirado"]);

        if (colHerramienta == nullptr)
        {
            // Si no existe o es TextBox, eliminar y crearla como ComboBox
            if (dataGridViewPrestamos->Columns->Contains("elementoRetirado"))
                dataGridViewPrestamos->Columns->Remove("elementoRetirado");

            colHerramienta = gcnew DataGridViewComboBoxColumn();
            colHerramienta->Name = "elementoRetirado";
            colHerramienta->HeaderText = "Herramienta";
            dataGridViewPrestamos->Columns->Add(colHerramienta);
        }

        // Asignar DataSource al ComboBoxColumn
        colHerramienta->DataSource = dtHerramientas;
        colHerramienta->DisplayMember = "nombre";          // lo que se muestra
        colHerramienta->ValueMember = "id_herramienta";    // lo que se guarda
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error al cargar herramientas: " + ex->Message);
    }
}

System::Void prestamos::dataGridViewPrestamos_EditingControlShowing(
    System::Object^ sender,
    DataGridViewEditingControlShowingEventArgs^ e)
{
    if (dataGridViewPrestamos->CurrentCell->ColumnIndex ==
        dataGridViewPrestamos->Columns["cantidad"]->Index)
    {
        TextBox^ tb = dynamic_cast<TextBox^>(e->Control);
        if (tb != nullptr)
        {
            tb->KeyPress -= gcnew KeyPressEventHandler(this, &prestamos::Cantidad_KeyPress);
            tb->KeyPress += gcnew KeyPressEventHandler(this, &prestamos::Cantidad_KeyPress);
        }
    }
}

System::Void prestamos::Cantidad_KeyPress(System::Object^ sender, KeyPressEventArgs^ e)
{
    if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar))
    {
        e->Handled = true; // bloquea letras y símbolos
    }
}

System::Void prestamos::buttonPrestamo_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        WebClient^ client = gcnew WebClient();
        client->Encoding = System::Text::Encoding::UTF8;

        // 1. Guardar préstamo principal
        NameValueCollection^ datosPrestamo = gcnew NameValueCollection();
        datosPrestamo->Add("id_profesor", cmbDocente->SelectedValue->ToString());
        datosPrestamo->Add("fecha", dateTimePickerFecha->Value.ToString("yyyy-MM-dd"));

        array<Byte>^ response = client->UploadValues("http://localhost/panol_api/insert_prestamo.php", "POST", datosPrestamo);
        String^ result = System::Text::Encoding::UTF8->GetString(response);

        MessageBox::Show("Respuesta insert_prestamo: " + result);


        int idPrestamo = Int32::Parse(result); // id_prestamo generado

        // 2. Guardar detalles
        for each(DataGridViewRow ^ row in dataGridViewPrestamos->Rows)
        {
            if (row->IsNewRow) continue;

            int idHerramienta = Convert::ToInt32(row->Cells["elementoRetirado"]->Value);
            int cantidad = Convert::ToInt32(row->Cells["cantidad"]->Value);

            NameValueCollection^ datosDetalle = gcnew NameValueCollection();
            datosDetalle->Add("id_prestamo", idPrestamo.ToString());
            datosDetalle->Add("id_herramienta", idHerramienta.ToString());
            datosDetalle->Add("cantidad", cantidad.ToString());
            datosDetalle->Add("novedades", ""); // opcional

            client->UploadValues("http://localhost/panol_api/insert_detalle.php", "POST", datosDetalle);
        }

        MessageBox::Show("Préstamo guardado correctamente.");
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error al guardar préstamo: " + ex->Message);
    }
}
/*
System::Void prestamos::buttonActualizar_Click(System::Object^ sender, System::EventArgs^ e)
{

    try
    {
        // 1️⃣ Validar docente seleccionado
        if (cmbDocente->SelectedIndex == -1)
        {
            MessageBox::Show("Seleccione un docente.");
            return;
        }

        int idProfesor = Convert::ToInt32(cmbDocente->SelectedValue);

        // 2️⃣ Obtener fecha formateada
        String^ fecha = dateTimePickerFecha->Value.ToString("yyyy-MM-dd");

        // 3️⃣ Construir URL
        String^ url = "http://localhost/panol_api/get_pedido_por_docente.php?id_profesor="
            + idProfesor.ToString() + "&fecha=" + fecha;

        WebClient^ client = gcnew WebClient();
        client->Encoding = System::Text::Encoding::UTF8;

        String^ json = client->DownloadString(url);

        // 4️⃣ Limpiar grid
        dataGridView1->Rows->Clear();

        // 5️⃣ Verificar si viene vacío
        if (json == "[]" || json->Trim()->Length == 0)
        {
            MessageBox::Show("No hay pedidos para ese docente en la fecha seleccionada.");
            return;
        }

        // 6️⃣ Parsear JSON simple
        Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
        auto matches = rx->Matches(json);

        for each (Match ^ m in matches)
        {
            String^ item = m->Value;

            String^ elemento = obtenerCampo(item, "elemento");
            String^ cantidad = obtenerCampo(item, "cantidad_solicitada");

            if (elemento != "" && cantidad != "")
            {
                dataGridView1->Rows->Add(elemento, cantidad);
            }
        }

        // 7️⃣ Si no hubo coincidencias reales
        if (dataGridView1->Rows->Count == 0)
        {
            MessageBox::Show("No se encontraron datos válidos.");
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error al cargar pedido: " + ex->Message);
    }
}*/

System::Void prestamos::buttonActualizar_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        // 1️⃣ Validar docente seleccionado
        if (cmbDocente->SelectedIndex == -1)
        {
            //MessageBox::Show("Seleccione un docente.");

            // SOLO mostramos el mensaje si NO fue el timer quien llamó a la función
            if (sender != timerActualizar) {
                MessageBox::Show("Seleccione un docente.");
            }

            return;
        }

        int idProfesor = Convert::ToInt32(cmbDocente->SelectedValue);

        // 2️⃣ Obtener fecha formateada
        String^ fecha = dateTimePickerFecha->Value.ToString("yyyy-MM-dd");

        // 3️⃣ Construir URL
        String^ url = "http://localhost/panol_api/get_pedido_por_docente.php?id_profesor="
            + idProfesor.ToString() + "&fecha=" + fecha;

        WebClient^ client = gcnew WebClient();
        client->Encoding = System::Text::Encoding::UTF8;

        String^ json = client->DownloadString(url);

        // 4️⃣ Limpiar grid
        dataGridView1->Rows->Clear();

        // 5️⃣ Verificar si viene vacío
        if (json == "[]" || json->Trim()->Length == 0)
        {
           // MessageBox::Show("No hay pedidos para ese docente en la fecha seleccionada.");
            // SOLO mostramos el mensaje si NO fue el timer
            if (sender != timerActualizar) {
                MessageBox::Show("No hay pedidos para ese docente en la fecha seleccionada.");
            }
            return;
        }

        // 6️⃣ Parsear JSON simple
        Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
        auto matches = rx->Matches(json);

        // 🔹 Definir colores para diferenciar pedidos
        array<Color>^ colores = { Color::LightBlue, Color::LightGreen, Color::LightYellow, Color::LightCoral };
        String^ ultimoIdPedido = "";
        Color colorFila;

        for each (Match ^ m in matches)
        {
            String^ item = m->Value;

            // 🔹 Obtener id_pedido también
            String^ idPedido = obtenerCampo(item, "id_pedido");
            String^ elemento = obtenerCampo(item, "elemento");
            String^ cantidad = obtenerCampo(item, "cantidad_solicitada");

            if (elemento != "" && cantidad != "")
            {
                // 🔹 Cambiar color si es un pedido nuevo
                if (idPedido != ultimoIdPedido)
                {
                    int colorIndex = Convert::ToInt32(idPedido) % colores->Length;
                    colorFila = colores[colorIndex];
                    ultimoIdPedido = idPedido;
                }

                // 🔹 Agregar fila y aplicar color
                int rowIndex = dataGridView1->Rows->Add(elemento, cantidad);
                dataGridView1->Rows[rowIndex]->DefaultCellStyle->BackColor = colorFila;
            }
        }

        dataGridView1->ClearSelection();

        // 7️⃣ Si no hubo coincidencias reales
        if (dataGridView1->Rows->Count == 0)
        {
            //MessageBox::Show("No se encontraron datos válidos.");
            if (sender != timerActualizar) {
                MessageBox::Show("No se encontraron datos válidos.");
            }
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error al cargar pedido: " + ex->Message);
    }
}

// prestamos.cpp
void prestamos::timerActualizar_Tick(System::Object^ sender, System::EventArgs^ e)
{
    // Llama a tu función de actualización del DataGridView
    //buttonActualizar_Click(nullptr, nullptr);

        // Solo si hay un docente seleccionado llamamos a la actualización
    if (cmbDocente->SelectedIndex != -1)
    {
        // Llamamos a la lógica, pero pasando el 'sender' del timer
        buttonActualizar_Click(sender, e);
    }
    // Si no hay docente, el timer no hace nada y se queda callado.
}






