#pragma once

namespace Panol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net; // Para WebClient
	using namespace System::Text::RegularExpressions; // Para Regex

	/// <summary>
	/// Resumen de consumibles
	/// </summary>
	public ref class consumibles : public System::Windows::Forms::Form
	{
	public:
		consumibles(void)
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
		~consumibles()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Button^ buttonIngreso;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ buttonRetiro;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: System::Windows::Forms::Button^ buttonVerStock;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Button^ buttonHistorialRetiro;
	private: System::Windows::Forms::DataGridView^ dataGridView4;








	private: System::Windows::Forms::DataGridViewTextBoxColumn^ fechaRetiro;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ materialRetiradoVer;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cantidadRetiradaVer;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nombreRetiro;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ nombreMaterial;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cantidadMaterial;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ descripcion;
	private: System::Windows::Forms::Button^ buttonNuevo;
	private: System::Windows::Forms::TextBox^ textBoxNuevo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ materialStock;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cantidadStock;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ materialRetirado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Cantidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nombreRetira;







	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

	private:

	private:
		// ... tus otras funciones ...
		System::Void buttonNuevo_Click(System::Object^ sender, System::EventArgs^ e);
		// Función para extraer datos del JSON (usando tu método de Regex)
		String^ obtenerCampo(String^ jsonItem, String^ campo);

		// Función para descargar los materiales desde el PHP al ComboBox
		void cargarMaterialesExistentes();

		System::Void buttonIngreso_Click(System::Object^ sender, System::EventArgs^ e);

		// --- EVENTOS DEL GRID ---
		// Para que el formulario cargue los datos al abrirse
		System::Void consumibles_Load(System::Object^ sender, System::EventArgs^ e);

		// Para permitir que el usuario escriba en el ComboBox del Grid
		System::Void dataGridView1_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e);

		// Para evitar que el Grid de error cuando el usuario escribe algo nuevo
		System::Void dataGridView1_DataError(System::Object^ sender, System::Windows::Forms::DataGridViewDataErrorEventArgs^ e);

		// Para formatear el texto (Mayúscula inicial) al terminar de escribir
	
		System::Void dataGridView1_CellParsing(System::Object^ sender, System::Windows::Forms::DataGridViewCellParsingEventArgs^ e);

		// Función para descargar los datos del stock
		void cargarStock();

		// Evento del botón "Ver Stock"
		System::Void buttonVerStock_Click(System::Object^ sender, System::EventArgs^ e);

		// ... tus otras funciones ...
		System::Void buttonRetiro_Click(System::Object^ sender, System::EventArgs^ e);

		// Evento para el autocompletado del Grid de Retiro
		System::Void dataGridView3_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e);

		// También es bueno agregar el DataError para evitar carteles de error si escriben mal
		System::Void dataGridView3_DataError(System::Object^ sender, System::Windows::Forms::DataGridViewDataErrorEventArgs^ e);

	
			void cargarHistorial();
			System::Void buttonHistorialRetiro_Click(System::Object^ sender, System::EventArgs^ e);


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonNuevo = (gcnew System::Windows::Forms::Button());
			this->textBoxNuevo = (gcnew System::Windows::Forms::TextBox());
			this->buttonIngreso = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->nombreMaterial = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->cantidadMaterial = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->descripcion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->buttonRetiro = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->materialRetirado = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Cantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nombreRetira = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->buttonVerStock = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->materialStock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cantidadStock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->buttonHistorialRetiro = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->fechaRetiro = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->materialRetiradoVer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cantidadRetiradaVer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nombreRetiro = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::Black;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->panel5, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel6, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel7, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel8, 1, 3);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1241, 704);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->panel1->Controls->Add(this->buttonNuevo);
			this->panel1->Controls->Add(this->textBoxNuevo);
			this->panel1->Controls->Add(this->buttonIngreso);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(614, 94);
			this->panel1->TabIndex = 0;
			// 
			// buttonNuevo
			// 
			this->buttonNuevo->Location = System::Drawing::Point(430, 53);
			this->buttonNuevo->Name = L"buttonNuevo";
			this->buttonNuevo->Size = System::Drawing::Size(160, 28);
			this->buttonNuevo->TabIndex = 3;
			this->buttonNuevo->Text = L"Crear Nuevo";
			this->buttonNuevo->UseVisualStyleBackColor = true;
			this->buttonNuevo->Click += gcnew System::EventHandler(this, &consumibles::buttonNuevo_Click);
			// 
			// textBoxNuevo
			// 
			this->textBoxNuevo->Location = System::Drawing::Point(433, 16);
			this->textBoxNuevo->Name = L"textBoxNuevo";
			this->textBoxNuevo->Size = System::Drawing::Size(158, 22);
			this->textBoxNuevo->TabIndex = 2;
			// 
			// buttonIngreso
			// 
			this->buttonIngreso->Location = System::Drawing::Point(219, 28);
			this->buttonIngreso->Name = L"buttonIngreso";
			this->buttonIngreso->Size = System::Drawing::Size(181, 45);
			this->buttonIngreso->TabIndex = 1;
			this->buttonIngreso->Text = L"Ingresar";
			this->buttonIngreso->UseVisualStyleBackColor = true;
			this->buttonIngreso->Click += gcnew System::EventHandler(this, &consumibles::buttonIngreso_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(11, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(191, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ingreso de Material";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->dataGridView1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(3, 103);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(614, 246);
			this->panel2->TabIndex = 1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->nombreMaterial,
					this->cantidadMaterial, this->descripcion
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(614, 246);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellParsing += gcnew System::Windows::Forms::DataGridViewCellParsingEventHandler(this, &consumibles::dataGridView1_CellParsing);
			this->dataGridView1->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &consumibles::dataGridView1_DataError);
			this->dataGridView1->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &consumibles::dataGridView1_EditingControlShowing);
			// 
			// nombreMaterial
			// 
			this->nombreMaterial->FillWeight = 200;
			this->nombreMaterial->HeaderText = L"Nombre Material";
			this->nombreMaterial->MinimumWidth = 6;
			this->nombreMaterial->Name = L"nombreMaterial";
			this->nombreMaterial->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->nombreMaterial->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->nombreMaterial->Width = 125;
			// 
			// cantidadMaterial
			// 
			this->cantidadMaterial->HeaderText = L"Cantidad";
			this->cantidadMaterial->MinimumWidth = 6;
			this->cantidadMaterial->Name = L"cantidadMaterial";
			this->cantidadMaterial->Width = 125;
			// 
			// descripcion
			// 
			this->descripcion->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->descripcion->HeaderText = L"Descripcion";
			this->descripcion->MinimumWidth = 6;
			this->descripcion->Name = L"descripcion";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel3->Controls->Add(this->buttonRetiro);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(3, 355);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(614, 94);
			this->panel3->TabIndex = 2;
			// 
			// buttonRetiro
			// 
			this->buttonRetiro->Location = System::Drawing::Point(300, 30);
			this->buttonRetiro->Name = L"buttonRetiro";
			this->buttonRetiro->Size = System::Drawing::Size(193, 45);
			this->buttonRetiro->TabIndex = 2;
			this->buttonRetiro->Text = L"Retirar";
			this->buttonRetiro->UseVisualStyleBackColor = true;
			this->buttonRetiro->Click += gcnew System::EventHandler(this, &consumibles::buttonRetiro_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(25, 38);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(177, 24);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Retiro de Material";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->dataGridView3);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(3, 455);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(614, 246);
			this->panel4->TabIndex = 3;
			// 
			// dataGridView3
			// 
			this->dataGridView3->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->materialRetirado,
					this->Cantidad, this->nombreRetira
			});
			this->dataGridView3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView3->Location = System::Drawing::Point(0, 0);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersWidth = 51;
			this->dataGridView3->RowTemplate->Height = 24;
			this->dataGridView3->Size = System::Drawing::Size(614, 246);
			this->dataGridView3->TabIndex = 0;
			this->dataGridView3->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &consumibles::dataGridView3_EditingControlShowing);
			// 
			// materialRetirado
			// 
			this->materialRetirado->FillWeight = 200;
			this->materialRetirado->HeaderText = L"Material Retirado";
			this->materialRetirado->MinimumWidth = 6;
			this->materialRetirado->Name = L"materialRetirado";
			this->materialRetirado->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->materialRetirado->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->materialRetirado->Width = 125;
			// 
			// Cantidad
			// 
			this->Cantidad->HeaderText = L"cantidadRetirada";
			this->Cantidad->MinimumWidth = 6;
			this->Cantidad->Name = L"Cantidad";
			this->Cantidad->Width = 125;
			// 
			// nombreRetira
			// 
			this->nombreRetira->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->nombreRetira->HeaderText = L"Quien Retira";
			this->nombreRetira->MinimumWidth = 6;
			this->nombreRetira->Name = L"nombreRetira";
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->panel5->Controls->Add(this->buttonVerStock);
			this->panel5->Controls->Add(this->label2);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(623, 3);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(615, 94);
			this->panel5->TabIndex = 4;
			// 
			// buttonVerStock
			// 
			this->buttonVerStock->Location = System::Drawing::Point(282, 27);
			this->buttonVerStock->Name = L"buttonVerStock";
			this->buttonVerStock->Size = System::Drawing::Size(193, 45);
			this->buttonVerStock->TabIndex = 4;
			this->buttonVerStock->Text = L"Ver Stock";
			this->buttonVerStock->UseVisualStyleBackColor = true;
			this->buttonVerStock->Click += gcnew System::EventHandler(this, &consumibles::buttonVerStock_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(31, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(174, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Stock de Material";
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->dataGridView2);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel6->Location = System::Drawing::Point(623, 103);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(615, 246);
			this->panel6->TabIndex = 5;
			// 
			// dataGridView2
			// 
			this->dataGridView2->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->materialStock,
					this->cantidadStock
			});
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(0, 0);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(615, 246);
			this->dataGridView2->TabIndex = 0;
			// 
			// materialStock
			// 
			this->materialStock->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->materialStock->HeaderText = L"Material";
			this->materialStock->MinimumWidth = 6;
			this->materialStock->Name = L"materialStock";
			this->materialStock->ReadOnly = true;
			this->materialStock->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// cantidadStock
			// 
			this->cantidadStock->HeaderText = L"Stock";
			this->cantidadStock->MinimumWidth = 6;
			this->cantidadStock->Name = L"cantidadStock";
			this->cantidadStock->ReadOnly = true;
			this->cantidadStock->Width = 125;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->panel7->Controls->Add(this->buttonHistorialRetiro);
			this->panel7->Controls->Add(this->label4);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel7->Location = System::Drawing::Point(623, 355);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(615, 94);
			this->panel7->TabIndex = 6;
			// 
			// buttonHistorialRetiro
			// 
			this->buttonHistorialRetiro->Location = System::Drawing::Point(282, 30);
			this->buttonHistorialRetiro->Name = L"buttonHistorialRetiro";
			this->buttonHistorialRetiro->Size = System::Drawing::Size(193, 45);
			this->buttonHistorialRetiro->TabIndex = 3;
			this->buttonHistorialRetiro->Text = L"Ver Retiros";
			this->buttonHistorialRetiro->UseVisualStyleBackColor = true;
			this->buttonHistorialRetiro->Click += gcnew System::EventHandler(this, &consumibles::buttonHistorialRetiro_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(31, 38);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Historial";
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->dataGridView4);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel8->Location = System::Drawing::Point(623, 455);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(615, 246);
			this->panel8->TabIndex = 7;
			// 
			// dataGridView4
			// 
			this->dataGridView4->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->fechaRetiro,
					this->materialRetiradoVer, this->cantidadRetiradaVer, this->nombreRetiro
			});
			this->dataGridView4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView4->Location = System::Drawing::Point(0, 0);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->RowHeadersWidth = 51;
			this->dataGridView4->RowTemplate->Height = 24;
			this->dataGridView4->Size = System::Drawing::Size(615, 246);
			this->dataGridView4->TabIndex = 0;
			// 
			// fechaRetiro
			// 
			this->fechaRetiro->HeaderText = L"Fecha";
			this->fechaRetiro->MinimumWidth = 6;
			this->fechaRetiro->Name = L"fechaRetiro";
			this->fechaRetiro->ReadOnly = true;
			this->fechaRetiro->Width = 125;
			// 
			// materialRetiradoVer
			// 
			this->materialRetiradoVer->FillWeight = 200;
			this->materialRetiradoVer->HeaderText = L"Material Retirado";
			this->materialRetiradoVer->MinimumWidth = 6;
			this->materialRetiradoVer->Name = L"materialRetiradoVer";
			this->materialRetiradoVer->ReadOnly = true;
			this->materialRetiradoVer->Width = 125;
			// 
			// cantidadRetiradaVer
			// 
			this->cantidadRetiradaVer->FillWeight = 50;
			this->cantidadRetiradaVer->HeaderText = L"Cantidad";
			this->cantidadRetiradaVer->MinimumWidth = 6;
			this->cantidadRetiradaVer->Name = L"cantidadRetiradaVer";
			this->cantidadRetiradaVer->ReadOnly = true;
			this->cantidadRetiradaVer->Width = 125;
			// 
			// nombreRetiro
			// 
			this->nombreRetiro->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->nombreRetiro->HeaderText = L"Nombre";
			this->nombreRetiro->MinimumWidth = 6;
			this->nombreRetiro->Name = L"nombreRetiro";
			this->nombreRetiro->ReadOnly = true;
			// 
			// consumibles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(1241, 704);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"consumibles";
			this->Text = L"consumibles";
			this->Load += gcnew System::EventHandler(this, &consumibles::consumibles_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel8->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
