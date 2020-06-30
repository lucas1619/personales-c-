#pragma once
#include"Dato.h"
using namespace std;
class Fila
{
private:
	Lista<Dato*>*datos;
	long long size;
public:
	Fila(Lista<Dato*>*datos) {
		this->datos = datos;
		size = this->datos->obtenerTamanho();
	};
	~Fila() {
		delete datos;
	};
	long long getSize() {
		return this->size;
	}
	Lista<Dato*>* getDatos() {
		return this->datos;
	}
	string saveInCSV() {
		string response = "";
		for (size_t i = 0; i < this->size; i++)
		{
			response += datos->obtenerElementoEnPos(i)->getValor() + ",";
		}
		return response;
	}
	void modificarDato(long long id, string nuevo) {
		if (id < this->datos->obtenerTamanho()) {
			this->datos->obtenerElementoEnPos(id)->setValor(nuevo);
			cout << "Modificacion exitosa" << endl;
		}
		cout << "Modificacion fallida, es probable que la columna elegida no existe" << endl;
		return;
	}
	Dato* obtenerDatoEnPosicion(long long id) {
		if (id < this->datos->obtenerTamanho()) {
			return this->datos->obtenerElementoEnPos(id);
		}
		return nullptr;
	}
	friend ostream& operator <<(ostream & os, Fila & a) {
		for (long long i = 0; i < a.getSize(); i++)
		{
			os << a.getDatos()->obtenerElementoEnPos(i) << "\t\t";
		}
		return os;
	}
	friend ostream& operator <<(ostream & os, Fila * a) {
		for (long long i = 0; i < a->getSize(); i++)
		{
			os << a->getDatos()->obtenerElementoEnPos(i) << "\t\t";
		}
		return os;
	}
};