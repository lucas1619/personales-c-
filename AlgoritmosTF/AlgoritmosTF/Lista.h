#pragma once
template <class K>
struct KNodo {
	K elemento;
	KNodo * siguiente;
	KNodo* anterior;
	KNodo() {
		siguiente = nullptr;
		anterior = nullptr;
	}
};
template <class K>
class Lista {
private:
	KNodo<K> *inicio;
	KNodo<K> *fin;
	long long tamanho;
	KNodo<K> *crearNodo(K elemento) {
		KNodo<K> *nuevo = new KNodo<K>();
		nuevo->elemento = elemento;
		return nuevo;
	}
public:
	Lista() {
		this->inicio = this->fin = nullptr;
		this->tamanho = 0;
	}
	~Lista() {
		while (!this->estaVacia()) {
			this->eliminarAlInicio();
		}
		delete this->inicio;
		delete this->fin;
	}

	void insertarAlInicio(K elemento) {
		KNodo<K> *nuevo = crearNodo(elemento);
		if (this->tamanho > 0) {
			nuevo->siguiente = this->inicio;
			this->inicio->anterior = nuevo;
			this->inicio = nuevo;
		}
		else {
			this->inicio = this->fin = nuevo;
		}
		++this->tamanho;
	}

	void insertarAlFinal(K elemento) {
		if (this->tamanho > 0) {
			KNodo<K> *nuevo = crearNodo(elemento);
			this->fin->siguiente = nuevo;
			nuevo->anterior = this->fin;
			this->fin = nuevo;
			++this->tamanho;
		}
		else {
			this->insertarAlInicio(elemento);
		}
	}

	void insertarEnPos(long long pos, K elemento) {
		if (pos < this->tamanho && pos >= 0) {
			if (pos == 0) {
				this->insertarAlInicio(elemento);
			}
			else if (pos == this->tamanho - 1) {
				this->insertarAlFinal(elemento);
			}
			else {
				KNodo<K> *nuevo = this->crearNodo(elemento);
				KNodo<K> *puntero = this->inicio;
				long long cont = 0;
				while (cont != pos - 1) {
					puntero = puntero->siguiente;
					++cont;
				}
				puntero->siguiente->anterior = nuevo;
				nuevo->siguiente = puntero->siguiente;
				nuevo->anterior = puntero;
				puntero->siguiente = nuevo;
				++this->tamanho;
			}
		}
	}

	void eliminarAlInicio() {
		if (this->tamanho > 0) {
			if (this->tamanho == 1) {
				delete this->inicio;
				this->inicio = this->fin = nullptr;
			}
			else {
				KNodo<K> *eliminado = this->inicio;
				this->inicio = eliminado->siguiente;
				eliminado->siguiente->anterior = nullptr;
				eliminado->siguiente = nullptr;
				delete eliminado;
			}
			--this->tamanho;
		}
	}

	void eliminarAlFinal() {
		if (this->tamanho <= 1) {
			this->eliminarAlInicio();
		}
		else {
			KNodo<K> *eliminado = this->fin;
			eliminado->anterior->siguiente = nullptr;
			this->fin = eliminado->anterior;
			eliminado->anterior = nullptr;
			delete eliminado;
			--this->tamanho;
		}
	}

	void eliminarEnPos(long long pos) {
		if (pos < this->tamanho && pos >= 0) {
			if (pos == 0) {
				this->eliminarAlInicio();
			}
			else if (pos == this->tamanho - 1) {
				this->eliminarAlFinal();
			}
			else {
				KNodo<K> *puntero = this->inicio;
				long long cont = 0;
				while (cont != pos - 1) {
					puntero = puntero->siguiente;
					++cont;
				}
				KNodo<K> *eliminado = puntero->siguiente;
				puntero->siguiente = eliminado->siguiente;
				eliminado->siguiente->anterior = puntero;
				eliminado->anterior = eliminado->siguiente = nullptr;
				delete eliminado;
				--this->tamanho;
			}
		}
	}

	K obtenerElementoAlInicio() {
		return this->inicio->elemento;
	}

	K obtenerElementoAlFinal() {
		return this->fin->elemento;
	}

	K obtenerElementoEnPos(long long pos) {
		if (pos < this->tamanho && pos >= 0) {
			if (pos == 0) {
				return this->obtenerElementoAlInicio();
			}
			else if (pos == this->tamanho - 1) {
				return this->obtenerElementoAlFinal();
			}
			else {
				KNodo<K> *puntero = this->inicio;
				long long cont = 0;
				while (cont != pos) {
					puntero = puntero->siguiente;
					++cont;
				}
				return puntero->elemento;
			}
		}
	}
	long long obtenerTamanho() {
		return this->tamanho;
	}
	bool estaVacia() {
		return this->tamanho == 0;
	}
};