#pragma once

namespace Panol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class materialTP : public System::Windows::Forms::Form
	{
	public:
		materialTP(void)
		{
			InitializeComponent();
			_cargandoDatos = false;

			this->Load += gcnew System::EventHandler(this, &materialTP::materialTP_Load);
			this->buttonListado->Click += gcnew System::EventHandler(this, &materialTP::buttonListado_Click);
			this->button2->Click += gcnew System::EventHandler(this, &materialTP::buttonCargar_Click);
			this->btnEditar->Click += gcnew System::EventHandler(this, &materialTP::buttonEditar_Click);
			this->btnGuardarEdicion->Click += gcnew System::EventHandler(this, &materialTP::buttonGuardarEdicion_Click);
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &materialTP::buttonLimpiar_Click);
			this->dataGridView1->SelectionChanged += gcnew System::EventHandler(this, &materialTP::dataGridView1_SelectionChanged);
			this->dataGridView1->CellClick += gcnew DataGridViewCellEventHandler(this, &materialTP::dataGridView1_CellClick);
			this->dataGridView2->EditingControlShowing += gcnew DataGridViewEditingControlShowingEventHandler(this, &materialTP::dataGridView2_EditingControlShowing);
			this->dataGridView2->CellValidating += gcnew DataGridViewCellValidatingEventHandler(this, &materialTP::dataGridView2_CellValidating);
			this->dataGridView2->DataError += gcnew DataGridViewDataErrorEventHandler(this, &materialTP::dataGridView2_DataError);
		}

	protected:
		~materialTP()
		{
			if (components)
				delete components;
		}

	private:
		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
		System::Windows::Forms::Panel^ panel1;
		System::Windows::Forms::Panel^ panel2;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ buttonListado;
		System::Windows::Forms::Button^ btnEditar;
		System::Windows::Forms::Button^ btnGuardarEdicion;
		System::Windows::Forms::Button^ btnLimpiar;
		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::DataGridView^ dataGridView2;

		System::Windows::Forms::DataGridViewTextBoxColumn^ columNombre;
		System::Windows::Forms::DataGridViewTextBoxColumn^ stock;
		System::Windows::Forms::DataGridViewTextBoxColumn^ descripcion;
		System::Windows::Forms::DataGridViewTextBoxColumn^ columObserv;

		System::Windows::Forms::DataGridViewTextBoxColumn^ materialEntrante;
		System::Windows::Forms::DataGridViewTextBoxColumn^ cantidadEntrante;
		System::Windows::Forms::DataGridViewTextBoxColumn^ columDescripIngresar;
		System::Windows::Forms::DataGridViewTextBoxColumn^ ColumObservIngresar;

	private:
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Label^ label1;
		   bool _cargandoDatos;

		System::Void materialTP_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonListado_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonCargar_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonEditar_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonGuardarEdicion_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonLimpiar_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void dataGridView1_SelectionChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void dataGridView1_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e);
		System::Void dataGridView2_EditingControlShowing(System::Object^ sender, DataGridViewEditingControlShowingEventArgs^ e);
		System::Void dataGridView2_CellValidating(System::Object^ sender, DataGridViewCellValidatingEventArgs^ e);
		System::Void dataGridView2_DataError(System::Object^ sender, DataGridViewDataErrorEventArgs^ e);
		System::Void Cantidad_KeyPress(System::Object^ sender, KeyPressEventArgs^ e);
		System::Void Texto_KeyPress(System::Object^ sender, KeyPressEventArgs^ e);

		void configurarGrids();
		void cargarMaterialesExistentes();
		void cargarFilaEnGridDerecho(int rowIndex);
		void limpiarGridDerecho();
		String^ obtenerCampo(String^ jsonItem, String^ campo);
		bool validarTexto(String^ texto);

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->columNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->stock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->descripcion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columObserv = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->materialEntrante = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cantidadEntrante = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columDescripIngresar = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumObservIngresar = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->btnGuardarEdicion = (gcnew System::Windows::Forms::Button());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->buttonListado = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
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
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1185, 638);
			this->tableLayoutPanel1->TabIndex = 0;
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
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 102);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1179, 434);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->columNombre,
					this->stock, this->descripcion, this->columObserv
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(3, 2);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(583, 430);
			this->dataGridView1->TabIndex = 0;
			// 
			// columNombre
			// 
			this->columNombre->HeaderText = L"Nombre";
			this->columNombre->MinimumWidth = 6;
			this->columNombre->Name = L"columNombre";
			this->columNombre->Width = 125;
			// 
			// stock
			// 
			this->stock->HeaderText = L"Stock";
			this->stock->MinimumWidth = 6;
			this->stock->Name = L"stock";
			this->stock->ReadOnly = true;
			this->stock->Width = 75;
			// 
			// descripcion
			// 
			this->descripcion->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->descripcion->HeaderText = L"Descripcion";
			this->descripcion->MinimumWidth = 6;
			this->descripcion->Name = L"descripcion";
			this->descripcion->ReadOnly = true;
			// 
			// columObserv
			// 
			this->columObserv->HeaderText = L"Observaciones";
			this->columObserv->MinimumWidth = 6;
			this->columObserv->Name = L"columObserv";
			this->columObserv->Width = 125;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->materialEntrante,
					this->cantidadEntrante, this->columDescripIngresar, this->ColumObservIngresar
			});
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(592, 2);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView2->MultiSelect = false;
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView2->Size = System::Drawing::Size(584, 430);
			this->dataGridView2->TabIndex = 1;
			// 
			// materialEntrante
			// 
			this->materialEntrante->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->materialEntrante->HeaderText = L"Nombre";
			this->materialEntrante->MinimumWidth = 6;
			this->materialEntrante->Name = L"materialEntrante";
			// 
			// cantidadEntrante
			// 
			this->cantidadEntrante->HeaderText = L"Cantidad a Ingresar";
			this->cantidadEntrante->MinimumWidth = 6;
			this->cantidadEntrante->Name = L"cantidadEntrante";
			this->cantidadEntrante->Width = 125;
			// 
			// columDescripIngresar
			// 
			this->columDescripIngresar->HeaderText = L"Descripcion";
			this->columDescripIngresar->MinimumWidth = 6;
			this->columDescripIngresar->Name = L"columDescripIngresar";
			this->columDescripIngresar->Width = 125;
			// 
			// ColumObservIngresar
			// 
			this->ColumObservIngresar->HeaderText = L"Observaciones";
			this->ColumObservIngresar->MinimumWidth = 6;
			this->ColumObservIngresar->Name = L"ColumObservIngresar";
			this->ColumObservIngresar->Width = 125;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 2);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1179, 96);
			this->panel1->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->btnLimpiar);
			this->panel2->Controls->Add(this->btnGuardarEdicion);
			this->panel2->Controls->Add(this->btnEditar);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->buttonListado);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(3, 540);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1179, 96);
			this->panel2->TabIndex = 2;
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->BackColor = System::Drawing::Color::Transparent;
			this->btnLimpiar->Location = System::Drawing::Point(800, 31);
			this->btnLimpiar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(173, 34);
			this->btnLimpiar->TabIndex = 4;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = false;
			// 
			// btnGuardarEdicion
			// 
			this->btnGuardarEdicion->Location = System::Drawing::Point(607, 31);
			this->btnGuardarEdicion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnGuardarEdicion->Name = L"btnGuardarEdicion";
			this->btnGuardarEdicion->Size = System::Drawing::Size(173, 34);
			this->btnGuardarEdicion->TabIndex = 3;
			this->btnGuardarEdicion->Text = L"Guardar Edicion";
			this->btnGuardarEdicion->UseVisualStyleBackColor = true;
			// 
			// btnEditar
			// 
			this->btnEditar->Location = System::Drawing::Point(413, 31);
			this->btnEditar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(173, 34);
			this->btnEditar->TabIndex = 2;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(220, 31);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(173, 34);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Cargar Material";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// buttonListado
			// 
			this->buttonListado->Location = System::Drawing::Point(27, 31);
			this->buttonListado->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->buttonListado->Name = L"buttonListado";
			this->buttonListado->Size = System::Drawing::Size(173, 34);
			this->buttonListado->TabIndex = 0;
			this->buttonListado->Text = L"Listado Existente";
			this->buttonListado->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(246, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(727, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Administracion de Materiales de los Trabajos de los Alumnos";
			// 
			// materialTP
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::NavajoWhite;
			this->ClientSize = System::Drawing::Size(1185, 638);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"materialTP";
			this->Text = L"Material TP";
			this->Load += gcnew System::EventHandler(this, &materialTP::materialTP_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}