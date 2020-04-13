#pragma once
#include "RepoFile.h"
#include <vector>
#include "Product.h"
class TestRepoFile {
private:
	RepoFile<Product> rf;
	vector<Product> products;
	const char* fileName = "TestProducts.txt";
	//const char* fileNameOut = "TestProductsOut.txt";

	void testLoadFromFile();
	void testSaveToFile();
	void testGetAll();
	void testGetSize();
	void testGetProductAtPosition();
	void testAddProduct();
	void testUpdateProduct();
	void testDeleteProduct();
public:
	TestRepoFile();
	void testAll();
};
