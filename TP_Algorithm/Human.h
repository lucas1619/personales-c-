#include "Inventory.h"

class CHuman {
protected:
	short PosX;
	short PosY;
	short Height;
	short Width;
	short age;
	short FamilyMembers; //number of family members
	short UsePPHH;
	short UseSoap;
	short UseGel;
	short NeedPPHH;
	short NeedSoap;
	short NeedGel;
	short RandomDesire;

public:

	CHuman() {}
	CHuman(short PosX, short PosY, short age, short fam, short desire, short usePPHH, short useSoap, short useGel) {
		this->PosX = PosX;
		this->PosY = PosY;
		this->Height = 30;
		this->Width = 30;
		this->age = age;
		this->FamilyMembers = fam;
		this->UsePPHH = usePPHH;
		this->UseSoap = useSoap;
		this->UseGel = useGel;
		this->RandomDesire = desire;
		this->NeedPPHH = (usePPHH * fam) + desire;
		this->NeedSoap = (useSoap * fam) + desire;
		this->NeedGel = (useGel * fam) + desire;
	}
	~CHuman() {}

	virtual void Draw(Graphics^ g) {};

	void setPosX(short Px) { this->PosX = Px; }
	void setPosY(short Py) { this->PosY = Py; }
	void setHeight(short h) { this->Height = h; }
	void setWidth(short w) { this->Width = w; }
	void setAge(short a) { this->age = a; }
	void setFamilyMembers(short fm) { this->FamilyMembers = fm; }
	void setUsePPHH(short Upphh) { this->UsePPHH = Upphh; }
	void setUseSoap(short Usoap) { this->UseSoap = Usoap; }
	void setUseGel(short Ugel) { this->UseGel = Ugel; }
	void setNeedPPHH(short Npphh) { this->NeedPPHH = Npphh; }
	void setNeedSoap(short NSoap) { this->NeedSoap = NSoap; }
	void setNeedGel(short NGel) { this->NeedGel = NGel; }
	void setRandomDesire(short des) { this->RandomDesire = des; }

	short getPosX() { return this->PosX; }
	short getPosY() { return this->PosY; }
	short getHeight() { return this->Height; }
	short getWidth() { return this->Width; }
	short getAge() { return this->age; }
	short getFamilyMembers() { return this->FamilyMembers; }
	short getUsePPHH() { return this->UsePPHH; }
	short getUseSoap() { return this->UseSoap; }
	short getUseGel() { return this->UseGel; }
	short getNeedPPHH() { return this->NeedPPHH; }
	short getNeedSoap() { return this->NeedSoap; }
	short getNeedGel() { return this->NeedGel; }
	short getRandomDesire() { return this->RandomDesire; }

};
