#include "Cashier.h"

class CPlayer :public CHuman {
private:
public:

	CPlayer() {}
	CPlayer(short PosX, short PosY, short age, short fam, short desire, short usePPHH, short useSoap, short useGel) :CHuman(PosX, PosY, age, fam, desire, usePPHH, useSoap, useGel) {
	}
	~CPlayer() {}

	void Draw(Graphics^ g) {
		g->FillRectangle(gcnew SolidBrush(Color::Red), this->PosX, this->PosY, this->Width, this->Height);
	}
};
