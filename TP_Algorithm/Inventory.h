#include "Gel.h"

class CInventory {
private:

	TpStack<CProduct*>* pphhStack;
	TpStack<CProduct*>* soapStack;
	TpStack<CProduct*>* gelStack;

	SaveFiles<long long> *data;
	vector<long long>productsSizes;

public:
	CInventory() {
		pphhStack = new TpStack<CProduct*>();
		soapStack = new TpStack<CProduct*>();
		gelStack = new TpStack<CProduct*>();

		this->data = new SaveFiles<long long>("Inventory.upc");
	}
	~CInventory() {
		pphhStack = NULL;
		soapStack = NULL;
		gelStack = NULL;

		delete this->data;
		this->productsSizes.clear();
	}

	void chargeStacks_new() {
		srand(time(NULL));

		for (int i = 0; i < rand() % 80 + 50; ++i) {
			cout << "pphh" << i + 1 << " ";
			pphhStack->push(new CPPHH("Bolivar", 5));
		}
		for (int i = 0; i < rand() % 80 + 50; ++i) {
			cout << "soap" << i + 1 << " ";
			soapStack->push(new CSoap("Suavitel", 1));
		}
		for (int i = 0; i < rand() % 80 + 50; ++i) {
			cout << "gel" << i + 1 << " ";
			gelStack->push(new CGel("P&G", 10));
		}
	}

	void chargeStacks_files() {
		this->productsSizes.clear();
		this->data->chargeDatesFromVector(this->productsSizes);
		for (int i = 0; i < this->productsSizes.at(1); ++i) {
			cout << "pphh" << i + 1 << " ";
			pphhStack->push(new CPPHH());
		}
		for (int i = 0; i < this->productsSizes.at(0); ++i) {
			cout << "soap" << i + 1 << " ";
			soapStack->push(new CSoap());
		}
		for (int i = 0; i < this->productsSizes.at(2); ++i) {
			cout << "gel" << i + 1 << " ";
			gelStack->push(new CGel());
		}
	}
	void saveStacks_files() {
		this->productsSizes.clear(); //0 jabones, 1 pphh, 2 geles
		this->productsSizes.push_back(this->getsoapSize());
		this->productsSizes.push_back(this->getpphhSize());
		this->productsSizes.push_back(this->getgelSize());
		this->data->saveDatesFromVector(this->productsSizes);
	}

	void unstackPaper(short needPPHH) {

		for (int i = 0; i < needPPHH; ++i) {
			pphhStack->pop();
		}
	}

	void unstackSoap(short needSoap) {

		for (int i = 0; i < needSoap; ++i) {
			soapStack->pop();
		}
	}

	void unstackGel(short needGel) {

		for (int i = 0; i < needGel; ++i) {
			gelStack->pop();
		}
	}

	long long getpphhSize() {
		return pphhStack->getSize();
	}
	long long getsoapSize() {
		return soapStack->getSize();
	}
	long long getgelSize() {
		return gelStack->getSize();
	}
};