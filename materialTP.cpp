#include "pch.h"
#include "materialTP.h"

using namespace Panol;
using namespace System;
using namespace System::Net;
using namespace System::Text;
using namespace System::Text::RegularExpressions;
using namespace System::Windows::Forms;



System::Void materialTP::materialTP_Load(System::Object^ sender, System::EventArgs^ e)
{
    configurarGrids();
    dataGridView1->Rows->Clear();
    dataGridView2->Rows->Clear();
    dataGridView2->Columns["cantidadEntrante"]->ReadOnly = false;
}


// CONFIGURAR GRIDS


void materialTP::configurarGrids()
{
    dataGridView1->ReadOnly = true;
    dataGridView1->AllowUserToAddRows = false;
    dataGridView1->AllowUserToDeleteRows = false;
    dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
    dataGridView1->MultiSelect = false;

    dataGridView2->AllowUserToAddRows = true;
    dataGridView2->AllowUserToDeleteRows = true;
    dataGridView2->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
    dataGridView2->MultiSelect = false;

    dataGridView2->Columns["materialEntrante"]->ReadOnly = false;
    dataGridView2->Columns["cantidadEntrante"]->ReadOnly = false;
    dataGridView2->Columns["columDescripIngresar"]->ReadOnly = false;
    dataGridView2->Columns["ColumObservIngresar"]->ReadOnly = false;
}


// VALIDAR TEXTO


bool materialTP::validarTexto(String^ texto)
{
    if (String::IsNullOrWhiteSpace(texto))
        return true;

    for each (wchar_t c in texto)
    {
        if (!Char::IsLetter(c) &&
            !Char::IsWhiteSpace(c) &&
            c != '.' && c != ',' &&
            c != '-' && c != '(' && c != ')' &&
            c != ':' && c != ';' && c != '\'')
            return false;
    }
    return true;
}


// OBTENER CAMPO JSON

/*
String^ materialTP::obtenerCampo(String^ jsonItem, String^ campo)
{
    String^ patron = "\"" + campo + "\"\\s*:\\s*(?:\"([^\"]*)\"|([0-9]+))";
    Regex^ rx = gcnew Regex(patron);
    Match^ m = rx->Match(jsonItem);

    if (!m->Success)
        return "";

    if (m->Groups[1]->Value != "")
        return m->Groups[1]->Value;

    return m->Groups[2]->Value;
}*/


String^ materialTP::obtenerCampo(String^ jsonItem, String^ campo)
{
    String^ patron = "\"" + campo + "\"\\s*:\\s*(?:\"([^\"]*)\"|([0-9]+))";
    Regex^ rx = gcnew Regex(patron);
    Match^ m = rx->Match(jsonItem);

    if (!m->Success)
        return "";

    String^ resultado = "";
    if (m->Groups[1]->Value != "")
        resultado = m->Groups[1]->Value;
    else
        resultado = m->Groups[2]->Value;

    // --- SOLUCIÓN AQUÍ ---
    // Esta línea convierte los \u00f1 y similares en caracteres reales
    try {
        resultado = System::Text::RegularExpressions::Regex::Unescape(resultado);
    }
    catch (...) {
        // Si no hay nada que desescapar, devuelve el original
    }

    return resultado;
}


// LIMPIAR GRID DERECHO


void materialTP::limpiarGridDerecho()
{
    dataGridView2->Rows->Clear();
    dataGridView1->ClearSelection();

    dataGridView2->Columns["cantidadEntrante"]->ReadOnly = false;
    dataGridView2->Columns["materialEntrante"]->ReadOnly = false;
    dataGridView2->Columns["columDescripIngresar"]->ReadOnly = false;
    dataGridView2->Columns["ColumObservIngresar"]->ReadOnly = false;

    dataGridView2->AllowUserToAddRows = true;
}


// BOTON LIMPIAR


System::Void materialTP::buttonLimpiar_Click(System::Object^ sender, System::EventArgs^ e)
{
    limpiarGridDerecho();
}


// BOTON LISTADO


System::Void materialTP::buttonListado_Click(System::Object^ sender, System::EventArgs^ e)
{
    cargarMaterialesExistentes();
}


// CARGAR MATERIALES EXISTENTES


void materialTP::cargarMaterialesExistentes()
{
    _cargandoDatos = true;

    try
    {
        WebClient^ client = gcnew WebClient();
        client->Encoding = Encoding::UTF8;

        String^ json = client->DownloadString(
            "http://localhost/panol_api/get_material_tp.php");

        dataGridView1->Rows->Clear();
        Regex^ rx = gcnew Regex("\\{[^\\{\\}]+\\}");

        for each (Match ^ m in rx->Matches(json))
        {
            String^ item = m->Value;
            String^ id = obtenerCampo(item, "id_material_tp");
            String^ nombre = obtenerCampo(item, "nombre");
            String^ cant = obtenerCampo(item, "cantidad");
            String^ desc = obtenerCampo(item, "descripcion");
            String^ obs = obtenerCampo(item, "observaciones");

            int i = dataGridView1->Rows->Add();
            dataGridView1->Rows[i]->Cells["columNombre"]->Value = nombre;
            dataGridView1->Rows[i]->Cells["stock"]->Value = cant;
            dataGridView1->Rows[i]->Cells["descripcion"]->Value = desc;
            dataGridView1->Rows[i]->Cells["columObserv"]->Value = obs;
            dataGridView1->Rows[i]->Tag = id;
        }

        dataGridView1->ClearSelection();
        dataGridView2->Rows->Clear();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error al cargar materiales: " + ex->Message);
    }
    finally
    {
        _cargandoDatos = false;
    }
}

// CARGAR FILA EN GRID DERECHO

void materialTP::cargarFilaEnGridDerecho(int rowIndex)
{
    if (rowIndex < 0 || rowIndex >= dataGridView1->Rows->Count)
        return;

    DataGridViewRow^ fila = dataGridView1->Rows[rowIndex];

    if (fila->Cells["columNombre"]->Value == nullptr)
        return;

    String^ id = (fila->Tag != nullptr) ? fila->Tag->ToString() : "";
    String^ nombre = (fila->Cells["columNombre"]->Value != nullptr) ?
        fila->Cells["columNombre"]->Value->ToString() : "";
    String^ cant = (fila->Cells["stock"]->Value != nullptr) ?
        fila->Cells["stock"]->Value->ToString() : "0";
    String^ desc = (fila->Cells["descripcion"]->Value != nullptr) ?
        fila->Cells["descripcion"]->Value->ToString() : "";
    String^ obs = (fila->Cells["columObserv"]->Value != nullptr) ?
        fila->Cells["columObserv"]->Value->ToString() : "";

    dataGridView2->Rows->Clear();
    int i = dataGridView2->Rows->Add();

    dataGridView2->Rows[i]->Cells["materialEntrante"]->Value = nombre;
    dataGridView2->Rows[i]->Cells["cantidadEntrante"]->Value = cant;
    dataGridView2->Rows[i]->Cells["columDescripIngresar"]->Value = desc;
    dataGridView2->Rows[i]->Cells["ColumObservIngresar"]->Value = obs;
    dataGridView2->Rows[i]->Tag = id;

    dataGridView2->Columns["cantidadEntrante"]->ReadOnly = true;
    dataGridView2->Rows[i]->Cells["materialEntrante"]->ReadOnly = true;
    dataGridView2->Rows[i]->Cells["columDescripIngresar"]->ReadOnly = true;
    dataGridView2->Rows[i]->Cells["ColumObservIngresar"]->ReadOnly = true;

    dataGridView2->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::White;
}

// SELECCIONAR FILA IZQUIERDA


System::Void materialTP::dataGridView1_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (_cargandoDatos)
        return;

    if (dataGridView1->SelectedRows->Count == 0)
        return;

    int rowIndex = dataGridView1->SelectedRows[0]->Index;
    cargarFilaEnGridDerecho(rowIndex);
}

// CELL CLICK


System::Void materialTP::dataGridView1_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex < 0)
        return;

    cargarFilaEnGridDerecho(e->RowIndex);
}


// BOTON EDITAR


System::Void materialTP::buttonEditar_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView2->Rows->Count == 0 ||
        dataGridView2->Rows[0]->IsNewRow ||
        dataGridView2->Rows[0]->Tag == nullptr ||
        String::IsNullOrEmpty(dataGridView2->Rows[0]->Tag->ToString()))
    {
        MessageBox::Show("Advertencia: Seleccione un material del listado izquierdo para editar.");
        return;
    }

    dataGridView2->Rows[0]->Cells["materialEntrante"]->ReadOnly = false;
    dataGridView2->Rows[0]->Cells["columDescripIngresar"]->ReadOnly = false;
    dataGridView2->Rows[0]->Cells["ColumObservIngresar"]->ReadOnly = false;
    dataGridView2->Columns["cantidadEntrante"]->ReadOnly = true;

    dataGridView2->Rows[0]->DefaultCellStyle->BackColor = System::Drawing::Color::LightYellow;

    MessageBox::Show("Modo edicion activado.\nPuede modificar: Nombre, Descripcion, Observaciones\nCantidad esta bloqueada\nPresione 'Guardar Edicion' o 'Limpiar' para cancelar.");
}


// BOTON GUARDAR EDICION

System::Void materialTP::buttonGuardarEdicion_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView2->Rows->Count == 0 ||
        dataGridView2->Rows[0]->IsNewRow ||
        dataGridView2->Rows[0]->Tag == nullptr)
    {
        MessageBox::Show("Advertencia: No hay material seleccionado para guardar.");
        return;
    }

    if (dataGridView2->Rows[0]->Cells["materialEntrante"]->ReadOnly == true)
    {
        MessageBox::Show("Advertencia: Debe presionar el boton 'Editar' antes de guardar los cambios.\n\nFlujo correcto:\n1. Seleccionar material\n2. Click en 'Editar'\n3. Modificar datos de la tabla\n4. Click en 'Guardar Edicion'");
        return;
    }

    DataGridViewRow^ row = dataGridView2->Rows[0];
    String^ id = row->Tag->ToString();

    String^ nombre = (row->Cells["materialEntrante"]->Value != nullptr) ?
        row->Cells["materialEntrante"]->Value->ToString()->Trim() : "";
    String^ desc = (row->Cells["columDescripIngresar"]->Value != nullptr) ?
        row->Cells["columDescripIngresar"]->Value->ToString()->Trim() : "";
    String^ obs = (row->Cells["ColumObservIngresar"]->Value != nullptr) ?
        row->Cells["ColumObservIngresar"]->Value->ToString()->Trim() : "";

    if (String::IsNullOrWhiteSpace(nombre))
    {
        MessageBox::Show("Error: El nombre es obligatorio.");
        return;
    }
    if (!validarTexto(nombre))
    {
        MessageBox::Show("Error: El nombre contiene caracteres no validos.");
        return;
    }
    if (!String::IsNullOrWhiteSpace(desc) && !validarTexto(desc))
    {
        MessageBox::Show("Error: La descripcion contiene caracteres no validos.");
        return;
    }
    if (!String::IsNullOrWhiteSpace(obs) && !validarTexto(obs))
    {
        MessageBox::Show("Error: Las observaciones contienen caracteres no validos.");
        return;
    }

    String^ json = "{"
        "\"id_material_tp\":" + id + ","
        "\"nombre\":\"" + nombre + "\","
        "\"descripcion\":\"" + desc + "\","
        "\"observaciones\":\"" + obs + "\""
        "}";

    try
    {
        WebClient^ client = gcnew WebClient();
        client->Headers->Add("Content-Type", "application/json");
        client->UploadString("http://localhost/panol_api/editar_material_tp.php", "POST", json);

        MessageBox::Show("Material actualizado correctamente.");

        limpiarGridDerecho();
        cargarMaterialesExistentes();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error al guardar: " + ex->Message);
    }
}


// BOTON CARGAR


System::Void materialTP::buttonCargar_Click(System::Object^ sender, System::EventArgs^ e)
{
    dataGridView2->Columns["cantidadEntrante"]->ReadOnly = false;
    dataGridView2->Columns["materialEntrante"]->ReadOnly = false;
    dataGridView2->Columns["columDescripIngresar"]->ReadOnly = false;
    dataGridView2->Columns["ColumObservIngresar"]->ReadOnly = false;

    dataGridView2->EndEdit();

    int filasValidas = 0;
    for each (DataGridViewRow ^ row in dataGridView2->Rows)
    {
        if (row->IsNewRow)
            continue;

        String^ nombre = (row->Cells["materialEntrante"]->Value != nullptr) ?
            row->Cells["materialEntrante"]->Value->ToString()->Trim() : "";

        if (!String::IsNullOrWhiteSpace(nombre))
            filasValidas++;
    }

    if (filasValidas == 0)
    {
        MessageBox::Show("Advertencia: No hay materiales para cargar. Nombre y cantidad son obligatorios.");
        return;
    }

    if (dataGridView2->Rows->Count > 0 &&
        !dataGridView2->Rows[0]->IsNewRow &&
        dataGridView2->Rows[0]->Tag != nullptr &&
        !String::IsNullOrEmpty(dataGridView2->Rows[0]->Tag->ToString()))
    {
        MessageBox::Show("Advertencia: Esta editando un material existente.\nUse 'Guardar Edicion' o 'Limpiar' para comenzar uno nuevo.");
        return;
    }

    String^ json = "[";
    bool primero = true;

    for each (DataGridViewRow ^ row in dataGridView2->Rows)
    {
        if (row->IsNewRow)
            continue;

        String^ nombre = (row->Cells["materialEntrante"]->Value != nullptr) ?
            row->Cells["materialEntrante"]->Value->ToString()->Trim() : "";

        if (String::IsNullOrWhiteSpace(nombre))
            continue;

        String^ cantStr = (row->Cells["cantidadEntrante"]->Value != nullptr) ?
            row->Cells["cantidadEntrante"]->Value->ToString()->Trim() : "";
        String^ desc = (row->Cells["columDescripIngresar"]->Value != nullptr) ?
            row->Cells["columDescripIngresar"]->Value->ToString()->Trim() : "";
        String^ obs = (row->Cells["ColumObservIngresar"]->Value != nullptr) ?
            row->Cells["ColumObservIngresar"]->Value->ToString()->Trim() : "";

        if (String::IsNullOrWhiteSpace(cantStr))
        {
            MessageBox::Show("Error: La cantidad es obligatoria para: " + nombre);
            return;
        }

        int cantidad = 0;
        if (!Int32::TryParse(cantStr, cantidad) || cantidad < 0)
        {
            MessageBox::Show("Error: Cantidad invalida para: " + nombre);
            return;
        }

        if (!String::IsNullOrWhiteSpace(desc) && !validarTexto(desc))
        {
            MessageBox::Show("Error: La descripcion contiene caracteres no validos: " + nombre);
            return;
        }

        if (!String::IsNullOrWhiteSpace(obs) && !validarTexto(obs))
        {
            MessageBox::Show("Error: Las observaciones contienen caracteres no validos: " + nombre);
            return;
        }

        if (!primero)
            json += ",";

        json += "{"
            "\"nombre\":\"" + nombre + "\","
            "\"cantidad\":" + cantidad.ToString() + ","
            "\"descripcion\":\"" + desc + "\","
            "\"observaciones\":\"" + obs + "\""
            "}";

        primero = false;
    }

    json += "]";

    try
    {
        WebClient^ client = gcnew WebClient();
        client->Headers->Add("Content-Type", "application/json");
        client->UploadString("http://localhost/panol_api/post_material_tp.php", "POST", json);

        MessageBox::Show("Carga exitosa");

        limpiarGridDerecho();
        cargarMaterialesExistentes();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error al cargar: " + ex->Message);
    }
}



System::Void materialTP::Cantidad_KeyPress(System::Object^ sender, KeyPressEventArgs^ e)
{
    if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar))
        e->Handled = true;
}



void materialTP::dataGridView2_EditingControlShowing(System::Object^ sender, DataGridViewEditingControlShowingEventArgs^ e)
{
    TextBox^ tb = dynamic_cast<TextBox^>(e->Control);

    if (tb != nullptr)
    {
        tb->KeyPress -= gcnew KeyPressEventHandler(this, &materialTP::Texto_KeyPress);
        tb->KeyPress -= gcnew KeyPressEventHandler(this, &materialTP::Cantidad_KeyPress);

        int col = dataGridView2->CurrentCell->ColumnIndex;
        DataGridViewColumn^ colCant = dataGridView2->Columns["cantidadEntrante"];

        if (col == colCant->Index)
        {
            tb->KeyPress += gcnew KeyPressEventHandler(this, &materialTP::Cantidad_KeyPress);
        }
        else
        {
            tb->KeyPress += gcnew KeyPressEventHandler(this, &materialTP::Texto_KeyPress);
        }
    }
}



void materialTP::Texto_KeyPress(System::Object^ sender, KeyPressEventArgs^ e)
{
    if (!Char::IsControl(e->KeyChar) &&
        !Char::IsLetter(e->KeyChar) &&
        !Char::IsWhiteSpace(e->KeyChar) &&
        e->KeyChar != '.' && e->KeyChar != ',' &&
        e->KeyChar != '-' && e->KeyChar != '(' && e->KeyChar != ')' &&
        e->KeyChar != ':' && e->KeyChar != ';' && e->KeyChar != '\'')
    {
        e->Handled = true;
    }
}



void materialTP::dataGridView2_CellValidating(System::Object^ sender, DataGridViewCellValidatingEventArgs^ e)
{
    if (dataGridView2->Columns[e->ColumnIndex]->Name == "cantidadEntrante")
    {
        String^ valor = e->FormattedValue->ToString();

        if (!String::IsNullOrWhiteSpace(valor))
        {
            int num;
            if (!Int32::TryParse(valor, num) || num < 0)
            {
                MessageBox::Show("La cantidad debe ser un numero positivo.");
                e->Cancel = true;
            }
        }
    }
}



void materialTP::dataGridView2_DataError(System::Object^ sender, DataGridViewDataErrorEventArgs^ e)
{
    MessageBox::Show("Dato invalido ingresado.");
    e->Cancel = true;
}