#pragma once
#include"Lista.h"
template<class R>
class Cola
{
private:
	Lista<R>* cola;
public:
	Cola() {
		cola = new Lista<R>();
	}
	~Cola() {
		delete cola;
	}
	void pop() {
		cola->eliminarAlInicio();
	}
	void pop_back() {
		cola->eliminarAlFinal();
	}
	void push(R elemento) {
		cola->insertarAlFinal(elemento);
	}
	R front() {
		return cola->obtenerElementoAlInicio();
	}
	R back() {
		return cola->obtenerElementoAlFinal();
	}
	bool isEmpty() {
		return cola->estaVacia();
	}
	long long size() {
		return cola->obtenerTamanho();
	}
};
	