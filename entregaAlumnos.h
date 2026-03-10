#pragma once

namespace Panol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de entregaAlumnos
	/// </summary>
	public ref class entregaAlumnos : public System::Windows::Forms::Form
	{
	public:
		entregaAlumnos(void)
		{
			InitializeComponent();
		
			this->Load += gcnew System::EventHandler(this, &entregaAlumnos::entregaAlumnos_Load);

		}

	protected:
		
		~entregaAlumnos()
		{
			if (components)
				delete components;
		}


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::ComboBox^ comboBoxAlumno;
	private: System::Windows::Forms::Button^ buttonBuscar;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::TextBox^ textBoxCurso;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ fecha;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cantidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ materialRetirado;
	private: System::Windows::Forms::Button^ buttonRetiro;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ fechaRetiro;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cantidadRetirar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ materialRetirar;


	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonBuscar = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBoxCurso = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxAlumno = (gcnew System::Windows::Forms::ComboBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->buttonRetiro = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->fecha = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->materialRetirado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->fechaRetiro = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cantidadRetirar = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->materialRetirar = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::SystemColors::Highlight;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1365, 668);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->buttonBuscar);
			this->panel1->Controls->Add(this->dateTimePicker1);
			this->panel1->Controls->Add(this->textBoxCurso);
			this->panel1->Controls->Add(this->comboBoxAlumno);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1359, 94);
			this->panel1->TabIndex = 0;
			// 
			// buttonBuscar
			// 
			this->buttonBuscar->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->buttonBuscar->Location = System::Drawing::Point(1031, 39);
			this->buttonBuscar->Name = L"buttonBuscar";
			this->buttonBuscar->Size = System::Drawing::Size(197, 36);
			this->buttonBuscar->TabIndex = 3;
			this->buttonBuscar->Text = L"Buscar";
			this->buttonBuscar->UseVisualStyleBackColor = true;
			this->buttonBuscar->Click += gcnew System::EventHandler(this, &entregaAlumnos::buttonBuscar_Click);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->dateTimePicker1->Location = System::Drawing::Point(1031, 9);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(197, 22);
			this->dateTimePicker1->TabIndex = 2;
			// 
			// textBoxCurso
			// 
			this->textBoxCurso->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->textBoxCurso->Location = System::Drawing::Point(546, 36);
			this->textBoxCurso->Name = L"textBoxCurso";
			this->textBoxCurso->Size = System::Drawing::Size(288, 22);
			this->textBoxCurso->TabIndex = 1;
			// 
			// comboBoxAlumno
			// 
			this->comboBoxAlumno->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->comboBoxAlumno->FormattingEnabled = true;
			this->comboBoxAlumno->Location = System::Drawing::Point(42, 36);
			this->comboBoxAlumno->Name = L"comboBoxAlumno";
			this->comboBoxAlumno->Size = System::Drawing::Size(328, 24);
			this->comboBoxAlumno->TabIndex = 0;
			this->comboBoxAlumno->SelectedIndexChanged += gcnew System::EventHandler(this, &entregaAlumnos::comboBoxAlumno_SelectedIndexChanged);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->buttonRetiro);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(3, 571);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1359, 94);
			this->panel2->TabIndex = 1;
			// 
			// buttonRetiro
			// 
			this->buttonRetiro->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->buttonRetiro->Location = System::Drawing::Point(334, 20);
			this->buttonRetiro->Name = L"buttonRetiro";
			this->buttonRetiro->Size = System::Drawing::Size(688, 49);
			this->buttonRetiro->TabIndex = 0;
			this->buttonRetiro->Text = L"Guardar Retiro";
			this->buttonRetiro->UseVisualStyleBackColor = true;
			this->buttonRetiro->Click += gcnew System::EventHandler(this, &entregaAlumnos::buttonRetiro_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->dataGridView1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->dataGridView2, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 103);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1359, 462);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->fecha,
					this->cantidad, this->materialRetirado
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(673, 456);
			this->dataGridView1->TabIndex = 0;
			// 
			// fecha
			// 
			this->fecha->HeaderText = L"Fecha";
			this->fecha->MinimumWidth = 6;
			this->fecha->Name = L"fecha";
			this->fecha->ReadOnly = true;
			this->fecha->Width = 125;
			// 
			// cantidad
			// 
			this->cantidad->HeaderText = L"Cantidad";
			this->cantidad->MinimumWidth = 6;
			this->cantidad->Name = L"cantidad";
			this->cantidad->ReadOnly = true;
			this->cantidad->Width = 125;
			// 
			// materialRetirado
			// 
			this->materialRetirado->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->materialRetirado->HeaderText = L"Material Ya Retirado";
			this->materialRetirado->MinimumWidth = 6;
			this->materialRetirado->Name = L"materialRetirado";
			this->materialRetirado->ReadOnly = true;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->fechaRetiro,
					this->cantidadRetirar, this->materialRetirar
			});
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(682, 3);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(674, 456);
			this->dataGridView2->TabIndex = 1;
			// 
			// fechaRetiro
			// 
			this->fechaRetiro->HeaderText = L"Fecha";
			this->fechaRetiro->MinimumWidth = 6;
			this->fechaRetiro->Name = L"fechaRetiro";
			this->fechaRetiro->Width = 125;
			// 
			// cantidadRetirar
			// 
			this->cantidadRetirar->HeaderText = L"Cantidad";
			this->cantidadRetirar->MinimumWidth = 6;
			this->cantidadRetirar->Name = L"cantidadRetirar";
			this->cantidadRetirar->Width = 125;
			// 
			// materialRetirar
			// 
			this->materialRetirar->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->materialRetirar->HeaderText = L"Material a Retirar";
			this->materialRetirar->MinimumWidth = 6;
			this->materialRetirar->Name = L"materialRetirar";
			// 
			// entregaAlumnos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(1365, 668);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"entregaAlumnos";
			this->Text = L"entregaAlumnos";
			this->Load += gcnew System::EventHandler(this, &entregaAlumnos::entregaAlumnos_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	// =============================
	// Metodos auxiliares
	// =============================
	private:
		void    CargarAlumnos();
		void    CargarMaterialRetirado(int idAlumno);
		void    CargarMaterialesDisponibles();
		void    BuscarCursoAlumno(int idAlumno);
		int     ObtenerIdAlumnoSeleccionado();
		String^ obtenerCampo(String^ jsonItem, String^ campo);

	// =============================
	// Eventos
	// =============================
	private:
		System::Void entregaAlumnos_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonBuscar_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonRetiro_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void comboBoxAlumno_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	

   };

		
}
