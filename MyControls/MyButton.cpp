#include "stdafx.h"
#include "MyButton.h"

System::Void MyControls::MyButton::MyButton_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
{
	Graphics ^g = e->Graphics;
	g->SmoothingMode = SmoothingMode::AntiAlias;
	if(DrawEffect)
	{
		Rectangle rect = Rectangle(pt.X, pt.Y, 0, 0);
		rect.Inflate(inf, inf);
		rect.Inflate(Math::Min(Width, Height), Math::Min(Width, Height));
		GraphicsPath^ gp = gcnew GraphicsPath();
		gp->AddEllipse(rect);
		PathGradientBrush ^lgb = gcnew PathGradientBrush(gp);
		ColorBlend ^bl = gcnew ColorBlend();
		array<Color>^ arr = gcnew array<Color>(3);
		arr[0] = Color::Transparent;
		arr[1] = Color::Transparent;
		arr[2] = EffectColor;
		bl->Colors = arr;
		array<float>^ arr2 = gcnew array<float>(3);
		arr2[0] = 0;
		arr2[1] = (float)0.2;
		arr2[2] = 1;
		bl->Positions = arr2;
		lgb->InterpolationColors = bl;
		g->FillEllipse(lgb, rect);
		Rectangle bord = Rectangle(0, 0, Width - 1, Height - 1);
		GraphicsPath^ gpb = gcnew GraphicsPath();
		gpb->AddEllipse(rect);
		PathGradientBrush ^lgbb = gcnew PathGradientBrush(gpb);
		ColorBlend ^blb = gcnew ColorBlend();
		array<Color>^ arrb = gcnew array<Color>(3);
		arrb[0] = Color::Transparent;
		arrb[1] = Color::Transparent;
		arrb[2] = Color::FromArgb(255,EffectColor);
		blb->Colors = arrb;
		array<float>^ arr2b = gcnew array<float>(3);
		arr2b[0] = 0;
		arr2b[1] = (float)0.2;
		arr2b[2] = 1;
		blb->Positions = arr2b;
		lgbb->InterpolationColors = blb;
		Pen^ pn = gcnew Pen(lgbb);
		g->DrawRectangle(pn, bord);
	}
	SolidBrush^ sld = gcnew SolidBrush(ForeColor);
	StringFormat^ sf = gcnew StringFormat(StringFormatFlags::NoWrap);
	sf->Alignment = StringAlignment::Center;
	sf->LineAlignment = StringAlignment::Center;
	g->DrawString(MyText, Font, sld, ClientRectangle, sf);
}

System::Void MyControls::MyButton::MyButton_MouseLeave(System::Object ^ sender, System::EventArgs ^ e)
{
	Reset();
}

System::Void MyControls::MyButton::MyButton_MouseMove(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
{
	pt = e->Location;
	Invalidate();
}

System::Void MyControls::MyButton::tInf_Tick(System::Object ^ sender, System::EventArgs ^ e)
{
	if(inf < 2 * Math::Max(Width, Height))
		inf += Increment;
	Invalidate();
}

System::Void MyControls::MyButton::MyButton_MouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
{
	tInf->Start();
}

System::Void MyControls::MyButton::MyButton_MouseUp(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
{
	tInf->Stop();
	Reset();
}

System::Void MyControls::MyButton::MyButton_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	Reset();
}

System::Void MyControls::MyButton::MyButton_Resize(System::Object ^ sender, System::EventArgs ^ e)
{
	Reset();
}

System::Void MyControls::MyButton::Reset()
{
	inf = Math::Min(Width, Height);
	pt = Point(-Math::Max(Width, Height), -Math::Max(Width, Height));
	Invalidate();
}
