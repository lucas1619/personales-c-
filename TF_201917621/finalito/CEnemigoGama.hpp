#pragma once
#include"CEnemigo.hpp"
class CEnemigoGama : public CEnemigo
{
public:
	CEnemigoGama(System::Drawing::Rectangle areaDibujo, System::Drawing::Rectangle areaRecorte, short imgAncho, bool armado) : CEnemigo(areaDibujo, areaRecorte, imgAncho, 2, armado) {};
	void mover(short limitDown, short limitRight, Direccion direccion) {
		if (rand() % 1278 == 0)
		{
			invisible = !invisible;
		}
		if (areaDibujo.X + dx + areaDibujo.Width> limitRight || areaDibujo.X + dx < 0)
		{
			dx *= -1;
		}
		if (areaDibujo.Y + dy + areaDibujo.Height > limitDown || areaDibujo.Y + dy < 0)
		{
			dy *= -1;
		}
		this->areaDibujo.X += dx;
		this->areaDibujo.Y += dy;
		moverAreaRecorte(4);
	}
private:

};
