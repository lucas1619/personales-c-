#pragma once
#include<iostream>
using namespace std;
using namespace System;
class CMapa
{
public:
	CMapa() {
		for (short i = 0; i < filas; i++)
		{
			mapa[i] = new short[columnas];
		}
		for (short i = 0; i < filas; i++)
		{
			for (short j = 0; j < columnas; j++)
			{
				if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1 || j == (columnas-1)/2)
				{
					if (j == (columnas - 1) / 2 && (i != 0 || i != filas - 1))
					{
						mapa[i][j] = 2;
					}
					if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1)
					{
						mapa[i][j] = 1;
					}
				}
				else
				{
					mapa[i][j] = 0;
				}
			}
		}
		for (short i = 0; i < filas; i++)
		{
			for (short j = 0; j < columnas; j++)
			{
				Console::SetCursorPosition(0 + j, 0 + i);
				if (mapa[i][j] == 1)
				{
					cout << char(219);
				}
				if (mapa[i][j] == 2)
				{
					cout << char(254);
				}
				if (mapa[i][j] == 0)
				{
					cout << char(0);
				}
			}
		}
	};
	~CMapa() {};
	bool pared(short posx, short posy) {
		if (mapa[posx][posy] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool medio(short posx, short posy) {
		if (mapa[posx][posy] == 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	const short filas = 30;
	const short columnas = 120;
	short **mapa = new short*[filas];
};