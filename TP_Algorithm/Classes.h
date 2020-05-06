#pragma once
#include "Settings.h"
#include <conio.h>

class CGame {
private:

	bool inventory_full;
	bool customers_full;
	CCustomers* queueCust;
	CInventory* stackInve;
	CSettings* sets;

	//vector<short> savePosX;

public:

	CGame() {
		sets = new CSettings;
		sets->read_first();
		queueCust = new CCustomers();
		stackInve = new CInventory();
		inventory_full = true;
		customers_full = true;
	}
	~CGame() {}

	void chargeEverything_New() {

		srand(time(NULL));
		system("cls");
		cout << sets->getSaveControl() << endl;
		queueCust->chargeQueue_new();
		stackInve->chargeStacks_new();

		queueCust->delete_minorcustomers();

		cout << endl;
		cout << endl;
		cout << endl;
	}

	void chargeSaveGame() {
		stackInve->chargeStacks_files();
		queueCust->chargeQueues_files();
	}

	void saveGame() {
		stackInve->saveStacks_files();
		queueCust->saveQueues_files();
	}


	void Draw(Graphics^ g) {

		g->FillRectangle(gcnew SolidBrush(Color::BurlyWood), 300, 20, 150, 90); //drawing inventory
		queueCust->Draw(g);

	}

	void verify_Inventory() {
		if (stackInve->getpphhSize() == 0 && stackInve->getsoapSize() == 0 && stackInve->getgelSize() == 0) {
			inventory_full = false;
		}
	}

	void verify_customers()
	{
		if (queueCust->getQueueSize()==1) {
			customers_full = false;
		}
	}

	void afterGuess(short guessPaper, short guessSoap, short guessGel) {

		queueCust->verifyPaper(guessPaper);
		queueCust->verifySoap(guessSoap);
		queueCust->verifyGel(guessGel);

		if (stackInve->getpphhSize() > 0) {
			if (stackInve->getpphhSize() - queueCust->getFront()->getNeedPPHH() > 0) {
				
				stackInve->unstackPaper(queueCust->getFront()->getNeedPPHH());
				
			}
			else {
				stackInve->unstackPaper(stackInve->getpphhSize());
			}
		}

		if (stackInve->getsoapSize() > 0) {
			if (stackInve->getsoapSize() - queueCust->getFront()->getNeedSoap() > 0) {

				stackInve->unstackSoap(queueCust->getFront()->getNeedSoap());

			}
			else {
				stackInve->unstackSoap(stackInve->getsoapSize());
			}
		}

		if (stackInve->getgelSize() > 0) {
			if (stackInve->getgelSize() - queueCust->getFront()->getNeedGel() > 0) {

				stackInve->unstackGel(queueCust->getFront()->getNeedGel());

			}
			else {
				stackInve->unstackGel(stackInve->getgelSize());
			}
		}

		queueCust->unQueue();

		cout << endl;
		cout << endl;
		cout << stackInve->getpphhSize() << endl;
		cout << stackInve->getsoapSize() << endl;
		cout << stackInve->getgelSize() << endl;
		
	}

	void attendPlayer() {

		
		if (stackInve->getpphhSize() > 0) {
			if (stackInve->getpphhSize() - queueCust->getFront()->getNeedPPHH() > 0) {

				stackInve->unstackPaper(queueCust->getFront()->getNeedPPHH());

			}
			else {
				stackInve->unstackPaper(stackInve->getpphhSize());
			}
		}

		if (stackInve->getsoapSize() > 0) {
			if (stackInve->getsoapSize() - queueCust->getFront()->getNeedSoap() > 0) {

				stackInve->unstackSoap(queueCust->getFront()->getNeedSoap());

			}
			else {
				stackInve->unstackSoap(stackInve->getsoapSize());
			}
		}

		if (stackInve->getgelSize() > 0) {
			if (stackInve->getgelSize() - queueCust->getFront()->getNeedGel() > 0) {

				stackInve->unstackGel(queueCust->getFront()->getNeedGel());

			}
			else {
				stackInve->unstackGel(stackInve->getgelSize());
			}
		}

	}

	bool missionAcomplish() {

		attendPlayer();

		if (queueCust->getFront()->getNeedPPHH() / 2 <= stackInve->getpphhSize() && queueCust->getFront()->getNeedSoap() / 2 <= stackInve->getsoapSize() &&
			queueCust->getFront()->getNeedGel() / 2 <= stackInve->getgelSize()) {

			return true;
		}
		else {
			return false;
		}
	}

	short topFam() {
		return queueCust->getFront()->getFamilyMembers();
	}
	short topUsePaper() {
		return queueCust->getFront()->getUsePPHH();
	}
	short topUseSoap() {
		return queueCust->getFront()->getUseSoap();
	}
	short topUseGel() {
		return queueCust->getFront()->getUseGel();
	}
	short topDesire() {
		return queueCust->getFront()->getRandomDesire();
	}

	bool full_products(){
		return this->inventory_full;
	}
	bool full_customers() {
		return this->customers_full;
	}

	CSettings* getSets() {
		return this->sets;
	}

	void SaveWritting() {
		sets->write_first();
	}

};
