#pragma once

namespace Panol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Net;
	using namespace System::IO;
	using namespace System::Data;
	using namespace System::Text;
	using namespace System::Web::Script::Serialization;
	using namespace System::Text::RegularExpressions;


	/// <summary>
	/// Resumen de HistorialPrestamos
	/// </summary>
	public ref class HistorialPrestamos : public System::Windows::Forms::Form
	{
	public:

		HistorialPrestamos(void);              // constructor vacío
		HistorialPrestamos(int idProfesor);    // constructor con parámetro

		/*
		HistorialPrestamos(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}*/




	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~HistorialPrestamos();
			/*
		{
			if (components)
			{
				delete components;
			}
		}*/
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ComboBox^ cmbDocente;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ fechaPrestamo;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ buttonAbrir;
	private: System::Windows::Forms::DataGridView^ dataGridView2;



	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ buttonDevolver;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Elemento;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cantRet;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cantDev;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id_herramienta;





	protected:

	protected:






	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		void cargarDocentes();
		
		String^ obtenerCampo(String^ jsonItem, String^ campo);
		void cargarPrestamosPorDocente(int idProfesor);
		System::Void HistorialPrestamos_Load(System::Object^ sender, System::EventArgs^ e);
		Void cmbDocente_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);

		void cargarDetallePrestamo(int idPrestamo);

		System::Void dataGridView1_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e);

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->cmbDocente = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->fechaPrestamo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->buttonAbrir = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Elemento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cantRet = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cantDev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->id_herramienta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->buttonDevolver = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				65)));
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->dataGridView1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->dataGridView2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel3, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel4, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1138, 664);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->cmbDocente);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(392, 94);
			this->panel1->TabIndex = 0;
			// 
			// cmbDocente
			// 
			this->cmbDocente->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->cmbDocente->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbDocente->FormattingEnabled = true;
			this->cmbDocente->Location = System::Drawing::Point(70, 31);
			this->cmbDocente->Name = L"cmbDocente";
			this->cmbDocente->Size = System::Drawing::Size(234, 33);
			this->cmbDocente->TabIndex = 1;
			this->cmbDocente->SelectionChangeCommitted += gcnew System::EventHandler(this, &HistorialPrestamos::cmbDocente_SelectedIndexChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->fechaPrestamo });
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(3, 103);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(392, 458);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &HistorialPrestamos::dataGridView1_CellClick);
			// 
			// fechaPrestamo
			// 
			this->fechaPrestamo->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->fechaPrestamo->HeaderText = L"Fecha del prestamo";
			this->fechaPrestamo->MinimumWidth = 6;
			this->fechaPrestamo->Name = L"fechaPrestamo";
			this->fechaPrestamo->ReadOnly = true;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->buttonAbrir);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(3, 567);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(392, 94);
			this->panel2->TabIndex = 2;
			// 
			// buttonAbrir
			// 
			this->buttonAbrir->Enabled = false;
			this->buttonAbrir->Location = System::Drawing::Point(20, 21);
			this->buttonAbrir->Name = L"buttonAbrir";
			this->buttonAbrir->Size = System::Drawing::Size(129, 53);
			this->buttonAbrir->TabIndex = 0;
			this->buttonAbrir->Text = L"Ver Prestamo";
			this->buttonAbrir->UseVisualStyleBackColor = true;
			this->buttonAbrir->Visible = false;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Elemento,
					this->cantRet, this->cantDev, this->id_herramienta
			});
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(401, 103);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(734, 458);
			this->dataGridView2->TabIndex = 3;
			// 
			// Elemento
			// 
			this->Elemento->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Elemento->HeaderText = L"Elemento";
			this->Elemento->MinimumWidth = 6;
			this->Elemento->Name = L"Elemento";
			this->Elemento->ReadOnly = true;
			// 
			// cantRet
			// 
			this->cantRet->HeaderText = L"Cantidad Retirada";
			this->cantRet->MinimumWidth = 6;
			this->cantRet->Name = L"cantRet";
			this->cantRet->ReadOnly = true;
			this->cantRet->Width = 125;
			// 
			// cantDev
			// 
			this->cantDev->HeaderText = L"Cantidad Devuelta";
			this->cantDev->MinimumWidth = 6;
			this->cantDev->Name = L"cantDev";
			this->cantDev->Width = 125;
			// 
			// id_herramienta
			// 
			this->id_herramienta->HeaderText = L"id_herramienta";
			this->id_herramienta->MinimumWidth = 6;
			this->id_herramienta->Name = L"id_herramienta";
			this->id_herramienta->Visible = false;
			this->id_herramienta->Width = 125;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->buttonDevolver);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(401, 567);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(734, 94);
			this->panel3->TabIndex = 4;
			// 
			// buttonDevolver
			// 
			this->buttonDevolver->Location = System::Drawing::Point(465, 13);
			this->buttonDevolver->Name = L"buttonDevolver";
			this->buttonDevolver->Size = System::Drawing::Size(239, 69);
			this->buttonDevolver->TabIndex = 0;
			this->buttonDevolver->Text = L"Cargar Devolucion";
			this->buttonDevolver->UseVisualStyleBackColor = true;
			this->buttonDevolver->Click += gcnew System::EventHandler(this, &HistorialPrestamos::buttonDevolver_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->label1);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(401, 3);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(734, 94);
			this->panel4->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(51, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(323, 75);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Seleccione el docente de la lista\r\ny luego la fecha del prestamo\r\n que desee ver\r"
				L"\n";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// HistorialPrestamos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1138, 664);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"HistorialPrestamos";
			this->Text = L"HistorialPrestamos";
			this->Load += gcnew System::EventHandler(this, &HistorialPrestamos::HistorialPrestamos_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


private: System::Void buttonDevolver_Click(System::Object^ sender, System::EventArgs^ e);

};
}
