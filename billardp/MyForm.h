#pragma once
#include "Billard.h"
namespace billardp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(Billard^ myBillard)
		{
			_monBillard = myBillard;
			InitializeComponent();
			SetStyle(ControlStyles::OptimizedDoubleBuffer,true);
			SetStyle(ControlStyles::UserPaint,true);
			SetStyle(ControlStyles::AllPaintingInWmPaint,true);
			_i = 0;


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{

			if (components)
			{
				delete components;
			}
			delete _monBillard;
		}
	private: System::Windows::Forms::Button^  _btnBille;
	private: System::Windows::Forms::Timer^  _timer1;
	private: System::Windows::Forms::Label^  l1;
	private: System::ComponentModel::IContainer^  components;

	private: Billard^ _monBillard;
	private: System::Windows::Forms::Button^  btClear;
	private: System::Windows::Forms::Button^  btX10;
			 /// <summary>
		/// Required designer variable.
		/// </summary>
		int _i;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->_btnBille = (gcnew System::Windows::Forms::Button());
			this->_timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->l1 = (gcnew System::Windows::Forms::Label());
			this->btClear = (gcnew System::Windows::Forms::Button());
			this->btX10 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// _btnBille
			// 
			this->_btnBille->Location = System::Drawing::Point(1, 1);
			this->_btnBille->Name = L"_btnBille";
			this->_btnBille->Size = System::Drawing::Size(75, 23);
			this->_btnBille->TabIndex = 0;
			this->_btnBille->Text = L"Bille";
			this->_btnBille->UseVisualStyleBackColor = true;
			this->_btnBille->Click += gcnew System::EventHandler(this, &MyForm::_btnBille_Click);
			// 
			// _timer1
			// 
			this->_timer1->Enabled = true;
			this->_timer1->Interval = 20;
			this->_timer1->Tick += gcnew System::EventHandler(this, &MyForm::_timer1_Tick);
			// 
			// l1
			// 
			this->l1->AutoSize = true;
			this->l1->Location = System::Drawing::Point(29, 67);
			this->l1->Name = L"l1";
			this->l1->Size = System::Drawing::Size(13, 13);
			this->l1->TabIndex = 1;
			this->l1->Text = L"0";
			// 
			// btClear
			// 
			this->btClear->Location = System::Drawing::Point(1, 30);
			this->btClear->Name = L"btClear";
			this->btClear->Size = System::Drawing::Size(75, 23);
			this->btClear->TabIndex = 2;
			this->btClear->Text = L"Clear";
			this->btClear->UseVisualStyleBackColor = true;
			this->btClear->Click += gcnew System::EventHandler(this, &MyForm::btClear_Click);
			// 
			// btX10
			// 
			this->btX10->Location = System::Drawing::Point(1, 95);
			this->btX10->Name = L"btX10";
			this->btX10->Size = System::Drawing::Size(75, 23);
			this->btX10->TabIndex = 3;
			this->btX10->Text = L"X10";
			this->btX10->UseVisualStyleBackColor = true;
			this->btX10->Click += gcnew System::EventHandler(this, &MyForm::btX10_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(844, 406);
			this->Controls->Add(this->btX10);
			this->Controls->Add(this->btClear);
			this->Controls->Add(this->l1);
			this->Controls->Add(this->_btnBille);
			this->Name = L"MyForm";
			this->Text = L"Billard";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

		System::Drawing::Graphics^ g = e->Graphics;

		_monBillard->dessineBandes(g);
		_monBillard->dessineBilles(g);


		_i++;
		l1->Text = Convert::ToString(_monBillard->getNombreBille());
		_monBillard->setTaille(this->Width, this->Height);
		
	}
	private: System::Void _timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		this->Refresh();
	}
	private: System::Void _btnBille_Click(System::Object^  sender, System::EventArgs^  e) {
		_monBillard->ajouterBille();
	}
	private: System::Void btClear_Click(System::Object^  sender, System::EventArgs^  e) {
		_monBillard->supprimeBille();
	}
private: System::Void btX10_Click(System::Object^  sender, System::EventArgs^  e) {
	for (int i = 0; i < 10; i++)
	{
		_monBillard->ajouterBille();
	}
}
};
}
