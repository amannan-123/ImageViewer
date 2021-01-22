/*
Project: Image Viewer App using Circular Doubly Linked List
Author: Abdul Mannan
*/
#include "MainForm.h"

#pragma region Conversions

//convert std::string to System::String
String ^ ImageViewerUI::MainForm::ToManaged(std::string str)
{
	String^ strr = "";
	for each (char ch in str)
	{
		strr += Convert::ToChar(ch);
	}
	return strr;
}

//convert System::String to std::string
std::string ImageViewerUI::MainForm::FromManaged(String ^ str)
{
	std::string strr = "";
	for each (char ch in str)
	{
		strr += (char)ch;
	}
	return strr;
}

#pragma endregion

#pragma region Image Handlers

//refresh current picture box image
Void ImageViewerUI::MainForm::RefreshImage()
{
	if (node != nullptr)
	{
		String^ path = ToManaged(node->data);
		if (File::Exists(path))
		{
			pictureBox1->ImageLocation = path;
			FileInfo^ finf = gcnew FileInfo(path);
			Text = finf->Name;
			label2->Text = "Current Image: " + (node->key+1).ToString() + "/" + cp->Length;
		}
	}
	else
	{
		Text = "Image Viewer";
		pictureBox1->ImageLocation = "";
		label2->Text = "";
	}
}

//show next image from list
Void ImageViewerUI::MainForm::NextImage()
{
	if (node != nullptr)
	{
		node = node->next;
		RefreshImage();
	}
}

//show previous image from list
Void ImageViewerUI::MainForm::PreviousImage()
{
	if (node != nullptr)
	{
		node = node->prev;
		RefreshImage();
	}
}

//remove current image from list
Void ImageViewerUI::MainForm::Remove()
{
	if (node != nullptr)
	{
		int ind = node->key;
		cp->Delete(node->key);
		node = cp->ItemAt(ind); //get next image from list
		if (node == nullptr)
			node = cp->ItemAt(ind - 1); //if there is no next image then get previous one.
		RefreshImage();
	}
}

//clear linked list
Void ImageViewerUI::MainForm::Clear()
{
	cp->Clear();
	node = nullptr;
	RefreshImage();
}

#pragma endregion

#pragma region LoadingImages

//load all image files from folder
Void ImageViewerUI::MainForm::LoadFolder(Boolean clear)
{
	if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if (clear)
		{
			cp->Clear();
		}
		int ind = cp->Length;
		int i = 0;
		AddFolder(folderBrowserDialog1->SelectedPath);
		if (clear)
		{
			node = cp->head;
		}
		else
		{
			node = cp->head;
			while (i < ind)
			{
				node = node->next;
				++i;
			}
		}
		RefreshImage();
	}
}

//load all selected files
Void ImageViewerUI::MainForm::LoadFiles(Boolean clear)
{
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if (clear)
		{
			cp->Clear();
		}
		int ind = cp->Length;
		int i = 0;
		for each (String^ str in openFileDialog1->FileNames)
		{
			AddFile(str);
		}
		if (clear)
		{
			node = cp->head;
		}
		else
		{
			node = cp->head;
			while (i < ind)
			{
				node = node->next;
				++i;
			}
		}
		RefreshImage();
	}
}

//add valid image file location in linked list
Void ImageViewerUI::MainForm::AddFile(String ^ path)
{
	if (File::Exists(path))
	{
		FileInfo^ finf = gcnew FileInfo(path);
		String^ ext = finf->Extension->ToLower();
		if (ext == ".png" ||
			ext == ".jpe" ||
			ext == ".jpg" ||
			ext == ".jpeg" ||
			ext == ".bmp" ||
			ext == ".gif")
		{
			cp->Add(FromManaged(finf->FullName));
		}
	}
}

//add valid image files location from given directory in linked list
Void ImageViewerUI::MainForm::AddFolder(String ^ path)
{
	if (Directory::Exists(path))
	{
		DirectoryInfo^ dinf = gcnew DirectoryInfo(path);
		for each (FileInfo^ finf in dinf->GetFiles())
		{
			AddFile(finf->FullName);
		}
	}
}

#pragma endregion

#pragma region PictureBox Resizing

Void ImageViewerUI::MainForm::SetPBSize()
{
	if (pictureBox1->SizeMode != PictureBoxSizeMode::AutoSize)
	{
		pictureBox1->Width = panel1->Width - 2;
		pictureBox1->Height = panel1->Height - 2;
		pictureBox1->Location = Point(0, 0);
		pictureBox1->Refresh();
		panel1->AutoScroll = false;
	}
	else
	{
		panel1->AutoScroll = true;
	}
}

#pragma endregion

#pragma region Form Events

System::Void ImageViewerUI::MainForm::MainForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	openFileDialog1->Filter = "Image files (*.jpg, *.jpeg, *.jpe, *.bmp, *.gif, *.png) | *.jpg; *.jpeg; *.jpe; *.bmp; *.gif; *.png";
	for each (String^ name in Enum::GetNames(PictureBoxSizeMode::typeid))
	{
		comboBox1->Items->Add(name);
	}
	comboBox1->SelectedIndex = 4;
	node = cp->head;
	RefreshImage();

}

System::Void ImageViewerUI::MainForm::MainForm_Resize(System::Object ^ sender, System::EventArgs ^ e)
{
	SetPBSize();
}

System::Void ImageViewerUI::MainForm::MainForm_FormClosed(System::Object ^ sender, System::Windows::Forms::FormClosedEventArgs ^ e)
{
	cp->Clear();
}

System::Void ImageViewerUI::MainForm::MainForm_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
{
	if (e->KeyData == Keys::Delete)
	{
		Remove();
	}
	if (e->KeyCode == Keys::C && e->Modifiers == Keys::Control)
	{
		Clear();
	}
}

#pragma endregion

#pragma region Buttons Events

System::Void ImageViewerUI::MainForm::dLoad_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LoadFolder(true);
}

System::Void ImageViewerUI::MainForm::dImport_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LoadFolder(false);
}

System::Void ImageViewerUI::MainForm::fLoad_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LoadFiles(true);
}

System::Void ImageViewerUI::MainForm::fImport_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LoadFiles(false);
}

System::Void ImageViewerUI::MainForm::bPrev_MouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
{
	PreviousImage();
}

System::Void ImageViewerUI::MainForm::bNext_MouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
{
	NextImage();
}

System::Void ImageViewerUI::MainForm::bRemove_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Remove();
}

System::Void ImageViewerUI::MainForm::myButton1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Clear();
}

#pragma endregion

#pragma region ComboBox Event

System::Void ImageViewerUI::MainForm::comboBox1_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	pictureBox1->SizeMode = (PictureBoxSizeMode)Enum::Parse(PictureBoxSizeMode::typeid, (String^)comboBox1->SelectedItem);
	SetPBSize();
	SetPBSize();
}

#pragma endregion

#pragma region DragDrop Handler

System::Void ImageViewerUI::MainForm::MainForm_DragDrop(System::Object ^ sender, System::Windows::Forms::DragEventArgs ^ e)
{
	int ind = -1;
	ind = cp->Length;
	for each (String^ str in (array<String^>^)e->Data->GetData(DataFormats::FileDrop))
	{
		//folder is dropped
		if (Directory::Exists(str))
		{
			AddFolder(str);
		}
		//file is dropped
		else
		{
			AddFile(str);
		}
	}
	node = cp->ItemAt(ind);
	RefreshImage();
}

System::Void ImageViewerUI::MainForm::MainForm_DragEnter(System::Object ^ sender, System::Windows::Forms::DragEventArgs ^ e)
{
	if (e->Data->GetDataPresent(DataFormats::FileDrop))
		e->Effect = DragDropEffects::Copy;
	else
		e->Effect = DragDropEffects::None;
}

#pragma endregion

#pragma region PictureBox Paint

System::Void ImageViewerUI::MainForm::pictureBox1_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
{
	//if no image is loaded then draw string
	if (pictureBox1 == nullptr || pictureBox1->Image == nullptr)
	{
		Graphics^ g = e->Graphics;
		g->TextRenderingHint = Drawing::Text::TextRenderingHint::AntiAlias;
		SolidBrush^ sld = gcnew SolidBrush(Color::White);
		StringFormat^ sf = gcnew StringFormat(StringFormatFlags::NoWrap);
		sf->Alignment = StringAlignment::Center;
		sf->LineAlignment = StringAlignment::Center;
		Drawing::Font^ fnt = gcnew Drawing::Font("Palatino Linotype", 20);
		g->DrawString("Please Load or Drag Image(s) Here!", fnt, sld, pictureBox1->ClientRectangle, sf);
	}
}

#pragma endregion