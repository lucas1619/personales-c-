#ifndef FINALTP_TPSTACK_H
#define FINALTP_TPSTACK_H


#include "SaveFiles.h"

using namespace Linked;
template <class T>
class TpStack {
private:
	Node<T>*begin;
	long long size;
	Node<T>* createNode(T newData) {
		Node<T>* newNode = new Node<T>();
		newNode->Element = newData;
		newNode->Next = nullptr;
		return newNode;
	}
	void DestroyNode(Node<T> * Node) {
		delete Node;
	}
public:
	TpStack() {
		this->begin = nullptr;
		this->size = 0;
	}
	~TpStack() {
		delete this->begin;
	}
	T top() {
		return this->begin->Element;
	}
	void pop() {
		if (!this->isEmpty()) {
			if (this->size == 1) {
				begin = nullptr;
				--this->size;
			}
			else {
				Node<T> * first = this->begin;
				this->begin = this->begin->Next;
				this->DestroyNode(first);
				--this->size;
			}
		}
	}
	void push(T Element) {
		Node<T> * insertedNode = createNode(Element);
		insertedNode->Next = this->begin;
		this->begin = insertedNode;
		++this->size;

		cout << "enter" << endl;
	}
	bool isEmpty() {
		return this->size == 0;
	}
	long long getSize() {
		return this->size;
	}
};
#endif //FINALTP_TPSTACK_H

