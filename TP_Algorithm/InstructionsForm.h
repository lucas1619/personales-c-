#pragma once

namespace TPAlgorithm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InstructionsForm
	/// </summary>
	public ref class InstructionsForm : public System::Windows::Forms::Form
	{
	public:
		InstructionsForm(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			bmpInstBackground = gcnew Bitmap("imagesAlgorithm\\newInstructions.jpg");
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InstructionsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:
	private: System::Windows::Forms::Timer^  timer1;

 	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		Graphics^ g;
		Bitmap^ bmpInstBackground;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &InstructionsForm::timer1_Tick);
			// 
			// InstructionsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1236, 561);
			this->Name = L"InstructionsForm";
			this->Text = L"InstructionsForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &InstructionsForm::InstructionsForm_FormClosed);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		BufferedGraphics^buffer;
		BufferedGraphicsContext^contexto = BufferedGraphicsManager::Current;
		buffer = contexto->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(this->BackColor);

		buffer->Graphics->DrawImage(bmpInstBackground, 0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);

		//DRAWING ELEMENTS
		/*int pos = 0;
		buffer->Graphics->DrawString("CASHIER => ", gcnew Drawing::Font("Arial", 10), Brushes::Black, 10, 35);
		buffer->Graphics->FillRectangle(gcnew SolidBrush(Color::Blue), 95, 30, 30, 30); 

		buffer->Graphics->DrawString("PERSON WITH FAMILY => ", gcnew Drawing::Font("Arial", 10), Brushes::Black, 13, 130);
		for (int i = 0; i < 5; ++i) {
			buffer->Graphics->FillRectangle(gcnew SolidBrush(Color::Green), 180, 125 + pos, 30, 30);

			pos += 50;
		}

		buffer->Graphics->DrawString("YOU => ", gcnew Drawing::Font("Arial", 10), Brushes::Black, 120, 380);
		buffer->Graphics->FillRectangle(gcnew SolidBrush(Color::Red), 180, 375, 30, 30);

		buffer->Graphics->FillRectangle(gcnew SolidBrush(Color::BurlyWood), 300, 20, 100, 50);
		buffer->Graphics->DrawString("<= INVENTORY", gcnew Drawing::Font("Arial", 10), Brushes::Black, 410, 35);*/


		buffer->Render(g);

		delete contexto;
		delete buffer;

		
	}
	private: System::Void InstructionsForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {

		timer1->Enabled = false;
	}
};
}
