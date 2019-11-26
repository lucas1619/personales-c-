#pragma once
#include"CEnemigo.hpp"
class CEnemigoBeta : public CEnemigo
{
public:
	CEnemigoBeta(System::Drawing::Rectangle areaDibujo, System::Drawing::Rectangle areaRecorte, short imgAncho, bool armado) : CEnemigo(areaDibujo, areaRecorte, imgAncho, 2, armado) {};
	void mover(short limitDown, short limitRight, Direccion direccion) {
		bool derecha = areaDibujo.X + areaDibujo.Width + dx > limitRight;
		bool izquierda = areaDibujo.X + dx < 0;
		if (derecha || izquierda)
		{
			if (derecha)
			{
				areaRecorte.Y = areaRecorte.Height * 1;
			}
			if (izquierda)
			{
				areaRecorte.Y = areaRecorte.Height * 3;
			}
			dx *= -1;
		}
		this->areaDibujo.X += dx;
		moverAreaRecorte(4);
	}
private:

};
