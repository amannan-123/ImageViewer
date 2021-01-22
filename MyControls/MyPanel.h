#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace MyControls {

	/// <summary>
	/// Flicker free panel.
	/// </summary>
	[DescriptionAttribute("Flicker free panel.")]
	[ToolboxBitmapAttribute(Panel::typeid)]
	public ref class MyPanel : public System::Windows::Forms::Panel
	{
	public:
		MyPanel(void)
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
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyPanel()
		{
			if (components)
			{
				delete components;
			}
		}

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
		
		}
#pragma endregion
	};
}
