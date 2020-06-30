#pragma once
#include"NodoIndexado.h"
class Columna
{
private:
	ArbolAVL<NodoIndexado>*arbolito;
	short tipoDato;
	string nombre;
public:
	Columna(string nombre, short tipoDato) {
		arbolito = new ArbolAVL<NodoIndexado>();
		this->nombre = nombre;
		this->tipoDato = tipoDato;
	}
	Columna() {}
	~Columna() {}
	void filtrarData(void(*nuevaFuncion)(NodoIndexado)) {
		this->arbolito->setProcesar(nuevaFuncion);
		this->arbolito->inOrden();
	}
	void ordenarAscendente(void(*nuevaFuncion)(NodoIndexado)) {
		this->arbolito->setProcesar(nuevaFuncion);
		this->arbolito->ascendente();
	}
	void ordenarDescendente(void(*nuevaFuncion)(NodoIndexado)) {
		this->arbolito->setProcesar(nuevaFuncion);
		this->arbolito->descendente();
	}
	string getNombre() {
		return nombre;
	}
	short getTipoDeDato() {
		return tipoDato;
	}
	void agregarElemento(NodoIndexado nodo) {
		arbolito->Insertar(nodo);
	}
};
