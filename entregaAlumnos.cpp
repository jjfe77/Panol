#include "pch.h"
#include "entregaAlumnos.h"

using namespace Panol;
using namespace System;
using namespace System::Net;
using namespace System::Text::RegularExpressions;
using namespace System::Data;

// =============================
// LOAD
// =============================
System::Void entregaAlumnos::entregaAlumnos_Load(System::Object^ sender, System::EventArgs^ e)
{
	CargarAlumnos();
	CargarMaterialesDisponibles();
}

// =============================
// AUXILIAR: parsea "campo":"valor" o "campo":123
// =============================
String^ entregaAlumnos::obtenerCampo(String^ jsonItem, String^ campo)
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
// AUXILIAR: obtiene el id_alumno seleccionado en el comboBox
// Cuando el DataSource es un DataTable, SelectedValue puede devolver
// DataRowView en vez del valor numerico — esta funcion lo maneja correctamente
// =============================
int entregaAlumnos::ObtenerIdAlumnoSeleccionado()
{
	if (comboBoxAlumno->SelectedItem == nullptr)
		return 0;

	DataRowView^ drv = dynamic_cast<DataRowView^>(comboBoxAlumno->SelectedItem);
	if (drv != nullptr)
	{
		Object^ val = drv["id_alumno"];
		if (val != nullptr)
			return Int32::Parse(val->ToString());
	}

	return 0;
}

// =============================
// CARGAR ALUMNOS EN COMBOBOX
// GET /get_alumnos.php
// [{id_alumno, alumno, dni, curso}, ...]
// =============================
void entregaAlumnos::CargarAlumnos()
{
	try
	{
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;

		String^ json = client->DownloadString("http://localhost/panol_api/get_alumnos.php");

		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("id_alumno", int::typeid);
		dt->Columns->Add("alumno", String::typeid);

		Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
		auto matches = rx->Matches(json);

		if (matches->Count == 0)
		{
			MessageBox::Show("No se encontraron alumnos.");
			return;
		}

		for each (Match ^ m in matches)
		{
			String^ item = m->Value;
			String^ idStr = obtenerCampo(item, "id_alumno");
			String^ nombre = obtenerCampo(item, "alumno");

			if (idStr != "" && nombre != "")
				dt->Rows->Add(Int32::Parse(idStr), nombre);
		}

		comboBoxAlumno->DisplayMember = "alumno";
		comboBoxAlumno->ValueMember = "id_alumno";
		comboBoxAlumno->DataSource = dt;
		comboBoxAlumno->SelectedIndex = -1;
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error al cargar alumnos: " + ex->Message);
	}
}

// =============================
// BUSCAR CURSO DEL ALUMNO
// GET /get_curso_alumno.php?id_alumno=X
// {"curso":"2° A - Grupo 1"}
// =============================
void entregaAlumnos::BuscarCursoAlumno(int idAlumno)
{
	try
	{
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;

		String^ url = "http://localhost/panol_api/get_curso_alumno.php?id_alumno=" + idAlumno.ToString();
		String^ json = client->DownloadString(url);

		String^ curso = obtenerCampo(json, "curso");
		textBoxCurso->Text = (curso == "") ? "No encontrado" : curso;
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error al buscar curso: " + ex->Message);
	}
}

// =============================
// CARGAR HISTORIAL DE RETIROS DEL ALUMNO -> dataGridView1 (izquierdo, solo lectura)
// GET /get_materiales_tp_alumnos.php?id_alumno=X
// [{fecha, cantidad, material}, ...]
// =============================
void entregaAlumnos::CargarMaterialRetirado(int idAlumno)
{
	try
	{
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;

		String^ url = "http://localhost/panol_api/get_materiales_tp_alumnos.php?id_alumno=" + idAlumno.ToString();
		String^ json = client->DownloadString(url);

		dataGridView1->Rows->Clear();

		Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
		auto matches = rx->Matches(json);

		for each (Match ^ m in matches)
		{
			String^ item = m->Value;
			String^ fec = obtenerCampo(item, "fecha");
			String^ cant = obtenerCampo(item, "cantidad");
			String^ mat = obtenerCampo(item, "material");

			dataGridView1->Rows->Add(fec, cant, mat);
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error al cargar historial: " + ex->Message);
	}
}

// =============================
// CARGAR STOCK DISPONIBLE -> dataGridView2 (derecho)
// El usuario edita la columna "cantidadRetirar"
// El Tag de cada fila guarda "id_material_tp|stockActual"
// GET /get_materiales_tp.php
// [{id_material_tp, nombre, cantidad, ...}, ...]
// =============================
void entregaAlumnos::CargarMaterialesDisponibles()
{
	try
	{
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;

		String^ json = client->DownloadString("http://localhost/panol_api/get_materiales_tp.php");

		dataGridView2->Rows->Clear();

		Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
		auto matches = rx->Matches(json);

		for each (Match ^ m in matches)
		{
			String^ item = m->Value;
			String^ idMat = obtenerCampo(item, "id_material_tp");
			String^ nombre = obtenerCampo(item, "nombre");
			String^ stockStr = obtenerCampo(item, "cantidad");

			int rowIdx = dataGridView2->Rows->Add("", "", nombre + "  [Stock: " + stockStr + "]");

			// Tag: id|stock para recuperarlo al guardar
			dataGridView2->Rows[rowIdx]->Tag = idMat + "|" + stockStr;
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error al cargar materiales: " + ex->Message);
	}
}

// =============================
// EVENTO: COMBOBOX CAMBIA
// =============================
System::Void entregaAlumnos::comboBoxAlumno_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	textBoxCurso->Text = "";
	dataGridView1->Rows->Clear();
}

// =============================
// BOTON BUSCAR
// =============================
System::Void entregaAlumnos::buttonBuscar_Click(System::Object^ sender, System::EventArgs^ e)
{
	int idAlumno = ObtenerIdAlumnoSeleccionado();

	if (idAlumno == 0)
	{
		MessageBox::Show("Seleccione un alumno primero.");
		return;
	}

	BuscarCursoAlumno(idAlumno);
	CargarMaterialRetirado(idAlumno);
}

// =============================
// BOTON GUARDAR RETIRO
// =============================
System::Void entregaAlumnos::buttonRetiro_Click(System::Object^ sender, System::EventArgs^ e)
{
	int idAlumno = ObtenerIdAlumnoSeleccionado();

	if (idAlumno == 0)
	{
		MessageBox::Show("Seleccione un alumno primero.");
		return;
	}

	bool huboCambios = false;
	bool huboErrores = false;

	for each (DataGridViewRow ^ row in dataGridView2->Rows)
	{
		if (row->IsNewRow) continue;

		// Leer cantidad ingresada por el usuario
		Object^ cellVal = row->Cells["cantidadRetirar"]->Value;
		if (cellVal == nullptr || cellVal->ToString()->Trim() == "")
			continue;   // fila sin cantidad: la salteamos

		String^ cantStr = cellVal->ToString()->Trim();
		int cantRetirar = 0;

		if (!Int32::TryParse(cantStr, cantRetirar) || cantRetirar <= 0)
		{
			MessageBox::Show("Cantidad invalida en la fila " + (row->Index + 1).ToString() +
				".\nIngrese un numero entero mayor a 0.");
			huboErrores = true;
			continue;
		}

		// Recuperar id y stock desde Tag
		if (row->Tag == nullptr) continue;
		array<String^>^ parts = row->Tag->ToString()->Split('|');
		if (parts->Length < 2) continue;

		String^ idMaterialStr = parts[0];
		int     stockDisponible = Int32::Parse(parts[1]);

		// Validacion de stock lado cliente
		if (cantRetirar > stockDisponible)
		{
			MessageBox::Show("Stock insuficiente para la fila " + (row->Index + 1).ToString() +
				".\nStock actual: " + stockDisponible.ToString());
			huboErrores = true;
			continue;
		}

		// Llamar a la API
		try
		{
			WebClient^ client = gcnew WebClient();
			client->Encoding = System::Text::Encoding::UTF8;

			System::Collections::Specialized::NameValueCollection^ datos =
				gcnew System::Collections::Specialized::NameValueCollection();

			datos->Add("id_alumno", idAlumno.ToString());
			datos->Add("id_material_tp", idMaterialStr);
			datos->Add("cantidad", cantRetirar.ToString());
			datos->Add("observaciones", "");

			array<unsigned char>^ respBytes =
				client->UploadValues("http://localhost/panol_api/guardar_entrega.php", "POST", datos);

			String^ resp = System::Text::Encoding::UTF8->GetString(respBytes);
			String^ success = obtenerCampo(resp, "success");
			String^ message = obtenerCampo(resp, "message");

			if (success == "true")
				huboCambios = true;
			else
			{
				MessageBox::Show("Error al guardar fila " + (row->Index + 1).ToString() + ": " + message);
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
		MessageBox::Show("No se ingreso ninguna cantidad.\n"
			"Escriba la cantidad en la columna 'Cantidad' del material que desea retirar.");
		return;
	}

	if (huboCambios)
		MessageBox::Show("Retiro guardado correctamente.");

	// Recargar ambos grids
	CargarMaterialRetirado(idAlumno);
	CargarMaterialesDisponibles();
}
