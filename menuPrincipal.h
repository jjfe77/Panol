#pragma once
#include "prestamos.h"
#include "entregaAlumnos.h"
#include "materialTP.h"	
#include "herramientas.h"
#include "consumibles.h"
#include "presupuestos.h"
#include "devoluciones.h"
#include "HistorialPrestamos.h"
#include "ClaveDialog.h"

namespace Panol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de menuPrincipal
	/// </summary>
	public ref class menuPrincipal : public System::Windows::Forms::Form
	{
	public:
		menuPrincipal(void)
		{
			InitializeComponent();

			//
			//TODO: agregar código de constructor aquí
			//
		}


	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~menuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonPrestamos;
	protected:
	private: System::Windows::Forms::Button^ buttonEntregaAlumnos;
	private: System::Windows::Forms::Button^ buttonMaterialTp;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ buttonConsumibles;
	private: System::Windows::Forms::Panel^ panelMenu;
	private: System::Windows::Forms::Button^ buttonPresupuestos;
	private: System::Windows::Forms::Button^ buttonDevoluciones;




	private: System::Windows::Forms::Button^ buttonHistorial;
	private: System::Windows::Forms::Button^ buttonSalir;
	private: System::Windows::Forms::Panel^ panelContenedor;
	//private: HistorialPrestamos^ formHistorialPrestamos;


	private:

		void AbrirFormulario(System::Windows::Forms::Form^ formulario)
		{
			// Si hay uno activo, lo ocultamos (NO lo borramos)
			if (formularioActivo != nullptr)
				formularioActivo->Hide();

			formularioActivo = formulario;

			// Solo lo agregamos al panel si todavía no está agregado
			if (!panelContenedor->Controls->Contains(formulario))
			{
				formulario->TopLevel = false;
				formulario->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
				formulario->Dock = DockStyle::Fill;
				panelContenedor->Controls->Add(formulario);
			}

			formulario->Show();
			formulario->BringToFront();
		}

		prestamos^ formPrestamos = nullptr;	
		entregaAlumnos^ formEntregaAlumnos = nullptr;
		materialTP^ formMaterialTP = nullptr;
		herramientas^ formHerramientas = nullptr;
		consumibles^ formConsumibles = nullptr;
		presupuestos^ formPresupuestos = nullptr;
		devoluciones^ formDevoluciones = nullptr;
		HistorialPrestamos^ formHistorial = nullptr;
		Form^ formularioActivo = nullptr;


		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonPrestamos = (gcnew System::Windows::Forms::Button());
			this->buttonEntregaAlumnos = (gcnew System::Windows::Forms::Button());
			this->buttonMaterialTp = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->buttonConsumibles = (gcnew System::Windows::Forms::Button());
			this->panelMenu = (gcnew System::Windows::Forms::Panel());
			this->buttonSalir = (gcnew System::Windows::Forms::Button());
			this->buttonHistorial = (gcnew System::Windows::Forms::Button());
			this->buttonDevoluciones = (gcnew System::Windows::Forms::Button());
			this->buttonPresupuestos = (gcnew System::Windows::Forms::Button());
			this->panelContenedor = (gcnew System::Windows::Forms::Panel());
			this->panelMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonPrestamos
			// 
			this->buttonPrestamos->Location = System::Drawing::Point(28, 36);
			this->buttonPrestamos->Name = L"buttonPrestamos";
			this->buttonPrestamos->Size = System::Drawing::Size(145, 73);
			this->buttonPrestamos->TabIndex = 0;
			this->buttonPrestamos->Text = L"Prestamos";
			this->buttonPrestamos->UseVisualStyleBackColor = true;
			this->buttonPrestamos->Click += gcnew System::EventHandler(this, &menuPrincipal::buttonPrestamos_Click);
			// 
			// buttonEntregaAlumnos
			// 
			this->buttonEntregaAlumnos->Location = System::Drawing::Point(28, 194);
			this->buttonEntregaAlumnos->Name = L"buttonEntregaAlumnos";
			this->buttonEntregaAlumnos->Size = System::Drawing::Size(145, 73);
			this->buttonEntregaAlumnos->TabIndex = 1;
			this->buttonEntregaAlumnos->Text = L"Entrega Alumnos";
			this->buttonEntregaAlumnos->UseVisualStyleBackColor = true;
			this->buttonEntregaAlumnos->Click += gcnew System::EventHandler(this, &menuPrincipal::buttonEntregaAlumnos_Click);
			// 
			// buttonMaterialTp
			// 
			this->buttonMaterialTp->Location = System::Drawing::Point(28, 273);
			this->buttonMaterialTp->Name = L"buttonMaterialTp";
			this->buttonMaterialTp->Size = System::Drawing::Size(145, 73);
			this->buttonMaterialTp->TabIndex = 2;
			this->buttonMaterialTp->Text = L"Material TP";
			this->buttonMaterialTp->UseVisualStyleBackColor = true;
			this->buttonMaterialTp->Click += gcnew System::EventHandler(this, &menuPrincipal::buttonMaterialTp_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(28, 352);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(145, 73);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Herramientas";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &menuPrincipal::button4_Click);
			// 
			// buttonConsumibles
			// 
			this->buttonConsumibles->Location = System::Drawing::Point(28, 431);
			this->buttonConsumibles->Name = L"buttonConsumibles";
			this->buttonConsumibles->Size = System::Drawing::Size(145, 73);
			this->buttonConsumibles->TabIndex = 3;
			this->buttonConsumibles->Text = L"Consumibles";
			this->buttonConsumibles->UseVisualStyleBackColor = true;
			this->buttonConsumibles->Click += gcnew System::EventHandler(this, &menuPrincipal::buttonConsumibles_Click);
			// 
			// panelMenu
			// 
			this->panelMenu->AutoScroll = true;
			this->panelMenu->BackColor = System::Drawing::Color::Teal;
			this->panelMenu->Controls->Add(this->buttonSalir);
			this->panelMenu->Controls->Add(this->buttonHistorial);
			this->panelMenu->Controls->Add(this->buttonDevoluciones);
			this->panelMenu->Controls->Add(this->buttonPresupuestos);
			this->panelMenu->Controls->Add(this->buttonMaterialTp);
			this->panelMenu->Controls->Add(this->buttonConsumibles);
			this->panelMenu->Controls->Add(this->buttonPrestamos);
			this->panelMenu->Controls->Add(this->button4);
			this->panelMenu->Controls->Add(this->buttonEntregaAlumnos);
			this->panelMenu->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelMenu->Location = System::Drawing::Point(0, 0);
			this->panelMenu->MaximumSize = System::Drawing::Size(200, 0);
			this->panelMenu->Name = L"panelMenu";
			this->panelMenu->Size = System::Drawing::Size(200, 853);
			this->panelMenu->TabIndex = 4;
			// 
			// buttonSalir
			// 
			this->buttonSalir->Location = System::Drawing::Point(28, 692);
			this->buttonSalir->Name = L"buttonSalir";
			this->buttonSalir->Size = System::Drawing::Size(145, 73);
			this->buttonSalir->TabIndex = 7;
			this->buttonSalir->Text = L"Salir";
			this->buttonSalir->UseVisualStyleBackColor = true;
			this->buttonSalir->Click += gcnew System::EventHandler(this, &menuPrincipal::buttonSalir_Click);
			// 
			// buttonHistorial
			// 
			this->buttonHistorial->Location = System::Drawing::Point(28, 115);
			this->buttonHistorial->Name = L"buttonHistorial";
			this->buttonHistorial->Size = System::Drawing::Size(145, 73);
			this->buttonHistorial->TabIndex = 6;
			this->buttonHistorial->Text = L"Historial Prestamos";
			this->buttonHistorial->UseVisualStyleBackColor = true;
			this->buttonHistorial->Click += gcnew System::EventHandler(this, &menuPrincipal::buttonHistorial_Click);
			// 
			// buttonDevoluciones
			// 
			this->buttonDevoluciones->Location = System::Drawing::Point(28, 589);
			this->buttonDevoluciones->Name = L"buttonDevoluciones";
			this->buttonDevoluciones->Size = System::Drawing::Size(145, 73);
			this->buttonDevoluciones->TabIndex = 5;
			this->buttonDevoluciones->Text = L"Registro de Usuarios\r\nHistoral de Ingresos";
			this->buttonDevoluciones->UseVisualStyleBackColor = true;
			this->buttonDevoluciones->Click += gcnew System::EventHandler(this, &menuPrincipal::buttonDevoluciones_Click);
			// 
			// buttonPresupuestos
			// 
			this->buttonPresupuestos->Location = System::Drawing::Point(28, 510);
			this->buttonPresupuestos->Name = L"buttonPresupuestos";
			this->buttonPresupuestos->Size = System::Drawing::Size(145, 73);
			this->buttonPresupuestos->TabIndex = 4;
			this->buttonPresupuestos->Text = L"Presupuestos";
			this->buttonPresupuestos->UseVisualStyleBackColor = true;
			this->buttonPresupuestos->Click += gcnew System::EventHandler(this, &menuPrincipal::buttonPresupuestos_Click);
			// 
			// panelContenedor
			// 
			this->panelContenedor->BackColor = System::Drawing::SystemColors::Control;
			this->panelContenedor->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContenedor->Location = System::Drawing::Point(200, 0);
			this->panelContenedor->Name = L"panelContenedor";
			this->panelContenedor->Size = System::Drawing::Size(1082, 853);
			this->panelContenedor->TabIndex = 5;
			// 
			// menuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1282, 853);
			this->Controls->Add(this->panelContenedor);
			this->Controls->Add(this->panelMenu);
			this->MinimumSize = System::Drawing::Size(1300, 900);
			this->Name = L"menuPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"                                  ";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &menuPrincipal::menuPrincipal_FormClosed);
			this->panelMenu->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void menuPrincipal_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}
	private: System::Void buttonPrestamos_Click(System::Object^ sender, System::EventArgs^ e) {

		if (formPrestamos == nullptr)
			formPrestamos = gcnew prestamos();

		AbrirFormulario(formPrestamos);
	}
	private: System::Void buttonEntregaAlumnos_Click(System::Object^ sender, System::EventArgs^ e) {

		if (formEntregaAlumnos == nullptr)
			formEntregaAlumnos = gcnew entregaAlumnos();

		AbrirFormulario(formEntregaAlumnos);
	}
private: System::Void buttonMaterialTp_Click(System::Object^ sender, System::EventArgs^ e) {
	if (formMaterialTP == nullptr)
		formMaterialTP = gcnew materialTP();
	AbrirFormulario(formMaterialTP);
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (formHerramientas == nullptr)
		formHerramientas = gcnew herramientas();
	AbrirFormulario(formHerramientas);
}
private: System::Void buttonConsumibles_Click(System::Object^ sender, System::EventArgs^ e) {
	if (formConsumibles == nullptr)
		formConsumibles = gcnew consumibles();
	AbrirFormulario(formConsumibles);
}
private: System::Void buttonPresupuestos_Click(System::Object^ sender, System::EventArgs^ e) {
	if (formPresupuestos == nullptr)
		formPresupuestos = gcnew presupuestos();
	AbrirFormulario(formPresupuestos);

}
/*
private: System::Void buttonDevoluciones_Click(System::Object^ sender, System::EventArgs^ e) {
	if (formDevoluciones == nullptr)
		formDevoluciones = gcnew devoluciones();
	AbrirFormulario(formDevoluciones);
}*/


private: System::Void buttonDevoluciones_Click(System::Object^ sender, System::EventArgs^ e) {
	ClaveDialog^ claveDialog = gcnew ClaveDialog();

	if (claveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ claveIngresada = claveDialog->ClaveIngresada;

		// Validar contra la base de datos
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;

		System::Collections::Specialized::NameValueCollection^ datos = gcnew System::Collections::Specialized::NameValueCollection();
		datos->Add("clave", claveIngresada);

		array<Byte>^ respuestaBytes = client->UploadValues("http://localhost/panol_api/validar_clave.php", "POST", datos);
		String^ respuesta = System::Text::Encoding::UTF8->GetString(respuestaBytes);

		if (respuesta == "OK") {
			if (formDevoluciones == nullptr)
				formDevoluciones = gcnew devoluciones();
			AbrirFormulario(formDevoluciones);
		}
		else {
			MessageBox::Show("Clave incorrecta. Acceso denegado.");
		}
	}
}

private: System::Void buttonHistorial_Click(System::Object^ sender, System::EventArgs^ e) {
	if (formHistorial == nullptr)
		formHistorial = gcnew HistorialPrestamos();

	AbrirFormulario(formHistorial);
}



private: System::Void buttonSalir_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
};
}
