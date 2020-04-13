#pragma once
#include "RepoFile.h"
#include "Coin.h"
#include <iterator>
#include <map>
class Service {
private:
	RepoFile<Product> repoProduct;
	RepoFile<Coin> repoCoin;
public:
	Service();
	Service(RepoFile<Product>& repoProduct, RepoFile<Coin>& repoCoin);
	~Service();

	void setRepo(RepoFile<Product>& repoProduct, RepoFile<Coin>& repoCoin);

	void addProduct(char* code, char* name, float price);
	vector<Product> getAllProducts();
	Product getProductAtPosition(int pos);
	void updateProductByCode(char* code, char* newCode, char* newName, float newPrice);
	void deleteProductByCode(char* code);
	void deleteProductByPosition(int pos);
	int getSizeProducts();

	void addCoin(float value, int number);
	vector<Coin> getAllCoins();
	Coin getCoinAtPosition(int pos);
	void updateCoinByValue(float value, float newValue, int newNumber);
	void deleteCoinByValue(float value);
	int getSizeCoins();

	bool buyProduct(char* code, float money, float& rest);
	void getRest(float &amount, Product p, map<float, int>& money);
};