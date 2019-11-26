#pragma once
#include<Windows.h>
#include <MMSystem.h>
#include"CJugador.hpp"
#include"CEnemigoAlfa.hpp"
#include"CEnemigoBeta.hpp"
#include"CEnemigoGama.hpp"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
ref class CJuego
{
public:
	CJuego(System::Drawing::Rectangle areaPantalla, short dificultad, short nivel, short tiempo, short vidas) {
		this->areaPantalla = areaPantalla;
		enemigos = new vector<CEnemigo*>();
		imgJugador = gcnew Bitmap("img\\jugador.png");
		jugador = new CJugador(System::Drawing::Rectangle(rand() % (areaPantalla.Width - 50) + 5, rand() % (areaPantalla.Height - 100) + 5, 40, 50), System::Drawing::Rectangle(0, 0, imgJugador->Width / 4, imgJugador->Height / 4), imgJugador->Width, vidas);
		setLevel(nivel);
		setDificultad(dificultad);
		cargar();
		this->tiempo = tiempo;
		puntaje = 0;
		contaInvisible = 2;
	};
	~CJuego() 
	{
		enemigos->clear();
		delete enemigos;
		delete jugador;
		delete imgEnemigo;
		delete imgJugador;
		delete imgEscenario;
		delete imgProyectilJugador;
		delete imgProyectilEnemigo;
	};
	CObjetoAnimado::Direccion direc;
	bool getDetectarChoque() {
		return this->detectarChoque;
	}
	void habilitarDetectarChoque() {
		detectarChoque = false;
	}
	void limpiarEnemigos() {
		for (short i = 0; i < enemigos->size(); i++)
		{
			delete enemigos->back();
			enemigos->pop_back();
		}
	}
	void limpiarJugadorDx() {
		jugador->cleardx();
		derecha = false;
		izquierda = false;
	}
	void limpiarJugadorDy() {
		jugador->cleardy();
		arriba = false;
		abajo = false;
	}
	short getTiempo() {
		return this->tiempo;
	}
	void resetTiempo() {
		this->tiempo = 150;
	}
	void disminuirTiempo() {
		tiempo--;
	}
	void setDificultad(short dificultad) {
		switch (dificultad)
		{
		case 2://Principiante
			this->cantalfa = 8;
			this->cantbeta = 8;
			this->cantgama = 4;
			armadoalfa = 0;//enemigo armado o no
			armadobeta = 1;
			armadogama = 1;
			break;
		case 3://avanzado
			this->cantalfa = 10;
			this->cantbeta = 10;
			this->cantgama = 6;
			armadoalfa = 1;
			armadobeta = 1;
			armadogama = 1;
			break;
		}
	}
	void setLevel(short level) {
		switch (level)
		{
		case 1://mundo corrupto
			imgEnemigo = gcnew Bitmap("img\\enemigo1.png");
			imgEscenario = gcnew Bitmap("img\\escenario1.jpeg");
			imgProyectilJugador = gcnew Bitmap("img\\pjugador1.png");
			imgProyectilEnemigo = gcnew Bitmap("img\\penemigo1.png");
			break;
		case 2://salvemos al medio ambiente
			delete imgEnemigo;
			delete imgEscenario;
			delete imgProyectilJugador;
			delete imgProyectilEnemigo;
			imgEnemigo = gcnew Bitmap("img\\enemigo2.png");
			imgEscenario = gcnew Bitmap("img\\escenario2.jpeg");
			imgProyectilJugador = gcnew Bitmap("img\\pjugador1.png");
			imgProyectilEnemigo = gcnew Bitmap("img\\penemigo2.png");
			break;
		case 3://mundo delincuencial
			delete imgEnemigo;
			delete imgEscenario;
			delete imgProyectilJugador;
			delete imgProyectilEnemigo;
			imgEnemigo = gcnew Bitmap("img\\enemigo3.png");
			imgEscenario = gcnew Bitmap("img\\escenario3.jpeg");
			imgProyectilJugador = gcnew Bitmap("img\\pjugador1.png");
			imgProyectilEnemigo = gcnew Bitmap("img\\penemigo3.png");
			break;
		}
	}
	void cargar() {
		cantalfa += 2;
		cantbeta += 2;
		cantgama += 2;
		for (short i = 0; i < cantalfa; i++)
		{
			enemigos->push_back(new CEnemigoAlfa(System::Drawing::Rectangle(rand() % (areaPantalla.Width - 50) + 5, rand() % (areaPantalla.Height - 100) + 5, 40, 50), System::Drawing::Rectangle(0, 0, imgEnemigo->Width / 4, imgEnemigo->Height / 4), imgEnemigo->Width, armadoalfa));
		}
		for (short i = 0; i < cantbeta; i++)
		{
			enemigos->push_back(new CEnemigoBeta(System::Drawing::Rectangle(rand() % (areaPantalla.Width - 50) + 5, rand() % (areaPantalla.Height - 100) + 5, 40, 50), System::Drawing::Rectangle(0, 0, imgEnemigo->Width / 4, imgEnemigo->Height / 4), imgEnemigo->Width, armadobeta));
		}
		for (short i = 0; i < cantgama; i++)
		{
			enemigos->push_back(new CEnemigoGama(System::Drawing::Rectangle(rand() % (areaPantalla.Width - 50) + 5, rand() % (areaPantalla.Height - 100) + 5, 40, 50), System::Drawing::Rectangle(0, 0, imgEnemigo->Width / 4, imgEnemigo->Height / 4), imgEnemigo->Width, armadogama));
		}
	}
	void jugar(System::Drawing::Rectangle areaPantalla, BufferedGraphics^buffer) {
		buffer->Graphics->DrawImage(imgEscenario, areaPantalla);
		buffer->Graphics->DrawString("Tiempo: " + Convert::ToString(tiempo), gcnew Drawing::Font("Arial Black", 12), gcnew SolidBrush(Color::Red), Point(10, 10));
		buffer->Graphics->DrawString("Vidas: " + Convert::ToString(jugador->getVidas()), gcnew Drawing::Font("Arial Black", 12), gcnew SolidBrush(Color::Red), Point(10, 30));
		buffer->Graphics->DrawString("Puntaje: " + Convert::ToString(puntaje), gcnew Drawing::Font("Arial Black", 12), gcnew SolidBrush(Color::Red), Point(10, 50));
		for (short i = 0; i < enemigos->size(); i++)
		{
			enemigos->at(i)->mover(areaPantalla.Height, areaPantalla.Width, direc);
			enemigos->at(i)->dibujar(imgEnemigo, buffer);
		}
		if (detectarChoque == false)
		{
			for (short i = 0; i < enemigos->size(); i++)
			{
				if (jugador->getAreaDibujo().IntersectsWith(enemigos->at(i)->getAreaDibujo()))
				{
					jugador->disminuirVidas();
					delete enemigos->at(i);
					enemigos->erase(enemigos->begin() + i);
					detectarChoque = true;
					break;
				}
			}
		}
		if (arriba)
		{
			jugador->mover(areaPantalla.Height, areaPantalla.Width, CObjetoAnimado::Direccion::Arriba, imgProyectilJugador->Width, imgProyectilJugador->Height);
		}
		if (abajo)
		{
			jugador->mover(areaPantalla.Height, areaPantalla.Width, CObjetoAnimado::Direccion::Abajo, imgProyectilJugador->Width, imgProyectilJugador->Height);
		}
		if (izquierda)
		{
			jugador->mover(areaPantalla.Height, areaPantalla.Width, CObjetoAnimado::Direccion::Izquierda, imgProyectilJugador->Width, imgProyectilJugador->Height);
		}
		if (derecha)
		{
			jugador->mover(areaPantalla.Height, areaPantalla.Width, CObjetoAnimado::Direccion::Derecha, imgProyectilJugador->Width, imgProyectilJugador->Height);
		}
		jugador->dibujar(imgJugador, buffer);
		for (short i = 0; i < jugador->getProyectiles()->size(); i++)
		{
			jugador->getProyectiles()->at(i)->mover(areaPantalla.Height, areaPantalla.Width);
			if (jugador->getProyectiles()->at(i)->getEliminame())
			{
				delete jugador->getProyectiles()->at(i);
				jugador->getProyectiles()->erase(jugador->getProyectiles()->begin() + i);
				break;
			}
			for (short j = 0; j < enemigos->size(); j++)
			{
				if (jugador->getProyectiles()->at(i)->colision(enemigos->at(j)->getAreaDibujo()))
				{
					delete enemigos->at(j);
					delete jugador->getProyectiles()->at(i);
					enemigos->erase(enemigos->begin() + j);
					jugador->getProyectiles()->erase(jugador->getProyectiles()->begin() + i);
					puntaje += 10;
					break;
				}
			}
		}
		for (short i = 0; i < jugador->getProyectiles()->size(); i++)
		{
			jugador->getProyectiles()->at(i)->dibujar(imgProyectilJugador, buffer);
		}
		for (short i = 0; i < enemigos->size(); i++)
		{
			if (enemigos->at(i)->armado)
			{
				enemigos->at(i)->disparar(jugador, imgProyectilEnemigo->Width, imgProyectilEnemigo->Height);
			}
		}
		for (short i = 0; i < enemigos->size(); i++)
		{
			for (short j = 0; j < enemigos->at(i)->getProyectiles()->size(); j++)
			{
				enemigos->at(i)->getProyectiles()->at(j)->mover(areaPantalla.Height, areaPantalla.Width);
				if (enemigos->at(i)->getProyectiles()->at(j)->colision(jugador->getAreaDibujo()))
				{
					delete enemigos->at(i)->getProyectiles()->at(j);
					enemigos->at(i)->getProyectiles()->erase(enemigos->at(i)->getProyectiles()->begin() + j);
					jugador->disminuirVidas();
					break;
				}
				enemigos->at(i)->getProyectiles()->at(j)->dibujar(imgProyectilEnemigo, buffer);
			}
		}
		if (jugador->getVidas() <= 0 || enemigos->size() == 0)
		{
			this->parar = true;
			if (enemigos->size() == 0)
			{
				winner = true;
			}
			if (jugador->getVidas() == 0)
			{
				winner = false;
			}
		}
	}
	void moverJugador(System::Windows::Forms::KeyEventArgs^  e, System::Drawing::Rectangle areaPantalla) {
		if (e->KeyCode == Keys::Up)
		{
			arriba = true;
			abajo = false;
		}
		if (e->KeyCode == Keys::Down)
		{
			arriba = false;
			abajo = true;
		}
		if (e->KeyCode == Keys::Left)
		{
			izquierda = true;
			derecha = false;
		}
		if (e->KeyCode == Keys::Right)
		{
			izquierda = false;
			derecha = true;
		}
		if (e->KeyCode == Keys::Space)
		{
			jugador->mover(areaPantalla.Height, areaPantalla.Width, CObjetoAnimado::Direccion::Dispara, imgProyectilJugador->Width, imgProyectilJugador->Height);
		}
		if (e->KeyCode == Keys::P)
		{
			if (puntaje >= 10 && contaInvisible > 0)
			{
				jugador->setInvisible(1);
				contaInvisible -= 1;
			}
		}
	}
	void SetSetInvisible(bool invisible) {
		jugador->setInvisible(invisible);
	}
	bool GetGetInvisible() {
		return jugador->getInvisible();
	}
	
public: bool parar, winner;
private:
	bool detectarChoque;
	System::Drawing::Rectangle areaPantalla;
	vector<CEnemigo*>*enemigos;
	short tiempo;
	bool arriba, abajo, izquierda, derecha;
	short cantalfa;
	bool armadoalfa;
	short cantbeta;
	bool armadobeta;
	short cantgama;
	bool armadogama;
	short puntaje;
	short contaInvisible;
	CJugador *jugador;
	Bitmap ^imgEnemigo;
	Bitmap ^imgJugador;
	Bitmap ^imgEscenario;
	Bitmap ^imgProyectilJugador;
	Bitmap ^imgProyectilEnemigo;
};