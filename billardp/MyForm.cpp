#include "MyForm.h"
#include "Billard.h"

using namespace System;
using namespace System::Windows::Forms;



[STAThread]
void Main(array<String^>^ args)
{
	Console::WriteLine("Test");
	Billard^ _Billard = gcnew Billard();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	billardp::MyForm _formBillard(_Billard);
	
	Application::Run(%_formBillard);
}
