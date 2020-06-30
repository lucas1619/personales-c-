#pragma once
#include"TableControllerCSV.h"
#include<ctype.h>
class DataBase
{
private:
	TableControllerCSV* bcontroller;
	vector<Table*>*tablas;
	string nombre;
	Table* _filtradoTabla(Table* tabla) {
		Table* retorna;
		descargarColaFilas();
		bool exit = false;
		long long idColumna;
		short ordenamiento;
		string valor;
		while (true)
		{
			system("CLS");
			cout << "Ingrese el numero de la columna que desea hacer el filtrado: " << endl;
			for (size_t i = 0; i < tabla->getColumnas()->obtenerTamanho(); i++)
			{
				cout << i + 1 << ".- " << tabla->getColumnas()->obtenerElementoEnPos(i)->getNombre() << endl;
			}
			cin >> idColumna;
			if (idColumna < 1 || idColumna > tabla->getColumnas()->obtenerTamanho()) {
				cout << "Ingrese un numero valido" << endl;
				system("pause");
			}
			else {
				break;
			}
		}
		idColumna -= 1;
		while (true)
		{
			system("CLS");
			cout << "Ingresa el numero del filtrado que desea hacer" << endl;
			cout << "1.- Mayores que un valor" << endl;
			cout << "2.- Menor que un valor" << endl;
			cout << "3.- Igual que un valor" << endl;
			cout << "4.- Inicia con un valor" << endl;
			cout << "5.- Finaliza con un valor" << endl;
			cout << "6.- El valor esta contenido" << endl;
			cout << "7.- El valor no esta contnido" << endl;
			cin >> ordenamiento;
			if (ordenamiento > 7 || ordenamiento < 1) {
				cout << "Ingrese un numero valido" << endl;
				system("pause");
			}
			else {
				break;
			}
		}
		while (true) {
			system("cls");
			cout << "Ingrese el valor con el que desea filtrar: ";
			cin >> valor;
			if (ordenamiento == 1 || ordenamiento == 2) {
				short td = tabla->getColumnas()->obtenerElementoEnPos(idColumna)->getTipoDeDato();
				switch (td)
				{
				case 1:
				case 2:
					if (esEntero(valor))
						exit = true;
					break;
				case 3:
				case 4:
					if (esDecimal(valor))
						exit = true;
					break;
				case 5:
					exit = true;
					break;
				}
			}
			else {
				exit = true;
			}
			if (exit) {
				break;
			}
			else {
				cout << "Ingrese un valor valido, recuerde que si el tipo de dato es INT o BIGNIT" << endl;
				cout << "debe colocar solo numeros enteros y si es DOUBLE o FLOAT el separador" << endl;
				cout << "de decimales debe ser un punto" << endl;
				system("pause");
			}
		}
		switch (ordenamiento)
		{
		case 1:
			retorna = tabla->obtenerMayorQue(idColumna, valor);
			break;
		case 2:
			retorna = tabla->obtenerMenorQue(idColumna, valor);
			break;
		case 3:
			retorna = tabla->obtenerIgualQue(idColumna, valor);
			break;
		case 4:
			retorna = tabla->obtenerIniciaCon(valor, idColumna);
			break;
		case 5:
			retorna = tabla->obtenerFinalizaCon(valor, idColumna);
			break;
		case 6:
			retorna = tabla->obtenerEstaContenidoEn(valor, idColumna);
			break;
		case 7:
			retorna = tabla->obtenerNoEstaContenidoEn(valor, idColumna);
			break;
		}
		if (retorna->getFilas()->empty()) {
			return nullptr;
		}
		do
		{
			cout << "¿Desea realizar otro filtro?" << endl;
			cout << "1.- Si     2.-No" << endl;
			cin >> ordenamiento;
		} while (ordenamiento < 1 || ordenamiento > 2);
		if (ordenamiento == 1)
		{
			return _filtradoTabla(retorna);
		}
		else {
			descargarColaFilas();
			return retorna;
		}
	}
	Table* _seleccionarColumna(Table* tabla) {
		long long idColumna;
		vector<long long>*ids = new vector<long long>();
		system("CLS");
		cout << "Ingrese las columnas que desea seleccionar: " << endl;
		for (size_t i = 0; i < tabla->getColumnas()->obtenerTamanho(); i++)
		{
			cout << i + 1 << " " << tabla->getColumnas()->obtenerElementoEnPos(i)->getNombre() << endl;
		}
		cout << "0 Para salir" << endl;
		while (true)
		{
			if (ids->size() == tabla->getColumnas()->obtenerTamanho()) {
				break;
			}
			cout << "Ingrese el id de la columna" << endl;
			cin >> idColumna;
			if (idColumna < 0 || idColumna > tabla->getColumnas()->obtenerTamanho()) {
				cout << "Ingrese un numero valido" << endl;
			}
			else if (idColumna > 0 && idColumna <= tabla->getColumnas()->obtenerTamanho()) {
				if (ids->empty()) {
					ids->push_back(idColumna - 1);
				}
				else {
					quickSort<long long>(ids, 0, ids->size() - 1);
					if (!binarySearch<long long>(ids, idColumna - 1))
					{
						ids->push_back(idColumna - 1);
					}
					else
					{
						cout << "Este id ya fue añadido" << endl;
					}
				}
			}
			else {
				break;
			}
		}
		return tabla->seleccionarColumnas(ids);
	}
	void agregarColumnaATabla(Table* tabla) {
		string nombre;
		short tipoDato;
		cout << "Ingrese el nombre que le va a poner a la columna: ", cin >> nombre;
		cout << "Ingrese el numero del tipo de dato que le va a poner a la columna " << nombre << ": " << endl;
		cout << "1.- INT" << endl;
		cout << "2.- BIG INT" << endl;
		cout << "3.- FLOAT" << endl;
		cout << "4.- DOUBLE" << endl;
		cout << "5.- STRING" << endl;
		do
		{
			cin >> tipoDato;
		} while (tipoDato > 5 || tipoDato < 1);
		tabla->agregarColumna(nombre, tipoDato);
	}
	void agregarTabla() {
		string nombre;
		long long cantidad;
		cout << "Ingresa un nombre para tu tabla" << endl;
		cin >> nombre;
		tablas->push_back(new Table(nombre));
		cout << "Ingresa la cantidad de columnas que va a tener su tabla" << endl;
		cin >> cantidad;
		for (size_t i = 0; i < cantidad; i++)
		{
			agregarColumnaATabla(tablas->at(tablas->size() - 1));
		}
	}
	void mostrarTabla(Table * tabla) {
		short ordenamiento;
		string valor;
		tabla->mostrarTabla();
		do
		{
			cout << endl << "¿Desea exportar esta tabla en un CSV?" << endl;
			cout << "1.- Si     2.-No" << endl;
			cin >> ordenamiento;
		} while (ordenamiento < 1 || ordenamiento > 2);
		if (ordenamiento == 1) {
			cout << "Ingrese un nombre para su archivo, recuerde que si repite el nombre este se sobre escribira" << endl;
			cin >> valor;
			bcontroller->saveTableCSV(valor, tabla);
		}
	}
	void agregarRegistroEnTabla(Table* tabla) {
		Lista<Dato*>*registro = new Lista<Dato*>();
		long long size = tabla->getColumnas()->obtenerTamanho();
		string dato;
		for (size_t i = 0; i < size; i++)
		{
			cout << "Insertar dato en la columna: " << tabla->getColumnas()->obtenerElementoEnPos(i)->getNombre() << endl;
			cout << "Tipo de dato: " << tabla->getColumnas()->obtenerElementoEnPos(i)->getTipoDeDato() << endl;
			cout << "Inserte el dato: ";
			cin >> dato;
			registro->insertarAlFinal(new Dato(tabla->getColumnas()->obtenerElementoEnPos(i)->getTipoDeDato(), dato));
			dato.clear();
			cout << endl;
		}
		cout << endl;
		tabla->agregarRegistro(new Fila(new Lista<Dato*>(*registro)));
	}
	void filtradoTabla(Table* tabla) {
		Table* auxiliar = _filtradoTabla(tabla);
		short ordenamiento;
		string valor;
		if (auxiliar == nullptr) {
			cout << "Su filtrado no tiene ningun resultado" << endl;
			system("pause");
			system("cls");
			return;
		}
		auxiliar->mostrarTabla();
		do
		{
			cout << endl << "¿Desea exportar esta tabla filtrada en un CSV?" << endl;
			cout << "1.- Si     2.-No" << endl;
			cin >> ordenamiento;
		} while (ordenamiento < 1 || ordenamiento > 2);
		if (ordenamiento == 1) {
			cout << "Ingrese un nombre para su archivo, recuerde que si repite el nombre este se sobre escribira" << endl;
			cin >> valor;
			bcontroller->saveTableCSV(valor, auxiliar);
		}
		descargarColaFilas();
		delete auxiliar;
	}
	void seleccionarColumnas(Table* tabla) {
		Table* auxiliar = _seleccionarColumna(tabla);
		short ordenamiento;
		string valor;
		auxiliar->mostrarTabla();
		do
		{
			cout << endl << "¿Desea exportar esta tabla seleccionada en un CSV?" << endl;
			cout << "1.- Si     2.-No" << endl;
			cin >> ordenamiento;
		} while (ordenamiento < 1 || ordenamiento > 2);
		if (ordenamiento == 1) {
			cout << "Ingrese un nombre para su archivo, recuerde que si repite el nombre este se sobre escribira" << endl;
			cin >> valor;
			bcontroller->saveTableCSV(valor, auxiliar);
		}
		delete auxiliar;
	}
	void ordenarTabla(Table* tabla) {
		descargarColaCSV();
		colaCSV->push(tabla->getNombre());
		colaCSV->push(tabla->nombresDeColumnaCSV());
		long long idColumna;
		short ordenamiento;
		string valor;
		while (true)
		{
			system("CLS");
			cout << "Ingrese el numero de la columna con el que desea ordenar su tabla: " << endl;
			for (size_t i = 0; i < tabla->getColumnas()->obtenerTamanho(); i++)
			{
				cout << i + 1 << ".- " << tabla->getColumnas()->obtenerElementoEnPos(i)->getNombre() << endl;
			}
			cin >> idColumna;
			if (idColumna < 1 || idColumna > tabla->getColumnas()->obtenerTamanho()) {
				cout << "Ingrese un numero valido" << endl;
				system("pause");
			}
			else {
				break;
			}
		}
		idColumna -= 1;
		do
		{
			cout << endl << "¿En que sentido quiere ordenar su tabla?" << endl;
			cout << "1.- Ascendente     2.- Descendente" << endl;
			cin >> ordenamiento;
		} while (ordenamiento < 1 || ordenamiento > 2);
		if (ordenamiento == 1) {
			tabla->mostrarOrdenado(true, idColumna);
		}
		else {
			tabla->mostrarOrdenado(false, idColumna);
		}
		do
		{
			cout << endl << "¿Desea exportar su tabla ordenada en formato CSV?" << endl;
			cout << "1.- Si     2.- No" << endl;
			cin >> ordenamiento;
		} while (ordenamiento < 1 || ordenamiento > 2);
		if (ordenamiento == 1) {
			cout << "Ingrese un nombre para su archivo, recuerde que si repite el nombre este se sobre escribira" << endl;
			cin >> valor;
			bcontroller->saveSearchCSV(valor, colaCSV);
		}
	}
public:
	DataBase(string nombre) {
		bcontroller = new TableControllerCSV();
		tablas = new vector<Table*>();
		this->nombre = nombre;
	};
	~DataBase() {
		delete bcontroller;
		tablas->clear();
		delete tablas;
	};
	void mainDB() {
		short decision;
		long long idTabla;
		while (true)
		{
			system("CLS");
			decision = NULL;
			idTabla = NULL;
			if (tablas->empty())
			{
				cout << "Es hora de crear tu primera tabla en esta DB :D" << endl;
				this->agregarTabla();
			}
			else
			{
				while (true)
				{
					system("CLS");
					cout << "Seleccione lo que desea hacer en la base de datos" << endl;
					cout << "1.- Crear una nueva tabla" << endl;
					cout << "2.- Operar  tabla" << endl;
					cout << "3.- Mostrar  tabla" << endl;
					cout << "4.- Agregar registro a una tabla" << endl;
					cout << "5.- Ordenar tabla" << endl;
					cout << "6.- Agregar columna a tabla" << endl;
					cout << "7.- Seleccionar columna de tabla" << endl;
					cin >> decision;
					if (decision < 1 || decision > 7) {
						cout << "Ingrese una opcion valida" << endl;
						system("pause");
					}
					else {
						break;
					}
				}
				if (decision == 1)
				{
					this->agregarTabla();
				}
				else {
					while (true)
					{
						system("CLS");
						cout << "Seleccione la tabla que desea usar" << endl;
						for (size_t i = 0; i < tablas->size(); i++)
						{
							cout << i + 1 << " " << tablas->at(i)->getNombre() << endl;
						}
						cin >> idTabla;
						if (idTabla < 1 || idTabla > tablas->size()) {
							cout << "Ingrese una opcion valida" << endl;
							system("pause");
						}
						else {
							break;
						}
					}
					if (decision == 2) {
						this->filtradoTabla(tablas->at(idTabla - 1));
					}
					else if (decision == 3) {
						this->mostrarTabla(tablas->at(idTabla - 1));
					}
					else if (decision == 4) {
						this->agregarRegistroEnTabla(tablas->at(idTabla - 1));
					}
					else if (decision == 5) {
						this->ordenarTabla(tablas->at(idTabla - 1));
					}
					else if (decision == 6) {
						this->agregarColumnaATabla(tablas->at(idTabla - 1));
					}
					else if (decision == 7) {
						this->seleccionarColumnas(tablas->at(idTabla - 1));
					}
				}
			}
			while (true)
			{
				system("CLS");
				cout << "¿Desea continuar en el menu de tablas?" << endl;
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
	string getNombre() {
		return nombre;
	}
};
