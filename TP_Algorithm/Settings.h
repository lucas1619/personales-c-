#pragma once
#include "Customers.h"

class CSettings {
private:
	int saveController = 0;

public:
	CSettings() {}
	~CSettings() {}

	void read_first() {

		ifstream nameArch;

		nameArch.open("Archive1.txt", ios::in);

		if (nameArch.is_open()) {

			nameArch >> saveController;
			nameArch.close();

		}
	}

	void write_first() {

		ofstream nameArch;
		saveController = 1;

		nameArch.open("Archive1.txt", ios::out);

		if (nameArch.is_open()) {

			nameArch << saveController;
			nameArch.close();

		}
	}

	int getSaveControl() {
		return this->saveController;
	}
};
