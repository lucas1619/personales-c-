#include "saveHuman.h"

class COtherPerson :public CHuman {
private:
public:

	COtherPerson() {}
	COtherPerson(short PosX, short PosY, short age, short fam, short desire, short usePPHH, short useSoap, short useGel) :CHuman(PosX, PosY, age, fam, desire, usePPHH, useSoap, useGel) {
	}
	~COtherPerson() {}

	void Draw(Graphics^ g) {
		g->FillRectangle(gcnew SolidBrush(Color::Green), this->PosX, this->PosY, this->Width, this->Height);
	}
};
