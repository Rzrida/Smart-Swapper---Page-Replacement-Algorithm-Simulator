#include "Form1.h"
using namespace::System;
using namespace::System::Windows::Forms;

void Main(cli::array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::Form1 form;
	Application::Run(% form);

}