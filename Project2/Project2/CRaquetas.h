#pragma once
#include"CMovil.h"
#include<conio.h>
class CRaquetas :public CMovil
{
public:
	CRaquetas(short posx, short posy, bool inteligencia, CMapa *mapa, int velocidad) : CMovil(posx, posy, 3, 1, mapa, velocidad) {
		this->inteligencia = inteligencia;
		if (this->inteligencia == true)
		{
			arriba = false;
		}
	}
	short getAncho() {
		return this->columnas;
	}
	short getAlto() {
		return this->filas;
	}
	short getPosx() {
		return this->posx;
	}
	short getPosy() {
		return this->posy;
	}
	void setArriba(bool arriba) {
		this->arriba = arriba;
	}
private:
	bool inteligencia, arriba;
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
		char tecla;
		if (inteligencia == false)
		{
			if (_kbhit())
			{
				tecla = _getch();
				if (tecla == 'w')
				{
					if (mapa->pared(posx - 1, posy) == false)
					{
						posx--;
					}
				}
				if (tecla == 's')
				{
					if (mapa->pared(posx + 3, posy) == false)
					{
						posx++;
					}
				}
			}
		}
		else
		{
			if (arriba == true)
			{
				if (mapa->pared(posx - 1, posy) == false)
				{
					posx--;
				}
				else
				{
					arriba = false;
					posx++;
				}
			}
			else
			{
				if (mapa->pared(posx + 3, posy) == false)
				{
					posx++;
				}
				else
				{
					arriba = true;
					posx--;
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
				Console::ForegroundColor = ConsoleColor::DarkBlue;
				cout << dibujo[i][j];
			}
		}
	}
};