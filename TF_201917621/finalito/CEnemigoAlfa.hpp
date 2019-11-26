#pragma once
#include"CEnemigo.hpp"
class CEnemigoAlfa : public CEnemigo
{
public:
	CEnemigoAlfa(System::Drawing::Rectangle areaDibujo, System::Drawing::Rectangle areaRecorte, short imgAncho, bool armado) : CEnemigo(areaDibujo, areaRecorte, imgAncho, 2, armado) {};
	void mover(short limitDown, short limitRight, Direccion direccion) {
		if (areaDibujo.Y + areaDibujo.Height + dy > limitDown || areaDibujo.Y + dy < 0)
		{
			if (areaDibujo.Y + areaDibujo.Height + dy > limitDown)
			{
				areaRecorte.Y = areaRecorte.Height * 0;
			}
			if (areaDibujo.Y + dy < 0)
			{
				areaRecorte.Y = areaRecorte.Height * 2;
			}
			dy *= -1;
		}
		this->areaDibujo.Y += dy;
		moverAreaRecorte(4);
	}
private:

};
