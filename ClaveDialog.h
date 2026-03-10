#pragma once

namespace Panol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ClaveDialog
	/// </summary>
	public ref class ClaveDialog : public System::Windows::Forms::Form
	{
	public:
		ClaveDialog(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		// Propiedad pública para devolver la clave ingresada
		property String^ ClaveIngresada;


	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~ClaveDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBoxClave;
	private: System::Windows::Forms::Button^ buttonAceptar;

	private:
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxClave = (gcnew System::Windows::Forms::TextBox());
			this->buttonAceptar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(70, 63);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(231, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ingrese la Clave";
			// 
			// textBoxClave
			// 
			this->textBoxClave->Location = System::Drawing::Point(83, 136);
			this->textBoxClave->Name = L"textBoxClave";
			this->textBoxClave->Size = System::Drawing::Size(205, 22);
			this->textBoxClave->TabIndex = 1;
			this->textBoxClave->UseSystemPasswordChar = true;
			// 
			// buttonAceptar
			// 
			this->buttonAceptar->Location = System::Drawing::Point(110, 191);
			this->buttonAceptar->Name = L"buttonAceptar";
			this->buttonAceptar->Size = System::Drawing::Size(160, 56);
			this->buttonAceptar->TabIndex = 2;
			this->buttonAceptar->Text = L"Aceptar";
			this->buttonAceptar->UseVisualStyleBackColor = true;
			this->buttonAceptar->Click += gcnew System::EventHandler(this, &ClaveDialog::buttonAceptar_Click);
			// 
			// ClaveDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(376, 312);
			this->Controls->Add(this->buttonAceptar);
			this->Controls->Add(this->textBoxClave);
			this->Controls->Add(this->label1);
			this->Name = L"ClaveDialog";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ClaveDialog";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void buttonAceptar_Click(System::Object^ sender, System::EventArgs^ e) {
			ClaveIngresada = textBoxClave->Text;
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}

	private: System::Void buttonDevoluciones_Click(System::Object^ sender, System::EventArgs^ e) {
		Panol::ClaveDialog^ claveDialog = gcnew Panol::ClaveDialog();

		if (claveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ claveIngresada = claveDialog->ClaveIngresada;
			MessageBox::Show("Clave ingresada: " + claveIngresada);
		}
	}



	};
}
