#ifndef FINALTP_SAVEFILES_H
#define FINALTP_SAVEFILES_H

#include "Nodes.h"

using namespace std;
template <typename T>
class SaveFiles {
private:
	string filename;
public:
	SaveFiles(string filename) {
		this->filename = filename;
	}
	void chargeDatesFromVector(vector<T>&vec) {
		ifstream file;
		T aux;
		file.open(this->filename, ios::in | ios::binary);
		if (file.is_open()) {
			int i = 0;
			do {
				file.seekg(i * sizeof(T), ios::beg);
				file.read((char*)&aux, sizeof(T));
				vec.push_back(T(aux));
				++i;
			} while (!(file.eof()));
			vec.erase(vec.begin() + vec.size() - 1);
			file.close();
		}
	}
	void saveDatesFromVector(vector<T>&nomasvec) {
		ofstream file;
		file.open(this->filename, ios::out | ios::binary);
		if (file.is_open()) {
			for (int i = 0; i < vec.size(); ++i)
			{
				file.write((char*)&vec.at(i), sizeof(T));
			}
			file.close();
		}
	}
};
#endif //FINALTP_SAVEFILES_H
