#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Lista.h"
#include"ArbolAVL.h"
using namespace std;
class Dato
{
private:
	unsigned short tipo;
	string valor;
public:
	Dato(unsigned short tipo = NULL, string valor = NULL) {
		this->tipo = tipo;
		this->valor = valor;
	};
	~Dato() {
		valor.clear();
	}
	unsigned short getTipo() {
		return this->tipo;
	}
	string getValor() {
		return this->valor;
	}
	void setValor(string valor) {
		this->valor = valor;
	}
	friend bool operator <(Dato & b, Dato & a) {
		switch (a.getTipo())
		{
		case 1: // int
			return stoi(a.valor) < stoi(b.valor);
		case 2: // bigint
			return stoll(a.valor) < stoi(b.valor);
		case 3: // float
			return stof(a.valor) < stof(b.valor);
		case 4: //double
			return stod(a.valor) < stod(b.valor);
		case 5: //string
			return a.valor < b.valor;
		default:
			return false;
		}
	}
	friend bool operator >(Dato & b, Dato & a) {
		switch (a.getTipo())
		{
		case 1: // int
			return stoi(a.valor) > stoi(b.valor);
		case 2: // bigint
			return stoll(a.valor) > stoi(b.valor);
		case 3: // float
			return stof(a.valor) > stof(b.valor);
		case 4: //double
			return stod(a.valor) > stod(b.valor);
		case 5: //string
			return a.valor > b.valor;
		default:
			return false;
		}
	}
	friend bool operator <=(Dato & b, Dato & a) {
		switch (a.getTipo())
		{
		case 1: // int
			return stoi(a.valor) <= stoi(b.valor);
		case 2: // bigint
			return stoll(a.valor) <= stoi(b.valor);
		case 3: // float
			return stof(a.valor) <= stof(b.valor);
		case 4: //double
			return stod(a.valor) <= stod(b.valor);
		case 5: //string
			return a.valor <= b.valor;
		default:
			return false;
		}
	}
	friend bool operator >=(Dato & b, Dato & a) {
		switch (a.getTipo())
		{
		case 1: // int
			return stoi(a.valor) >= stoi(b.valor);
		case 2: // bigint
			return stoll(a.valor) >= stoi(b.valor);
		case 3: // float
			return stof(a.valor) >= stof(b.valor);
		case 4: //double
			return stod(a.valor) >= stod(b.valor);
		case 5: //string
			return a.valor >= b.valor;
		default:
			return false;
		}
	}
	friend bool operator ==(Dato & b, Dato & a) {
		return a.valor == b.valor;
	}
	friend ostream& operator <<(ostream & os, Dato & a) {
		os << a.getValor();
		return os;
	}
	friend ostream& operator <<(ostream & os, Dato * a) {
		os << a->getValor();
		return os;
	}
};