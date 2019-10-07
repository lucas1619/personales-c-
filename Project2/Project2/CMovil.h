#pragma once
#include<iostream>
#include"CMapa.h"
using namespace std;
using namespace System;
class CMovil abstract
{
public:
	CMovil(short posx, short posy, short filas, short columnas, CMapa *mapa, int velocidad):posx(posx), posy(posy), filas(filas), columnas(columnas), mapa(mapa), velocidad(velocidad){
		iniciardibujo();
	}
	~CMovil() {
		delete mapa;
		for (short i = 0; i < filas; i++)
		{
			delete[] dibujo[i];
		}
		delete dibujo;
	}
	void desplazar() {
		cont++;
		if (cont == velocidad)
		{
			borrar();
			mover();
			pintar();
			cont = 0;
		}
	}
protected:
	short posx, posy, filas, columnas;
	int velocidad, cont = 0;
	CMapa *mapa;
	char **dibujo = new char*[filas];
	void iniciardibujo() {
		for (short i = 0; i < filas; i++)
		{
			dibujo[i] = new char[columnas];
		}
		for (short i = 0; i < filas; i++)
		{
			for (short j = 0; j < columnas; j++)
			{
				dibujo[i][j] = char(219);
			}
		}
	}
	virtual void borrar() {}
	virtual void mover() {}
	virtual void pintar() {}
};