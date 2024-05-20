#include "table.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args)
{
	

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	schedualmaker::scheduelre form;
	Application::Run(% form);
}