#include "ProductTest.h"
#include "Product.h"
#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

// tests for class Product
void testProduct() {
	Product p1;
	char* code = new char[20];
	strcpy_s(code, strlen("12A") + 1, "12A");
	char* name = new char[20];
	strcpy_s(name, strlen("oreo") + 1, "oreo");
	Product p2(code, name, 4.5);
	char* code1 = new char[20];
	strcpy_s(code1, strlen("15A") + 1, "15A");
	char* name1 = new char[20];
	strcpy_s(name1, strlen("milka") + 1, "milka");
	char* code2 = new char[20];
	strcpy_s(code2, strlen("15A") + 1, "15A");
	char* name2 = new char[20];
	strcpy_s(name2, strlen("milka") + 1, "milka");
	Product p3(code2, name2, 5.5);


	p2.setCode(code1);
	p2.setName(name1);
	p2.setPrice(5.5);


	assert(p1.getPrice() == 0);
	assert(strcmp(p2.getCode(), code1) == 0);
	assert(strcmp(p2.getName(), name1) == 0);
	assert(strcmp(p3.getCode(), code1) == 0);
	assert(strcmp(p3.getName(), name1) == 0);
	assert(p2 == p3);

	cout << "Product test... OK!" << endl;
}