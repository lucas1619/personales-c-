#pragma once
#include"Fila.h"
#include"Columna.h"
#include <algorithm>
#include"Utils.h"
using namespace utils;
class Table
{
private:
	string nombre;
	vector<Fila*>*filas;
	Lista<Columna*>*columnas;
	void imprimirEncabezados() {
		for (size_t i = 0; i < columnas->obtenerTamanho(); i++)
		{
			cout << columnas->obtenerElementoEnPos(i)->getNombre() << "\t\t";
		}
		cout << endl;
	}
public:
	Table(vector<string>nombreColumnas, vector<short>tipoDato, string nombre = "") {
		this->nombre = nombre;
		columnas = new Lista<Columna*>();
		filas = new vector<Fila*>();
		for (size_t i = 0; i < nombreColumnas.size(); i++)
		{
			columnas->insertarAlFinal(new Columna(nombreColumnas.at(i), tipoDato.at(i)));
		}
	}
	Table(Lista<Columna*>*columnas, vector<Fila*>*filas, string nombre = "") {
		this->nombre = nombre;
		this->columnas = columnas;
		this->filas = filas;
	}
	Table(Lista<Columna*>*columnas, Cola<Fila*>*colfil, string nombre = "") {
		this->nombre = nombre;
		this->columnas = new Lista<Columna*>();
		for (size_t i = 0; i < columnas->obtenerTamanho(); i++)
		{
			this->agregarColumna(columnas->obtenerElementoEnPos(i)->getNombre(), columnas->obtenerElementoEnPos(i)->getTipoDeDato());
		}
		this->filas = new vector<Fila*>();
		while (!colfil->isEmpty())
		{
			this->agregarRegistro(colfil->front());
			colfil->pop();
		}
	}
	Table() {
		nombre = "";
		columnas = new Lista<Columna*>();
		filas = new vector<Fila*>();
	}
	Table(string nombre) {
		this->nombre = nombre;
		this->filas = new vector<Fila*>();
		this->columnas = new Lista<Columna*>();
	}
	~Table() {}
	string obtenerNombreColumna(long long idColumna) {
		return columnas->obtenerElementoEnPos(idColumna)->getNombre();
	}
	string nombresDeColumnaCSV() {
		string response = "";
		for (size_t i = 0; i < columnas->obtenerTamanho(); i++)
		{
			response += obtenerNombreColumna(i) + ",";
		}
		return response;
	}
	Table* seleccionarColumnas(vector<long long>*columnasElegidas) {
		quickSort<long long>(columnasElegidas, 0, columnasElegidas->size() - 1);
		Lista<Columna*>*cols = new Lista<Columna*>();
		vector<Fila*>*fils = new vector<Fila*>();
		for (size_t i = 0; i < columnasElegidas->size(); i++)
		{
			cols->insertarAlFinal(columnas->obtenerElementoEnPos(columnasElegidas->at(i)));
		}
		for (size_t i = 0; i < filas->size(); i++)
		{
			Lista<Dato*>*dats = new Lista<Dato*>();
			for (size_t j = 0; j < columnasElegidas->size(); j++)
			{
				dats->insertarAlFinal(filas->at(i)->obtenerDatoEnPosicion(columnasElegidas->at(j)));
			}
			Fila*nuevo = new Fila(dats);
			fils->push_back(nuevo);
		}
		columnasElegidas->clear();
		delete columnasElegidas;
		return new Table(cols, fils, this->nombre);
	}
	void agregarColumna(string nombre, short tipoDato) {
		columnas->insertarAlFinal(new Columna(nombre, tipoDato));
	}
	void agregarRegistro(Fila* nueva) {
		filas->push_back(nueva);
		for (size_t i = 0; i < columnas->obtenerTamanho(); i++)
		{
			columnas->obtenerElementoEnPos(i)->agregarElemento(NodoIndexado(nueva->obtenerDatoEnPosicion(i), filas->at(filas->size() - 1)));
		}
	}
	void mostrarOrdenado(bool ascendente, short idColumna) {
		if (idColumna < columnas->obtenerTamanho()) {
			if(ascendente)
				columnas->obtenerElementoEnPos(idColumna)->ordenarAscendente(imprimirYGuardarCSV);
			else
				columnas->obtenerElementoEnPos(idColumna)->ordenarDescendente(imprimirYGuardarCSV);
			return;
		}
		cout << "Ocurrio un error, es posible que el numero de columna solicitada no exista" << endl;
	}
	Table* obtenerMayorQue(long long idColumna, string valor) {
		letras = valor;
		this->columnas->obtenerElementoEnPos(idColumna)->filtrarData(mayorQue);
		return new Table(this->columnas, cola, this->nombre);
	}
	Table* obtenerMenorQue(long long idColumna, string valor) {
		imprimirEncabezados();
		letras = valor;
		this->columnas->obtenerElementoEnPos(idColumna)->filtrarData(menorQue);
		return new Table(this->columnas, cola, this->nombre);
	}
	Table* obtenerIgualQue(long long idColumna, string valor) {
		imprimirEncabezados();
		letras = valor;
		this->columnas->obtenerElementoEnPos(idColumna)->filtrarData(igualQue);
		return new Table(this->columnas, cola, this->nombre);
	}
	Table* obtenerIniciaCon(string valor, long long idColumna) {
		imprimirEncabezados();
		letras = valor;
		this->columnas->obtenerElementoEnPos(idColumna)->filtrarData(iniciaCon);
		return new Table(this->columnas, cola, this->nombre);
	}
	Table* obtenerFinalizaCon(string valor, long long idColumna) {
		imprimirEncabezados();
		letras = valor;
		this->columnas->obtenerElementoEnPos(idColumna)->filtrarData(finalizaCon);
		return new Table(this->columnas, cola, this->nombre);
	}
	Table* obtenerEstaContenidoEn(string valor, long long idColumna) {
		imprimirEncabezados();
		letras = valor;
		this->columnas->obtenerElementoEnPos(idColumna)->filtrarData(estaContenidoEn);
		return new Table(this->columnas, cola, this->nombre);
	}
	Table* obtenerNoEstaContenidoEn(string valor, long long idColumna) {
		imprimirEncabezados();
		letras = valor;
		this->columnas->obtenerElementoEnPos(idColumna)->filtrarData(noEstaContenidoEn);
		return new Table(this->columnas, cola, this->nombre);
	}

	vector<Fila*>* getFilas() {
		return filas;
	}
	Lista<Columna*>* getColumnas() {
		return columnas;
	}
	string getNombre() {
		if (nombre == "") {
			return "Tabla sin nombre";
		}
		return nombre;
	}
	void mostrarTabla() {
		imprimirEncabezados();
		for (size_t i = 0; i < filas->size(); i++)
		{
			cout << filas->at(i) << endl;
		}
	}
};
