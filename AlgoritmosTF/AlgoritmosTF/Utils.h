#pragma once
#include"NodoIndexado.h"
#include"Cola.h"
#include<vector>
using namespace std;
namespace utils {
	double numero;
	string letras;
	bool esTexto;
	Cola<Fila*>*cola = new Cola<Fila*>();
	Cola<string>*colaCSV = new Cola<string>();
	void imprimir(NodoIndexado elemento) {
		cout << elemento << endl;
	}
	void mayorQue(NodoIndexado elemento) {
		esTexto = elemento.getMDato()->getTipo()== 5;
		if (esTexto) {
			if (elemento.getMDato()->getValor() > letras) {
				cola->push(new Fila(*elemento.getFila()));
			}
		}
		else {
			numero = stod(letras);
			if (stod(elemento.getMDato()->getValor()) > numero) {
				cola->push(new Fila(*elemento.getFila()));
			}
		}
	}
	void menorQue(NodoIndexado elemento) {
		esTexto = elemento.getMDato()->getTipo() == 5;
		if (esTexto) {
			if (elemento.getMDato()->getValor() < letras) {
				cola->push(new Fila(*elemento.getFila()));
			}
		}
		else {
			numero = stod(letras);
			if (stod(elemento.getMDato()->getValor()) < numero) {
				cola->push(new Fila(*elemento.getFila()));
			}
		}
	}
	void igualQue(NodoIndexado elemento) {
		if (elemento.getMDato()->getValor() == letras) {
			cola->push(new Fila(*elemento.getFila()));
		}
	}
	void iniciaCon(NodoIndexado elemento) {
		if (elemento.getMDato()->getValor().at(0) == letras.at(0)) {
			cola->push(new Fila(*elemento.getFila()));
		}
	}
	void finalizaCon(NodoIndexado elemento) {
		if (elemento.getMDato()->getValor().at(elemento.getDato().getValor().size() - 1) == letras.at(0)) {
			cola->push(new Fila(*elemento.getFila()));
		}
	}
	void estaContenidoEn(NodoIndexado elemento) {
		if (elemento.getMDato()->getValor().find(letras) < string::npos) {
			cola->push(new Fila(*elemento.getFila()));
		}
	}
	void noEstaContenidoEn(NodoIndexado elemento) {
		if (elemento.getMDato()->getValor().find(letras) == string::npos) {
			cola->push(new Fila(*elemento.getFila()));
		}
	}
	void descargarColaCSV() {
		while (!colaCSV->isEmpty())
		{
			colaCSV->pop();
		}
	}
	void descargarColaFilas() {
		while (!cola->isEmpty())
		{
			cola->pop();
		}
	}
	void cargarColaCSV(Cola<Fila*>*col) {
		while (!col->isEmpty())
		{
			cout << col->front() << endl;
			colaCSV->push(col->front()->saveInCSV());
			col->pop();
		}
	}
	void imprimirYGuardarCSV(NodoIndexado elemento){
		cout << elemento << endl;
		colaCSV->push(elemento.getFila()->saveInCSV());
	}
	bool esDecimal(string texto) {
		bool num = true;
		short conpunt = 0;
		for (size_t i = 0; i < texto.size(); i++)
		{
			if (!isdigit(texto.at(i)))
			{
				if (texto.at(i) == '.')
				{
					if (++conpunt > 1) {
						num = false;
						break;
					}
				}
				else {
					num = false;
					break;
				}
			}
		}
		return num;
	}
	bool esEntero(string texto) {
		bool num = true;
		for (size_t i = 0; i < texto.size(); i++)
		{
			if (!isdigit(texto.at(i)))
			{
				num = false;
				break;
			}
		}
		return num;
	}
	template<class T>
	bool _binarySearch(vector<T>* sorted_vec, T key, long long left, long long rigth) {
		if (left == rigth)
		{
			return sorted_vec->at(left) == key;
		}
		if (left < rigth)
		{
			long long mid = left + (rigth - left) / 2;
			if (key > sorted_vec->at(mid)) {
				left = mid + 1;
				return _binarySearch<T>(sorted_vec, key, left, rigth);
			}
			else if (key < sorted_vec->at(mid)) {
				rigth = mid;
				return _binarySearch<T>(sorted_vec, key, left, rigth);
			}
			else {
				return true;
			}
		}
		return false;
	}
	template <class T>
	bool binarySearch(vector<T>* sorted_vec, T key) {
		return _binarySearch<T>(sorted_vec, key, 0, sorted_vec->size() - 1);
	}
	/*--------------------INICIO QUICK SORT--------------------------------------*/
	void swap(long long *xp, long long *yp)
	{
		long long temp = *xp;
		*xp = *yp;
		*yp = temp;
	}
	template <class T>
	long long partition(vector<T>* arr, T low, T high)
	{
		long long pivot = arr->at(high);
		long long i = (low - 1);
		for (long long j = low; j <= high - 1; j++)
		{
			if (arr->at(j) < pivot)
			{
				i++;
				swap(&arr->at(i), &arr->at(j));
			}
		}
		swap(&arr->at(i + 1), &arr->at(high));
		return (i + 1);
	}
	template<class T>
	void quickSort(vector<T>* arr, T low, T high)
	{
		if (low < high)
		{
			long long pi = partition<T>(arr, low, high);
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}
	/*--------------------FIN QUICK SORT--------------------------------------*/
}
