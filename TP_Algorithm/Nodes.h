#ifndef FINALTP_NODES_H
#define FINALTP_NODES_H

//#include <bits/stdc++.h>

#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <functional>

using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Media;
using namespace std;

namespace Linked {
	template <class T>
	struct Node {
		T Element;
		Node<T> *Next;
		Node() {
			
			Next = nullptr;
		}
	};
}
namespace DoubleLinked {
	template <class T>
	struct Node {
		T Element;
		Node<T> *Next;
		Node<T> *Prev;
		Node() {
			
			Next = nullptr;
			Prev = nullptr;
		}
	};
}
#endif //FINALTP_NODES_H

