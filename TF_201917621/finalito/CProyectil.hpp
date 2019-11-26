#pragma once
#include"CObjetoAnimadp.hpp"
class CProyectil : public CObjetoAnimado
{
public:
	CProyectil(System::Drawing::Rectangle areaDibujo, System::Drawing::Rectangle areaRecorte, short imgAncho, short direccion) :CObjetoAnimado(areaDibujo, areaRecorte, imgAncho) {
		this->eliminame = false;
		this->direccion = direccion;
		dx = 10;
		dy = 10;
	};
	~CProyectil() 
	{
	

	};
	void mover(short limitDown, short limitRight)
	{
		switch (direccion)
		{
		case 1://arriba
			dy = -10;
			if (areaDibujo.Y + dy <= 0)
			{
				eliminame = true;
			}
			areaDibujo.Y += dy;
			break;
		case 2://abajo
			if (areaDibujo.Y + dy >= limitDown)
			{
				eliminame = true;
			}
			areaDibujo.Y += dy;
			break;
		case 3://izquierda
			dx = -10;
			if (areaDibujo.X + dx <= 0)
			{
				eliminame = true;
			}
			areaDibujo.X += dx;
			break;
		case 4://derecha
			if (areaDibujo.X + dx >= limitRight)
			{
				eliminame = true;
			}
			areaDibujo.X += dx;
			break;
		}
	}
	bool getEliminame() {
		return this->eliminame;
	}
	void setEliminame(bool eliminame) {
		this->eliminame = eliminame;
	}
private:
	bool eliminame;
	short direccion;
};