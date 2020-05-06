#pragma once
#include "Classes.h"
namespace TPAlgorithm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(int saver)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			gameSimulator = new CGame();
			saveController = saver;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

			 Graphics^ g;
	private: System::Windows::Forms::GroupBox^  groupInfo;
	private: System::Windows::Forms::Label^  labelDesire;

	private: System::Windows::Forms::Label^  labelUseGel;
	private: System::Windows::Forms::Label^  labelUseSoap;
	private: System::Windows::Forms::Label^  labelUsePaper;
	private: System::Windows::Forms::Label^  labelFam;
	private: System::Windows::Forms::TextBox^  textBoxGel;
	private: System::Windows::Forms::TextBox^  textBoxSoap;
	private: System::Windows::Forms::TextBox^  textBoxPaper;
	private: System::Windows::Forms::Label^  labelGuessGel;
	private: System::Windows::Forms::Label^  labelGuessSoap;
	private: System::Windows::Forms::Label^  labelGuessPaper;
	private: System::Windows::Forms::Label^  labelGuess;
	private: System::Windows::Forms::Button^  buttonGuess;
	private: System::Windows::Forms::Button^  buttonSave;
	private: System::Windows::Forms::Label^  labelDes;
	private: System::Windows::Forms::Label^  labelgel;
	private: System::Windows::Forms::Label^  labelsoap;
	private: System::Windows::Forms::Label^  labelpaper;
	private: System::Windows::Forms::Label^  labelnumFam;

			 CGame* gameSimulator;
			 short topFam ;
			 short topUsePaper;
			 short topUseSoap;
			 short topUseGel;
			 short topDesire;

			 int topNeedPaper;
			 int topNeedSoap;
			 int topNeedGel;

			 int saveController;

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
			this->groupInfo = (gcnew System::Windows::Forms::GroupBox());
			this->labelDes = (gcnew System::Windows::Forms::Label());
			this->labelgel = (gcnew System::Windows::Forms::Label());
			this->labelsoap = (gcnew System::Windows::Forms::Label());
			this->labelpaper = (gcnew System::Windows::Forms::Label());
			this->labelnumFam = (gcnew System::Windows::Forms::Label());
			this->textBoxGel = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSoap = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPaper = (gcnew System::Windows::Forms::TextBox());
			this->labelGuessGel = (gcnew System::Windows::Forms::Label());
			this->labelGuessSoap = (gcnew System::Windows::Forms::Label());
			this->labelGuessPaper = (gcnew System::Windows::Forms::Label());
			this->labelGuess = (gcnew System::Windows::Forms::Label());
			this->labelDesire = (gcnew System::Windows::Forms::Label());
			this->labelUseGel = (gcnew System::Windows::Forms::Label());
			this->labelUseSoap = (gcnew System::Windows::Forms::Label());
			this->labelUsePaper = (gcnew System::Windows::Forms::Label());
			this->labelFam = (gcnew System::Windows::Forms::Label());
			this->buttonGuess = (gcnew System::Windows::Forms::Button());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->groupInfo->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &GameForm::timer1_Tick);
			// 
			// groupInfo
			// 
			this->groupInfo->Controls->Add(this->labelDes);
			this->groupInfo->Controls->Add(this->labelgel);
			this->groupInfo->Controls->Add(this->labelsoap);
			this->groupInfo->Controls->Add(this->labelpaper);
			this->groupInfo->Controls->Add(this->labelnumFam);
			this->groupInfo->Controls->Add(this->textBoxGel);
			this->groupInfo->Controls->Add(this->textBoxSoap);
			this->groupInfo->Controls->Add(this->textBoxPaper);
			this->groupInfo->Controls->Add(this->labelGuessGel);
			this->groupInfo->Controls->Add(this->labelGuessSoap);
			this->groupInfo->Controls->Add(this->labelGuessPaper);
			this->groupInfo->Controls->Add(this->labelGuess);
			this->groupInfo->Controls->Add(this->labelDesire);
			this->groupInfo->Controls->Add(this->labelUseGel);
			this->groupInfo->Controls->Add(this->labelUseSoap);
			this->groupInfo->Controls->Add(this->labelUsePaper);
			this->groupInfo->Controls->Add(this->labelFam);
			this->groupInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupInfo->Location = System::Drawing::Point(394, 162);
			this->groupInfo->Name = L"groupInfo";
			this->groupInfo->Size = System::Drawing::Size(375, 373);
			this->groupInfo->TabIndex = 0;
			this->groupInfo->TabStop = false;
			this->groupInfo->Text = L"INFO";
			// 
			// labelDes
			// 
			this->labelDes->AutoSize = true;
			this->labelDes->Location = System::Drawing::Point(224, 172);
			this->labelDes->Name = L"labelDes";
			this->labelDes->Size = System::Drawing::Size(78, 20);
			this->labelDes->TabIndex = 16;
			this->labelDes->Text = L"         ...";
			// 
			// labelgel
			// 
			this->labelgel->AutoSize = true;
			this->labelgel->Location = System::Drawing::Point(278, 137);
			this->labelgel->Name = L"labelgel";
			this->labelgel->Size = System::Drawing::Size(24, 20);
			this->labelgel->TabIndex = 15;
			this->labelgel->Text = L"...";
			// 
			// labelsoap
			// 
			this->labelsoap->AutoSize = true;
			this->labelsoap->Location = System::Drawing::Point(278, 102);
			this->labelsoap->Name = L"labelsoap";
			this->labelsoap->Size = System::Drawing::Size(24, 20);
			this->labelsoap->TabIndex = 14;
			this->labelsoap->Text = L"...";
			// 
			// labelpaper
			// 
			this->labelpaper->AutoSize = true;
			this->labelpaper->Location = System::Drawing::Point(278, 67);
			this->labelpaper->Name = L"labelpaper";
			this->labelpaper->Size = System::Drawing::Size(24, 20);
			this->labelpaper->TabIndex = 13;
			this->labelpaper->Text = L"...";
			// 
			// labelnumFam
			// 
			this->labelnumFam->AutoSize = true;
			this->labelnumFam->Location = System::Drawing::Point(278, 34);
			this->labelnumFam->Name = L"labelnumFam";
			this->labelnumFam->Size = System::Drawing::Size(24, 20);
			this->labelnumFam->TabIndex = 12;
			this->labelnumFam->Text = L"...";
			// 
			// textBoxGel
			// 
			this->textBoxGel->Location = System::Drawing::Point(290, 303);
			this->textBoxGel->Name = L"textBoxGel";
			this->textBoxGel->Size = System::Drawing::Size(47, 27);
			this->textBoxGel->TabIndex = 11;
			// 
			// textBoxSoap
			// 
			this->textBoxSoap->Location = System::Drawing::Point(164, 303);
			this->textBoxSoap->Name = L"textBoxSoap";
			this->textBoxSoap->Size = System::Drawing::Size(47, 27);
			this->textBoxSoap->TabIndex = 10;
			// 
			// textBoxPaper
			// 
			this->textBoxPaper->Location = System::Drawing::Point(48, 303);
			this->textBoxPaper->Name = L"textBoxPaper";
			this->textBoxPaper->Size = System::Drawing::Size(47, 27);
			this->textBoxPaper->TabIndex = 9;
			// 
			// labelGuessGel
			// 
			this->labelGuessGel->AutoSize = true;
			this->labelGuessGel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelGuessGel->Location = System::Drawing::Point(296, 266);
			this->labelGuessGel->Name = L"labelGuessGel";
			this->labelGuessGel->Size = System::Drawing::Size(31, 18);
			this->labelGuessGel->TabIndex = 8;
			this->labelGuessGel->Text = L"Gel";
			// 
			// labelGuessSoap
			// 
			this->labelGuessSoap->AutoSize = true;
			this->labelGuessSoap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelGuessSoap->Location = System::Drawing::Point(168, 266);
			this->labelGuessSoap->Name = L"labelGuessSoap";
			this->labelGuessSoap->Size = System::Drawing::Size(43, 18);
			this->labelGuessSoap->TabIndex = 7;
			this->labelGuessSoap->Text = L"Soap";
			// 
			// labelGuessPaper
			// 
			this->labelGuessPaper->AutoSize = true;
			this->labelGuessPaper->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelGuessPaper->Location = System::Drawing::Point(29, 266);
			this->labelGuessPaper->Name = L"labelGuessPaper";
			this->labelGuessPaper->Size = System::Drawing::Size(85, 18);
			this->labelGuessPaper->TabIndex = 6;
			this->labelGuessPaper->Text = L"Toilet paper";
			// 
			// labelGuess
			// 
			this->labelGuess->AutoSize = true;
			this->labelGuess->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelGuess->Location = System::Drawing::Point(16, 219);
			this->labelGuess->Name = L"labelGuess";
			this->labelGuess->Size = System::Drawing::Size(79, 24);
			this->labelGuess->TabIndex = 5;
			this->labelGuess->Text = L"GUESS";
			// 
			// labelDesire
			// 
			this->labelDesire->AutoSize = true;
			this->labelDesire->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDesire->Location = System::Drawing::Point(17, 174);
			this->labelDesire->Name = L"labelDesire";
			this->labelDesire->Size = System::Drawing::Size(121, 18);
			this->labelDesire->TabIndex = 4;
			this->labelDesire->Text = L"Random desire : ";
			// 
			// labelUseGel
			// 
			this->labelUseGel->AutoSize = true;
			this->labelUseGel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelUseGel->Location = System::Drawing::Point(17, 137);
			this->labelUseGel->Name = L"labelUseGel";
			this->labelUseGel->Size = System::Drawing::Size(137, 18);
			this->labelUseGel->TabIndex = 3;
			this->labelUseGel->Text = L"Weekly use of gel : ";
			// 
			// labelUseSoap
			// 
			this->labelUseSoap->AutoSize = true;
			this->labelUseSoap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelUseSoap->Location = System::Drawing::Point(17, 102);
			this->labelUseSoap->Name = L"labelUseSoap";
			this->labelUseSoap->Size = System::Drawing::Size(151, 18);
			this->labelUseSoap->TabIndex = 2;
			this->labelUseSoap->Text = L"Weekly use of soap : ";
			// 
			// labelUsePaper
			// 
			this->labelUsePaper->AutoSize = true;
			this->labelUsePaper->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelUsePaper->Location = System::Drawing::Point(17, 67);
			this->labelUsePaper->Name = L"labelUsePaper";
			this->labelUsePaper->Size = System::Drawing::Size(194, 18);
			this->labelUsePaper->TabIndex = 1;
			this->labelUsePaper->Text = L"Weekly use of toilet paper :  ";
			// 
			// labelFam
			// 
			this->labelFam->AutoSize = true;
			this->labelFam->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelFam->Location = System::Drawing::Point(17, 35);
			this->labelFam->Name = L"labelFam";
			this->labelFam->Size = System::Drawing::Size(163, 18);
			this->labelFam->TabIndex = 0;
			this->labelFam->Text = L"N° of family members : ";
			// 
			// buttonGuess
			// 
			this->buttonGuess->Location = System::Drawing::Point(805, 414);
			this->buttonGuess->Name = L"buttonGuess";
			this->buttonGuess->Size = System::Drawing::Size(111, 49);
			this->buttonGuess->TabIndex = 1;
			this->buttonGuess->Text = L"MAKE YOUR GUESS";
			this->buttonGuess->UseVisualStyleBackColor = true;
			this->buttonGuess->Click += gcnew System::EventHandler(this, &GameForm::buttonGuess_Click);
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(805, 486);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(111, 49);
			this->buttonSave->TabIndex = 2;
			this->buttonSave->Text = L"SAVE GAME";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &GameForm::buttonSave_Click);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1138, 638);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->buttonGuess);
			this->Controls->Add(this->groupInfo);
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &GameForm::GameForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->groupInfo->ResumeLayout(false);
			this->groupInfo->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		BufferedGraphics^buffer;
		BufferedGraphicsContext^context = BufferedGraphicsManager::Current;
		buffer = context->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(this->BackColor);

		topFam = gameSimulator->topFam();
		topUsePaper = gameSimulator->topUsePaper();
		topUseSoap = gameSimulator->topUseSoap();
		topUseGel = gameSimulator->topUseGel();
		topDesire = gameSimulator->topDesire();

		labelnumFam->Text = topFam.ToString();
		labelpaper->Text = topUsePaper.ToString();
		labelsoap->Text = topUseSoap.ToString();
		labelgel->Text = topUseGel.ToString();
		labelDes->Text = "< 0 ..... " + (topDesire + 2).ToString() + " >";

		gameSimulator->Draw(buffer->Graphics);
		gameSimulator->verify_Inventory();
		gameSimulator->verify_customers();

		if (gameSimulator->full_customers() == false) {
			labelFam->Text = L"";
			labelnumFam->Text = L"";
			labelUsePaper->Text = L"Your need of toilet paper :  ";
			labelpaper->Text = (topUsePaper * topFam + topDesire).ToString();
			labelUseSoap->Text = L"Your need of soap : ";
			labelsoap->Text = (topUseSoap * topFam + topDesire).ToString();
			labelUseGel->Text = L"Your need of gel : ";
			labelgel->Text = (topUseGel * topFam + topDesire).ToString();
			labelDes->Text = "";
			labelDesire->Text = L"";

			if (gameSimulator->missionAcomplish())
			{
				timer1->Enabled=false;
				MessageBox::Show("Congratulations!!! You've done it. You've got at least half of the amount of products you need to get through this quarantine with your family");
				this->Close();
			}
			else {
				timer1->Enabled = false;
				MessageBox::Show("I'm sorry. You couldn't get half of the amount of products you need, but that's how people behave in these trouble times.");
				this->Close();
			}

		}

		buffer->Render(g);

		delete buffer;
		delete context;


	}
	private: System::Void GameForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {

		timer1->Enabled = false;
	}
	private: System::Void GameForm_Load(System::Object^  sender, System::EventArgs^  e) {

		if (saveController == 1) {

			if(gameSimulator->getSets()->getSaveControl()==1){
				gameSimulator->chargeSaveGame();
			}

			if(gameSimulator->getSets()->getSaveControl() == 0){
				
				gameSimulator->chargeEverything_New();
				MessageBox::Show("There's no save simulation so let's make a new one");
			}

		}
		if(saveController==0) {
			gameSimulator->chargeEverything_New();
		}
	}
private: System::Void buttonGuess_Click(System::Object^  sender, System::EventArgs^  e) {

	if (gameSimulator->full_customers()) {
		if (gameSimulator->full_products()) {
			if (textBoxPaper->Text != "" && textBoxSoap->Text != "" && textBoxGel->Text != "") {
				topNeedPaper = System::Int32::Parse(textBoxPaper->Text);
				topNeedSoap = System::Int32::Parse(textBoxSoap->Text);
				topNeedGel = System::Int32::Parse(textBoxGel->Text);

				gameSimulator->afterGuess((short)topNeedPaper, (short)topNeedSoap, (short)topNeedGel);

				textBoxPaper->Text = "";
				textBoxSoap->Text = "";
				textBoxGel->Text = "";
			}
			else {
				MessageBox::Show("I know it's hard but you need to guess");
			}
		}
		else {

			MessageBox::Show("The market just ran out of every product. There's nothing left. I'm sorry");
			textBoxPaper->Text = "";
			textBoxSoap->Text = "";
			textBoxGel->Text = "";

			this->Close();
		}
	}

}
private: System::Void buttonSave_Click(System::Object^  sender, System::EventArgs^  e) {

	gameSimulator->SaveWritting();
	gameSimulator->saveGame();
}
};
}
