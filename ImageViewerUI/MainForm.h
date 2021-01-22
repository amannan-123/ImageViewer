#include "CircularList.h"
#include <string>

#pragma once

namespace ImageViewerUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace System::IO;
	
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: MyControls::MyPanel^  myPanel1;
	private: MyControls::MyButton^  bPrev;
	private: MyControls::MyButton^  bNext;
	protected:


	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: MyControls::MyButton^  dImport;

	private: MyControls::MyButton^  dLoad;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: MyControls::MyButton^  fImport;

	private: MyControls::MyButton^  fLoad;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label2;
	private: MyControls::MyButton^  bRemove;
	private: MyControls::MyButton^  myButton1;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->myPanel1 = (gcnew MyControls::MyPanel());
			this->myButton1 = (gcnew MyControls::MyButton());
			this->bRemove = (gcnew MyControls::MyButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->fImport = (gcnew MyControls::MyButton());
			this->fLoad = (gcnew MyControls::MyButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->dImport = (gcnew MyControls::MyButton());
			this->dLoad = (gcnew MyControls::MyButton());
			this->bPrev = (gcnew MyControls::MyButton());
			this->bNext = (gcnew MyControls::MyButton());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->myPanel1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// myPanel1
			// 
			this->myPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->myPanel1->Controls->Add(this->myButton1);
			this->myPanel1->Controls->Add(this->bRemove);
			this->myPanel1->Controls->Add(this->label2);
			this->myPanel1->Controls->Add(this->label1);
			this->myPanel1->Controls->Add(this->comboBox1);
			this->myPanel1->Controls->Add(this->groupBox2);
			this->myPanel1->Controls->Add(this->groupBox1);
			this->myPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->myPanel1->Location = System::Drawing::Point(0, 0);
			this->myPanel1->Name = L"myPanel1";
			this->myPanel1->Size = System::Drawing::Size(1366, 70);
			this->myPanel1->TabIndex = 0;
			// 
			// myButton1
			// 
			this->myButton1->BackColor = System::Drawing::Color::Black;
			this->myButton1->ForeColor = System::Drawing::Color::White;
			this->myButton1->Location = System::Drawing::Point(711, 23);
			this->myButton1->MyText = L"Clear";
			this->myButton1->Name = L"myButton1";
			this->myButton1->Size = System::Drawing::Size(80, 29);
			this->myButton1->TabIndex = 6;
			this->myButton1->Click += gcnew System::EventHandler(this, &MainForm::myButton1_Click);
			// 
			// bRemove
			// 
			this->bRemove->BackColor = System::Drawing::Color::Black;
			this->bRemove->ForeColor = System::Drawing::Color::White;
			this->bRemove->Location = System::Drawing::Point(625, 23);
			this->bRemove->MyText = L"Remove";
			this->bRemove->Name = L"bRemove";
			this->bRemove->Size = System::Drawing::Size(80, 29);
			this->bRemove->TabIndex = 5;
			this->bRemove->Click += gcnew System::EventHandler(this, &MainForm::bRemove_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(885, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 21);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Count";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(353, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 21);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Size Mode:";
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.35F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(444, 23);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(150, 29);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox1_SelectedIndexChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->groupBox2->Controls->Add(this->fImport);
			this->groupBox2->Controls->Add(this->fLoad);
			this->groupBox2->ForeColor = System::Drawing::Color::White;
			this->groupBox2->Location = System::Drawing::Point(170, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(161, 64);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"File";
			// 
			// fImport
			// 
			this->fImport->BackColor = System::Drawing::Color::Black;
			this->fImport->ForeColor = System::Drawing::Color::White;
			this->fImport->Location = System::Drawing::Point(83, 19);
			this->fImport->MyText = L"Import";
			this->fImport->Name = L"fImport";
			this->fImport->Size = System::Drawing::Size(70, 30);
			this->fImport->TabIndex = 1;
			this->fImport->Click += gcnew System::EventHandler(this, &MainForm::fImport_Click);
			// 
			// fLoad
			// 
			this->fLoad->BackColor = System::Drawing::Color::Black;
			this->fLoad->ForeColor = System::Drawing::Color::White;
			this->fLoad->Location = System::Drawing::Point(7, 19);
			this->fLoad->MyText = L"Load";
			this->fLoad->Name = L"fLoad";
			this->fLoad->Size = System::Drawing::Size(70, 30);
			this->fLoad->TabIndex = 0;
			this->fLoad->Click += gcnew System::EventHandler(this, &MainForm::fLoad_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->groupBox1->Controls->Add(this->dImport);
			this->groupBox1->Controls->Add(this->dLoad);
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(161, 64);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Folder";
			// 
			// dImport
			// 
			this->dImport->BackColor = System::Drawing::Color::Black;
			this->dImport->ForeColor = System::Drawing::Color::White;
			this->dImport->Location = System::Drawing::Point(83, 19);
			this->dImport->MyText = L"Import";
			this->dImport->Name = L"dImport";
			this->dImport->Size = System::Drawing::Size(70, 30);
			this->dImport->TabIndex = 1;
			this->dImport->Click += gcnew System::EventHandler(this, &MainForm::dImport_Click);
			// 
			// dLoad
			// 
			this->dLoad->BackColor = System::Drawing::Color::Black;
			this->dLoad->ForeColor = System::Drawing::Color::White;
			this->dLoad->Location = System::Drawing::Point(7, 19);
			this->dLoad->MyText = L"Load";
			this->dLoad->Name = L"dLoad";
			this->dLoad->Size = System::Drawing::Size(70, 30);
			this->dLoad->TabIndex = 0;
			this->dLoad->Click += gcnew System::EventHandler(this, &MainForm::dLoad_Click);
			// 
			// bPrev
			// 
			this->bPrev->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->bPrev->BackColor = System::Drawing::Color::Black;
			this->bPrev->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bPrev->ForeColor = System::Drawing::Color::White;
			this->bPrev->Location = System::Drawing::Point(3, 327);
			this->bPrev->MyText = L"<";
			this->bPrev->Name = L"bPrev";
			this->bPrev->Size = System::Drawing::Size(50, 50);
			this->bPrev->TabIndex = 1;
			this->bPrev->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::bPrev_MouseDown);
			// 
			// bNext
			// 
			this->bNext->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->bNext->BackColor = System::Drawing::Color::Black;
			this->bNext->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bNext->ForeColor = System::Drawing::Color::White;
			this->bNext->Location = System::Drawing::Point(1313, 327);
			this->bNext->MyText = L">";
			this->bNext->Name = L"bNext";
			this->bNext->Size = System::Drawing::Size(50, 50);
			this->bNext->TabIndex = 2;
			this->bNext->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::bNext_MouseDown);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1252, 620);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pictureBox1_Paint);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Multiselect = true;
			this->openFileDialog1->Title = L"Choose Image File(s)";
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(56, 76);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1254, 622);
			this->panel1->TabIndex = 4;
			// 
			// MainForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ClientSize = System::Drawing::Size(1366, 705);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->bNext);
			this->Controls->Add(this->bPrev);
			this->Controls->Add(this->myPanel1);
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Image Viewer";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::MainForm_DragDrop);
			this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::MainForm_DragEnter);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MainForm::MainForm_Resize);
			this->myPanel1->ResumeLayout(false);
			this->myPanel1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: ListNode<std::string>* node = nullptr;
	private: CircularList<std::string>^ cp = gcnew CircularList<std::string>;
	private: String^ ToManaged(std::string str);
	private: std::string FromManaged(String^ str);
	private: Void RefreshImage();
	private: Void NextImage();
	private: Void PreviousImage();
	private: Void LoadFolder(Boolean clear);
	private: Void LoadFiles(Boolean clear);
	public: Void AddFile(String^ path);
	public: Void AddFolder(String^ path);
	private: Void SetPBSize();
	private: Void Remove();
	private: Void Clear();
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void dLoad_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void dImport_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void fLoad_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void fImport_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bPrev_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void bNext_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MainForm_Resize(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MainForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
	private: System::Void bRemove_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MainForm_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void MainForm_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
	private: System::Void myButton1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	protected: bool ProcessCmdKey(Message% msg, Keys keyData) override
	{
		//base override to set left and right keys as shortcut keys.
		if (keyData == Keys::Left)
		{
			PreviousImage();
		}
		else if (keyData == Keys::Right)
		{
			NextImage();
		}
		return __super::ProcessCmdKey(msg, keyData);
	}
};
}
