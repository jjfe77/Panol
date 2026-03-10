#pragma once

namespace Panol {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Collections::Specialized;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Resumen de presupuestos
	/// </summary>
	public ref class presupuestos : public System::Windows::Forms::Form
	{
	public:
		presupuestos(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->Load += gcnew System::EventHandler(this, &presupuestos::presupuestos_Load);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~presupuestos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridViewPresupuestos;
	private: System::Windows::Forms::DataGridView^ dataGridViewCompras;




	private: System::Windows::Forms::Button^ buttonGenerarCompra;
	private: System::Windows::Forms::TextBox^ textBoxTotal;



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ elemento;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cantidadComprar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ precioP1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ precioP2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ precioP3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ observaciones;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ elementoElegido;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cantidadSolicitada;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ precioUnitario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ precioItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ proveedorSeleccionado;
	private: System::Windows::Forms::Button^ buttonNuevoProovedor;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBoxProv3;
	private: System::Windows::Forms::ComboBox^ comboBoxProv2;
	private: System::Windows::Forms::ComboBox^ comboBoxProv1;
	private: System::Windows::Forms::TextBox^ textBoxProovedorNuevo;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::ComboBox^ cmbCargasAnteriores;
	private: System::Windows::Forms::TextBox^ txtNombreCarga;
	private: System::Windows::Forms::Button^ btnNuevoPresupuesto;

	private: System::Windows::Forms::Button^ btnGuardarBorrador;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;




	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBoxProovedorNuevo = (gcnew System::Windows::Forms::TextBox());
			this->buttonNuevoProovedor = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridViewPresupuestos = (gcnew System::Windows::Forms::DataGridView());
			this->elemento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cantidadComprar = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->precioP1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->precioP2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->precioP3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->observaciones = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBoxProv3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxProv2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxProv1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->dataGridViewCompras = (gcnew System::Windows::Forms::DataGridView());
			this->elementoElegido = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cantidadSolicitada = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->precioUnitario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->precioItem = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->proveedorSeleccionado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonGenerarCompra = (gcnew System::Windows::Forms::Button());
			this->textBoxTotal = (gcnew System::Windows::Forms::TextBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtNombreCarga = (gcnew System::Windows::Forms::TextBox());
			this->cmbCargasAnteriores = (gcnew System::Windows::Forms::ComboBox());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->btnNuevoPresupuesto = (gcnew System::Windows::Forms::Button());
			this->btnGuardarBorrador = (gcnew System::Windows::Forms::Button());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPresupuestos))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCompras))->BeginInit();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				75)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->panel5, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->panel6, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel7, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel8, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel9, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->panel10, 1, 4);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 80)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 170)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1075, 729);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::SteelBlue;
			this->panel1->Controls->Add(this->textBoxProovedorNuevo);
			this->panel1->Controls->Add(this->buttonNuevoProovedor);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(800, 74);
			this->panel1->TabIndex = 0;
			// 
			// textBoxProovedorNuevo
			// 
			this->textBoxProovedorNuevo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBoxProovedorNuevo->Location = System::Drawing::Point(328, 23);
			this->textBoxProovedorNuevo->Name = L"textBoxProovedorNuevo";
			this->textBoxProovedorNuevo->Size = System::Drawing::Size(255, 30);
			this->textBoxProovedorNuevo->TabIndex = 4;
			// 
			// buttonNuevoProovedor
			// 
			this->buttonNuevoProovedor->Location = System::Drawing::Point(602, 22);
			this->buttonNuevoProovedor->Name = L"buttonNuevoProovedor";
			this->buttonNuevoProovedor->Size = System::Drawing::Size(178, 38);
			this->buttonNuevoProovedor->TabIndex = 3;
			this->buttonNuevoProovedor->Text = L"Agregar Proveedor Nuevo";
			this->buttonNuevoProovedor->UseVisualStyleBackColor = true;
			this->buttonNuevoProovedor->Click += gcnew System::EventHandler(this, &presupuestos::buttonNuevoProovedor_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(9, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(299, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Presupuestos y compras";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->dataGridViewPresupuestos);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(3, 83);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(800, 183);
			this->panel2->TabIndex = 1;
			// 
			// dataGridViewPresupuestos
			// 
			this->dataGridViewPresupuestos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewPresupuestos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->elemento,
					this->cantidadComprar, this->precioP1, this->precioP2, this->precioP3, this->observaciones
			});
			this->dataGridViewPresupuestos->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridViewPresupuestos->Location = System::Drawing::Point(0, 0);
			this->dataGridViewPresupuestos->Name = L"dataGridViewPresupuestos";
			this->dataGridViewPresupuestos->RowHeadersWidth = 51;
			this->dataGridViewPresupuestos->RowTemplate->Height = 24;
			this->dataGridViewPresupuestos->Size = System::Drawing::Size(800, 183);
			this->dataGridViewPresupuestos->TabIndex = 0;
			// 
			// elemento
			// 
			this->elemento->HeaderText = L"Elemento a Comprar";
			this->elemento->MinimumWidth = 6;
			this->elemento->Name = L"elemento";
			this->elemento->Width = 250;
			// 
			// cantidadComprar
			// 
			this->cantidadComprar->HeaderText = L"Cantidad";
			this->cantidadComprar->MinimumWidth = 6;
			this->cantidadComprar->Name = L"cantidadComprar";
			this->cantidadComprar->Width = 125;
			// 
			// precioP1
			// 
			this->precioP1->HeaderText = L"Precio Prov 3";
			this->precioP1->MinimumWidth = 6;
			this->precioP1->Name = L"precioP1";
			this->precioP1->Width = 125;
			// 
			// precioP2
			// 
			this->precioP2->HeaderText = L"Precio Prov 2";
			this->precioP2->MinimumWidth = 6;
			this->precioP2->Name = L"precioP2";
			this->precioP2->Width = 125;
			// 
			// precioP3
			// 
			this->precioP3->HeaderText = L"Precio Prov 3";
			this->precioP3->MinimumWidth = 6;
			this->precioP3->Name = L"precioP3";
			this->precioP3->Width = 125;
			// 
			// observaciones
			// 
			this->observaciones->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->observaciones->HeaderText = L"Observaciones";
			this->observaciones->MinimumWidth = 6;
			this->observaciones->Name = L"observaciones";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::SteelBlue;
			this->panel3->Controls->Add(this->label5);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->comboBoxProv3);
			this->panel3->Controls->Add(this->comboBoxProv2);
			this->panel3->Controls->Add(this->comboBoxProv1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(3, 272);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(800, 164);
			this->panel3->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(292, 113);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(118, 25);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Proveedor 3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(292, 63);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(118, 25);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Proveedor 2";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(292, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(118, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Proveedor 1";
			// 
			// comboBoxProv3
			// 
			this->comboBoxProv3->FormattingEnabled = true;
			this->comboBoxProv3->Location = System::Drawing::Point(52, 113);
			this->comboBoxProv3->Name = L"comboBoxProv3";
			this->comboBoxProv3->Size = System::Drawing::Size(225, 24);
			this->comboBoxProv3->TabIndex = 2;
			this->comboBoxProv3->SelectedIndexChanged += gcnew System::EventHandler(this, &presupuestos::validarProveedoresDiferentes);
			// 
			// comboBoxProv2
			// 
			this->comboBoxProv2->FormattingEnabled = true;
			this->comboBoxProv2->Location = System::Drawing::Point(52, 63);
			this->comboBoxProv2->Name = L"comboBoxProv2";
			this->comboBoxProv2->Size = System::Drawing::Size(225, 24);
			this->comboBoxProv2->TabIndex = 1;
			this->comboBoxProv2->SelectedIndexChanged += gcnew System::EventHandler(this, &presupuestos::validarProveedoresDiferentes);
			// 
			// comboBoxProv1
			// 
			this->comboBoxProv1->FormattingEnabled = true;
			this->comboBoxProv1->Location = System::Drawing::Point(52, 20);
			this->comboBoxProv1->Name = L"comboBoxProv1";
			this->comboBoxProv1->Size = System::Drawing::Size(225, 24);
			this->comboBoxProv1->TabIndex = 0;
			this->comboBoxProv1->SelectedIndexChanged += gcnew System::EventHandler(this, &presupuestos::validarProveedoresDiferentes);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->dataGridViewCompras);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(3, 442);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(800, 183);
			this->panel4->TabIndex = 3;
			// 
			// dataGridViewCompras
			// 
			this->dataGridViewCompras->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewCompras->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->elementoElegido,
					this->cantidadSolicitada, this->precioUnitario, this->precioItem, this->proveedorSeleccionado
			});
			this->dataGridViewCompras->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridViewCompras->Location = System::Drawing::Point(0, 0);
			this->dataGridViewCompras->Name = L"dataGridViewCompras";
			this->dataGridViewCompras->RowHeadersWidth = 51;
			this->dataGridViewCompras->RowTemplate->Height = 24;
			this->dataGridViewCompras->Size = System::Drawing::Size(800, 183);
			this->dataGridViewCompras->TabIndex = 0;
			// 
			// elementoElegido
			// 
			this->elementoElegido->HeaderText = L"Elemento a Comprar";
			this->elementoElegido->MinimumWidth = 6;
			this->elementoElegido->Name = L"elementoElegido";
			this->elementoElegido->ReadOnly = true;
			this->elementoElegido->Width = 250;
			// 
			// cantidadSolicitada
			// 
			this->cantidadSolicitada->HeaderText = L"Cantidad";
			this->cantidadSolicitada->MinimumWidth = 6;
			this->cantidadSolicitada->Name = L"cantidadSolicitada";
			this->cantidadSolicitada->ReadOnly = true;
			this->cantidadSolicitada->Width = 125;
			// 
			// precioUnitario
			// 
			this->precioUnitario->HeaderText = L"Precio Unitario";
			this->precioUnitario->MinimumWidth = 6;
			this->precioUnitario->Name = L"precioUnitario";
			this->precioUnitario->ReadOnly = true;
			this->precioUnitario->Width = 125;
			// 
			// precioItem
			// 
			this->precioItem->HeaderText = L"Precio Compra";
			this->precioItem->MinimumWidth = 6;
			this->precioItem->Name = L"precioItem";
			this->precioItem->ReadOnly = true;
			this->precioItem->Width = 125;
			// 
			// proveedorSeleccionado
			// 
			this->proveedorSeleccionado->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->proveedorSeleccionado->HeaderText = L"Proveedor Seleccionado";
			this->proveedorSeleccionado->MinimumWidth = 6;
			this->proveedorSeleccionado->Name = L"proveedorSeleccionado";
			this->proveedorSeleccionado->ReadOnly = true;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::SteelBlue;
			this->panel5->Controls->Add(this->label3);
			this->panel5->Controls->Add(this->buttonGenerarCompra);
			this->panel5->Controls->Add(this->textBoxTotal);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(3, 631);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(800, 95);
			this->panel5->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(445, 37);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(124, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Costo Total";
			// 
			// buttonGenerarCompra
			// 
			this->buttonGenerarCompra->Location = System::Drawing::Point(52, 21);
			this->buttonGenerarCompra->Name = L"buttonGenerarCompra";
			this->buttonGenerarCompra->Size = System::Drawing::Size(244, 44);
			this->buttonGenerarCompra->TabIndex = 1;
			this->buttonGenerarCompra->Text = L"Generar Listado de Compras";
			this->buttonGenerarCompra->UseVisualStyleBackColor = true;
			this->buttonGenerarCompra->Click += gcnew System::EventHandler(this, &presupuestos::buttonGenerarCompra_Click);
			// 
			// textBoxTotal
			// 
			this->textBoxTotal->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBoxTotal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxTotal->Location = System::Drawing::Point(591, 31);
			this->textBoxTotal->Name = L"textBoxTotal";
			this->textBoxTotal->Size = System::Drawing::Size(170, 34);
			this->textBoxTotal->TabIndex = 0;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->dateTimePicker1);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel6->Location = System::Drawing::Point(809, 3);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(263, 74);
			this->panel6->TabIndex = 5;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->dateTimePicker1->Location = System::Drawing::Point(36, 28);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 22);
			this->dateTimePicker1->TabIndex = 0;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::SteelBlue;
			this->panel7->Controls->Add(this->label7);
			this->panel7->Controls->Add(this->label6);
			this->panel7->Controls->Add(this->txtNombreCarga);
			this->panel7->Controls->Add(this->cmbCargasAnteriores);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel7->Location = System::Drawing::Point(809, 83);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(263, 183);
			this->panel7->TabIndex = 6;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(34, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(170, 25);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Cargas Anteriores";
			// 
			// txtNombreCarga
			// 
			this->txtNombreCarga->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->txtNombreCarga->Location = System::Drawing::Point(28, 109);
			this->txtNombreCarga->Name = L"txtNombreCarga";
			this->txtNombreCarga->Size = System::Drawing::Size(208, 22);
			this->txtNombreCarga->TabIndex = 1;
			// 
			// cmbCargasAnteriores
			// 
			this->cmbCargasAnteriores->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->cmbCargasAnteriores->FormattingEnabled = true;
			this->cmbCargasAnteriores->Location = System::Drawing::Point(28, 29);
			this->cmbCargasAnteriores->Name = L"cmbCargasAnteriores";
			this->cmbCargasAnteriores->Size = System::Drawing::Size(207, 24);
			this->cmbCargasAnteriores->TabIndex = 0;
			this->cmbCargasAnteriores->SelectedIndexChanged += gcnew System::EventHandler(this, &presupuestos::cmbCargasAnteriores_SelectedIndexChanged);
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::SteelBlue;
			this->panel8->Controls->Add(this->btnNuevoPresupuesto);
			this->panel8->Controls->Add(this->btnGuardarBorrador);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel8->Location = System::Drawing::Point(809, 272);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(263, 164);
			this->panel8->TabIndex = 7;
			// 
			// btnNuevoPresupuesto
			// 
			this->btnNuevoPresupuesto->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->btnNuevoPresupuesto->Location = System::Drawing::Point(40, 91);
			this->btnNuevoPresupuesto->Name = L"btnNuevoPresupuesto";
			this->btnNuevoPresupuesto->Size = System::Drawing::Size(184, 46);
			this->btnNuevoPresupuesto->TabIndex = 1;
			this->btnNuevoPresupuesto->Text = L"Limpiar / Nuevo";
			this->btnNuevoPresupuesto->UseVisualStyleBackColor = true;
			this->btnNuevoPresupuesto->Click += gcnew System::EventHandler(this, &presupuestos::btnNuevoPresupuesto_Click);
			// 
			// btnGuardarBorrador
			// 
			this->btnGuardarBorrador->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->btnGuardarBorrador->Location = System::Drawing::Point(40, 26);
			this->btnGuardarBorrador->Name = L"btnGuardarBorrador";
			this->btnGuardarBorrador->Size = System::Drawing::Size(184, 46);
			this->btnGuardarBorrador->TabIndex = 0;
			this->btnGuardarBorrador->Text = L"Guardar Avance";
			this->btnGuardarBorrador->UseVisualStyleBackColor = true;
			this->btnGuardarBorrador->Click += gcnew System::EventHandler(this, &presupuestos::btnGuardarBorrador_Click);
			// 
			// panel9
			// 
			this->panel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel9->Location = System::Drawing::Point(809, 442);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(263, 183);
			this->panel9->TabIndex = 8;
			// 
			// panel10
			// 
			this->panel10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel10->Location = System::Drawing::Point(809, 631);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(263, 95);
			this->panel10->TabIndex = 9;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(34, 146);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(140, 25);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Nombre Carga";
			// 
			// presupuestos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(1075, 729);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"presupuestos";
			this->Text = L"presupuestos";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPresupuestos))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCompras))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	/* 
	private:
		// Función para procesar la respuesta JSON del PHP
		System::String^ obtenerCampo(System::String^ jsonItem, System::String^ campo);

		// Función para cargar los proveedores en los 3 ComboBox
		void cargarProveedores();

		// Evento del botón para agregar nuevo proveedor
		System::Void buttonNuevoProovedor_Click(System::Object^ sender, System::EventArgs^ e);

		// 4. Evento Load del formulario
		System::Void Panol::presupuestos::presupuestos_Load(System::Object^ sender, System::EventArgs^ e) {
			cargarProveedores();
			cargarCargasAnteriores();
		}

	private:
		System::Void validarProveedoresDiferentes(System::Object^ sender, System::EventArgs^ e);

	private:
		int idPresupuestoActual = 0; // 0 significa nuevo, >0 significa editando uno existente

		// Funciones para los nuevos botones
		System::Void btnGuardarBorrador_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnNuevoPresupuesto_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void cmbCargasAnteriores_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonGenerarCompra_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private:
		// Llena el ComboBox de cargas guardadas
		void cargarCargasAnteriores();


		// Nueva función auxiliar para parsear números (ID, Cantidad, Precio)
		String^ obtenerCampoNum(String^ jsonItem, String^ campo);

		*/



	private:

		int idPresupuestoActual = 0;

		bool flagCargando = false;
		// Estas son las ÚNICAS declaraciones que deben quedar en el .h
		System::Void presupuestos_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void btnGuardarBorrador_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnNuevoPresupuesto_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonNuevoProovedor_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void validarProveedoresDiferentes(System::Object^ sender, System::EventArgs^ e);
		System::Void cmbCargasAnteriores_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonGenerarCompra_Click(System::Object^ sender, System::EventArgs^ e);

		// Funciones auxiliares
		void cargarProveedores();
		void cargarCargasAnteriores();
		System::String^ obtenerCampo(System::String^ jsonItem, System::String^ campo);
		System::String^ obtenerCampoNum(System::String^ jsonItem, System::String^ campo);
	};
}


