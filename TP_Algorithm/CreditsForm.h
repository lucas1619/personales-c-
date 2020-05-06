#pragma once

namespace TPAlgorithm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CreditsForm
	/// </summary>
	public ref class CreditsForm : public System::Windows::Forms::Form
	{
	public:
		CreditsForm(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			bmpCreditsBackground = gcnew Bitmap("imagesAlgorithm\\newCredits.jpg");

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CreditsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;
			 Graphics^g;

			 //MULTIMEDIA ELEMENTS
			 Bitmap^bmpCreditsBackground;
	private:
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &CreditsForm::timer1_Tick);
			// 
			// CreditsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 519);
			this->Name = L"CreditsForm";
			this->Text = L"CreditsForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &CreditsForm::CreditsForm_FormClosed);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		//BUFFER
		BufferedGraphics^buffer;
		BufferedGraphicsContext^contexto = BufferedGraphicsManager::Current;
		buffer = contexto->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(this->BackColor);

		//DRAWING ELEMENTS
		buffer->Graphics->DrawImage(bmpCreditsBackground, 0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);


		buffer->Render(g);

		delete contexto;
		delete buffer;
	}
	private: System::Void CreditsForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		timer1->Enabled = false;
	}
	};
}
