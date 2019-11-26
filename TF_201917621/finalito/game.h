#pragma once
#include"CJuego.hpp"
namespace finalito {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de game
	/// </summary>
	public ref class game : public System::Windows::Forms::Form
	{
	public:
		game(short tiempo, short vidas, short dificultad)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->tiempo = tiempo;
			this->vidas = vidas;
			this->dificultad = dificultad;
			jueguito = gcnew CJuego(this->ClientRectangle, this->dificultad, 1, this->tiempo, this->vidas);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~game()
		{
			if (components)
			{
				delete components;
			}
			delete jueguito;
		}
	private: System::Windows::Forms::Timer^  juego;
	private: System::Windows::Forms::Timer^  tempor;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->juego = (gcnew System::Windows::Forms::Timer(this->components));
			this->tempor = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// juego
			// 
			this->juego->Enabled = true;
			this->juego->Interval = 60;
			this->juego->Tick += gcnew System::EventHandler(this, &game::juego_Tick);
			// 
			// tempor
			// 
			this->tempor->Enabled = true;
			this->tempor->Interval = 1000;
			this->tempor->Tick += gcnew System::EventHandler(this, &game::tempor_Tick);
			// 
			// game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1265, 594);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"game";
			this->Text = L"game";
			this->Load += gcnew System::EventHandler(this, &game::game_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &game::game_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &game::game_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		CJuego^jueguito;
		bool  parar = false, detectarTime = false;
		short tiempoAnterior, level = 1, dificultad, vidas, tiempo;
	private: System::Void juego_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (parar)
		{
			delete jueguito;
			jueguito = gcnew CJuego(this->ClientRectangle, dificultad, level, tiempo, vidas);
			PlaySound(NULL, NULL, 0);
			if (level == 2)
			{
				PlaySound(TEXT("medioambiente.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			}
			if (level == 3)
			{
				PlaySound(TEXT("delincuencia.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			}
			parar = false;
		}
		Graphics ^graficador = this->CreateGraphics();
		BufferedGraphicsContext^espaciobuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espaciobuffer->Allocate(graficador, this->ClientRectangle);
		buffer->Graphics->Clear(this->BackColor);
		jueguito->jugar(this->ClientRectangle, buffer);
		buffer->Render(graficador);
		if (jueguito->parar == true)
		{
			if (jueguito->winner == true)
			{
				parar = true;
				if (++level >= 4)
				{
					PlaySound(NULL, NULL, 0);
					this->Text = "WINNER!!!";
					tempor->Enabled = false;
					juego->Enabled = false;
				}
				jueguito->winner = false;
			}
			else
			{
				PlaySound(NULL, NULL, 0);
				this->Text = "LOOSER!!!";
				PlaySound(NULL, NULL, 0);
				tempor->Enabled = false;
				juego->Enabled = false;
			}
		}
		delete buffer;
		delete espaciobuffer;
		delete graficador;
	}
	private: System::Void game_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		jueguito->moverJugador(e, this->ClientRectangle);
	}
	private: System::Void game_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Up || e->KeyCode == Keys::Down)
		{
			jueguito->limpiarJugadorDy();
		}
		if (e->KeyCode == Keys::Right|| e->KeyCode == Keys::Left)
		{
			jueguito->limpiarJugadorDx();
		}
	}
	private: System::Void tempor_Tick(System::Object^  sender, System::EventArgs^  e) {
		jueguito->disminuirTiempo();
		if (jueguito->getTiempo() == 0)
		{
			parar = true;
			tempor->Stop();
		}
		if (jueguito->getDetectarChoque())
		{
			if (detectarTime == false)
			{
				tiempoAnterior = jueguito->getTiempo();
				detectarTime = true;
			}
			if (tiempoAnterior - jueguito->getTiempo() == 3)
			{
				jueguito->habilitarDetectarChoque();
				detectarTime = false;
			}
		}
		if (jueguito->GetGetInvisible())
		{
			if (detectarTime == false)
			{
				tiempoAnterior = jueguito->getTiempo();
				detectarTime = true;
			}
			if (tiempoAnterior - jueguito->getTiempo() == 3)
			{
				jueguito->SetSetInvisible(0);
				detectarTime = false;
			}
		}
	}
	private: System::Void game_Load(System::Object^  sender, System::EventArgs^  e) {
		PlaySound(TEXT("corrupcion.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	};
}
