#pragma once
#include<iostream>
#include<vector>
using namespace std;
using namespace System;
using namespace System::Drawing;
class CObjetoAnimado
{
public:
	enum Direccion { Arriba, Abajo, Izquierda, Derecha, Dispara };
	CObjetoAnimado(System::Drawing::Rectangle areaDibujo, System::Drawing::Rectangle areaRecorte, short imgAncho) {
		this->areaDibujo = areaDibujo; //short posx, posy, ancho, alto;
		this->areaRecorte = areaRecorte; //short posx, posy, ancho, alto;
		this->imgAncho = imgAncho;
		this->invisible = false;
		dx = dy = 5;
	};
	~CObjetoAnimado() {};
	void moverAreaRecorte(short imgAncho) {
		areaRecorte.X = (areaRecorte.X + areaRecorte.Width) % (imgAncho*areaRecorte.Width);
	}
	short getImgAncho() {
		return this->imgAncho;
	}
	virtual void mover(short limitDown, short limitRight, Direccion direccion) {}
	void dibujar(Bitmap^img, BufferedGraphics^buffer) {
		if (invisible)
		{
			return;
		}
		else
		{
			buffer->Graphics->DrawImage(img, areaDibujo, areaRecorte, GraphicsUnit::Pixel);

		}
	}
	bool colision(System::Drawing::Rectangle b) {
		if (areaDibujo.IntersectsWith(b))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void setInvisible(bool invisible) {
		this->invisible = invisible;
	}
	bool getInvisible() {
		return this->invisible;
	}
	System::Drawing::Rectangle getAreaDibujo() {
		return this->areaDibujo;
	}
	short getPosx() {
		return this->areaDibujo.X;
	}
	short getPosy() {
		return this->areaDibujo.Y;
	}
	short getAncho() {
		return this->areaDibujo.Width;
	}
	short getAlto() {
		return this->areaDibujo.Height;
	}
protected:
	//area de dibujo
	System::Drawing::Rectangle areaDibujo;
	//Rectangulo de recorte o origen o cortadito
	System::Drawing::Rectangle areaRecorte;
	//movimiento
	short dx, dy, imgAncho;
	bool invisible;
};