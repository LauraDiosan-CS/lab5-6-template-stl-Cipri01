#pragma once
#include "Repo.h"
class TestRepo {
private:
	Repo<Product> repo;
	vector<Product> products;

	void testGetAll();
	void testGetSize();
	void testGetProductAtPosition();
	void testAddProduct();
	void testUpdateProduct();
	void testDeleteProduct();
public:
	TestRepo();
	void testAll();
};
