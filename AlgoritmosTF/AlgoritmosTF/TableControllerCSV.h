#pragma once
#include<fstream>
#include"Table.h"
class TableControllerCSV
{
private:
	bool isCSV(string filename) {
		if (filename.at(filename.length() - 1) == 'v' && filename.at(filename.length() - 2) == 's' && filename.at(filename.length() - 3) == 'c' && filename.at(filename.length() - 4) == '.') {
			return true;
		}
		return false;
	}
	void reemplazar(string &filename, char a, char b) {
		for (size_t i = 0; i < filename.size(); i++)
		{
			if (filename.at(i) == a)
				filename.at(i) = b;
		}
	}
public:
	TableControllerCSV() {}
	~TableControllerCSV() {}
	void saveTableCSV(string filename, Table* tabla){
		system("if not exist %userprofile%\\documents\\AbrahamDB mkdir %userprofile%\\documents\\AbrahamDB");
		ofstream file;
		file.open(filename + ".csv");
		file << tabla->getNombre() << endl;
		file << tabla->nombresDeColumnaCSV() << endl;
		for (size_t i = 0; i < tabla->getFilas()->size(); i++)
		{
			file << tabla->getFilas()->at(i)->saveInCSV() << endl;
		}
		file.close();
		string copiar = "move " + filename + ".csv %userprofile%\\documents\\AbrahamDB > 0";
		system(copiar.c_str());
		cout << "Se almaceno exitosamente en el archivo " << filename << ".csv" << endl;
		cout << "dentro de la carpeta AbrahamDB que esta en tu carpeta Documentos " << endl;
		system("pause");
	}
	void saveSearchCSV(string filename, Cola<string>* busqueda) {
		system("if not exist %userprofile%\\documents\\AbrahamDB mkdir %userprofile%\\documents\\AbrahamDB");
		ofstream file;
		file.open(filename + ".csv");
		while (!busqueda->isEmpty())
		{
			file << busqueda->front() << endl;
			busqueda->pop();
		}
		file.close();
		string copiar = "move " + filename + ".csv %userprofile%\\documents\\AbrahamDB > 0";
		system(copiar.c_str());
		cout << "Se almaceno exitosamente en el archivo " << filename << ".csv" << endl;
		cout << "dentro de la carpeta AbrahamDB que esta en tu carpeta Documentos " << endl;
		system("pause");
	}
};