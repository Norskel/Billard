#pragma once
#include "BandeBillard.h"
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
		MyForm(void)
		{
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
		}
	private: System::Windows::Forms::Button^  _btnBille;
	protected:
	private: System::Windows::Forms::Timer^  _timer1;
	private: System::Windows::Forms::Label^  l1;

	private: System::ComponentModel::IContainer^  components;

	private:
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
			this->l1->Location = System::Drawing::Point(82, 6);
			this->l1->Name = L"l1";
			this->l1->Size = System::Drawing::Size(13, 13);
			this->l1->TabIndex = 1;
			this->l1->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(844, 406);
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

		BandeBillard b1(10, 10, 200, 10, Color(Color::Blue));

		b1.dessine(g);

		_i++;
		l1->Text = _i.ToString();
		
	}
	private: System::Void _timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		this->Refresh();
	}
	};
}
