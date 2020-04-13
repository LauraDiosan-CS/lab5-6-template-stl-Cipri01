#include "Coin.h"
#include <string.h>
#include <ostream>
#include<iostream>

Coin::Coin() {
	this->value = 0.0;
	this->number = 0;
}

Coin::Coin(float value, int number) {
	this->value = value;
	this->number = number;
}

Coin::Coin(const Coin& c) {
	this->value = c.value;
	this->number = c.number;
}

Coin::~Coin() {}

void Coin::setValue(float newValue) {
	this->value = newValue;
}

void Coin::setNumber(int newNumber) {
	this->number = newNumber;
}

float Coin::getValue() {
	return this->value;
}

int Coin::getNumber() {
	return this->number;
}

Coin& Coin::operator=(const Coin& c) {
	this->setValue(c.value);
	this->setNumber(c.number);
	return *this;
}

bool Coin::operator==(const Coin& c) {
	return (this->value == c.value && this->number == c.number);
}

bool Coin::operator!() {
	if (this->value == 0.0 || this->number == 0)
		return true;
	return false;
}

istream& operator>>(istream& isc, Coin& c) {
	float value;
	isc >> value;

	int number;
	isc >> number;

	return isc;
}

ostream& operator<<(ostream& osc, Coin& c){
	osc << c.value << " " << c.number << endl;
	return osc;
}
