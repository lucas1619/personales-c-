#pragma once
#include"CObjetoAnimadp.hpp"
#include"CProyectil.hpp"
using namespace System;
using namespace System::Drawing;
class CJugador :public CObjetoAnimado
{
public:
	CJugador(System::Drawing::Rectangle areaDibujo, System::Drawing::Rectangle areaRecorte, short imgAncho, short vidas) : CObjetoAnimado(areaDibujo, areaRecorte, imgAncho) {
		this->vidas = vidas;
		proyectiles = new vector<CProyectil*>();
		cleardx();
		cleardy();
	}
	~CJugador() 
	{
		proyectiles->clear();
		delete proyectiles;
	}
	void cleardx() {
		dx = 0;
	}
	void cleardy() {
		dy = 0;
	}
	void disparar(short imgAnchoBala, short imgAltoBala) {
		if (areaRecorte.Y == 3 * areaRecorte.Height)
		{
			proyectiles->push_back(new CProyectil(System::Drawing::Rectangle(this->getPosx() + this->getAncho(), this->getPosy() + (this->getAlto() / 2), 10, 10), System::Drawing::Rectangle(0, 0, imgAnchoBala, imgAltoBala), imgAnchoBala, 1));
		}
		if (areaRecorte.Y == 0 * areaRecorte.Height)
		{
			proyectiles->push_back(new CProyectil(System::Drawing::Rectangle(this->getPosx() + this->getAncho(), this->getPosy() + (this->getAlto() / 2), 10, 10), System::Drawing::Rectangle(0, 0, imgAnchoBala, imgAltoBala), imgAnchoBala, 2));
		}
		if (areaRecorte.Y == 1 * areaRecorte.Height)
		{
			proyectiles->push_back(new CProyectil(System::Drawing::Rectangle(this->getPosx() + this->getAncho(), this->getPosy() + (this->getAlto() / 2), 10, 10), System::Drawing::Rectangle(0, 0, imgAnchoBala, imgAltoBala), imgAnchoBala, 3));
		}
		if (areaRecorte.Y == 2 * areaRecorte.Height)
		{
			proyectiles->push_back(new CProyectil(System::Drawing::Rectangle(this->getPosx() + this->getAncho(), this->getPosy() + (this->getAlto() / 2), 10, 10), System::Drawing::Rectangle(0, 0, imgAnchoBala, imgAltoBala), imgAnchoBala, 4));
		}
	}
	void mover(short limitDown, short limitRight, Direccion direccion, short anchobala, short altobala)
	{
		switch (direccion)
		{
		case Direccion::Arriba:
			if (areaDibujo.Y - dy > 0)
			{
				dy = -4;
				areaRecorte.Y = 3 * areaRecorte.Height;
			}
			else
			{
				dy = 0;
			}
			break;
		case Direccion::Abajo:
			if (areaDibujo.Y + areaDibujo.Height + dy < limitDown)
			{
				dy = 4;
				areaRecorte.Y = 0 * areaRecorte.Height;
			}
			else
			{
				dy = 0;
			}
			break;
		case Direccion::Izquierda:
			if (areaDibujo.X - dx > 0)
			{
				dx = -4;
				areaRecorte.Y = 1 * areaRecorte.Height;
			}
			else
			{
				dx = 0;
			}
			break;
		case Direccion::Derecha:
			if (areaDibujo.X + areaDibujo.Width + dx < limitRight)
			{
				dx = 4;
				areaRecorte.Y = 2 * areaRecorte.Height;
			}
			else
			{
				dx = 0;
			}
			break;
		case Direccion::Dispara:
			disparar(anchobala, altobala);
		}
		areaDibujo.X += dx;
		areaDibujo.Y += dy;
		moverAreaRecorte(4);
		cout << areaRecorte.X << endl;
	}
	void disminuirVidas() {
		this->vidas--;
	}
	short getVidas() {
		return this->vidas;
	}
	vector<CProyectil*>* getProyectiles() {
		return this->proyectiles;
	}
private:
	short vidas;
	vector<CProyectil*>*proyectiles;
};