#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
namespace MyControls {
	/// <summary>
	/// Flicker free stylish button.
	/// </summary>
	[DescriptionAttribute("Flicker free stylish button.")]
	[DefaultEventAttribute("Click")]
	[DefaultPropertyAttribute("MyText")]
	[ToolboxBitmapAttribute(Button::typeid)]
	public ref class MyButton : public System::Windows::Forms::UserControl
	{
	public:
		MyButton(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->SetStyle(static_cast<ControlStyles>(
				ControlStyles::AllPaintingInWmPaint |
				ControlStyles::DoubleBuffer |
				ControlStyles::UserPaint), true);
			this->UpdateStyles();
			__super::Text = "Text";
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyButton()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  tInf;
	protected:
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tInf = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// tInf
			// 
			this->tInf->Interval = 1;
			this->tInf->Tick += gcnew System::EventHandler(this, &MyButton::tInf_Tick);
			// 
			// MyButton
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Black;
			this->ForeColor = System::Drawing::Color::White;
			this->Name = L"MyButton";
			this->Size = System::Drawing::Size(100, 50);
			this->Load += gcnew System::EventHandler(this, &MyButton::MyButton_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyButton::MyButton_Paint);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyButton::MyButton_MouseDown);
			this->MouseLeave += gcnew System::EventHandler(this, &MyButton::MyButton_MouseLeave);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyButton::MyButton_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyButton::MyButton_MouseUp);
			this->Resize += gcnew System::EventHandler(this, &MyButton::MyButton_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		Color clr = Color::FromArgb(60, 255, 255, 255);
		int inc = 3;
		bool eff = true;
		Point pt;
		bool md;
		int inf;

	public:
		/// <summary>
		/// The text associated with the control.
		/// </summary>
		[DescriptionAttribute("The text associated with the control.")]
		[DefaultValueAttribute("Text")]
		[CategoryAttribute("Appearance")]
		property String^ MyText
		{
			String^ get()
			{
				return __super::Text;
			}
			void set(String^ value)
			{
				__super::Text = value;
				Invalidate();
			}
		}

		/// <summary>
		/// Gets or sets the effect color the control.
		/// </summary>
		[DescriptionAttribute("Gets or sets the effect color the control.")]
		[DefaultValueAttribute((Color::typeid), "60, 255, 255, 255")]
		[CategoryAttribute("Appearance")]
		property Color EffectColor
		{
			Color get()
			{
				return clr;
			}
			void set(Color value)
			{
				clr = value;
				Invalidate();
			}
		}

		/// <summary>
		/// Gets or sets the effect's increment value.
		/// </summary>
		[DescriptionAttribute("Gets or sets the effect's increment value.")]
		[DefaultValueAttribute(3)]
		[CategoryAttribute("Appearance")]
		property int Increment
		{
			int get()
			{
				return inc;
			}
			void set(int value)
			{
				inc = value;
				Invalidate();
			}
		}

		/// <summary>
		/// Indicates whether effect should be drawn or not.
		/// </summary>
		[DescriptionAttribute("Indicates whether effect should be drawn or not.")]
		[DefaultValueAttribute((bool::typeid), "True")]
		[CategoryAttribute("Appearance")]
		property bool DrawEffect
		{
			bool get()
			{
				return eff;
			}
			void set(bool value)
			{
				eff = value;
				Reset();
			}
		}

	private: System::Void MyButton_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
	private: System::Void MyButton_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyButton_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void tInf_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyButton_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void MyButton_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void MyButton_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyButton_Resize(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Reset();

};
}
