#pragma once

namespace Panol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// Resumen de herramientas

	public ref class herramientas : public System::Windows::Forms::Form
	{
	public:
		herramientas(void)
		{
			InitializeComponent();

			this->Load += gcnew System::EventHandler(this, &herramientas::herramientas_Load);
		}

	protected:
		~herramientas()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::DataGridView^ dataGridViewListado;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ buttonGuardar;
	private: System::Windows::Forms::Button^ buttonEditar;
	private: System::Windows::Forms::Button^ buttonListar;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::DataGridView^ dataGridViewStock;
	private: System::Windows::Forms::Panel^ panel5;
    private: System::Windows::Forms::DataGridView^ dataGridViewAltas;
	private: System::Windows::Forms::Button^ buttonAltaHerramienta;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ numeroInventario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nombreHerramienta;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ tipoHerramienta;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cantidad;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ estadoHerramienta;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ descripcion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ inventarioAlta;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nombreAlta;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ tipoAlta;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ stockAlta;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ estadoAlta;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ descripcionAlta;

	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridViewListado = (gcnew System::Windows::Forms::DataGridView());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->buttonGuardar = (gcnew System::Windows::Forms::Button());
			this->buttonEditar = (gcnew System::Windows::Forms::Button());
			this->buttonListar = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->dataGridViewAltas = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewStock = (gcnew System::Windows::Forms::DataGridView());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->buttonAltaHerramienta = (gcnew System::Windows::Forms::Button());
			this->numeroInventario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nombreHerramienta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tipoHerramienta = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->cantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->estadoHerramienta = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->descripcion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->inventarioAlta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nombreAlta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tipoAlta = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->stockAlta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->estadoAlta = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->descripcionAlta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewListado))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAltas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStock))->BeginInit();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,100)));
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->panel5, 0, 4);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1394, 774);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->dateTimePicker1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1388, 94);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(66, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(398, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Alta de Herramientas y Control de Stock";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Enabled = false;
			this->dateTimePicker1->Location = System::Drawing::Point(748, 34);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(291, 22);
			this->dateTimePicker1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->dataGridViewListado);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(3, 103);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1388, 231);
			this->panel2->TabIndex = 1;
			// 
			// dataGridViewListado
			// 
			this->dataGridViewListado->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewListado->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
			this->numeroInventario,this->nombreHerramienta, this->tipoHerramienta, this->cantidad, this->estadoHerramienta, this->descripcion});
			this->dataGridViewListado->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridViewListado->Location = System::Drawing::Point(0, 0);
			this->dataGridViewListado->Name = L"dataGridViewListado";
			this->dataGridViewListado->RowHeadersWidth = 51;
			this->dataGridViewListado->RowTemplate->Height = 24;
			this->dataGridViewListado->Size = System::Drawing::Size(1388, 231);
			this->dataGridViewListado->TabIndex = 0;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->buttonGuardar);
			this->panel3->Controls->Add(this->buttonEditar);
			this->panel3->Controls->Add(this->buttonListar);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(3, 340);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1388, 94);
			this->panel3->TabIndex = 2;
			// 
			// buttonGuardar
			// 
			this->buttonGuardar->Location = System::Drawing::Point(851, 25);
			this->buttonGuardar->Name = L"buttonGuardar";
			this->buttonGuardar->Size = System::Drawing::Size(150, 45);
			this->buttonGuardar->TabIndex = 2;
			this->buttonGuardar->Text = L"Guardar";
			this->buttonGuardar->UseVisualStyleBackColor = true;
			this->buttonGuardar->Click += gcnew System::EventHandler(this, &herramientas::buttonGuardar_Click);
			// 
			// buttonEditar
			// 
			this->buttonEditar->Location = System::Drawing::Point(493, 25);
			this->buttonEditar->Name = L"buttonEditar";
			this->buttonEditar->Size = System::Drawing::Size(150, 45);
			this->buttonEditar->TabIndex = 1;
			this->buttonEditar->Text = L"Editar";
			this->buttonEditar->UseVisualStyleBackColor = true;
			this->buttonEditar->Click += gcnew System::EventHandler(this, &herramientas::buttonEditar_Click);
			// 
			// buttonListar
			// 
			this->buttonListar->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->buttonListar->Location = System::Drawing::Point(153, 21);
			this->buttonListar->Name = L"buttonListar";
			this->buttonListar->Size = System::Drawing::Size(150, 45);
			this->buttonListar->TabIndex = 0;
			this->buttonListar->Text = L"Listado de Herramientas";
			this->buttonListar->UseVisualStyleBackColor = true;
			this->buttonListar->Click += gcnew System::EventHandler(this, &herramientas::buttonListar_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->dataGridViewAltas);
			this->panel4->Controls->Add(this->dataGridViewStock);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(3, 440);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1388, 231);
			this->panel4->TabIndex = 3;
			// 
			// dataGridViewAltas
			// 
			this->dataGridViewAltas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewAltas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
			this->inventarioAlta,this->nombreAlta, this->tipoAlta, this->stockAlta, this->estadoAlta, this->descripcionAlta});
			this->dataGridViewAltas->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridViewAltas->Location = System::Drawing::Point(0, 0);
			this->dataGridViewAltas->Name = L"dataGridViewAltas";
			this->dataGridViewAltas->RowHeadersWidth = 51;
			this->dataGridViewAltas->RowTemplate->Height = 24;
			this->dataGridViewAltas->Size = System::Drawing::Size(1388, 231);
			this->dataGridViewAltas->TabIndex = 1;
			// 
			// dataGridViewStock
			// 
			this->dataGridViewStock->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewStock->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridViewStock->Location = System::Drawing::Point(0, 0);
			this->dataGridViewStock->Name = L"dataGridViewStock";
			this->dataGridViewStock->RowHeadersWidth = 51;
			this->dataGridViewStock->RowTemplate->Height = 24;
			this->dataGridViewStock->Size = System::Drawing::Size(1388, 231);
			this->dataGridViewStock->TabIndex = 0;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->buttonAltaHerramienta);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(3, 677);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(1388, 94);
			this->panel5->TabIndex = 4;
			// 
			// buttonAltaHerramienta
			// 
			this->buttonAltaHerramienta->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAltaHerramienta->Location = System::Drawing::Point(387, 19);
			this->buttonAltaHerramienta->Name = L"buttonAltaHerramienta";
			this->buttonAltaHerramienta->Size = System::Drawing::Size(624, 50);
			this->buttonAltaHerramienta->TabIndex = 0;
			this->buttonAltaHerramienta->Text = L"Guardar Alta Herramientas";
			this->buttonAltaHerramienta->UseVisualStyleBackColor = true;
			this->buttonAltaHerramienta->Click += gcnew System::EventHandler(this, &herramientas::buttonAltaHerramienta_Click);
			// 
			// numeroInventario
			// 
			this->numeroInventario->HeaderText = L"N° Inventario";
			this->numeroInventario->MinimumWidth = 6;
			this->numeroInventario->Name = L"numeroInventario";
			this->numeroInventario->ReadOnly = true;
			this->numeroInventario->Width = 80;
			// 
			// nombreHerramienta
			// 
			this->nombreHerramienta->HeaderText = L"Nombre";
			this->nombreHerramienta->MinimumWidth = 6;
			this->nombreHerramienta->Name = L"nombreHerramienta";
			this->nombreHerramienta->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->nombreHerramienta->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->nombreHerramienta->Width = 300;
			// 
			// tipoHerramienta
			// 
			this->tipoHerramienta->HeaderText = L"Tipo";
			this->tipoHerramienta->MinimumWidth = 6;
			this->tipoHerramienta->Name = L"tipoHerramienta";
			this->tipoHerramienta->Width = 125;
			this->tipoHerramienta->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"ELECTRICA", L"MANUAL", L"MEDICION", L"INSTRUMENTAL" });
			// 
			// cantidad
			// 
			this->cantidad->HeaderText = L"Stock";
			this->cantidad->MinimumWidth = 6;
			this->cantidad->Name = L"cantidad";
			this->cantidad->ReadOnly = true;
			this->cantidad->Width = 125;
			// 
			// estadoHerramienta
			// 
			this->estadoHerramienta->HeaderText = L"Estado";
			this->estadoHerramienta->MinimumWidth = 6;
			this->estadoHerramienta->Name = L"estadoHerramienta";
			this->estadoHerramienta->Width = 125;
			this->estadoHerramienta->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"BUENO", L"REGULAR", L"BAJA" });
			// 
			// descripcion
			// 
			this->descripcion->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->descripcion->HeaderText = L"Descripcion - Obsrevaciones";
			this->descripcion->MinimumWidth = 6;
			this->descripcion->Name = L"descripcion";
			// 
			// inventarioAlta
			// 
			this->inventarioAlta->HeaderText = L"N° Inventario";
			this->inventarioAlta->MinimumWidth = 6;
			this->inventarioAlta->Name = L"inventarioAlta";
			this->inventarioAlta->Width = 80;
			// 
			// nombreAlta
			// 
			this->nombreAlta->HeaderText = L"Nombre";
			this->nombreAlta->MinimumWidth = 6;
			this->nombreAlta->Name = L"nombreAlta";
			this->nombreAlta->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->nombreAlta->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->nombreAlta->Width = 300;
			// 
			// tipoAlta
			// 
			this->tipoAlta->HeaderText = L"Tipo";
			this->tipoAlta->MinimumWidth = 6;
			this->tipoAlta->Name = L"tipoAlta";
			this->tipoAlta->Width = 125;
			this->tipoAlta->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"ELECTRICA", L"MANUAL", L"MEDICION", L"INSTRUMENTAL" });
            // 
			// stockAlta
			// 
			this->stockAlta->HeaderText = L"Stock";
			this->stockAlta->MinimumWidth = 6;
			this->stockAlta->Name = L"stockAlta";
			this->stockAlta->Width = 125;
			// 
			// estadoAlta
			// 
			this->estadoAlta->HeaderText = L"Estado";
			this->estadoAlta->MinimumWidth = 6;
			this->estadoAlta->Name = L"estadoAlta";
			this->estadoAlta->Width = 125;
			this->estadoAlta->Items->AddRange(gcnew cli::array<System::Object^>(3) { L"BUENO", L"REGULAR", L"BAJA" });
			// 
			// descripcionAlta
			// 
			this->descripcionAlta->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->descripcionAlta->HeaderText = L"Descripcion - Obsrevaciones";
			this->descripcionAlta->MinimumWidth = 6;
			this->descripcionAlta->Name = L"descripcionAlta";
			// 
			// herramientas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Turquoise;
			this->ClientSize = System::Drawing::Size(1394, 774);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"herramientas";
			this->Text = L"herramientas";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewListado))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAltas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStock))->EndInit();
			this->panel5->ResumeLayout(false);
			this->ResumeLayout(false);

		}

#pragma endregion
		// ===========================
		// Metodos auxiliares
		// =============================
	private:
		void    CargarListado();
		void    GuardarEdicion(int idHerramienta, DataGridViewRow^ row);
		String^ ObtenerCampo(String^ jsonItem, String^ campo);

		// =============================
		// Eventos
		// =============================
	private:
		System::Void herramientas_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonListar_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonEditar_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonGuardar_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonAltaHerramienta_Click(System::Object^ sender, System::EventArgs^ e);

		

};
}
