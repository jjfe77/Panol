#include "pch.h"
#include "consumibles.h"

using namespace Panol;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Net;
using namespace System::Text::RegularExpressions;
using namespace System::Collections::Specialized;

// --- 1. AUXILIAR JSON ---
String^ Panol::consumibles::obtenerCampo(String^ jsonItem, String^ campo) {
    String^ patron = "\\\"" + campo + "\\\"\\s*:\\s*\\\"?([^\\\",\\}]*)\\\"?";
    Regex^ rx = gcnew Regex(patron);
    Match^ m = rx->Match(jsonItem);
    return m->Success ? m->Groups[1]->Value : "";
}

// --- 2. CARGA DE MATERIALES ---
void Panol::consumibles::cargarMaterialesExistentes() {
    try {
        WebClient^ client = gcnew WebClient();
        client->Encoding = System::Text::Encoding::UTF8;
        String^ url = "http://localhost/panol_api/get_materiales.php";
        String^ json = client->DownloadString(url);

        DataTable^ dt = gcnew DataTable();
        dt->Columns->Add("id_consumible", Int32::typeid);
        dt->Columns->Add("nombre", String::typeid);

        Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
        auto matches = rx->Matches(json);
        for each (Match ^ m in matches) {
            String^ idStr = obtenerCampo(m->Value, "id_consumible");
            String^ nombre = obtenerCampo(m->Value, "nombre");
            if (idStr != "" && nombre != "") dt->Rows->Add(Int32::Parse(idStr), nombre);
        }

        nombreMaterial->DataSource = nullptr;
        nombreMaterial->DataSource = dt;
        nombreMaterial->DisplayMember = "nombre";
        nombreMaterial->ValueMember = "nombre"; // IMPORTANTE: Valor es el nombre

        // Hacemos lo mismo para el combo de retiro
        materialRetirado->DataSource = dt; // Usamos el mismo DataTable 'dt'
        materialRetirado->DisplayMember = "nombre";
        materialRetirado->ValueMember = "nombre";
    }
    catch (Exception^ ex) { MessageBox::Show("Error carga: " + ex->Message); }
}

System::Void Panol::consumibles::consumibles_Load(System::Object^ sender, System::EventArgs^ e) {
    cargarMaterialesExistentes();
}

// --- 3. CONFIGURACIÓN DEL COMBO (Permite escribir) ---
System::Void Panol::consumibles::dataGridView1_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e) {
    if (dataGridView1->CurrentCell->ColumnIndex == 0) {
        ComboBox^ combo = safe_cast<ComboBox^>(e->Control);
        if (combo != nullptr) {
            combo->DropDownStyle = ComboBoxStyle::DropDown;
            combo->AutoCompleteMode = AutoCompleteMode::SuggestAppend;
            combo->AutoCompleteSource = AutoCompleteSource::ListItems;
        }
    }
}

// --- 4. LA SOLUCIÓN DEFINITIVA PARA QUE NO SE BORRE EL TEXTO ---
System::Void Panol::consumibles::dataGridView1_CellParsing(System::Object^ sender, System::Windows::Forms::DataGridViewCellParsingEventArgs^ e) {
    if (e->ColumnIndex == 0 && e->Value != nullptr) {
        String^ textoEscrito = e->Value->ToString()->Trim();
        if (!String::IsNullOrEmpty(textoEscrito)) {
            // Formatear: Primera Mayúscula
            String^ formateado = textoEscrito->Substring(0, 1)->ToUpper() + (textoEscrito->Length > 1 ? textoEscrito->Substring(1)->ToLower() : "");

            DataTable^ dt = safe_cast<DataTable^>(nombreMaterial->DataSource);
            bool existe = false;

            for (int i = 0; i < dt->Rows->Count; i++) {
                if (dt->Rows->default[i]->default["nombre"]->ToString()->Equals(formateado, StringComparison::OrdinalIgnoreCase)) {
                    formateado = dt->Rows->default[i]->default["nombre"]->ToString();
                    existe = true;
                    break;
                }
            }

            // SI ES NUEVO: Lo agregamos al DataTable AHORA MISMO
            if (!existe) {
                DataRow^ fila = dt->NewRow();
                fila->default["id_consumible"] = gcnew Int32(0);
                fila->default["nombre"] = formateado;
                dt->Rows->Add(fila);
            }

            e->Value = formateado;
            e->ParsingApplied = true; // Le dice al Grid: "Acepta este valor, ya lo validé"
        }
    }
}

// --- 5. BOTÓN INGRESAR (YA FUNCIONA "10 PUNTOS") ---
System::Void Panol::consumibles::buttonIngreso_Click(System::Object^ sender, System::EventArgs^ e) {

    // --- ESTO VA AL PRINCIPIO ---
    System::Windows::Forms::DialogResult dr = MessageBox::Show(
        "¿Está seguro de que desea registrar este ingreso de materiales?",
        "Confirmar Ingreso",
        MessageBoxButtons::YesNo,
        MessageBoxIcon::Question);

    if (dr == System::Windows::Forms::DialogResult::No) {
        return; // Si el usuario dice que NO, la función se detiene aquí y no hace nada
    }
    // ----------------------------


    dataGridView1->EndEdit();
    try {
        int contador = 0;
        WebClient^ client = gcnew WebClient();
        for (int i = 0; i < dataGridView1->Rows->Count; i++) {
            if (dataGridView1->Rows->default[i]->IsNewRow) continue;

            Object^ n = dataGridView1->Rows->default[i]->Cells->default[0]->Value;
            Object^ c = dataGridView1->Rows->default[i]->Cells->default[1]->Value;
            Object^ d = dataGridView1->Rows->default[i]->Cells->default[2]->Value;

            if (n != nullptr && c != nullptr && !String::IsNullOrWhiteSpace(c->ToString())) {
                NameValueCollection^ parametros = gcnew NameValueCollection();
                parametros->Add("nombre", n->ToString());
                parametros->Add("cantidad", c->ToString());
                parametros->Add("descripcion", (d != nullptr) ? d->ToString() : "");

                client->UploadValues("http://localhost/panol_api/save_ingreso.php", "POST", parametros);
                contador++;
            }
        }
        if (contador > 0) {
            MessageBox::Show("Guardado exitoso: " + contador + " materiales.");
            dataGridView1->Rows->Clear();
            cargarMaterialesExistentes();
            cargarStock();
        }
    }
    catch (Exception^ ex) { MessageBox::Show("Error: " + ex->Message); }
}

System::Void Panol::consumibles::dataGridView1_DataError(System::Object^ sender, System::Windows::Forms::DataGridViewDataErrorEventArgs^ e) {
    e->ThrowException = false;
}

System::Void Panol::consumibles::buttonNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
    // 1. Obtener el texto del TextBox
    String^ nombreNuevo = textBoxNuevo->Text->Trim();

    // 2. Validar que no esté vacío
    if (String::IsNullOrWhiteSpace(nombreNuevo)) {
        MessageBox::Show("Por favor, ingrese el nombre del material nuevo.", "Aviso");
        return;
    }

    // 3. Formatear: Primera Mayúscula, resto minúscula (Ej: "lija" -> "Lija")
    String^ formateado = nombreNuevo->Substring(0, 1)->ToUpper() + (nombreNuevo->Length > 1 ? nombreNuevo->Substring(1)->ToLower() : "");

    try {
        // 4. Preparar el envío al PHP
        WebClient^ client = gcnew WebClient();
        NameValueCollection^ parametros = gcnew NameValueCollection();
        parametros->Add("nombre", formateado);
        parametros->Add("cantidad", "0"); // Lo creamos con cantidad cero
        parametros->Add("descripcion", "Material nuevo registrado desde el panel");

        // Usamos el mismo PHP que ya tienes
        client->UploadValues("http://localhost/panol_api/save_ingreso.php", "POST", parametros);

        MessageBox::Show("Material '" + formateado + "' registrado correctamente.", "Éxito");

        // 5. Limpiar el TextBox
        textBoxNuevo->Text = "";

        // 6. ¡MUY IMPORTANTE!: Recargar el ComboBox del DataGridView
        // Esto hace que el nuevo nombre aparezca inmediatamente en la lista desplegable
        cargarMaterialesExistentes();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al conectar con el servidor: " + ex->Message, "Error");
    }
}

// 1. Función para descargar y llenar el Grid de Stock
void Panol::consumibles::cargarStock()
{
    try
    {
        WebClient^ client = gcnew WebClient();
        client->Encoding = System::Text::Encoding::UTF8;
        String^ url = "http://localhost/panol_api/get_stock.php";
        String^ json = client->DownloadString(url);

        // Limpiamos las filas actuales del Grid antes de cargar las nuevas
        dataGridView2->Rows->Clear();

        // Usamos Regex para separar cada objeto del JSON {...}
        Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
        auto matches = rx->Matches(json);

        for each (Match ^ m in matches) {
            String^ item = m->Value;

            // Extraemos nombre y cantidad usando tu función obtenerCampo
            String^ nombre = obtenerCampo(item, "nombre");
            String^ cantidad = obtenerCampo(item, "cantidad");

            if (nombre != "" && cantidad != "") {
                // Agregamos la fila al dataGridView2
                // El orden debe coincidir con tus columnas: 0: materialStock, 1: cantidadStock
                dataGridView2->Rows->Add(nombre, cantidad);

                for each (DataGridViewRow ^ row in dataGridView2->Rows)
                {
                    if (row->Cells[1]->Value != nullptr)
                    {
                        int cant = Convert::ToInt32(row->Cells[1]->Value);

                        if (cant < 5)
                        {
                            row->Cells[1]->Style->BackColor = Color::Yellow;
                            //row->Cells[1]->Style->ForeColor = Color::Black;
                        }
                    }
                }
            }
        }
        // 1. Quitamos el foco de la celda (el recuadro punteado)
        dataGridView2->CurrentCell = nullptr;

        // 2. Quitamos el color azul de selección
        dataGridView2->ClearSelection();
    }

    catch (Exception^ ex)
    {
        MessageBox::Show("Error al cargar el stock: " + ex->Message);
    }
}

// 2. Evento del botón "Ver Stock"
System::Void Panol::consumibles::buttonVerStock_Click(System::Object^ sender, System::EventArgs^ e) {
    cargarStock();
}

System::Void Panol::consumibles::buttonRetiro_Click(System::Object^ sender, System::EventArgs^ e) {

    // --- ESTO VA AL PRINCIPIO ---
    System::Windows::Forms::DialogResult dr = MessageBox::Show(
        "¿Confirmar el retiro de los materiales seleccionados?",
        "Confirmar Retiro",
        MessageBoxButtons::YesNo,
        MessageBoxIcon::Warning); // Usamos Warning para que el icono sea de advertencia

    if (dr == System::Windows::Forms::DialogResult::No) {
        return; // Se detiene y no descuenta nada del stock
    }
    // ----------------------------



    dataGridView3->EndEdit(); // Asegurar que se guarden los cambios en las celdas

    try {
        int exitos = 0;
        int fallidos = 0;
        WebClient^ client = gcnew WebClient();

        for (int i = 0; i < dataGridView3->Rows->Count; i++) {
            if (dataGridView3->Rows->default[i]->IsNewRow) continue;

            // 0: materialRetirado (Combo), 1: Cantidad (Text), 2: nombreRetira (Text)
            Object^ vNombre = dataGridView3->Rows->default[i]->Cells->default[0]->Value;
            Object^ vCant = dataGridView3->Rows->default[i]->Cells->default[1]->Value;
            Object^ vQuien = dataGridView3->Rows->default[i]->Cells->default[2]->Value;

            if (vNombre != nullptr && vCant != nullptr && vQuien != nullptr) {
                NameValueCollection^ parametros = gcnew NameValueCollection();
                parametros->Add("nombre", vNombre->ToString());
                parametros->Add("cantidad", vCant->ToString());
                parametros->Add("quien_retira", vQuien->ToString());

                // Enviamos y recibimos la respuesta del PHP
                array<Byte>^ responseBytes = client->UploadValues("http://localhost/panol_api/save_retiro.php", "POST", parametros);
                String^ respuesta = System::Text::Encoding::UTF8->GetString(responseBytes);

                if (respuesta->Trim() == "success") {
                    exitos++;
                }
                else if (respuesta->Trim() == "insufficient") {
                    MessageBox::Show("Stock insuficiente para: " + vNombre->ToString(), "Atención");
                    fallidos++;
                }
                else {
                    MessageBox::Show("Error con el material: " + vNombre->ToString(), "Error");
                    fallidos++;
                }
            }
        }

        if (exitos > 0) {
            MessageBox::Show("Se procesaron " + exitos + " retiros correctamente.", "Éxito");
            dataGridView3->Rows->Clear(); // Limpiar el grid de retiro
            cargarStock(); // Actualizar el grid de stock automáticamente
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al procesar retiro: " + ex->Message);
    }
}

// Autocompletado para el Grid de Retiro
System::Void Panol::consumibles::dataGridView3_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e) {
    // Verificamos que sea la columna del material (índice 0)
    if (dataGridView3->CurrentCell->ColumnIndex == 0) {
        ComboBox^ combo = safe_cast<ComboBox^>(e->Control);
        if (combo != nullptr) {
            // Permitimos escribir
            combo->DropDownStyle = ComboBoxStyle::DropDown;
            // Configuramos el autocompletado
            combo->AutoCompleteMode = AutoCompleteMode::SuggestAppend;
            combo->AutoCompleteSource = AutoCompleteSource::ListItems;
        }
    }
}

// Manejo de errores para el Grid de Retiro
System::Void Panol::consumibles::dataGridView3_DataError(System::Object^ sender, System::Windows::Forms::DataGridViewDataErrorEventArgs^ e) {
    e->ThrowException = false; // Evita que el programa se trabe si escriben algo que no existe
}

// Función para descargar el historial y llenar el dataGridView4
void Panol::consumibles::cargarHistorial() {
    try {
        WebClient^ client = gcnew WebClient();
        client->Encoding = System::Text::Encoding::UTF8;
        String^ url = "http://localhost/panol_api/get_historial.php";
        String^ json = client->DownloadString(url);

        // Limpiamos el grid antes de cargar
        dataGridView4->Rows->Clear();

        Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
        auto matches = rx->Matches(json);

        for each (Match ^ m in matches) {
            String^ item = m->Value;

            // Extraemos los datos usando tu función obtenerCampo
            String^ fecha = obtenerCampo(item, "fecha_salida");
            String^ material = obtenerCampo(item, "material");
            String^ cantidad = obtenerCampo(item, "cantidad_retirada");
            String^ persona = obtenerCampo(item, "nombre_retira");

            if (fecha != "") {
                // Agregamos la fila al dataGridView4
                dataGridView4->Rows->Add(fecha, material, cantidad, persona);
            }
        }
        // 1. Quitamos el foco de la celda (el recuadro punteado)
        dataGridView4->CurrentCell = nullptr;

        // 2. Quitamos el color azul de selección
        dataGridView4->ClearSelection();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al cargar historial: " + ex->Message);
    }
}

// Evento del botón "Ver Retiros"
System::Void Panol::consumibles::buttonHistorialRetiro_Click(System::Object^ sender, System::EventArgs^ e) {
    cargarHistorial();
}
