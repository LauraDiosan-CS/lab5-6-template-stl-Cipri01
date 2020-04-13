#include "Product.h"
#include <string.h>
#include <ostream>
#include <iostream>

//Descr: create an Product object
//In: - 
//Out: an instance of Product
Product::Product() {
	this->code = NULL;
	this->name = NULL;
	this->price = 0.0;
}

//Descr: create an Product object
//In: code - code for product, name - name for product, price -price for product
//Out: an instance of Product
Product::Product(char* code, char* name, float price) {
	this->code = new char[strlen(code) + 1];
	strcpy_s(this->code, 1 + strlen(code), code);
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);
	this->price = price;
}

//Descr: create an Product object from another Product object
//In: an Product object
//Out: an instance of Product equal to p
Product::Product(const Product& p) {
	this->code = new char[strlen(p.code) + 1];
	strcpy_s(this->code, 1 + strlen(p.code), p.code);
	this->name = new char[strlen(p.name) + 1];
	strcpy_s(this->name, 1 + strlen(p.name), p.name);
	this->price = p.price;
}

//Descr: destroy an Product object
//In: the current Product object
//Out: -
Product::~Product() {
	if (this->code) {
		delete[] this->code;
		this->code = NULL;
	}
	if (this->name) {
		delete[] this->name;
		this->name = NULL;
	}
}

//Descr: change the code of an Product object
//In: an Product object and a value for code
//Out: the Product object with changed code
void Product::setCode(char* valueCode) {
	if (this->code) {
		delete[] this->code;
	}
	this->code = new char[strlen(valueCode) + 1];
	strcpy_s(this->code, 1 + strlen(valueCode), valueCode);
}

//Descr: change the name of an Product object
//In: an Product object and a value for name
//Out: the Product object with changed name
void Product::setName(char* valueName) {
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(valueName) + 1];
	strcpy_s(this->name, 1 + strlen(valueName), valueName);
}

//Descr: change the price of an Product object
//In: an Product object and a value for price
//Out: the Product object with changed price
void Product::setPrice(float valuePrice) {
	this->price = valuePrice;
}

//Descr: acces the code of an Product object
//In: an Product object
//Out: the code for an Product
char* Product::getCode() {
	return this->code;
}

//Descr: acces the name of an Product object
//In: an Product object
//Out: the name for an Product
char* Product::getName() {
	return this->name;
}

//Descr: acces the price of an Product object
//In: an Product object
//Out: the price for an Product
float Product::getPrice() {
	return this->price;
}

//Descr: create a new Product object (equal to  given Product object)
//In: an Product object
//Out: a new Product object
Product& Product::operator=(const Product& p) {
	this->setCode(p.code);
	this->setName(p.name);
	this->setPrice(p.price);
	return *this;
}

//Descr: compare two Product object
//In: two Product object (the crt one, p)
//Out: true or false
bool Product::operator==(const Product& p) {
	return ((strcmp(this->code, p.code) == 0) && (strcmp(this->name, p.name) == 0) && (this->price == p.price));
}

//IO operators
//Descr: load an Product object from an input stream
//In: an input stream
//Out: a new Product object
istream& operator>>(istream& is, Product& p) {
	char* code = new char[20];
	is >> code;
	
	char* name = new char[20];
	is >> name;
	
	float price;
	is >> price;

	p.setCode(code);
	p.setName(name);
	p.setPrice(price);

	delete[] code;
	delete[] name;

	return is;
}

//IO operators
//Descr: save an Product object into an output stream
//In: an output stream, an Product object
//Out: the output stream (loaded by info about Product object)
ostream& operator<<(ostream& os, Product& p) {
	os << p.code << " " << p.name << " " << p.price << endl;
	return os;
}

bool Product::operator!() {
	if (this->code == NULL || this->name == NULL || this->price == 0.0) {
		return true;
	}
	return false;
}
