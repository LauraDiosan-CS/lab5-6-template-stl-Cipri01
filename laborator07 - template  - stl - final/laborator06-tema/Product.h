#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
using namespace std;

class Product {
private:
	char* code;
	char* name;
	float price;
public:
	Product();
	Product(char* code, char* name, float price);
	Product(const Product& p);
	~Product();
	void setCode(char* valueCode);
	void setName(char* valueName);
	void setPrice(float price);
	char* getCode();
	char* getName();
	float getPrice();

	Product& operator=(const Product& p);
	bool operator==(const Product& p);
	bool operator!();

	friend istream& operator>>(istream& is, Product& p); // IO operator
	friend ostream& operator<<(ostream& os, Product& p); // IO operator
};
#endif // !PRODUCT_H
