#pragma once
#include"CObjetoAnimadp.hpp"
#include"CJugador.hpp"
#include"CProyectil.hpp"
class CEnemigo : public CObjetoAnimado
{
public:
	CEnemigo(System::Drawing::Rectangle areaDibujo, System::Drawing::Rectangle areaRecorte, short imgAncho, short handicap, bool armado) : CObjetoAnimado(areaDibujo, areaRecorte, imgAncho) {
		proyectiles = new vector<CProyectil*>();
		this->handicap = handicap;
		this->armado = armado;
		contador = 0;
	};
	~CEnemigo() {
		proyectiles->clear();
		delete proyectiles;
	};
	short getHandicap() {
		return this->handicap;
	}
	void disminuirHandicap() {
		this->handicap -= 1;
	}
	void disparar(CJugador *jugador, short imgAnchoBala, short imgAltoBala) {
		if (armado)
		{
			contador++;
			if (this->areaRecorte.Y == 1 * this->areaRecorte.Height && jugador->getPosx() + jugador->getAncho() < this->areaDibujo.X && this->areaDibujo.Y < jugador->getPosy() + jugador->getAlto() && this->areaDibujo.Y + this->areaDibujo.Height > jugador->getPosy())//disparar a la izquierda
			{
				if (contador % 15 == 0)
				{
					proyectiles->push_back(new CProyectil(System::Drawing::Rectangle(this->getPosx() + this->getAncho(), this->getPosy() + (this->getAlto() / 2), 10, 10), System::Drawing::Rectangle(0, 0, imgAnchoBala, imgAltoBala), 1, 3));
				}
			}
			if (this->areaRecorte.Y == 3 * this->areaRecorte.Height && this->areaDibujo.X + this->areaDibujo.Width < jugador->getPosx() && this->areaDibujo.Y < jugador->getPosy() + jugador->getAlto() && this->areaDibujo.Y + this->areaDibujo.Height > jugador->getPosy())//disparar a la derecha
			{
				if (contador % 15 == 0)
				{
					proyectiles->push_back(new CProyectil(System::Drawing::Rectangle(this->getPosx() + this->getAncho(), this->getPosy() + (this->getAlto() / 2), 10, 10), System::Drawing::Rectangle(0, 0, imgAnchoBala, imgAltoBala), 1, 4));
				}
			}
			if (this->areaRecorte.Y == 0 * this->areaRecorte.Height && jugador->getPosy() + jugador->getAlto() < this->areaDibujo.Y && this->areaDibujo.X < jugador->getPosx() + jugador->getAncho() && this->areaDibujo.X + this->areaDibujo.Width > jugador->getPosx())//disparar a la arriba
			{
				if (contador % 15 == 0)
				{
					proyectiles->push_back(new CProyectil(System::Drawing::Rectangle(this->getPosx() + this->getAncho(), this->getPosy() + (this->getAlto() / 2), 10, 10), System::Drawing::Rectangle(0, 0, imgAnchoBala, imgAltoBala), 1, 1));
				}
			}
			if (this->areaRecorte.Y == 2 * this->areaRecorte.Height && this->areaDibujo.Y + this->areaDibujo.Height > jugador->getPosy() && this->areaDibujo.X < jugador->getPosx() + jugador->getAncho() && this->areaDibujo.X + this->areaDibujo.Width > jugador->getPosx())//disparar a la abajo
			{
				if (contador % 15 == 0)
				{
					proyectiles->push_back(new CProyectil(System::Drawing::Rectangle(this->getPosx() + this->getAncho(), this->getPosy() + (this->getAlto() / 2), 10, 10), System::Drawing::Rectangle(0, 0, imgAnchoBala, imgAltoBala), 1, 2));
				}
			}
		}
	}
	void colisionProyectilJugador(CJugador *jugador) {
		for (short i = 0; i < proyectiles->size(); i++)
		{
			if (proyectiles->at(i)->colision(jugador->getAreaDibujo()))
			{
				jugador->disminuirVidas();
				proyectiles->erase(proyectiles->begin() + i);
				break;
			}
		}
	}
	vector<CProyectil*>*getProyectiles() {
		return this->proyectiles;
	}
protected:
	short handicap, contador;
	vector<CProyectil*>*proyectiles;
public: bool armado;
};