#include "RepoTest.h"
#include <assert.h>


// class TestRepo initialization
TestRepo::TestRepo() {
	char* code1 = new char[10];
	strcpy_s(code1, 1 + strlen("12A"), "12A");

	char* code2 = new char[10];
	strcpy_s(code2, 1 + strlen("100C"), "100C");

	char* code3 = new char[10];
	strcpy_s(code3, 1 + strlen("12#A"), "12#A");

	char* code4 = new char[10];
	strcpy_s(code4, 1 + strlen("122@A"), "122@A");

	char* name1 = new char[10];
	strcpy_s(name1, 1 + strlen("oreo"), "oreo");

	char* name2 = new char[10];
	strcpy_s(name2, 1 + strlen("lays"), "lays");

	char* name3 = new char[10];
	strcpy_s(name3, 1 + strlen("pepsi"), "pepsi");

	char* name4 = new char[10];
	strcpy_s(name4, 1 + strlen("cola"), "cola");

	Product p1(code1, name1, 5.5);
	Product p2(code2, name2, 8.0);
	Product p3(code3, name3, 6.5);
	Product p4(code4, name4, 7.0);

	this->products.push_back(p1);
	this->products.push_back(p2);
	this->products.push_back(p3);
	this->products.push_back(p4);

	repo.addElement(p1);
	repo.addElement(p2);
	repo.addElement(p3);
	repo.addElement(p4);

}

// test all method
void TestRepo::testAll()
{
	this->testGetAll();
	this->testGetSize();
	this->testGetProductAtPosition();
	this->testAddProduct();
	this->testUpdateProduct();
	this->testDeleteProduct();
}

//test for get all method
void TestRepo::testGetAll() {
	vector<Product> prod = this->repo.getAll();
	for (int i = 0; i < this->repo.getSize(); i++) {
		assert(prod[i] == this->products[i]);
	}
}

// test for get size method
void TestRepo::testGetSize() {
	assert(4 == this->products.size());
	assert(repo.getSize() == 4);
	assert(this->products.size() == repo.getSize());
}

// test for get product at position
void TestRepo::testGetProductAtPosition() {
	for (int i = 0; i < this->repo.getSize(); i++) {
		assert(this->repo.getItemAtPosition(i) == this->products[i]);
	}
}

// test for add product
void TestRepo::testAddProduct() {
	int initialLen = this->repo.getSize();

	char* code1 = new char[10];
	strcpy_s(code1, 1 + strlen("12A"), "12A");

	char* name3 = new char[10];
	strcpy_s(name3, 1 + strlen("pepsi"), "pepsi");

	Product p5(code1, name3, 10.0);

	this->repo.addElement(p5);

	assert(this->repo.getSize() == initialLen + 1);
	assert(this->repo.getItemAtPosition(initialLen) == p5);
}

// test for update product
void TestRepo::testUpdateProduct() {
	char* code1 = new char[10];
	strcpy_s(code1, 1 + strlen("12A"), "12A");

	char* name3 = new char[10];
	strcpy_s(name3, 1 + strlen("pepsi"), "pepsi");

	Product p6(code1, name3, 2.0);

	this->repo.updateElement(this->repo.getAll()[1], p6);
	
	assert(this->repo.getItemAtPosition(1).getPrice() == 2.0);
	assert(this->repo.getAll()[1] == p6);
}

// test for delete product
void TestRepo::testDeleteProduct() {
	int initialLen = this->repo.getSize();
	this->repo.deleteElement(this->repo.getAll()[1]);

	assert(this->repo.getSize() == initialLen-1);

	cout << "Repo test... OK!" << endl;
}
