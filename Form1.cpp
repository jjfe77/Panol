#include "pch.h"
#include "Form1.h"
#include "menuPrincipal.h"

//using namespace Panol;
using namespace CppCLRWinFormsProject;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Net;
using namespace System::Net::Security;
using namespace System::Security::Cryptography::X509Certificates;
using namespace System::Collections::Specialized; // para NameValueCollection



System::Void Form1::buttonLogin_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (textBoxDni->Text->Trim() == "")
    {
        MessageBox::Show("Ingrese Usuario");
        return;
    }

    try
    {
        WebClient^ client = gcnew WebClient();
        client->Encoding = System::Text::Encoding::UTF8;

        String^ usuario = textBoxDni->Text->Trim();
        String^ url = "http://localhost/panol_api/login.php?user=" + usuario;

        String^ response = client->DownloadString(url);

        if (response == "OK") {
            menuPrincipal^ menu = gcnew menuPrincipal();
            menu->Show();
            this->Hide();
        }
        else if (response == "NO_EXISTE") {
            MessageBox::Show("Usuario no registrado");
        }
        else {
            MessageBox::Show("Error en el servidor" + response);
        }


        /*
        String^ apellido = textBoxDni->Text->Trim();
        String^ url = "http://localhost/panol_api/login.php?apellido=" + apellido;

        String^ response = client->DownloadString(url);

        if (response == "OK")
        {
            menuPrincipal^ menu = gcnew menuPrincipal();
            menu->Show();
            this->Hide();
        }
        else
        {
            MessageBox::Show("Apellido no registrado");
        }*/
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error: " + ex->Message);
    }
}




