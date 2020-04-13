#pragma once
#include <iostream>
using namespace std;

class Coin {
private:
	float value;
	int number;
public:
	Coin();
	Coin(float value, int number);
	Coin(const Coin& c);
	~Coin();

	void setValue(float newValue);
	void setNumber(int newNumber);

	float getValue();
	int getNumber();

	Coin& operator=(const Coin& c);
	bool operator==(const Coin& c);
	bool operator!();

	friend istream& operator>>(istream& isc, Coin& c);
	friend ostream& operator<<(ostream& osc, Coin& c);
};