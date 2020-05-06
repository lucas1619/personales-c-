#ifndef FINALTP_TPQUEUE_H
#define FINALTP_TPQUEUE_H

#include "Stack.h"

template <class T>
class TpDoubleLinkedList {
private:
	DoubleLinked::Node<T> *head;
	DoubleLinked::Node<T> *end;
	long long size;
public:
	TpDoubleLinkedList() {
		this->head = this->end = nullptr;
		this->size = 0;
	}
	~TpDoubleLinkedList() {
		while (this->head != nullptr && this->end != nullptr) {
			this->pop();
		}
		delete this->head;
		delete this->end;
	}
	void push(T new_n)
	{																	  //ANALISIS DE COMPLEJIDAD ALGOR�TMICA

		DoubleLinked::Node<T> *newNode = new DoubleLinked::Node<T>();     //1
		newNode->Element = new_n;										  //2

		if (head == nullptr)											  //1
		{
			this->head = this->end = newNode;                             //2
		}
		else
		{
			this->end->Next = newNode;									  //2
			newNode->Prev = this->end;									  //2
		}

		this->end = newNode;											  //1
		this->size++;													  //2
		
	}
	T getElement(int Nodepos) {

		DoubleLinked::Node<T> * aux = this->head;

		for (int i = 0; i < Nodepos; ++i) {
			aux = aux->Next;
		}

		return aux->Element;
	}
	void deleteNotNeeded(int pos,function<bool(T)> aux) {

		DoubleLinked::Node<T>* search = this->head;

		for (int i = 0; i < pos; ++i) {
			search = search->Next;
		}

		if (aux(search->Element)==false) {
			if (pos == 0) {
				pop();
				
			}
			if (pos == size - 1) {
				this->end = search->Prev;
				delete search;
				this->size--;

				
			}
			if (pos != 0 && pos != size - 1) {
				search->Prev->Next = search->Next;
				search->Next->Prev = search->Prev;
				delete search;
				this->size--;

				
			}
		}
	}
	void pop()
	{
		if (this->head != nullptr && this->end != nullptr) {
			DoubleLinked::Node<T> *destroy = this->head;
			if (this->head == this->end)
			{
				this->end = this->head = nullptr;
			}
			else
			{
				head = head->Next;
			}
			delete destroy;
			this->size--;
		}
	}
	long long getSize() {
		return this->size;
	}
	bool isEmpty() {
		return this->size == 0;
	}
	T front() {
		return this->head->Element;
	}
};
#endif //FINALTP_TPQUEUE_H
