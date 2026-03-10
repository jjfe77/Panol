#include "pch.h"
#include "herramientas.h"

using namespace Panol;
using namespace System;
using namespace System::Net;
using namespace System::Text::RegularExpressions;
using namespace System::Collections::Specialized;


// =============================
// LOAD
// =============================
System::Void herramientas::herramientas_Load(System::Object^ sender, System::EventArgs^ e)
{
CargarListado();
}


// =============================
// AUXILIAR: parsea "campo":"valor"  o  "campo":123
// =============================
String^ herramientas::ObtenerCampo(String^ jsonItem, String^ campo)
{
	// valor string
	String^ patron = "\\\"" + campo + "\\\"\\s*:\\s*\\\"([^\\\"]*)\\\"";
	Regex^ rx = gcnew Regex(patron);
	Match^ m = rx->Match(jsonItem);
	if (m->Success)
		return m->Groups[1]->Value;

	// valor numerico
	String^ patronNum = "\\\"" + campo + "\\\"\\s*:\\s*([0-9]+)";
	Regex^ rxNum = gcnew Regex(patronNum);
	Match^ mNum = rxNum->Match(jsonItem);
	if (mNum->Success)
		return mNum->Groups[1]->Value;

	return "";
}


// =============================
// CARGAR LISTADO -> dataGridViewListado
// GET /get_lista_herramientas.php
// =============================
void herramientas::CargarListado()
{
	try
	{
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;

		String^ json = client->DownloadString("http://localhost/panol_api/get_lista_herramientas.php");

		dataGridViewListado->Rows->Clear();

		Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
		auto matches = rx->Matches(json);

		if (matches->Count == 0)
		{
			MessageBox::Show("No se encontraron herramientas.");
			return;
		}

		for each(Match ^ m in matches)
		{
			String^ item = m->Value;
			String^ id = ObtenerCampo(item, "id_herramienta");
			String^ inv = ObtenerCampo(item, "numero_inventario");
			String^ nom = ObtenerCampo(item, "nombre");
			String^ tipo = ObtenerCampo(item, "tipo");
			String^ cant = ObtenerCampo(item, "cantidad");
			String^ est = ObtenerCampo(item, "estado");
			String^ desc = ObtenerCampo(item, "descripcion");

			int rowIdx = dataGridViewListado->Rows->Add(inv, nom, tipo, cant, est, desc);

			// Guardamos el id en el Tag para usarlo en edicion
			dataGridViewListado->Rows[rowIdx]->Tag = id;
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error al cargar herramientas: " + ex->Message);
	}
}


// =============================
// AUXILIAR: envia POST con los datos de una fila editada
// POST /editar_herramientas.php
// =============================
void herramientas::GuardarEdicion(int idHerramienta, DataGridViewRow^ row)
{
	try
	{
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;

		NameValueCollection^ datos = gcnew NameValueCollection();
		datos->Add("id_herramienta", idHerramienta.ToString());
		datos->Add("numero_inventario", row->Cells["numeroInventario"]->Value != nullptr ? row->Cells["numeroInventario"]->Value->ToString() : "");
		datos->Add("nombre", row->Cells["nombreHerramienta"]->Value != nullptr ? row->Cells["nombreHerramienta"]->Value->ToString() : "");
		datos->Add("tipo", row->Cells["tipoHerramienta"]->Value != nullptr ? row->Cells["tipoHerramienta"]->Value->ToString() : "");
		datos->Add("cantidad", row->Cells["cantidad"]->Value != nullptr ? row->Cells["cantidad"]->Value->ToString() : "0");
		datos->Add("estado", row->Cells["estadoHerramienta"]->Value != nullptr ? row->Cells["estadoHerramienta"]->Value->ToString() : "");
		datos->Add("descripcion", row->Cells["descripcion"]->Value != nullptr ? row->Cells["descripcion"]->Value->ToString() : "");

		array<unsigned char>^ respBytes =
			client->UploadValues("http://localhost/panol_api/editar_herramientas.php", "POST", datos);

		String^ resp = System::Text::Encoding::UTF8->GetString(respBytes);
		String^ success = ObtenerCampo(resp, "success");
		String^ message = ObtenerCampo(resp, "message");

		if (success == "true")
			MessageBox::Show("Herramienta actualizada correctamente.");
		else
			MessageBox::Show("Error al actualizar: " + message);
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error de conexion: " + ex->Message);
	}
}


// =============================
// BOTON: Listado de Herramientas -> recarga el grid
// =============================
System::Void herramientas::buttonListar_Click(System::Object^ sender, System::EventArgs^ e)
{
	CargarListado();
}


// =============================
// BOTON: Editar -> habilita edicion en la fila seleccionada
// =============================
System::Void herramientas::buttonEditar_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridViewListado->SelectedRows->Count == 0)
	{
		MessageBox::Show("Seleccione una herramienta del listado para editar.");
		return;
	}

	// Habilitar edicion solo en columnas editables
	dataGridViewListado->Columns["nombreHerramienta"]->ReadOnly = false;
	dataGridViewListado->Columns["tipoHerramienta"]->ReadOnly = false;
	dataGridViewListado->Columns["estadoHerramienta"]->ReadOnly = false;
	dataGridViewListado->Columns["descripcion"]->ReadOnly = false;

	dataGridViewListado->EditMode =
		System::Windows::Forms::DataGridViewEditMode::EditOnKeystrokeOrF2;

	dataGridViewListado->CurrentCell =
		dataGridViewListado->SelectedRows[0]->Cells["nombreHerramienta"];
	dataGridViewListado->BeginEdit(true);

	MessageBox::Show("Modifique los campos y presione 'Guardar' para confirmar.",
		"Modo edicion", MessageBoxButtons::OK, MessageBoxIcon::Information);
}


// =============================
// BOTON: Guardar -> POST sobre la fila seleccionada
// =============================
System::Void herramientas::buttonGuardar_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridViewListado->SelectedRows->Count == 0)
	{
		MessageBox::Show("Seleccione una herramienta del listado para guardar cambios.");
		return;
	}

	// Confirmar edicion pendiente en la celda activa
	dataGridViewListado->EndEdit();

	DataGridViewRow^ row = dataGridViewListado->SelectedRows[0];

	if (row->Tag == nullptr)
	{
		MessageBox::Show("La fila seleccionada no tiene ID valido.");
		return;
	}

	int idHerramienta = Int32::Parse(row->Tag->ToString());
	GuardarEdicion(idHerramienta, row);

	// Volver a modo solo lectura y recargar
	dataGridViewListado->Columns["nombreHerramienta"]->ReadOnly = true;
	dataGridViewListado->Columns["tipoHerramienta"]->ReadOnly = true;
	dataGridViewListado->Columns["estadoHerramienta"]->ReadOnly = true;
	dataGridViewListado->Columns["descripcion"]->ReadOnly = true;

	dataGridViewListado->EditMode =
		System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;

	CargarListado();
}


// =============================
// BOTON: Guardar Alta Herramientas -> POST por cada fila de dataGridViewAltas
// POST /post_herramientas.php
// =============================
System::Void herramientas::buttonAltaHerramienta_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool huboCambios = false;
	bool huboErrores = false;

	for each(DataGridViewRow ^ row in dataGridViewAltas->Rows)
	{
		if (row->IsNewRow) continue;

		// Validar que al menos el nombre este cargado
		Object^ nombreVal = row->Cells["nombreAlta"]->Value;
		if (nombreVal == nullptr || nombreVal->ToString()->Trim() == "")
			continue;

		// Validar stock
		Object^ stockVal = row->Cells["stockAlta"]->Value;
		int stock = 0;
		if (stockVal != nullptr && stockVal->ToString()->Trim() != "")
		{
			if (!Int32::TryParse(stockVal->ToString()->Trim(), stock) || stock < 0)
			{
				MessageBox::Show("Stock invalido en la fila " + (row->Index + 1).ToString() +
					".\nIngrese un numero entero mayor o igual a 0.");
				huboErrores = true;
				continue;
			}
		}

		try
		{
			WebClient^ client = gcnew WebClient();
			client->Encoding = System::Text::Encoding::UTF8;

			NameValueCollection^ datos = gcnew NameValueCollection();
			datos->Add("numero_inventario", row->Cells["inventarioAlta"]->Value != nullptr ? row->Cells["inventarioAlta"]->Value->ToString() : "");
			datos->Add("nombre", row->Cells["nombreAlta"]->Value != nullptr ? row->Cells["nombreAlta"]->Value->ToString() : "");
			datos->Add("tipo", row->Cells["tipoAlta"]->Value != nullptr ? row->Cells["tipoAlta"]->Value->ToString() : "");
			datos->Add("cantidad", stock.ToString());
			datos->Add("estado", row->Cells["estadoAlta"]->Value != nullptr ? row->Cells["estadoAlta"]->Value->ToString() : "");
			datos->Add("descripcion", row->Cells["descripcionAlta"]->Value != nullptr ? row->Cells["descripcionAlta"]->Value->ToString() : "");

			array<unsigned char>^ respBytes =
				client->UploadValues("http://localhost/panol_api/post_herramientas.php", "POST", datos);

			String^ resp = System::Text::Encoding::UTF8->GetString(respBytes);
			String^ success = ObtenerCampo(resp, "success");
			String^ message = ObtenerCampo(resp, "message");

			if (success == "true")
				huboCambios = true;
			else
			{
				MessageBox::Show("Error en fila " + (row->Index + 1).ToString() + ": " + message);
				huboErrores = true;
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error de conexion: " + ex->Message);
			huboErrores = true;
		}
	}

	if (!huboCambios && !huboErrores)
	{
		MessageBox::Show("No se ingreso ninguna herramienta.\n"
			"Complete al menos el campo 'Nombre' en el grid de altas.");
		return;
	}

	if (huboCambios)
	{
		MessageBox::Show("Alta guardada correctamente.");
		dataGridViewAltas->Rows->Clear();
		CargarListado();
	}
}