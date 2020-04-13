#include "ServiceTest.h"
#include <assert.h>
#include <iterator>
#include <map>

TestService::TestService() {
}

void TestService::testAll() {
	this->testAddProduct();
	this->testGetAll();
	this->testGetProductAtPosition();
	this->testUpdateProductByCode();
	this->testDeleteProductByCode();
	this->testDeleteProductByPosition();
	this->testBuy();
	this->testGetRest();
}

void TestService::testAddProduct() {
	RepoFile<Product> repoProduct;
	RepoFile<Coin> repoCoin;

	this->service.setRepo(repoProduct, repoCoin);

	char* code1 = new char[10];
	strcpy_s(code1, 1 + strlen("12A"), "12A");

	char* name1 = new char[10];
	strcpy_s(name1, 1 + strlen("oreo"), "oreo");

	Product p(code1, name1, 5.5);

	this->service.addProduct(code1, name1, 5.5);

	assert(this->service.getProductAtPosition(0) == p);
	assert(this->service.getProductAtPosition(0).getPrice() == 5.5);

	this->service.deleteProductByCode(code1);
}

void TestService::testGetAll() {
	RepoFile<Product> repoProduct;
	RepoFile<Coin> repoCoin;

	this->service.setRepo(repoProduct, repoCoin);

	char* code1 = new char[10];
	strcpy_s(code1, 1 + strlen("12A"), "12A");

	char* code2 = new char[10];
	strcpy_s(code2, 1 + strlen("100C"), "100C");

	char* name1 = new char[10];
	strcpy_s(name1, 1 + strlen("oreo"), "oreo");

	char* name2 = new char[10];
	strcpy_s(name2, 1 + strlen("lays"), "lays");

	Product p1(code1, name1, 5.5);
	Product p2(code2, name2, 10.0);

	this->service.addProduct(code1, name1, 5.5);
	this->service.addProduct(code2, name2, 10.0);

	vector<Product> products = this->service.getAllProducts();

	assert(products.size() == 2);
	assert(products[0] == p1);
	assert(products[1] == p2);

	this->service.deleteProductByCode(code1);
	this->service.deleteProductByCode(code2);
}

void TestService::testGetProductAtPosition() {
	RepoFile<Product> repoProduct;
	RepoFile<Coin> repoCoin;

	this->service.setRepo(repoProduct, repoCoin);

	char* code1 = new char[10];
	strcpy_s(code1, 1 + strlen("12A"), "12A");

	char* name1 = new char[10];
	strcpy_s(name1, 1 + strlen("oreo"), "oreo");

	Product p(code1, name1, 5.5);

	this->service.addProduct(code1, name1, 5.5);

	assert(this->service.getProductAtPosition(0) == p);

	this->service.deleteProductByCode(code1);
}

void TestService::testUpdateProductByCode() {
	RepoFile<Product> repoProduct;
	RepoFile<Coin> repoCoin;

	this->service.setRepo(repoProduct, repoCoin);

	char* code1 = new char[10];
	strcpy_s(code1, 1 + strlen("12A"), "12A");

	char* code2 = new char[10];
	strcpy_s(code2, 1 + strlen("100C"), "100C");

	char* name1 = new char[10];
	strcpy_s(name1, 1 + strlen("oreo"), "oreo");

	char* name2 = new char[10];
	strcpy_s(name2, 1 + strlen("lays"), "lays");

	Product p1(code1, name1, 5.5);
	Product p2(code2, name2, 10.0);

	this->service.addProduct(code1, name1, 5.5);
	this->service.updateProductByCode(code1, p2.getCode(), p2.getName(), p2.getPrice());

	assert(this->service.getProductAtPosition(0) == p2);

	this->service.deleteProductByCode(code1);
	this->service.deleteProductByCode(code2);
}

void TestService::testDeleteProductByCode() {
	RepoFile<Product> repoProduct;
	RepoFile<Coin> repoCoin;

	this->service.setRepo(repoProduct, repoCoin);

	char* code1 = new char[10];
	strcpy_s(code1, 1 + strlen("12A"), "12A");

	char* code2 = new char[10];
	strcpy_s(code2, 1 + strlen("100C"), "100C");

	char* name1 = new char[10];
	strcpy_s(name1, 1 + strlen("oreo"), "oreo");

	Product p(code1, name1, 5.5);

	this->service.addProduct(code1, name1, 5.5);
	this->service.deleteProductByCode(code2);

	vector<Product> products = this->service.getAllProducts();

	assert(products.size() == 1);
	assert(products[0] == p);

	this->service.deleteProductByCode(code1);

	products = this->service.getAllProducts();

	assert(products.size() == 0);

}

void TestService::testDeleteProductByPosition() {
	RepoFile<Product> repoProduct;
	RepoFile<Coin> repoCoin;

	this->service.setRepo(repoProduct, repoCoin);

	char* code1 = new char[10];
	strcpy_s(code1, 1 + strlen("12A"), "12A");

	char* name1 = new char[10];
	strcpy_s(name1, 1 + strlen("oreo"), "oreo");

	Product p(code1, name1, 5.5);

	this->service.addProduct(code1, name1, 5.5);
	this->service.deleteProductByPosition(0);

	vector<Product> products = this->service.getAllProducts();

	assert(products.size() == 0);

	//cout << "Service test... OK!" << endl;
}

void TestService::testBuy() {
	RepoFile<Product> repoProduct;
	RepoFile<Coin> repoCoin;

	this->service.setRepo(repoProduct, repoCoin);

	char* code1 = new char[10];
	strcpy_s(code1, 1 + strlen("12A"), "12A");

	char* name1 = new char[10];
	strcpy_s(name1, 1 + strlen("oreo"), "oreo");

	Product p(code1, name1, 5.5);
	this->service.addProduct(code1, name1, 5.5);
	float rest = 0;
	bool ok = this->service.buyProduct(code1, 6.0, rest);

	assert(ok == 1);
	assert(rest == 0.5);
}

void TestService::testGetRest() {
	RepoFile<Product> repoProduct;
	RepoFile<Coin> repoCoin;

	this->service.setRepo(repoProduct, repoCoin);

	char* code1 = new char[10];
	strcpy_s(code1, 1 + strlen("12A"), "12A");

	char* name1 = new char[10];
	strcpy_s(name1, 1 + strlen("oreo"), "oreo");

	Product p(code1, name1, 5.5);
	this->service.addProduct(code1, name1, 5.5);

	float amount = 20.0;

	map<float, int> money;

	this->service.addCoin(50.0, 5);
	this->service.addCoin(10.0, 5);
	this->service.addCoin(5.0, 25);
	this->service.addCoin(1.0, 40);
	this->service.addCoin(0.5, 50);

	this->service.getRest(amount, p, money);

	map<float, int>::iterator itr;

	assert(money.begin()->first == 0.5);
	assert(money.begin()->second == 1);

	cout << "Service test... OK!" << endl;
}