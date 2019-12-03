#pragma once

namespace FoodOrdering {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlLeftSide;
	protected:

	private: System::Windows::Forms::Button^ btnDania;
	private: System::Windows::Forms::Panel^ pnlTopSide;




	private: System::Windows::Forms::Label^ logoLabel;
	private: System::Windows::Forms::Panel^ pnlOnButtonPosition;


	private: System::Windows::Forms::Button^ btnDesery;

	private: System::Windows::Forms::Button^ btnNapoje;


	private: System::Windows::Forms::Button^ btnO_nas;

	private: System::Windows::Forms::Button^ btnPrzekaski;


	private: System::Windows::Forms::Panel^ pnlDania;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ pnlNapoje;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ pnlDesery;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ pnlPrzekaski;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ pnlO_nas;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Button^ btnZamowienie;
	private: System::Windows::Forms::Panel^ pnlZamowienie;
	private: System::Windows::Forms::Button^ button6;









	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->pnlLeftSide = (gcnew System::Windows::Forms::Panel());
			this->btnZamowienie = (gcnew System::Windows::Forms::Button());
			this->pnlOnButtonPosition = (gcnew System::Windows::Forms::Panel());
			this->btnDania = (gcnew System::Windows::Forms::Button());
			this->btnO_nas = (gcnew System::Windows::Forms::Button());
			this->btnPrzekaski = (gcnew System::Windows::Forms::Button());
			this->btnDesery = (gcnew System::Windows::Forms::Button());
			this->btnNapoje = (gcnew System::Windows::Forms::Button());
			this->logoLabel = (gcnew System::Windows::Forms::Label());
			this->pnlTopSide = (gcnew System::Windows::Forms::Panel());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->pnlDania = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pnlNapoje = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pnlDesery = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pnlPrzekaski = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pnlO_nas = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->pnlZamowienie = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->pnlLeftSide->SuspendLayout();
			this->pnlTopSide->SuspendLayout();
			this->pnlDania->SuspendLayout();
			this->pnlNapoje->SuspendLayout();
			this->pnlDesery->SuspendLayout();
			this->pnlPrzekaski->SuspendLayout();
			this->pnlO_nas->SuspendLayout();
			this->pnlZamowienie->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlLeftSide
			// 
			this->pnlLeftSide->BackColor = System::Drawing::Color::Crimson;
			this->pnlLeftSide->Controls->Add(this->pnlOnButtonPosition);
			this->pnlLeftSide->Controls->Add(this->btnDania);
			this->pnlLeftSide->Controls->Add(this->btnO_nas);
			this->pnlLeftSide->Controls->Add(this->btnPrzekaski);
			this->pnlLeftSide->Controls->Add(this->btnDesery);
			this->pnlLeftSide->Controls->Add(this->btnNapoje);
			this->pnlLeftSide->Controls->Add(this->logoLabel);
			this->pnlLeftSide->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlLeftSide->Location = System::Drawing::Point(0, 0);
			this->pnlLeftSide->Name = L"pnlLeftSide";
			this->pnlLeftSide->Size = System::Drawing::Size(200, 498);
			this->pnlLeftSide->TabIndex = 0;
			this->pnlLeftSide->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panel1_Paint);
			// 
			// btnZamowienie
			// 
			this->btnZamowienie->FlatAppearance->BorderSize = 0;
			this->btnZamowienie->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnZamowienie->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnZamowienie->Font = (gcnew System::Drawing::Font(L"Cooper Black", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnZamowienie->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnZamowienie->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnZamowienie.Image")));
			this->btnZamowienie->Location = System::Drawing::Point(182, 0);
			this->btnZamowienie->Name = L"btnZamowienie";
			this->btnZamowienie->Size = System::Drawing::Size(284, 44);
			this->btnZamowienie->TabIndex = 10;
			this->btnZamowienie->Text = L"Twoje zamówienie";
			this->btnZamowienie->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnZamowienie->UseVisualStyleBackColor = true;
			this->btnZamowienie->Click += gcnew System::EventHandler(this, &MainForm::button6_Click_2);
			// 
			// pnlOnButtonPosition
			// 
			this->pnlOnButtonPosition->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->pnlOnButtonPosition->Location = System::Drawing::Point(1, 135);
			this->pnlOnButtonPosition->Name = L"pnlOnButtonPosition";
			this->pnlOnButtonPosition->Size = System::Drawing::Size(12, 44);
			this->pnlOnButtonPosition->TabIndex = 2;
			this->pnlOnButtonPosition->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pnlOnButtonPosition_Paint);
			// 
			// btnDania
			// 
			this->btnDania->FlatAppearance->BorderSize = 0;
			this->btnDania->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnDania->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDania->Font = (gcnew System::Drawing::Font(L"Cooper Black", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDania->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnDania->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDania.Image")));
			this->btnDania->Location = System::Drawing::Point(1, 135);
			this->btnDania->Name = L"btnDania";
			this->btnDania->Size = System::Drawing::Size(200, 44);
			this->btnDania->TabIndex = 0;
			this->btnDania->Text = L"Dania";
			this->btnDania->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnDania->UseVisualStyleBackColor = true;
			this->btnDania->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// btnO_nas
			// 
			this->btnO_nas->FlatAppearance->BorderSize = 0;
			this->btnO_nas->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnO_nas->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnO_nas->Font = (gcnew System::Drawing::Font(L"Cooper Black", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnO_nas->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnO_nas->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnO_nas.Image")));
			this->btnO_nas->Location = System::Drawing::Point(0, 421);
			this->btnO_nas->Name = L"btnO_nas";
			this->btnO_nas->Size = System::Drawing::Size(200, 44);
			this->btnO_nas->TabIndex = 9;
			this->btnO_nas->Text = L" O nas";
			this->btnO_nas->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnO_nas->UseVisualStyleBackColor = true;
			this->btnO_nas->Click += gcnew System::EventHandler(this, &MainForm::btnO_nas_Click);
			// 
			// btnPrzekaski
			// 
			this->btnPrzekaski->FlatAppearance->BorderSize = 0;
			this->btnPrzekaski->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnPrzekaski->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPrzekaski->Font = (gcnew System::Drawing::Font(L"Cooper Black", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPrzekaski->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnPrzekaski->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPrzekaski.Image")));
			this->btnPrzekaski->Location = System::Drawing::Point(0, 235);
			this->btnPrzekaski->Name = L"btnPrzekaski";
			this->btnPrzekaski->Size = System::Drawing::Size(200, 44);
			this->btnPrzekaski->TabIndex = 7;
			this->btnPrzekaski->Text = L"Przekaski";
			this->btnPrzekaski->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnPrzekaski->UseVisualStyleBackColor = true;
			this->btnPrzekaski->Click += gcnew System::EventHandler(this, &MainForm::btnPrzekaski_Click);
			// 
			// btnDesery
			// 
			this->btnDesery->FlatAppearance->BorderSize = 0;
			this->btnDesery->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnDesery->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDesery->Font = (gcnew System::Drawing::Font(L"Cooper Black", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDesery->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnDesery->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDesery.Image")));
			this->btnDesery->Location = System::Drawing::Point(0, 285);
			this->btnDesery->Name = L"btnDesery";
			this->btnDesery->Size = System::Drawing::Size(200, 44);
			this->btnDesery->TabIndex = 5;
			this->btnDesery->Text = L"Desery";
			this->btnDesery->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnDesery->UseVisualStyleBackColor = true;
			this->btnDesery->Click += gcnew System::EventHandler(this, &MainForm::btnDesery_Click);
			// 
			// btnNapoje
			// 
			this->btnNapoje->FlatAppearance->BorderSize = 0;
			this->btnNapoje->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnNapoje->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNapoje->Font = (gcnew System::Drawing::Font(L"Cooper Black", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNapoje->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnNapoje->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNapoje.Image")));
			this->btnNapoje->Location = System::Drawing::Point(1, 185);
			this->btnNapoje->Name = L"btnNapoje";
			this->btnNapoje->Size = System::Drawing::Size(200, 44);
			this->btnNapoje->TabIndex = 4;
			this->btnNapoje->Text = L"Napoje";
			this->btnNapoje->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnNapoje->UseVisualStyleBackColor = true;
			this->btnNapoje->Click += gcnew System::EventHandler(this, &MainForm::btnNapoje_Click);
			// 
			// logoLabel
			// 
			this->logoLabel->AutoSize = true;
			this->logoLabel->Font = (gcnew System::Drawing::Font(L"Wide Latin", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logoLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->logoLabel->Location = System::Drawing::Point(35, 27);
			this->logoLabel->Name = L"logoLabel";
			this->logoLabel->Size = System::Drawing::Size(135, 69);
			this->logoLabel->TabIndex = 3;
			this->logoLabel->Text = L"Knajpa \r\n       u \r\nWieœka";
			this->logoLabel->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// pnlTopSide
			// 
			this->pnlTopSide->BackColor = System::Drawing::Color::Crimson;
			this->pnlTopSide->Controls->Add(this->btnZamowienie);
			this->pnlTopSide->Controls->Add(this->btnClose);
			this->pnlTopSide->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlTopSide->Location = System::Drawing::Point(200, 0);
			this->pnlTopSide->Name = L"pnlTopSide";
			this->pnlTopSide->Size = System::Drawing::Size(683, 45);
			this->pnlTopSide->TabIndex = 1;
			// 
			// btnClose
			// 
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClose->ForeColor = System::Drawing::Color::Crimson;
			this->btnClose->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClose.Image")));
			this->btnClose->Location = System::Drawing::Point(633, 0);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(50, 52);
			this->btnClose->TabIndex = 13;
			this->btnClose->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btnClose->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &MainForm::button6_Click_1);
			// 
			// pnlDania
			// 
			this->pnlDania->Controls->Add(this->button1);
			this->pnlDania->Location = System::Drawing::Point(200, 51);
			this->pnlDania->Name = L"pnlDania";
			this->pnlDania->Size = System::Drawing::Size(683, 447);
			this->pnlDania->TabIndex = 2;
			this->pnlDania->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pnlDania_Paint);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(182, 151);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(313, 94);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Dania";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click_1);
			// 
			// pnlNapoje
			// 
			this->pnlNapoje->Controls->Add(this->button2);
			this->pnlNapoje->Location = System::Drawing::Point(200, 51);
			this->pnlNapoje->Name = L"pnlNapoje";
			this->pnlNapoje->Size = System::Drawing::Size(683, 447);
			this->pnlNapoje->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(182, 151);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(313, 94);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Napoje";
			this->button2->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// pnlDesery
			// 
			this->pnlDesery->Controls->Add(this->button3);
			this->pnlDesery->Location = System::Drawing::Point(200, 51);
			this->pnlDesery->Name = L"pnlDesery";
			this->pnlDesery->Size = System::Drawing::Size(683, 447);
			this->pnlDesery->TabIndex = 4;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(182, 151);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(313, 94);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Desery";
			this->button3->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button3->UseVisualStyleBackColor = true;
			// 
			// pnlPrzekaski
			// 
			this->pnlPrzekaski->Controls->Add(this->button4);
			this->pnlPrzekaski->Location = System::Drawing::Point(200, 48);
			this->pnlPrzekaski->Name = L"pnlPrzekaski";
			this->pnlPrzekaski->Size = System::Drawing::Size(683, 447);
			this->pnlPrzekaski->TabIndex = 4;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(182, 151);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(313, 94);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Przekaski";
			this->button4->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button4->UseVisualStyleBackColor = true;
			// 
			// pnlO_nas
			// 
			this->pnlO_nas->Controls->Add(this->button5);
			this->pnlO_nas->Location = System::Drawing::Point(200, 51);
			this->pnlO_nas->Name = L"pnlO_nas";
			this->pnlO_nas->Size = System::Drawing::Size(683, 447);
			this->pnlO_nas->TabIndex = 5;
			this->pnlO_nas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pnlO_nas_Paint);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(182, 151);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(313, 94);
			this->button5->TabIndex = 0;
			this->button5->Text = L"O nas";
			this->button5->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button5->UseVisualStyleBackColor = true;
			// 
			// pnlZamowienie
			// 
			this->pnlZamowienie->Controls->Add(this->button6);
			this->pnlZamowienie->Location = System::Drawing::Point(200, 45);
			this->pnlZamowienie->Name = L"pnlZamowienie";
			this->pnlZamowienie->Size = System::Drawing::Size(683, 447);
			this->pnlZamowienie->TabIndex = 3;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(182, 151);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(313, 94);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Zamówienie";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(883, 498);
			this->Controls->Add(this->pnlZamowienie);
			this->Controls->Add(this->pnlO_nas);
			this->Controls->Add(this->pnlPrzekaski);
			this->Controls->Add(this->pnlDesery);
			this->Controls->Add(this->pnlNapoje);
			this->Controls->Add(this->pnlDania);
			this->Controls->Add(this->pnlTopSide);
			this->Controls->Add(this->pnlLeftSide);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Tag = L"mainFram";
			this->Text = L"MainForm";
			this->pnlLeftSide->ResumeLayout(false);
			this->pnlLeftSide->PerformLayout();
			this->pnlTopSide->ResumeLayout(false);
			this->pnlDania->ResumeLayout(false);
			this->pnlNapoje->ResumeLayout(false);
			this->pnlDesery->ResumeLayout(false);
			this->pnlPrzekaski->ResumeLayout(false);
			this->pnlO_nas->ResumeLayout(false);
			this->pnlZamowienie->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void btnDania_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pnlDania_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
		pnlOnButtonPosition->Height = btnDania->Height;
		pnlOnButtonPosition->Top = btnDania->Top;
		pnlDania->Visible = true;
		pnlNapoje->Visible = false;
		pnlDesery->Visible = false;
		pnlPrzekaski->Visible = false;
		pnlO_nas->Visible = false;
		pnlZamowienie->Visible = false;
}
private: System::Void btnNapoje_Click(System::Object^ sender, System::EventArgs^ e) {
		pnlOnButtonPosition->Height = btnNapoje->Height;
		pnlOnButtonPosition->Top = btnNapoje->Top;
		pnlDania->Visible = false;
		pnlNapoje->Visible = true;
		pnlDesery->Visible = false;
		pnlPrzekaski->Visible = false;
		pnlO_nas->Visible = false;
		pnlZamowienie->Visible = false;
}
private: System::Void btnDesery_Click(System::Object^ sender, System::EventArgs^ e) {

	pnlOnButtonPosition->Height = btnDesery->Height;
	pnlOnButtonPosition->Top = btnDesery->Top;
	pnlDania->Visible = false;
	pnlNapoje->Visible = false;
	pnlDesery->Visible = true;
	pnlPrzekaski->Visible = false;
	pnlO_nas->Visible = false;
	pnlZamowienie->Visible = false;
}
private: System::Void btnPrzekaski_Click(System::Object^ sender, System::EventArgs^ e) {

	pnlOnButtonPosition->Height = btnPrzekaski->Height;
	pnlOnButtonPosition->Top = btnPrzekaski->Top;
	pnlDania->Visible = false;
	pnlNapoje->Visible = false;
	pnlDesery->Visible = false;
	pnlPrzekaski->Visible = true;
	pnlO_nas->Visible = false;
	pnlZamowienie->Visible = false;

}
private: System::Void btnO_nas_Click(System::Object^ sender, System::EventArgs^ e) {

	pnlOnButtonPosition->Height = btnO_nas->Height;
	pnlOnButtonPosition->Top = btnO_nas->Top;
	pnlDania->Visible = false;
	pnlNapoje->Visible = false;
	pnlDesery->Visible = false;
	pnlPrzekaski->Visible = false;
	pnlO_nas->Visible = true;
	pnlZamowienie->Visible = false;

}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void button6_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pnlO_nas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button6_Click_2(System::Object^ sender, System::EventArgs^ e) {

	pnlOnButtonPosition->Visible = false;
	pnlDania->Visible = false;
	pnlNapoje->Visible = false;
	pnlDesery->Visible = false;
	pnlPrzekaski->Visible = false;
	pnlO_nas->Visible = false;
	pnlZamowienie->Visible = true;
	
}
private: System::Void pnlOnButtonPosition_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
