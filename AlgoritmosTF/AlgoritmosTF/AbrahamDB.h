#pragma once
#include"DataBase.h"
class AbrahamDB
{
private:
	vector<DataBase*>*basesDeDatos;
	void agregarDB() {
		string nombre;
		cout << "Coloque el nombre que le va a poner a su base de datos" << endl;
		cin >> nombre;
		basesDeDatos->push_back(new DataBase(nombre));
	}
public:
	AbrahamDB() {
		basesDeDatos = new vector<DataBase*>();
	}
	~AbrahamDB() {
		basesDeDatos->clear();
		delete basesDeDatos;
	}
	void mainADB() {
		short decision;
		long long idTabla;
		while (true)
		{
			system("CLS");
			decision = NULL;
			idTabla = NULL;
			cout << "Development by Lucas Moreno & Ricardo Ponce" << endl << endl;
			cout << "Bienvenido al nuevo gestor de base de datos AbrahamDB" << endl;
			if (basesDeDatos->empty())
			{
				cout << "Es hora de crear tu primera base de datos en AbrahamDB :D" << endl << endl;
				this->agregarDB();
			}
			else
			{
				while (true)
				{
					system("CLS");
					cout << "Seleccione lo que desea hacer en la base de datos" << endl;
					cout << "1.- Crear una nueva base de datos" << endl;
					cout << "2.- Operar  base de datos" << endl;
					cin >> decision;
					if (decision < 1 || decision > 2) {
						cout << "Ingrese una opcion valida" << endl;
						system("pause");
					}
					else {
						break;
					}
				}
				if (decision == 1)
				{
					this->agregarDB();
				}
				else {
					while (true)
					{
						system("CLS");
						cout << "Seleccione la base de datos que desea usar" << endl;
						for (size_t i = 0; i < basesDeDatos->size(); i++)
						{
							cout << i + 1 << " " << basesDeDatos->at(i)->getNombre() << endl;
						}
						cin >> idTabla;
						if (idTabla < 1 || idTabla > basesDeDatos->size()) {
							cout << "Ingrese una opcion valida" << endl;
							system("pause");
						}
						else {
							break;
						}
					}
					basesDeDatos->at(idTabla - 1)->mainDB();
				}
			}
			while (true)
			{
				system("CLS");
				cout << "¿Desea continuar en el menu de bases de datos?" << endl;
				cout << "1.- Si" << endl;
				cout << "2.- No" << endl;
				cin >> decision;
				if (decision < 1 || decision > 2) {
					cout << "Ingrese una opcion valida" << endl;
					system("pause");
				}
				else {
					break;
				}
			}
			if (decision == 2)
			{
				break;
			}
		}
	}
};