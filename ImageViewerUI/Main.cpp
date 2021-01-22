/*
Project: Image Viewer App using Circular Doubly Linked List
Author: Abdul Mannan
*/
#include "MainForm.h"

namespace ImageViewerUI {

	void ExitWhenLastWindowClosed(Object^ sender, FormClosedEventArgs^ e) {
		if (Application::OpenForms->Count == 0) Application::Exit();
		else Application::OpenForms[0]->FormClosed += gcnew FormClosedEventHandler(ExitWhenLastWindowClosed);
	}

	[STAThread]
	int Main(array<System::String ^> ^args)
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		//create new instance of main form
		MainForm^ frm = gcnew MainForm();
		//support open-with and drag-drop functionality in explorer
		for each (String^ str in args)
		{
			//folder detected
			if (Directory::Exists(str))
			{
				frm->AddFolder(str);
			}
			//file detected
			else
			{
				frm->AddFile(str);
			}
		}
		//add closed event
		frm->FormClosed += gcnew FormClosedEventHandler(ExitWhenLastWindowClosed);
		//show main form
		frm->Show();
		Application::Run();
		return 0;
	}
}