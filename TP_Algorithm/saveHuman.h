#include "Human.h"

class CSaveHuman {
private:
	short PosX;
	short PosY;
	short age;
	short fam;
	short desire;
	short usePPHH;
	short useSoap;
	short useGel;
public:
	short getAge() { return this->age; }
	short getFamilyMembers() { return this->fam; }
	short getUsePPHH() { return this->usePPHH; }
	short getUseSoap() { return this->useSoap; }
	short getUseGel() { return this->useGel; }
	short getPosX() { return this->PosX; }
	short getPosY() { return this->PosY; }
	short getRandomDesire() { return this->desire; }
	CSaveHuman() {}
	CSaveHuman(short PosX, short PosY, short age, short fam, short desire, short usePPHH, short useSoap, short useGel) {
		this->PosX = PosX;
		this->PosY = PosY;
		this->fam = fam;
		this->age = age;
		this->usePPHH = usePPHH;
		this->useSoap = useSoap;
		this->useGel = useGel;
		this->desire = desire;
	}
};
