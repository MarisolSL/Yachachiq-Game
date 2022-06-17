#pragma once
#include "Controladora.h"

namespace YachachiqGame { //Nombre del proyecto

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public Form
	{
		Controladora^ controladora;

	public:
		MyForm(void)
		{
			InitializeComponent();
			controladora = gcnew Controladora();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete controladora;
		}
	private: System::Windows::Forms::Timer^ clock;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->clock = (gcnew System::Windows::Forms::Timer(this->components));
			   this->SuspendLayout();
			   // 
			   // clock
			   // 
			   this->clock->Enabled = true;
			   this->clock->Interval = 30;
			   this->clock->Tick += gcnew System::EventHandler(this, &MyForm::clock_Tick);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(284, 261);
			   this->Name = L"MyForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"MyForm";
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			   this->ResumeLayout(false);

		   }
#pragma endregion
		   Void clock_Tick(Object^ sender, EventArgs^ e)
		   {
			   Graphics^ g = this->CreateGraphics();
			   g->Clear(Color::White);
			   controladora->Mover(g);
			   controladora->Mostrar(g);
		   }
		   Void MyForm_KeyDown(Object^ sender, KeyEventArgs^ e) //Presionar una tecla
		   {
			   controladora->MovimientoProfesor(true, e->KeyCode);
		   }
		   Void MyForm_KeyUp(Object^ sender, KeyEventArgs^ e)
		   {
			   controladora->MovimientoProfesor(false, e->KeyCode); //Soltar una tecla
		   }

	};
}
