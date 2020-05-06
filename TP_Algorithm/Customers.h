#include "Player.h"

class CCustomers {
private:
	TpDoubleLinkedList<CHuman*>* customersQueue;
	SaveFiles<CSaveHuman>*data;
	vector<CSaveHuman>personData;

public:
	CCustomers() {
		customersQueue = new TpDoubleLinkedList<CHuman*>();
		data = new SaveFiles<CSaveHuman>("Customers.upc");
	}
	~CCustomers() {
		customersQueue = NULL;
	}

	void chargeQueue_new() {

		int pos;
		for (int i = 0; i < rand() % 10 + 3; ++i) {
			cout << "guy " << i + 1 << " ";
			customersQueue->push(new COtherPerson(180, 125 + pos, rand() % 70 + 8, rand() % 4 + 1, rand() % 4 + 1, rand() % 6 + 2, rand() % 6 + 2, rand() % 6 + 2));
			pos += 80;
		}
		cout << "cashier ";
		customersQueue->push(new CCashier(95, 30, 20, rand() % 4 + 1, rand() % 4 + 1, rand() % 6 + 2, rand() & 6 + 2, rand() % 6 + 2));
		cout << "you ";
		customersQueue->push(new CPlayer(180, 125 + pos, 19, rand() % 4 + 1, rand() % 4 + 1, rand() % 6 + 2, rand() & 6 + 2, rand() % 6 + 2));

	}

	void chargeQueues_files() {
		this->personData.clear();
		this->data->chargeDatesFromVector(this->personData);
		int i;
		for (i = 0; i < this->personData.size() - 2; ++i) {
			cout << "guy " << i + 1 << " ";
			customersQueue->push(new COtherPerson(this->personData.at(i).getPosX(),
				this->personData.at(i).getPosY(),
				this->personData.at(i).getAge(),
				this->personData.at(i).getFamilyMembers(),
				this->personData.at(i).getRandomDesire(),
				this->personData.at(i).getUsePPHH(),
				this->personData.at(i).getUseSoap(),
				this->personData.at(i).getUseGel()
			));
		}
		cout << "cashier ";
		customersQueue->push(new CCashier(this->personData.at(i).getPosX(),
			this->personData.at(i).getPosY(),
			this->personData.at(i).getAge(),
			this->personData.at(i).getFamilyMembers(),
			this->personData.at(i).getRandomDesire(),
			this->personData.at(i).getUsePPHH(),
			this->personData.at(i).getUseSoap(),
			this->personData.at(i).getUseGel()
		));
		++i;
		cout << "you ";
		customersQueue->push(new CPlayer(this->personData.at(i).getPosX(),
			this->personData.at(i).getPosY(),
			this->personData.at(i).getAge(),
			this->personData.at(i).getFamilyMembers(),
			this->personData.at(i).getRandomDesire(),
			this->personData.at(i).getUsePPHH(),
			this->personData.at(i).getUseSoap(),
			this->personData.at(i).getUseGel()
		));
		for (int i = 0; i < customersQueue->getSize(); ++i) {
			cout << customersQueue->getElement(i)->getAge() << endl;
		}
	}
	void saveQueues_files() {
		this->personData.clear(); //<= size-3 otherperson ,size-2 -> cashier, size-1 player
		for (int i = 0; i < this->customersQueue->getSize(); ++i) {
			this->personData.push_back(CSaveHuman(customersQueue->getElement(i)->getPosX(),
				customersQueue->getElement(i)->getPosY(), customersQueue->getElement(i)->getAge(),
				customersQueue->getElement(i)->getFamilyMembers(), customersQueue->getElement(i)->getRandomDesire(),
				customersQueue->getElement(i)->getUsePPHH(), customersQueue->getElement(i)->getUseSoap(),
				customersQueue->getElement(i)->getUseGel()));
		}
		this->data->saveDatesFromVector(this->personData);
	}

	void delete_minorcustomers() {
		auto verifyAge = [](CHuman* costumer) {return (costumer->getAge() > 18 && costumer->getAge() < 70); };

		for (int i = 0; i < customersQueue->getSize() - 2; ++i) {
			customersQueue->deleteNotNeeded(i, verifyAge);
			//cout << "elimino" << endl;
			cout << customersQueue->getSize();
		}

		int pos = 0;
		for (int j = 0; j < customersQueue->getSize() - 2; ++j) {
			customersQueue->getElement(j)->setPosY(125 + pos);
			pos += 50;
		}

		customersQueue->getElement(customersQueue->getSize() - 1)->setPosY(125 + pos);
	}

	void Draw(Graphics^ g) {
		for (int i = 0; i < customersQueue->getSize(); ++i) {
			customersQueue->getElement(i)->Draw(g);
		}
	}


	void verifyPaper(short guessPaper) {
		if (customersQueue->front()->getNeedPPHH() == guessPaper) {
			customersQueue->front()->setNeedPPHH(customersQueue->front()->getNeedPPHH() - customersQueue->front()->getRandomDesire() - 2);
		}
		else {
			customersQueue->front()->setNeedPPHH(customersQueue->front()->getNeedPPHH() + 4);
		}
	}
	void verifySoap(short guessSoap) {
		if (customersQueue->front()->getNeedSoap() == guessSoap) {
			customersQueue->front()->setNeedSoap(customersQueue->front()->getNeedSoap() - customersQueue->front()->getRandomDesire() - 2);
		}
		else {
			customersQueue->front()->setNeedSoap(customersQueue->front()->getNeedSoap() + 4);
		}
	}
	void verifyGel(short guessGel) {
		if (customersQueue->front()->getNeedGel() == guessGel) {
			customersQueue->front()->setNeedGel(customersQueue->front()->getNeedGel() - customersQueue->front()->getRandomDesire() - 2);
		}
		else {
			customersQueue->front()->setNeedGel(customersQueue->front()->getNeedGel() + 4);
		}
	}

	void unQueue() {

		customersQueue->pop();

		for (int i = 0; i < customersQueue->getSize() - 2; ++i) {
			customersQueue->getElement(i)->setPosY(customersQueue->getElement(i)->getPosY() - 50);
		}

		customersQueue->getElement(customersQueue->getSize() - 1)->setPosY(customersQueue->getElement(customersQueue->getSize() - 1)->getPosY() - 50);

	}

	long long getQueueSize() {
		return customersQueue->getSize();
	}

	CHuman* getFront() {
		return customersQueue->front();
	}

	void bigPop() {
		customersQueue->pop();
	}

};
