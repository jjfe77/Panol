#include "pch.h"
#include "presupuestos.h"

using namespace Panol;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Net;
using namespace System::Collections::Specialized;
using namespace System::Text::RegularExpressions;

// --- 1. FUNCIONES AUXILIARES ---
String^ Panol::presupuestos::obtenerCampo(String^ jsonItem, String^ campo) {
	String^ patron = "\\\"" + campo + "\\\"\\s*:\\s*\\\"([^\\\"]*)\\\"";
	Regex^ rx = gcnew Regex(patron);
	Match^ m = rx->Match(jsonItem);
	if (m->Success) return System::Text::RegularExpressions::Regex::Unescape(m->Groups[1]->Value);
	return "";
}

String^ Panol::presupuestos::obtenerCampoNum(String^ jsonItem, String^ campo) {
	String^ patron = "\\\"" + campo + "\\\"\\s*:\\s*\\\"?([^\\\",\\}]*)\\\"?";
	Regex^ rx = gcnew Regex(patron);
	Match^ m = rx->Match(jsonItem);
	return m->Success ? m->Groups[1]->Value : "0";
}

// --- 2. CARGAS INICIALES ---
void Panol::presupuestos::cargarProveedores() {
	try {
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;
		String^ json = client->DownloadString("http://localhost/panol_api/get_proveedores.php");
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("id_proveedor", Int32::typeid);
		dt->Columns->Add("nombre_proveedor", String::typeid);
		Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
		for each (Match ^ m in rx->Matches(json)) {
			dt->Rows->Add(Int32::Parse(obtenerCampoNum(m->Value, "id_proveedor")), obtenerCampo(m->Value, "nombre_proveedor"));
		}
		comboBoxProv1->DataSource = dt->Copy(); comboBoxProv1->DisplayMember = "nombre_proveedor"; comboBoxProv1->ValueMember = "id_proveedor"; comboBoxProv1->SelectedIndex = -1;
		comboBoxProv2->DataSource = dt->Copy(); comboBoxProv2->DisplayMember = "nombre_proveedor"; comboBoxProv2->ValueMember = "id_proveedor"; comboBoxProv2->SelectedIndex = -1;
		comboBoxProv3->DataSource = dt->Copy(); comboBoxProv3->DisplayMember = "nombre_proveedor"; comboBoxProv3->ValueMember = "id_proveedor"; comboBoxProv3->SelectedIndex = -1;
	}
	catch (...) {}
}

void Panol::presupuestos::cargarCargasAnteriores() {
	try {
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;
		String^ json = client->DownloadString("http://localhost/panol_api/get_lista_presupuestos.php");
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("id_presupuesto", Int32::typeid);
		dt->Columns->Add("nombre_listado", String::typeid);
		Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
		for each (Match ^ m in rx->Matches(json)) {
			dt->Rows->Add(Int32::Parse(obtenerCampoNum(m->Value, "id_presupuesto")), obtenerCampo(m->Value, "nombre_listado"));
		}
		cmbCargasAnteriores->DataSource = dt; cmbCargasAnteriores->DisplayMember = "nombre_listado"; cmbCargasAnteriores->ValueMember = "id_presupuesto"; cmbCargasAnteriores->SelectedIndex = -1;
	}
	catch (...) {}
}

System::Void Panol::presupuestos::presupuestos_Load(System::Object^ sender, System::EventArgs^ e) {
	cargarProveedores();
	cargarCargasAnteriores();
}

// --- 3. GUARDAR (VERSIÓN CORREGIDA SIN LAMBDAS) ---
System::Void Panol::presupuestos::btnGuardarBorrador_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(txtNombreCarga->Text)) { MessageBox::Show("Asigne un nombre a la carga."); return; }
	if (comboBoxProv1->SelectedIndex == -1 || comboBoxProv2->SelectedIndex == -1 || comboBoxProv3->SelectedIndex == -1) { MessageBox::Show("Seleccione 3 proveedores."); return; }

	dataGridViewPresupuestos->EndEdit();
	try {
		String^ json = "{ \"id_presupuesto\":" + idPresupuestoActual + ", \"nombre_listado\":\"" + txtNombreCarga->Text + "\",";
		json += "\"id_prov1\":" + comboBoxProv1->SelectedValue + ", \"id_prov2\":" + comboBoxProv2->SelectedValue + ", \"id_prov3\":" + comboBoxProv3->SelectedValue + ", \"materiales\": [";

		bool primero = true;
		for (int i = 0; i < dataGridViewPresupuestos->Rows->Count; i++) {
			if (dataGridViewPresupuestos->Rows->default[i]->IsNewRow) continue;
			if (!primero) json += ",";

			// Extracción celda por celda sin lambdas
			String^ el = (dataGridViewPresupuestos->Rows->default[i]->Cells->default[0]->Value != nullptr) ? dataGridViewPresupuestos->Rows->default[i]->Cells->default[0]->Value->ToString() : "";
			String^ ca = (dataGridViewPresupuestos->Rows->default[i]->Cells->default[1]->Value != nullptr) ? dataGridViewPresupuestos->Rows->default[i]->Cells->default[1]->Value->ToString() : "0";
			String^ p1 = (dataGridViewPresupuestos->Rows->default[i]->Cells->default[2]->Value != nullptr) ? dataGridViewPresupuestos->Rows->default[i]->Cells->default[2]->Value->ToString()->Replace(",", ".") : "0";
			String^ p2 = (dataGridViewPresupuestos->Rows->default[i]->Cells->default[3]->Value != nullptr) ? dataGridViewPresupuestos->Rows->default[i]->Cells->default[3]->Value->ToString()->Replace(",", ".") : "0";
			String^ p3 = (dataGridViewPresupuestos->Rows->default[i]->Cells->default[4]->Value != nullptr) ? dataGridViewPresupuestos->Rows->default[i]->Cells->default[4]->Value->ToString()->Replace(",", ".") : "0";
			String^ ob = (dataGridViewPresupuestos->Rows->default[i]->Cells->default[5]->Value != nullptr) ? dataGridViewPresupuestos->Rows->default[i]->Cells->default[5]->Value->ToString() : "";

			json += "{\"elemento\":\"" + el + "\", \"cantidad\":" + ca + ", \"p1\":" + p1 + ", \"p2\":" + p2 + ", \"p3\":" + p3 + ", \"obs\":\"" + ob + "\"}";
			primero = false;
		}
		json += "]}";

		WebClient^ client = gcnew WebClient();
		client->Headers->Add("Content-Type", "application/json");
		String^ res = client->UploadString("http://localhost/panol_api/save_presupuesto_completo.php", "POST", json);
		if (obtenerCampo(res, "success") == "true") {
			idPresupuestoActual = Int32::Parse(obtenerCampoNum(res, "id"));
			MessageBox::Show("Guardado con éxito.");
			cargarCargasAnteriores();
		}
	}
	catch (Exception^ ex) { MessageBox::Show("Error: " + ex->Message); }
}

// --- 4. RECUPERAR ---
/* 
System::Void Panol::presupuestos::cmbCargasAnteriores_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (cmbCargasAnteriores->SelectedIndex == -1 || cmbCargasAnteriores->SelectedValue == nullptr) return;
	try {
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;
		String^ json = client->DownloadString("http://localhost/panol_api/get_detalle_presupuesto.php?id=" + cmbCargasAnteriores->SelectedValue->ToString());

		dataGridViewPresupuestos->Rows->Clear();
		Regex^ rxCab = gcnew Regex("\\\"cabecera\\\"\\s*:\\s*(\\{[^\\}]+\\})");
		Match^ mCab = rxCab->Match(json);
		if (mCab->Success) {
			String^ c = mCab->Groups[1]->Value;
			idPresupuestoActual = Int32::Parse(obtenerCampoNum(c, "id_presupuesto"));
			txtNombreCarga->Text = obtenerCampo(c, "nombre_listado");
			comboBoxProv1->SelectedValue = Int32::Parse(obtenerCampoNum(c, "id_prov1"));
			comboBoxProv2->SelectedValue = Int32::Parse(obtenerCampoNum(c, "id_prov2"));
			comboBoxProv3->SelectedValue = Int32::Parse(obtenerCampoNum(c, "id_prov3"));
		}
		Regex^ rxMat = gcnew Regex("\\{[^\\}]+\\}");
		auto matches = rxMat->Matches(json, mCab->Index + mCab->Length);
		for each (Match ^ m in matches) {
			dataGridViewPresupuestos->Rows->Add(obtenerCampo(m->Value, "elemento"), obtenerCampoNum(m->Value, "cantidad"), obtenerCampoNum(m->Value, "precio_p1"), obtenerCampoNum(m->Value, "precio_p2"), obtenerCampoNum(m->Value, "precio_p3"), obtenerCampo(m->Value, "observaciones"));
		}
	}
	catch (...) {}
}
*/

System::Void Panol::presupuestos::cmbCargasAnteriores_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	// 1. Validar que haya algo seleccionado
	if (cmbCargasAnteriores->SelectedIndex == -1 || cmbCargasAnteriores->SelectedValue == nullptr) return;

	try {
		flagCargando = true; // Silenciamos los validadores de proveedores

		// Limpiamos todo antes de cargar (Llamando a tu función de limpieza)
		btnNuevoPresupuesto_Click(nullptr, nullptr);

		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;
		String^ id = cmbCargasAnteriores->SelectedValue->ToString();
		String^ url = "http://localhost/panol_api/get_detalle_presupuesto.php?id=" + id;
		String^ json = client->DownloadString(url);

		// --- EXTRACCIÓN DE CABECERA ---
		// Esta es la parte que te faltaba o daba error:
		Regex^ rxCab = gcnew Regex("\\\"cabecera\\\"\\s*:\\s*(\\{[^\\}]+\\})");
		Match^ mCab = rxCab->Match(json); // AQUÍ SE DECLARA mCab

		if (mCab->Success) {
			String^ datosCab = mCab->Groups[1]->Value;

			idPresupuestoActual = Int32::Parse(obtenerCampoNum(datosCab, "id_presupuesto"));
			txtNombreCarga->Text = obtenerCampo(datosCab, "nombre_listado");

			// Asignamos proveedores (el flag evita que salten carteles de error)
			comboBoxProv1->SelectedValue = Int32::Parse(obtenerCampoNum(datosCab, "id_prov1"));
			comboBoxProv2->SelectedValue = Int32::Parse(obtenerCampoNum(datosCab, "id_prov2"));
			comboBoxProv3->SelectedValue = Int32::Parse(obtenerCampoNum(datosCab, "id_prov3"));
		}

		// --- EXTRACCIÓN DE MATERIALES ---
		dataGridViewPresupuestos->Rows->Clear();
		Regex^ rxMat = gcnew Regex("\\{[^\\}]+\\}");
		// Buscamos materiales saltándonos la parte de la cabecera
		auto matches = rxMat->Matches(json, mCab->Index + mCab->Length);

		for each (Match ^ m in matches) {
			String^ item = m->Value;
			String^ elem = obtenerCampo(item, "elemento");
			String^ cant = obtenerCampoNum(item, "cantidad");
			String^ p1 = obtenerCampoNum(item, "precio_p1");
			String^ p2 = obtenerCampoNum(item, "precio_p2");
			String^ p3 = obtenerCampoNum(item, "precio_p3");
			String^ obs = obtenerCampo(item, "observaciones");

			if (!String::IsNullOrEmpty(elem)) {
				dataGridViewPresupuestos->Rows->Add(elem, cant, p1, p2, p3, obs);
			}
		}

		flagCargando = false; // Volvemos a activar los validadores
		dataGridViewPresupuestos->ClearSelection();

	}
	catch (Exception^ ex) {
		flagCargando = false;
		MessageBox::Show("Error al recuperar presupuesto: " + ex->Message);
	}
}


// --- 5. OTROS EVENTOS ---
System::Void Panol::presupuestos::btnNuevoPresupuesto_Click(System::Object^ sender, System::EventArgs^ e) {
	idPresupuestoActual = 0; txtNombreCarga->Text = ""; dataGridViewPresupuestos->Rows->Clear(); dataGridViewCompras->Rows->Clear(); textBoxTotal->Text = "";
	comboBoxProv1->SelectedIndex = -1; comboBoxProv2->SelectedIndex = -1; comboBoxProv3->SelectedIndex = -1;
}

System::Void Panol::presupuestos::buttonNuevoProovedor_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ n = textBoxProovedorNuevo->Text->Trim();
	if (String::IsNullOrWhiteSpace(n)) return;
	if (MessageBox::Show("¿Registrar a " + n + "?", "Confirmar", MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::Cancel) return;
	try {
		WebClient^ client = gcnew WebClient();
		NameValueCollection^ p = gcnew NameValueCollection(); p->Add("nombre", n);
		client->UploadValues("http://localhost/panol_api/save_proveedor.php", "POST", p);
		textBoxProovedorNuevo->Text = ""; cargarProveedores();
	}
	catch (...) {}
}

System::Void Panol::presupuestos::validarProveedoresDiferentes(System::Object^ sender, System::EventArgs^ e) {
	if (flagCargando) return;
	ComboBox^ c = safe_cast<ComboBox^>(sender);
	if (c->SelectedIndex == -1) return;
	Object^ v1 = comboBoxProv1->SelectedValue; Object^ v2 = comboBoxProv2->SelectedValue; Object^ v3 = comboBoxProv3->SelectedValue;
	bool d = false;
	if (v1 && v2 && v1->Equals(v2)) d = true;
	if (v1 && v3 && v1->Equals(v3)) d = true;
	if (v2 && v3 && v2->Equals(v3)) d = true;
	if (d) { MessageBox::Show("Proveedor duplicado."); c->SelectedIndex = -1; }
}

System::Void Panol::presupuestos::buttonGenerarCompra_Click(System::Object^ sender, System::EventArgs^ e) {
	if (idPresupuestoActual == 0) {
		MessageBox::Show("Primero debe guardar el presupuesto (Avance) antes de generar la compra.", "Aviso");
		return;
	}

	dataGridViewPresupuestos->EndEdit();
	dataGridViewCompras->Rows->Clear();
	double totalGeneral = 0;

	try {
		// --- 1. PROCESAR COMPARATIVA Y LLENAR GRID DE COMPRAS ---
		for (int i = 0; i < dataGridViewPresupuestos->Rows->Count; i++) {
			if (dataGridViewPresupuestos->Rows->default[i]->IsNewRow) continue;

			// Extraer Nombre
			Object^ objElem = dataGridViewPresupuestos->Rows->default[i]->Cells->default["elemento"]->Value;
			if (objElem == nullptr) continue;
			String^ elem = objElem->ToString();

			// Extraer Cantidad
			Object^ objCant = dataGridViewPresupuestos->Rows->default[i]->Cells->default["cantidadComprar"]->Value;
			double cant = 0;
			if (objCant != nullptr && !String::IsNullOrWhiteSpace(objCant->ToString())) {
				cant = Convert::ToDouble(objCant->ToString()->Replace(".", ","));
			}
			if (cant <= 0) cant = 1; // Evitar división por cero

			// Extraer Precios (P1, P2, P3) - Forma manual sin lambdas
			double p1 = 0, p2 = 0, p3 = 0;

			Object^ v1 = dataGridViewPresupuestos->Rows->default[i]->Cells->default["precioP1"]->Value;
			if (v1 != nullptr && !String::IsNullOrWhiteSpace(v1->ToString())) p1 = Convert::ToDouble(v1->ToString()->Replace(".", ","));

			Object^ v2 = dataGridViewPresupuestos->Rows->default[i]->Cells->default["precioP2"]->Value;
			if (v2 != nullptr && !String::IsNullOrWhiteSpace(v2->ToString())) p2 = Convert::ToDouble(v2->ToString()->Replace(".", ","));

			Object^ v3 = dataGridViewPresupuestos->Rows->default[i]->Cells->default["precioP3"]->Value;
			if (v3 != nullptr && !String::IsNullOrWhiteSpace(v3->ToString())) p3 = Convert::ToDouble(v3->ToString()->Replace(".", ","));

			// Determinar el proveedor ganador (el precio menor que sea > 0)
			double precioGanadorTotal = 0;
			String^ provGanador = "";

			if (p1 > 0) { precioGanadorTotal = p1; provGanador = comboBoxProv1->Text; }

			if (p2 > 0) {
				if (precioGanadorTotal == 0 || p2 < precioGanadorTotal) {
					precioGanadorTotal = p2;
					provGanador = comboBoxProv2->Text;
				}
			}
			if (p3 > 0) {
				if (precioGanadorTotal == 0 || p3 < precioGanadorTotal) {
					precioGanadorTotal = p3;
					provGanador = comboBoxProv3->Text;
				}
			}

			// Si hay un ganador, calcular y agregar
			if (precioGanadorTotal > 0) {
				double precioUnitario = precioGanadorTotal / cant; // El guardado es el total, así que dividimos
				totalGeneral += precioGanadorTotal;

				dataGridViewCompras->Rows->Add(elem, cant, precioUnitario.ToString("F2"), precioGanadorTotal.ToString("F2"), provGanador);
			}
		}

		// --- 2. ORDENAR POR PROVEEDOR (Índice 4) ---
		if (dataGridViewCompras->Rows->Count > 0) {
			dataGridViewCompras->Sort(dataGridViewCompras->Columns->default[4], System::ComponentModel::ListSortDirection::Ascending);
		}

		textBoxTotal->Text = totalGeneral.ToString("N2");

		// --- 3. GUARDAR RESULTADO EN BDD ---
		if (dataGridViewCompras->Rows->Count == 0) return;

		String^ json = "{ \"id_presupuesto\":" + idPresupuestoActual + ", \"lista\": [";
		bool primero = true;

		for (int j = 0; j < dataGridViewCompras->Rows->Count; j++) {
			if (dataGridViewCompras->Rows->default[j]->IsNewRow) continue;

			if (!primero) json += ",";

			// Extraer datos de la fila del grid de compras (ya ordenado)
			String^ e_elem = dataGridViewCompras->Rows->default[j]->Cells->default[0]->Value->ToString();
			String^ e_cant = dataGridViewCompras->Rows->default[j]->Cells->default[1]->Value->ToString();
			String^ e_puni = dataGridViewCompras->Rows->default[j]->Cells->default[2]->Value->ToString()->Replace(",", ".");
			String^ e_ptot = dataGridViewCompras->Rows->default[j]->Cells->default[3]->Value->ToString()->Replace(",", ".");
			String^ e_prov = dataGridViewCompras->Rows->default[j]->Cells->default[4]->Value->ToString();

			json += "{\"elem\":\"" + e_elem + "\", \"cant\":" + e_cant + ", \"p_uni\":" + e_puni + ", \"p_tot\":" + e_ptot + ", \"prov\":\"" + e_prov + "\"}";
			primero = false;
		}
		json += "]}";

		WebClient^ client = gcnew WebClient();
		client->Headers->Add("Content-Type", "application/json");
		client->Encoding = System::Text::Encoding::UTF8;
		client->UploadString("http://localhost/panol_api/save_compra_final.php", "POST", json);

		MessageBox::Show("Listado de compras generado y guardado exitosamente.", "Éxito");
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error en la operación: " + ex->Message);
	}

	MessageBox::Show("Listado generado y guardado correctamente.", "Éxito");

	// --- ABRIR EL REPORTE AUTOMÁTICAMENTE ---
	String^ urlReporte = "http://localhost/panol_api/reporte_compra.php?id=" + idPresupuestoActual;

	// Esta línea abre el navegador predeterminado con la URL del reporte
	System::Diagnostics::Process::Start(gcnew System::Diagnostics::ProcessStartInfo(urlReporte));

}