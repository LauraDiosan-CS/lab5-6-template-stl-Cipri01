#pragma once
#include "Product.h"
#include "Coin.h"
#include <vector>
template <class T>
class Repo {
protected:
	vector<T> elements;
public:
	Repo();
	~Repo();

	void addElement(const T& elem);
	vector<T> getAll();
	void updateElement(T& oldElement, T& newElement);
	void deleteElement(T& elem);
	
	T getItemAtPosition(int pos);
	int getSize();

};

#include "Repo.h"

using namespace std;

template <class T>
Repo<T>::Repo() {

}

template <class T>
Repo<T>::~Repo() {
	this->elements.clear();
}

template <class T>
void Repo<T>::addElement(const T& elem) {
	this->elements.push_back(elem);
}

template <class T>
vector<T> Repo<T>::getAll() {
	return this->elements;
}

template <class T>
void Repo<T>::updateElement(T& oldElement, T& newElement) {
	typename vector<T>::iterator it;
	it = find(this->elements.begin(), this->elements.end(), oldElement);
	if (it != this->elements.end()) {
		*it = newElement;
	}
	/*for (int i = 0; i < this->products.size(); i++) {
		if (this->products[i] == oldProduct) {
			this->products[i] = newProduct;
		}
	}*/
}

template <class T>
void Repo<T>::deleteElement(T& elem) {
	typename vector<T>::iterator it;
	it = find(this->elements.begin(), this->elements.end(), elem);
	if (!(it == this->elements.end())) {
		this->elements.erase(it);
	}
}

template <class T>
T Repo<T>::getItemAtPosition(int pos)
{
	return this->elements[pos];
}

template <class T>
int Repo<T>::getSize() {
	return this->elements.size();
}
