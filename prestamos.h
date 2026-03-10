#pragma once

namespace Panol {

	using namespace System::Collections::Generic;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::IO;
	using namespace System::Data;
	using namespace System::Text;
	using namespace System::Web::Script::Serialization;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Resumen de prestamos
	/// </summary>
	public ref class prestamos : public System::Windows::Forms::Form
	{
	public:
		prestamos(void);
		~prestamos();

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
	
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::DataGridView^ dataGridViewPrestamos;
	private: System::Windows::Forms::DataGridView^ dataGridView1;





	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ buttonActualizar;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerFecha;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cantidad;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ elementoRetirado;
	private: System::Windows::Forms::Panel^ panel2;



	private: System::Windows::Forms::Button^ buttonPrestamo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ elementoSolicitado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cantidadSolicitada;
	private: System::Windows::Forms::Label^ label1;




	private: System::Windows::Forms::ComboBox^ cmbDocente;

		   // prestamos.h
	private:
		System::Windows::Forms::Timer^ timerActualizar;  // Timer para actualizar el DataGridView
		void timerActualizar_Tick(System::Object^ sender, System::EventArgs^ e); // Evento Tick

	protected:

	protected:

	private:

		// Firmas de funciones propias
		//void InitializeComponent(void);
		System::Void prestamos_Load(System::Object^ sender, System::EventArgs^ e);
		void cargarDocentes();
		String^ obtenerCampo(String^ jsonItem, String^ campo);
		void cargarHerramientas();
	




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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dataGridViewPrestamos = (gcnew System::Windows::Forms::DataGridView());
			this->cantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->elementoRetirado = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->elementoSolicitado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cantidadSolicitada = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonActualizar = (gcnew System::Windows::Forms::Button());
			this->dateTimePickerFecha = (gcnew System::Windows::Forms::DateTimePicker());
			this->cmbDocente = (gcnew System::Windows::Forms::ComboBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->buttonPrestamo = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPrestamos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 120)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1158, 612);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->dataGridViewPrestamos, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->dataGridView1, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 123);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1152, 386);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// dataGridViewPrestamos
			// 
			this->dataGridViewPrestamos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewPrestamos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->cantidad,
					this->elementoRetirado
			});
			this->dataGridViewPrestamos->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridViewPrestamos->Location = System::Drawing::Point(3, 3);
			this->dataGridViewPrestamos->Name = L"dataGridViewPrestamos";
			this->dataGridViewPrestamos->RowHeadersWidth = 51;
			this->dataGridViewPrestamos->RowTemplate->Height = 24;
			this->dataGridViewPrestamos->Size = System::Drawing::Size(570, 380);
			this->dataGridViewPrestamos->TabIndex = 0;
			this->dataGridViewPrestamos->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &prestamos::dataGridViewPrestamos_EditingControlShowing);
			// 
			// cantidad
			// 
			this->cantidad->HeaderText = L"Cantidad";
			this->cantidad->MinimumWidth = 6;
			this->cantidad->Name = L"cantidad";
			this->cantidad->Width = 125;
			// 
			// elementoRetirado
			// 
			this->elementoRetirado->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->elementoRetirado->HeaderText = L"Elemento Retirado";
			this->elementoRetirado->MinimumWidth = 6;
			this->elementoRetirado->Name = L"elementoRetirado";
			this->elementoRetirado->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->elementoRetirado->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->elementoSolicitado,
					this->cantidadSolicitada
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(579, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(570, 380);
			this->dataGridView1->TabIndex = 1;
			// 
			// elementoSolicitado
			// 
			this->elementoSolicitado->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->elementoSolicitado->HeaderText = L"Elemento Solicitado";
			this->elementoSolicitado->MinimumWidth = 6;
			this->elementoSolicitado->Name = L"elementoSolicitado";
			this->elementoSolicitado->ReadOnly = true;
			// 
			// cantidadSolicitada
			// 
			this->cantidadSolicitada->HeaderText = L"Cantidad";
			this->cantidadSolicitada->MinimumWidth = 6;
			this->cantidadSolicitada->Name = L"cantidadSolicitada";
			this->cantidadSolicitada->ReadOnly = true;
			this->cantidadSolicitada->Width = 125;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->buttonActualizar);
			this->panel1->Controls->Add(this->dateTimePickerFecha);
			this->panel1->Controls->Add(this->cmbDocente);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1152, 114);
			this->panel1->TabIndex = 1;
			// 
			// buttonActualizar
			// 
			this->buttonActualizar->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->buttonActualizar->Location = System::Drawing::Point(934, 31);
			this->buttonActualizar->Name = L"buttonActualizar";
			this->buttonActualizar->Size = System::Drawing::Size(193, 48);
			this->buttonActualizar->TabIndex = 2;
			this->buttonActualizar->Text = L"Ver Pedido";
			this->buttonActualizar->UseVisualStyleBackColor = true;
			this->buttonActualizar->Click += gcnew System::EventHandler(this, &prestamos::buttonActualizar_Click);
			// 
			// dateTimePickerFecha
			// 
			this->dateTimePickerFecha->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->dateTimePickerFecha->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateTimePickerFecha->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateTimePickerFecha->Location = System::Drawing::Point(405, 37);
			this->dateTimePickerFecha->Name = L"dateTimePickerFecha";
			this->dateTimePickerFecha->Size = System::Drawing::Size(361, 28);
			this->dateTimePickerFecha->TabIndex = 1;
			// 
			// cmbDocente
			// 
			this->cmbDocente->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->cmbDocente->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbDocente->FormattingEnabled = true;
			this->cmbDocente->Location = System::Drawing::Point(24, 37);
			this->cmbDocente->Name = L"cmbDocente";
			this->cmbDocente->Size = System::Drawing::Size(233, 33);
			this->cmbDocente->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->buttonPrestamo);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(3, 515);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1152, 94);
			this->panel2->TabIndex = 2;
			// 
			// buttonPrestamo
			// 
			this->buttonPrestamo->Dock = System::Windows::Forms::DockStyle::Left;
			this->buttonPrestamo->Location = System::Drawing::Point(0, 0);
			this->buttonPrestamo->Name = L"buttonPrestamo";
			this->buttonPrestamo->Size = System::Drawing::Size(252, 94);
			this->buttonPrestamo->TabIndex = 0;
			this->buttonPrestamo->Text = L"Prestar";
			this->buttonPrestamo->UseVisualStyleBackColor = true;
			this->buttonPrestamo->Click += gcnew System::EventHandler(this, &prestamos::buttonPrestamo_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(67, 83);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(144, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Seleccione un docente";
			// 
			// prestamos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1158, 612);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"prestamos";
			this->Text = L"prestamos";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPrestamos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion



	private: System::Void dataGridViewPrestamos_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e);	
	
	private: System::Void Cantidad_KeyPress(System::Object^ sender, KeyPressEventArgs^ e);

	private: System::Void buttonPrestamo_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void buttonActualizar_Click(System::Object^ sender, System::EventArgs^ e);


};
}
