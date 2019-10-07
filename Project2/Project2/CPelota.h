#pragma once
#include"CMovil.h"
#include"CRaquetas.h"
class CPelota : public CMovil
{
public:
	CPelota(short posx, short posy, CMapa *mapa, bool arriba, bool abajo, bool derecha, bool izquierda, CRaquetas *a, CRaquetas *b, int velocidad) : CMovil(posx, posy, 1, 1, mapa, velocidad) {
		this->abajo = abajo;
		this->arriba = arriba;
		this->derecha = derecha;
		this->izquierda = izquierda;
		this->a = a;
		this->b = b;
	}
	void avisarIA(CRaquetas *b){
		if (this->posx > b->getPosx())
		{
			b->setArriba(false);
		}
		else
		{
			b->setArriba(true);
		}
	}
private:
	CRaquetas *a;
	CRaquetas *b;
	bool arriba, abajo, derecha, izquierda;
	bool colision(CRaquetas *r) {
		if ((r->getPosy() + r->getAncho() >= this->posy && r->getPosy() <= this->posy+1)&& (r->getPosx() + r->getAlto() >= this->posx && r->getPosx() <= this->posx))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void negar() {
		arriba = false;
		abajo = false;
		derecha = false;
		izquierda = false;
	}
	void borrar() {
		for (short i = 0; i < filas; i++)
		{
			for (short j = 0; j < columnas; j++)
			{
				Console::SetCursorPosition(posy + j, posx + i);
				cout << char(0);
			}
		}
	}
	void mover() {
		if (arriba == true && derecha == true)
		{
			if (posy == 119 || posy == 0)
			{
				posx = 15;
				posy = 60;
			}
			else
			{
				if (colision(a) == true || colision(b) == true)
				{
					negar();
					arriba = true;
					izquierda = true;
					posx--;
					posy = posy - 2;
				}
				if (colision(a) == false && colision(b) == false)
				{
					if (mapa->pared(posx - 1, posy + 1) == false)
					{
						posx--;
						posy++;
					}
					else
					{
						negar();
						abajo = true;
						derecha = true;
					}
				}
			}
		}
		if (arriba == true && izquierda == true)
		{
			if (posy == 118 || posy == 1)
			{
				posx = 15;
				posy = 60;
			}
			else
			{
				if (colision(a) == true || colision(b) == true)
				{
					negar();
					arriba = true;
					derecha = true;
					posx--;
					posy = posy + 2;
				}
				if (colision(a) == false && colision(b) == false)
				{
					if (mapa->pared(posx - 1, posy - 1) == false)
					{
						posx--;
						posy--;
					}
					else
					{
						negar();
						abajo = true;
						izquierda = true;
					}
				}
			}
		}
		if (abajo == true && derecha == true)
		{
			if (posy == 118 || posy == 1)
			{
				posx = 15;
				posy = 60;
			}
			else
			{
				if (colision(a) == true || colision(b) == true)
				{
					negar();
					abajo = true;
					izquierda = true;
					posx++;
					posy = posy - 2;
				}
				if (colision(a) == false && colision(b) == false)
				{
					if (mapa->pared(posx + 1, posy + 1) == false)
					{
						posx++;
						posy++;
					}
					else
					{
						negar();
						arriba = true;
						derecha = true;
					}
				}
			}
		}
		if (abajo == true && izquierda == true)
		{
			if (colision(a) == true || colision(b) == true)
			{
				negar();
				abajo = true;
				derecha = true;
				posx++;
				posy = posy + 2;
			}
			if (colision(a) == false && colision(b) == false)
			{
				if (posy == 118 || posy == 1)
				{
					posx = 15;
					posy = 60;
				}
				else
				{
					if (mapa->pared(posx + 1, posy - 1) == false)
					{
						posx++;
						posy--;
					}
					else
					{
						negar();
						arriba = true;
						izquierda = true;
					}
				}
			}
		}
	}
	void pintar() {
		for (short i = 0; i < filas; i++)
		{
			for (short j = 0; j < columnas; j++)
			{
				Console::SetCursorPosition(posy + j, posx + i);
				Console::ForegroundColor = ConsoleColor::Red;
				cout << dibujo[i][j];
			}
		}
	}
};