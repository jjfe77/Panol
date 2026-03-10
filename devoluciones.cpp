#include "pch.h"
#include "devoluciones.h"

using namespace Panol;
using namespace System;
using namespace System::Net;
using namespace System::Windows::Forms;
using namespace System::Text;
using namespace System::Text::RegularExpressions;
using namespace System::IO;

System::Void devoluciones::devoluciones_Load(System::Object^ sender, System::EventArgs^ e)
{
    //MessageBox::Show("Load ejecutado");
    cargarUsuarios();
}

void devoluciones::cargarUsuarios()
{
    try
    {
        WebClient^ client = gcnew WebClient();
        client->Encoding = Encoding::UTF8;

        String^ url = "http://localhost/panol_api/get_usuarios.php";
        String^ json = client->DownloadString(url);

        dataGridView1->Rows->Clear();

        Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
        auto matches = rx->Matches(json);

        for each (Match ^ m in matches)
        {
            String^ item = m->Value;

            String^ id = obtenerCampo(item, "id_usuario");
            String^ dni = obtenerCampo(item, "dni");
            String^ apellido = obtenerCampo(item, "apellido");
            String^ nombre = obtenerCampo(item, "nombre");
            String^ user = obtenerCampo(item, "user");

            if (id != "")
            {
                int rowIndex = dataGridView1->Rows->Add();

                dataGridView1->Rows[rowIndex]->Cells["dni"]->Value = dni;
                dataGridView1->Rows[rowIndex]->Cells["apellido"]->Value = apellido;
                dataGridView1->Rows[rowIndex]->Cells["nombre"]->Value = nombre;
                dataGridView1->Rows[rowIndex]->Cells["user"]->Value = user;

                // Guardamos el ID oculto en Tag
                dataGridView1->Rows[rowIndex]->Tag = id;
            }
        }

        dataGridView1->ClearSelection();
        dataGridView1->CurrentCell = nullptr;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error al cargar usuarios: " + ex->Message);
    }
}

String^ devoluciones::obtenerCampo(String^ jsonItem, String^ campo)
{
    String^ patron = "\\\"" + campo + "\\\"\\s*:\\s*\\\"([^\\\"]*)\\\"";
    Regex^ rx = gcnew Regex(patron);
    Match^ m = rx->Match(jsonItem);
    return m->Success ? m->Groups[1]->Value : "";
}

void devoluciones::guardarCambios()
{
    try
    {
        for each (DataGridViewRow ^ row in dataGridView1->Rows)
        {
            if (row->IsNewRow) continue;

            String^ dni = Convert::ToString(row->Cells["dni"]->Value);
            String^ apellido = Convert::ToString(row->Cells["apellido"]->Value);
            String^ nombre = Convert::ToString(row->Cells["nombre"]->Value);
            String^ user = Convert::ToString(row->Cells["user"]->Value);

            if (String::IsNullOrEmpty(dni)) continue;

            if (row->Tag != nullptr)
            {
                String^ id = safe_cast<String^>(row->Tag);
                actualizarUsuario(id, dni, apellido, nombre, user);
            }
            else
            {
                insertarUsuario(dni, apellido, nombre, user);
            }
        }

        MessageBox::Show("Cambios guardados correctamente.");
        cargarUsuarios();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error: " + ex->Message);
    }
}

void devoluciones::actualizarUsuario(String^ id, String^ dni, String^ apellido, String^ nombre, String^ user)
{
    HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create("http://localhost/panol_api/update_usuario.php");
    request->Method = "POST";

    String^ postData = "id_usuario=" + id +
        "&dni=" + dni +
        "&apellido=" + apellido +
        "&nombre=" + nombre +
        "&user=" + user;

    array<Byte>^ byteArray = Encoding::UTF8->GetBytes(postData);
    request->ContentType = "application/x-www-form-urlencoded";
    request->ContentLength = byteArray->Length;

    Stream^ dataStream = request->GetRequestStream();
    dataStream->Write(byteArray, 0, byteArray->Length);
    dataStream->Close();

    request->GetResponse()->Close();
}

void devoluciones::insertarUsuario(String^ dni, String^ apellido, String^ nombre, String^ user)
{
    HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create("http://localhost/panol_api/insert_usuario.php");
    request->Method = "POST";

    String^ postData = "dni=" + dni +
        "&apellido=" + apellido +
        "&nombre=" + nombre +
        "&user=" + user;

    array<Byte>^ byteArray = Encoding::UTF8->GetBytes(postData);
    request->ContentType = "application/x-www-form-urlencoded";
    request->ContentLength = byteArray->Length;

    Stream^ dataStream = request->GetRequestStream();
    dataStream->Write(byteArray, 0, byteArray->Length);
    dataStream->Close();

    request->GetResponse()->Close();
}

void devoluciones::cargarRegistroIngreso()
{
    try
    {
        WebClient^ client = gcnew WebClient();
        client->Encoding = Encoding::UTF8;

        String^ url = "http://localhost/panol_api/get_registro_ingreso.php";
        String^ json = client->DownloadString(url);

        dataGridView2->Rows->Clear();

        Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
        auto matches = rx->Matches(json);

        for each (Match ^ m in matches)
        {
            String^ item = m->Value;

            String^ id = obtenerCampo(item, "id_registro");
            String^ apellido = obtenerCampo(item, "apellido");
            String^ fecha = obtenerCampo(item, "fecha_ingreso");

            int rowIndex = dataGridView2->Rows->Add();
            dataGridView2->Rows[rowIndex]->Cells["fecha"]->Value = fecha;
            dataGridView2->Rows[rowIndex]->Cells["apellidoIngreso"]->Value = apellido;

            dataGridView2->Rows[rowIndex]->Tag = id; // opcional
        }

        dataGridView2->ClearSelection();
        dataGridView2->CurrentCell = nullptr;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error al cargar registro ingreso: " + ex->Message);
    }
}

void devoluciones::cambiarClave()
{
    String^ clave1 = textBoxClave1->Text;
    String^ clave2 = textBoxClave2->Text;

    // 1️⃣ Verificar que no estén vacías
    if (String::IsNullOrWhiteSpace(clave1) || String::IsNullOrWhiteSpace(clave2))
    {
        MessageBox::Show("Debe completar ambos campos.");
        return;
    }

    // 2️⃣ Verificar que coincidan
    if (clave1 != clave2)
    {
        MessageBox::Show("Las claves no coinciden.");
        return;
    }

    // 3️⃣ Confirmación
    System::Windows::Forms::DialogResult resultado =
        MessageBox::Show(
            "¿Está seguro que desea cambiar la clave del director?",
            "Confirmar cambio",
            MessageBoxButtons::OKCancel,
            MessageBoxIcon::Question
        );

    if (resultado == System::Windows::Forms::DialogResult::OK)
    {
        try
        {
            HttpWebRequest^ request =
                (HttpWebRequest^)WebRequest::Create("http://localhost/panol_api/update_clave_admin.php");

            request->Method = "POST";

            String^ postData = "clave=" + clave1;

            array<Byte>^ byteArray = Encoding::UTF8->GetBytes(postData);

            request->ContentType = "application/x-www-form-urlencoded";
            request->ContentLength = byteArray->Length;

            Stream^ dataStream = request->GetRequestStream();
            dataStream->Write(byteArray, 0, byteArray->Length);
            dataStream->Close();

            WebResponse^ response = request->GetResponse();
            response->Close();

            MessageBox::Show("Clave actualizada correctamente.");

            textBoxClave1->Clear();
            textBoxClave2->Clear();
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error al actualizar la clave: " + ex->Message);
        }
    }
}
