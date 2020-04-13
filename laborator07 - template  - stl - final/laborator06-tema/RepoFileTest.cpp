#include "RepoFileTest.h"
#include <assert.h>


// class TestRepo initialization
TestRepoFile::TestRepoFile() {
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
}

// test all method
void TestRepoFile::testAll()
{
	this->testLoadFromFile();
	this->testSaveToFile();
	this->testGetAll();
	this->testGetSize();
	this->testGetProductAtPosition();
	this->testAddProduct();
	this->testUpdateProduct();
	this->testDeleteProduct();
}

void TestRepoFile::testLoadFromFile() {
	this->rf.setFileName(this->fileName);
	//this->rf.setFileNameOut(this->fileNameOut);
	//this->rf.addElement(products[1]);
	//this->rf.saveToFile();
	this->rf.loadFromFile();
	//cout << this->rf.getSize();
	assert(this->rf.getSize() == 4);
	vector<Product> productsIn = this->rf.getAll();
	for (int i = 0; i < this->rf.getSize(); i++) {
		assert(productsIn[i] == this->products[i]);
	}
}

void TestRepoFile::testSaveToFile() {
	this->rf.setFileName(this->fileName);
	//this->rf.setFileNameOut(this->fileNameOut);
	this->rf.loadFromFile();
	int initialLen = this->rf.getSize();
	char* code5 = new char[10];
	strcpy_s(code5, 1 + strlen("28C"), "28C");
	char* name5 = new char[10];
	strcpy_s(name5, 1 + strlen("fanta"), "fanta");
	Product p5(code5, name5, 9.3);
	this->rf.addElement(p5);
	this->rf.saveToFile();
	//this->rf.setFileNameIn(this->fileNameOut);
	this->rf.loadFromFile();
	//cout << this->rf.getSize();
	assert(this->rf.getSize() == initialLen + 1);
	vector<Product> productsIn = this->rf.getAll();
	for (int i = 0; i < this->rf.getSize() - 1; i++) {
		assert(productsIn[i] == this->products[i]);
	}
	assert(productsIn[initialLen] == p5);
	this->rf.deleteElement(p5);
}
//test for get all method
void TestRepoFile::testGetAll() {
	this->rf.setFileName(this->fileName);
	this->rf.loadFromFile();
	vector<Product> productsIn = this->rf.getAll();
	for (int i = 0; i < this->rf.getSize(); i++) {
		assert(productsIn[i] == this->products[i]);
	}
}

// test for get size method
void TestRepoFile::testGetSize() {
	this->rf.setFileName(this->fileName);
	this->rf.loadFromFile();
	assert(4 == this->products.size());
	assert(rf.getSize() == 4);
	assert(this->products.size() == this->rf.getSize());
}

// test for get product at position
void TestRepoFile::testGetProductAtPosition() {
	this->rf.setFileName(this->fileName);
	this->rf.loadFromFile();
	for (int i = 0; i < this->rf.getSize(); i++) {
		assert(this->rf.getItemAtPosition(i) == this->products[i]);
	}
}

// test for add product
void TestRepoFile::testAddProduct() {
	this->rf.setFileName(this->fileName);
	this->rf.loadFromFile();
	int initialLen = this->rf.getSize();

	char* code1 = new char[10];
	strcpy_s(code1, 1 + strlen("12A"), "12A");

	char* name3 = new char[10];
	strcpy_s(name3, 1 + strlen("pepsi"), "pepsi");

	Product p5(code1, name3, 10.0);

	this->rf.addElement(p5);

	assert(this->rf.getSize() == initialLen + 1);
	assert(this->rf.getItemAtPosition(initialLen) == p5);
	this->rf.deleteElement(p5);
}

// test for update product
void TestRepoFile::testUpdateProduct() {
	this->rf.setFileName(this->fileName);
	this->rf.loadFromFile();
	char* code1 = new char[10];
	strcpy_s(code1, 1 + strlen("12A"), "12A");

	char* name3 = new char[10];
	strcpy_s(name3, 1 + strlen("pepsi"), "pepsi");

	Product p6(code1, name3, 2.0);

	Product old = this->rf.getAll()[1];
	this->rf.updateElement(this->rf.getAll()[1], p6);

	assert(this->rf.getItemAtPosition(1).getPrice() == 2.0);
	assert(this->rf.getAll()[1] == p6);
	this->rf.updateElement(this->rf.getAll()[1], old);
}

//test for delete product
void TestRepoFile::testDeleteProduct() {
	this->rf.setFileName(this->fileName);
	this->rf.loadFromFile();
	int initialLen = this->rf.getSize();
	Product del = this->rf.getAll()[3];
	this->rf.deleteElement(this->rf.getAll()[3]);

	assert(this->rf.getSize() == initialLen - 1);
	this->rf.addElement(del);
	cout << "Repo File test... OK!" << endl;
}
