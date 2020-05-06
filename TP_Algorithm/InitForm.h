#pragma once
#include "GameForm.h"
#include "InstructionsForm.h"
#include "CreditsForm.h"

namespace TPAlgorithm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InitForm
	/// </summary>
	public ref class InitForm : public System::Windows::Forms::Form
	{
	public:
		InitForm(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();

			bmpInitBackground = gcnew Bitmap("imagesAlgorithm\\newInit.jpg");
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InitForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonInstructions;
	protected:

	private: System::Windows::Forms::Button^  buttonPlay;
	private: System::Windows::Forms::Button^  buttonCredits;

			 bool InstructionsController = false;

	private:

		Graphics^g;

		//MULTIMEDIA ELEMENTS
		Bitmap^bmpInitBackground;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  buttonLoad;

	private: System::ComponentModel::IContainer^  components;

		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->buttonInstructions = (gcnew System::Windows::Forms::Button());
			this->buttonPlay = (gcnew System::Windows::Forms::Button());
			this->buttonCredits = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->buttonLoad = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonInstructions
			// 
			this->buttonInstructions->Location = System::Drawing::Point(673, 410);
			this->buttonInstructions->Name = L"buttonInstructions";
			this->buttonInstructions->Size = System::Drawing::Size(146, 39);
			this->buttonInstructions->TabIndex = 1;
			this->buttonInstructions->Text = L"INSTRUCTIONS";
			this->buttonInstructions->UseVisualStyleBackColor = true;
			this->buttonInstructions->Click += gcnew System::EventHandler(this, &InitForm::buttonInstructions_Click);
			// 
			// buttonPlay
			// 
			this->buttonPlay->Location = System::Drawing::Point(673, 299);
			this->buttonPlay->Name = L"buttonPlay";
			this->buttonPlay->Size = System::Drawing::Size(146, 39);
			this->buttonPlay->TabIndex = 0;
			this->buttonPlay->Text = L"PLAY NEW";
			this->buttonPlay->UseVisualStyleBackColor = true;
			this->buttonPlay->Click += gcnew System::EventHandler(this, &InitForm::buttonPlay_Click);
			// 
			// buttonCredits
			// 
			this->buttonCredits->Location = System::Drawing::Point(673, 464);
			this->buttonCredits->Name = L"buttonCredits";
			this->buttonCredits->Size = System::Drawing::Size(146, 39);
			this->buttonCredits->TabIndex = 3;
			this->buttonCredits->Text = L"CREDITS";
			this->buttonCredits->UseVisualStyleBackColor = true;
			this->buttonCredits->Click += gcnew System::EventHandler(this, &InitForm::buttonCredits_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &InitForm::timer1_Tick);
			// 
			// buttonLoad
			// 
			this->buttonLoad->Location = System::Drawing::Point(673, 356);
			this->buttonLoad->Name = L"buttonLoad";
			this->buttonLoad->Size = System::Drawing::Size(146, 39);
			this->buttonLoad->TabIndex = 4;
			this->buttonLoad->Text = L"LOAD";
			this->buttonLoad->UseVisualStyleBackColor = true;
			this->buttonLoad->Click += gcnew System::EventHandler(this, &InitForm::buttonLoad_Click);
			// 
			// InitForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(866, 563);
			this->Controls->Add(this->buttonLoad);
			this->Controls->Add(this->buttonCredits);
			this->Controls->Add(this->buttonInstructions);
			this->Controls->Add(this->buttonPlay);
			this->Name = L"InitForm";
			this->Text = L"InitForm";
			this->Load += gcnew System::EventHandler(this, &InitForm::InitForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void InitForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		//BUFFER
		BufferedGraphics^buffer;
		BufferedGraphicsContext^contexto = BufferedGraphicsManager::Current;
		buffer = contexto->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(this->BackColor);

		//DRAWING ELEMENTS
		buffer->Graphics->DrawImage(bmpInitBackground, 0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);


		buffer->Render(g);

		delete contexto;
		delete buffer;
	}
private: System::Void buttonPlay_Click(System::Object^  sender, System::EventArgs^  e) {

	if (InstructionsController == false) {
		MessageBox::Show("Read the instructions to know what this simulation is about");
	}
	else {
		GameForm^ frmPlay = gcnew GameForm(0);

		frmPlay->ShowDialog();

		InstructionsController = false;
	}
}
private: System::Void buttonInstructions_Click(System::Object^  sender, System::EventArgs^  e) {

	InstructionsForm^ frmInstructions = gcnew InstructionsForm();

	frmInstructions->ShowDialog();

	InstructionsController = true;
}
private: System::Void buttonCredits_Click(System::Object^  sender, System::EventArgs^  e) {
	CreditsForm^ frmCredits = gcnew CreditsForm();

	frmCredits->ShowDialog();

}
private: System::Void buttonLoad_Click(System::Object^  sender, System::EventArgs^  e) {

	if (InstructionsController == false) {
		MessageBox::Show("Read the instructions to know what this simulation is about");
	}
	else {
		GameForm^ frmPlay1 = gcnew GameForm(1);

		frmPlay1->ShowDialog();

		InstructionsController = false;
	}
}
};
}
