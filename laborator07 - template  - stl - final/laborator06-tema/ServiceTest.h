#pragma once
#include "Service.h"

class TestService {
private:
	Service service;

	void testAddProduct();
	void testGetAll();
	void testGetProductAtPosition();
	void testUpdateProductByCode();
	void testDeleteProductByCode();
	void testDeleteProductByPosition();
	void testBuy();
	void testGetRest();
public:
	TestService();
	void testAll();
};