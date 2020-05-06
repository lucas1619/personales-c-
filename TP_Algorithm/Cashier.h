#include "OtherPerson.h"

class CCashier :public CHuman {
private:
public:

	CCashier() {}
	CCashier(short PosX, short PosY, short age, short fam, short desire, short usePPHH, short useSoap, short useGel) :CHuman(PosX, PosY, age, fam, desire, usePPHH, useSoap, useGel) {
	}
	~CCashier() {}

	void Draw(Graphics^ g) {
		g->FillRectangle(gcnew SolidBrush(Color::Blue), this->PosX, this->PosY, this->Width, this->Height);
	}
};