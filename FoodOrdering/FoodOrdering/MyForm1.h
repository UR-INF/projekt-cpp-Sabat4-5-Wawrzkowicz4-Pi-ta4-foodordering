#pragma once
#include "MainForm.h"

namespace FoodOrdering {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Bunifu::UI::WinForms::BunifuButton::BunifuButton^ bunifuButton1;
	protected:
	private: Bunifu::Framework::UI::BunifuThinButton2^ bunifuThinButton21;





	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;



	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Button^ btnSingIn;
	private: System::Windows::Forms::Panel^ panel1;
	private: Bunifu::Framework::UI::BunifuMaterialTextbox^ txtPassword;
	private: Bunifu::Framework::UI::BunifuMaterialTextbox^ txtLogin;



	private: System::ComponentModel::IContainer^ components;




	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnSingIn = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtPassword = (gcnew Bunifu::Framework::UI::BunifuMaterialTextbox());
			this->txtLogin = (gcnew Bunifu::Framework::UI::BunifuMaterialTextbox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label1->Location = System::Drawing::Point(465, 162);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(204, 56);
			this->label1->TabIndex = 1;
			this->label1->Text = L" Knajpa";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(573, 232);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 44);
			this->label2->TabIndex = 2;
			this->label2->Text = L"u";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(508, 279);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(150, 44);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Wieœka";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::Crimson;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnLogin->ForeColor = System::Drawing::Color::White;
			this->btnLogin->Location = System::Drawing::Point(78, 291);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(152, 44);
			this->btnLogin->TabIndex = 2;
			this->btnLogin->Text = L"Zaloguj";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &MyForm::btnLogin_Click);
			// 
			// btnSingIn
			// 
			this->btnSingIn->BackColor = System::Drawing::Color::Crimson;
			this->btnSingIn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnSingIn->ForeColor = System::Drawing::Color::White;
			this->btnSingIn->Location = System::Drawing::Point(78, 341);
			this->btnSingIn->Name = L"btnSingIn";
			this->btnSingIn->Size = System::Drawing::Size(152, 44);
			this->btnSingIn->TabIndex = 3;
			this->btnSingIn->Text = L"Rejestracja";
			this->btnSingIn->UseVisualStyleBackColor = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel1->Controls->Add(this->txtPassword);
			this->panel1->Controls->Add(this->txtLogin);
			this->panel1->Controls->Add(this->btnSingIn);
			this->panel1->Controls->Add(this->btnLogin);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(342, 501);
			this->panel1->TabIndex = 0;
			// 
			// txtPassword
			// 
			this->txtPassword->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::None;
			this->txtPassword->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::None;
			this->txtPassword->BackColor = System::Drawing::Color::White;
			this->txtPassword->characterCasing = System::Windows::Forms::CharacterCasing::Normal;
			this->txtPassword->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->txtPassword->ForeColor = System::Drawing::Color::Gray;
			this->txtPassword->HintForeColor = System::Drawing::Color::Empty;
			this->txtPassword->HintText = L"Podaj Has³o";
			this->txtPassword->isPassword = true;
			this->txtPassword->LineFocusedColor = System::Drawing::Color::Crimson;
			this->txtPassword->LineIdleColor = System::Drawing::Color::Gray;
			this->txtPassword->LineMouseHoverColor = System::Drawing::Color::Crimson;
			this->txtPassword->LineThickness = 6;
			this->txtPassword->Location = System::Drawing::Point(31, 207);
			this->txtPassword->Margin = System::Windows::Forms::Padding(4);
			this->txtPassword->MaxLength = 32767;
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->txtPassword->Size = System::Drawing::Size(266, 48);
			this->txtPassword->TabIndex = 5;
			this->txtPassword->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			// 
			// txtLogin
			// 
			this->txtLogin->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::None;
			this->txtLogin->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::None;
			this->txtLogin->BackColor = System::Drawing::Color::White;
			this->txtLogin->characterCasing = System::Windows::Forms::CharacterCasing::Normal;
			this->txtLogin->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->txtLogin->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->txtLogin->ForeColor = System::Drawing::Color::Gray;
			this->txtLogin->HintForeColor = System::Drawing::Color::Empty;
			this->txtLogin->HintText = L"Podaj nazwê u¿ytkownika";
			this->txtLogin->isPassword = false;
			this->txtLogin->LineFocusedColor = System::Drawing::Color::Crimson;
			this->txtLogin->LineIdleColor = System::Drawing::Color::Gray;
			this->txtLogin->LineMouseHoverColor = System::Drawing::Color::Crimson;
			this->txtLogin->LineThickness = 6;
			this->txtLogin->Location = System::Drawing::Point(31, 151);
			this->txtLogin->Margin = System::Windows::Forms::Padding(4);
			this->txtLogin->MaxLength = 32767;
			this->txtLogin->Name = L"txtLogin";
			this->txtLogin->Size = System::Drawing::Size(266, 48);
			this->txtLogin->TabIndex = 4;
			this->txtLogin->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->txtLogin->OnValueChanged += gcnew System::EventHandler(this, &MyForm::txtLogin_OnValueChanged);
			// 
			// MyForm
			// 
			this->BackColor = System::Drawing::Color::Crimson;
			this->ClientSize = System::Drawing::Size(854, 501);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Tag = L"";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}


	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ constring = L"datasource=localhost;port=3306;username=root;password=admin";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDatabase = gcnew MySqlCommand("select * from foodordering.users where login='"+this->txtLogin->Text+"' and password= '"+this->txtPassword->Text+"' ;", conDatabase);
		MySqlDataReader^ myReader;
		try {
			conDatabase->Open();
			myReader = cmdDatabase->ExecuteReader();
			int count = 0;
			while (myReader->Read()){
				count = count + 1;
			}
			if (count == 1) {
				/*MessageBox::Show("Login i haslo poprawne");*/
				
				this->Hide();
				MainForm;
				MainForm^ mainform= gcnew MainForm();

				mainform->ShowDialog();

			}
			else if (count > 1) {
				MessageBox::Show("Blad logowania");
			}
			else {
				MessageBox::Show("Login lub haslo niepoprawne... Blad logowania");
			}

		}
		catch (Exception ^ ex) {
			MessageBox::Show(ex->Message);
		}
		
	}


private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtLogin_OnValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}