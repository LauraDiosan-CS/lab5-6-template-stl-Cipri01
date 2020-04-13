////#include "Repo.h"
////
////using namespace std;
////
//////Descr:	create an empty Repo object
//////In:		none
//////out:		an instance of type Repo (without elements)
////Repo::Repo() {
////	this->products.size();
////}
////
//////Descr:	destroy a Repo object
//////In:		a Repo object
//////out:		none
////Repo::~Repo() {
////	this->products.clear();
////}
////
//////Descr:	add an element p into vector "elements"
//////In:		a Product object
//////out:		the (changed) vector
////void Repo::addProduct(const Product& p) {
////	this->products.push_back(p);
////}
////
//////Descr:	get all elemts of vector "elements"
//////In:		none
//////out:		vector "elements"
////vector<Product> Repo::getAll() {
////	return this->products;
////}
////
//////Descr:	update an elemnt of vector "elemnts"
//////In:		the vector, old item and new item 
//////out:		the (changed) vector
////void Repo::updateProduct(Product& oldProduct, Product& newProduct) {
////	vector<Product>::iterator it;
////	it = find(this->products.begin(), this->products.end(), oldProduct);
////	if (it != this->products.end()) {
////		*it = newProduct;
////	}
////	/*for (int i = 0; i < this->products.size(); i++) {
////		if (this->products[i] == oldProduct) {
////			this->products[i] = newProduct;
////		}
////	}*/
////}
////
//////Descr:	delete all elemnt el of vector "elemnts"
//////In:		the vector and item el for delete
//////out:		the (changed) vector
////void Repo::deleteProduct(Product& p) {
////	vector<Product>::iterator it;
////	it = find(this->products.begin(), this->products.end(), p);
////	if (!(it == this->products.end())) {
////		this->products.erase(it);
////	}
////}
////
//////Descr:	acces an element from the vector
//////In:		the vector and a position
//////out:		the vector's element from the given position
////Product Repo::getItemAtPosition(int pos)
////{
////	return this->products[pos];
////}
////
//////Descr:	acces the size of the vector
//////In:		the vector
//////out:		the vector's size
////int Repo::getSize() {
////	return this->products.size();
////}
////
//////Descr:	change an element from the vector
//////In:		the vector, a position and an element
//////out:		the (changed) vector
////void Repo::setElemPos(int pos, Product p)
////{
////	this->products[pos] = p;
////}
