#include "DoubleLinkedList.h"

class CProduct {
private:
	string brand;
	int price;
public:

	CProduct() {}
	CProduct(string b, int p) {
		this->brand = b;
		this->price = p;
	}
	~CProduct() {}
};
