#pragma once
#include"Dato.h"
#include"Fila.h"
class NodoIndexado
{
private:
	Dato* dato;
	Fila* fila;
public:
	NodoIndexado(Dato* dato, Fila* fila) {
		this->dato = dato;
		this->fila = fila;
	}
	NodoIndexado() {}
	~NodoIndexado(){}
	Dato getDato() {
		return *dato;
	}
	Dato* getMDato() {
		return dato;
	}
	Fila* getFila() {
		return this->fila;
	}
	friend bool operator <(NodoIndexado & b, NodoIndexado & a) {
		return a.getDato() < b.getDato();
	}
	friend bool operator >(NodoIndexado & b, NodoIndexado & a) {
		return a.getDato() > b.getDato();
	}
	friend bool operator <=(NodoIndexado & b, NodoIndexado & a) {
		return a.getDato() <= b.getDato();
	}
	friend bool operator >=(NodoIndexado & b, NodoIndexado & a) {
		return a.getDato() >= b.getDato();
	}
	friend bool operator ==(NodoIndexado &b, NodoIndexado & a) {
		return a.getDato() == b.getDato();
	}
	friend ostream& operator <<(ostream & os, NodoIndexado & a) {
		os << a.fila;
		return os;
	}
	friend ostream& operator <<(ostream & os, NodoIndexado * a) {
		os << a->fila;
		return os;
	}
};