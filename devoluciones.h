#pragma once

namespace Panol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de devoluciones
	/// </summary>
	public ref class devoluciones : public System::Windows::Forms::Form
	{
	public:
		devoluciones(void)
		{
			InitializeComponent();
			cargarUsuarios();
			cargarRegistroIngreso();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~devoluciones()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::DataGridView^ dataGridView1;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ buttonCambioClave;
	private: System::Windows::Forms::TextBox^ textBoxClave2;
	private: System::Windows::Forms::TextBox^ textBoxClave1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::DataGridView^ dataGridView2;


	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dni;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ apellido;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ user;
	private: System::Windows::Forms::Button^ buttonGuardarCambios;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ fecha;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ apellidoIngreso;







	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

		void cargarUsuarios();
		String^ obtenerCampo(String^ jsonItem, String^ campo);

		void guardarCambios();
		void insertarUsuario(String^ dni, String^ apellido, String^ nombre, String^ user);
		void actualizarUsuario(String^ id, String^ dni, String^ apellido, String^ nombre, String^ user);
	
		void cargarRegistroIngreso();
		void cambiarClave();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->buttonGuardarCambios = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dni = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->apellido = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->user = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->textBoxClave1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxClave2 = (gcnew System::Windows::Forms::TextBox());
			this->buttonCambioClave = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->fecha = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->apellidoIngreso = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel3, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel4, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel5, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->dataGridView1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel6, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel7, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel8, 2, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1095, 747);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(432, 94);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bell MT", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(44, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(351, 33);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Administracion de Usuarios";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label5);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(441, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(432, 94);
			this->panel2->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Bell MT", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(73, 30);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(268, 33);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Registro de Ingresos";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->dataGridView2);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(441, 103);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(432, 521);
			this->panel3->TabIndex = 2;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->fecha,
					this->apellidoIngreso
			});
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(0, 0);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(432, 521);
			this->dataGridView2->TabIndex = 0;
			// 
			// panel4
			// 
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(441, 630);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(432, 94);
			this->panel4->TabIndex = 3;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->buttonGuardarCambios);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(3, 630);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(432, 94);
			this->panel5->TabIndex = 4;
			// 
			// buttonGuardarCambios
			// 
			this->buttonGuardarCambios->Location = System::Drawing::Point(63, 19);
			this->buttonGuardarCambios->Name = L"buttonGuardarCambios";
			this->buttonGuardarCambios->Size = System::Drawing::Size(312, 53);
			this->buttonGuardarCambios->TabIndex = 0;
			this->buttonGuardarCambios->Text = L"Guardar Cambios";
			this->buttonGuardarCambios->UseVisualStyleBackColor = true;
			this->buttonGuardarCambios->Click += gcnew System::EventHandler(this, &devoluciones::buttonGuardarCambios_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dni, this->apellido,
					this->nombre, this->user
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(3, 103);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(432, 521);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &devoluciones::dataGridView1_CellContentClick);
			// 
			// dni
			// 
			this->dni->FillWeight = 50;
			this->dni->HeaderText = L"DNI";
			this->dni->MinimumWidth = 6;
			this->dni->Name = L"dni";
			this->dni->Width = 125;
			// 
			// apellido
			// 
			this->apellido->FillWeight = 80;
			this->apellido->HeaderText = L"Apellido";
			this->apellido->MinimumWidth = 6;
			this->apellido->Name = L"apellido";
			this->apellido->Width = 125;
			// 
			// nombre
			// 
			this->nombre->FillWeight = 80;
			this->nombre->HeaderText = L"Nombre";
			this->nombre->MinimumWidth = 6;
			this->nombre->Name = L"nombre";
			this->nombre->Width = 125;
			// 
			// user
			// 
			this->user->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->user->HeaderText = L"Usuario";
			this->user->MinimumWidth = 6;
			this->user->Name = L"user";
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->label2);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel6->Location = System::Drawing::Point(879, 3);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(213, 94);
			this->panel6->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bell MT", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(192, 66);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Clave\r\nAdministrador";
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->textBoxClave1);
			this->panel7->Controls->Add(this->textBoxClave2);
			this->panel7->Controls->Add(this->buttonCambioClave);
			this->panel7->Controls->Add(this->label3);
			this->panel7->Controls->Add(this->label4);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel7->Location = System::Drawing::Point(879, 103);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(213, 521);
			this->panel7->TabIndex = 7;
			// 
			// textBoxClave1
			// 
			this->textBoxClave1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxClave1->Location = System::Drawing::Point(15, 127);
			this->textBoxClave1->Name = L"textBoxClave1";
			this->textBoxClave1->Size = System::Drawing::Size(189, 22);
			this->textBoxClave1->TabIndex = 4;
			this->textBoxClave1->UseSystemPasswordChar = true;
			// 
			// textBoxClave2
			// 
			this->textBoxClave2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxClave2->Location = System::Drawing::Point(15, 274);
			this->textBoxClave2->Name = L"textBoxClave2";
			this->textBoxClave2->Size = System::Drawing::Size(189, 22);
			this->textBoxClave2->TabIndex = 5;
			this->textBoxClave2->UseSystemPasswordChar = true;
			// 
			// buttonCambioClave
			// 
			this->buttonCambioClave->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->buttonCambioClave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonCambioClave->Location = System::Drawing::Point(28, 423);
			this->buttonCambioClave->Name = L"buttonCambioClave";
			this->buttonCambioClave->Size = System::Drawing::Size(153, 54);
			this->buttonCambioClave->TabIndex = 6;
			this->buttonCambioClave->Text = L"Cambiar Clave";
			this->buttonCambioClave->UseVisualStyleBackColor = true;
			this->buttonCambioClave->Click += gcnew System::EventHandler(this, &devoluciones::buttonCambioClave_Click);
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Bell MT", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(22, 223);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(165, 33);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Nueva Clave";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Bell MT", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(22, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(165, 33);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Nueva Clave";
			// 
			// panel8
			// 
			this->panel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel8->Location = System::Drawing::Point(879, 630);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(213, 94);
			this->panel8->TabIndex = 8;
			// 
			// fecha
			// 
			this->fecha->HeaderText = L"Fecha";
			this->fecha->MinimumWidth = 6;
			this->fecha->Name = L"fecha";
			this->fecha->ReadOnly = true;
			this->fecha->Width = 125;
			// 
			// apellidoIngreso
			// 
			this->apellidoIngreso->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->apellidoIngreso->HeaderText = L"Apellido";
			this->apellidoIngreso->MinimumWidth = 6;
			this->apellidoIngreso->Name = L"apellidoIngreso";
			this->apellidoIngreso->ReadOnly = true;
			// 
			// devoluciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(1095, 747);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"devoluciones";
			this->Text = L"devoluciones";
			this->Load += gcnew System::EventHandler(this, &devoluciones::devoluciones_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void devoluciones_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonGuardarCambios_Click(System::Object^ sender, System::EventArgs^ e) {
	guardarCambios();
}
private: System::Void buttonCambioClave_Click(System::Object^ sender, System::EventArgs^ e) {
	cambiarClave();
}
};
}
