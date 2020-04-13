#include "Service.h"

Service::Service() {
}

Service::Service(RepoFile<Product>& repoProduct, RepoFile<Coin>& repoCoin) {
	this->repoProduct = repoProduct;
	this->repoCoin = repoCoin;
}

Service::~Service() {
}

void Service::setRepo(RepoFile<Product>& repoProduct, RepoFile<Coin>& repoCoin) {
	this->repoProduct = repoProduct;
	this->repoCoin = repoCoin;
}

void Service::addProduct(char* code, char* name, float price) {
	this->repoProduct.addElement(Product(code, name, price));
}

void Service::addCoin(float value, int number) {
	this->repoCoin.addElement(Coin(value, number));
}


vector<Product> Service::getAllProducts() {
	return this->repoProduct.getAll();
}

Product Service::getProductAtPosition(int pos) {
	return this->repoProduct.getItemAtPosition(pos);
}

void Service::updateProductByCode( char* code, char* newCode, char* newName, float newPrice) {
	vector<Product> products = this->repoProduct.getAll();
	Product newProduct(newCode, newName, newPrice);
	for (int i = 0; i < this->repoProduct.getSize(); i++) {
		if (strcmp(products[i].getCode(), code) == 0) {
			Product oldProduct(code, products[i].getName(), products[i].getPrice());
			this->repoProduct.updateElement(oldProduct, newProduct);
		}
	}
}

void Service::deleteProductByCode(char* code) {
	vector<Product> products = this->repoProduct.getAll();
	for (int i = 0; i < this->repoProduct.getSize(); i++) {
		Product productToBeDeleted(code, products[i].getName(), products[i].getPrice());
		this->repoProduct.deleteElement(productToBeDeleted);
	} 
}

void Service::deleteProductByPosition(int pos) {
	Product productToBeDeleted = this->repoProduct.getItemAtPosition(pos);
	this->repoProduct.deleteElement(productToBeDeleted);
}

int Service::getSizeProducts() {
	return this->repoProduct.getSize();
}


vector<Coin> Service::getAllCoins() {
	return this->repoCoin.getAll();
}

Coin Service::getCoinAtPosition(int pos) {
	return this->repoCoin.getItemAtPosition(pos);
}

void Service::updateCoinByValue(float value, float newValue, int newNumber) {
	vector<Coin> coins = this->repoCoin.getAll();
	Coin newCoin(newValue, newNumber);
	for (int i = 0; i < this->repoCoin.getSize(); i++) {
		if (coins[i].getValue() == value) {
			Coin oldCoin(value, coins[i].getNumber());
			this->repoCoin.updateElement(oldCoin, newCoin);
		}
	}
}

void Service::deleteCoinByValue(float value) {
	vector<Coin> coins = this->repoCoin.getAll();
	for (int i = 0; i < this->repoCoin.getSize(); i++) {
		Coin coinToBeDeleted(value, coins[i].getNumber());
		this->repoCoin.deleteElement(coinToBeDeleted);
	}
}

int Service::getSizeCoins() {
	return this->repoCoin.getSize();
}

bool Service::buyProduct(char* code, float money, float& rest) {
	bool ok = false;
	for (int i = 0; i < this->repoProduct.getSize(); i++) {
		if (strcmp(this->repoProduct.getAll()[i].getCode(), code) == 0) {
			float price = this->repoProduct.getAll()[i].getPrice();
			rest = money - price;
			if (rest < 0) {
				return false;
			}
			else {
				return true;
			}
		}
	}
}

void Service::getRest(float &amount, Product p, map<float, int>& money){
	vector<Coin> coins = this->repoCoin.getAll();
	float rest = 0.0;
	bool ok = buyProduct(p.getCode(), amount, rest);
	int counter[6] = { 0 };
	int k = 0;
	for (int i = 0;i<this->repoCoin.getSize();i++) {
		Coin coin = this->repoCoin.getAll()[i];
		if (rest >= coin.getValue()) {
			counter[k] = rest / coin.getValue();
			if (counter[k] < coin.getNumber()) {
				rest = rest - coin.getValue() * counter[k];
				Coin cNew = coin;
				cNew.setNumber(cNew.getNumber() - counter[k]);
				this->repoCoin.updateElement(coin, cNew);
				money.insert(pair<float, int>(coin.getValue(), counter[k]));
				k++;
			}
			else {
				rest = rest - coin.getValue() * coin.getNumber();
				money.insert(pair<float, int>(coin.getValue(), coin.getNumber()));
				this->repoCoin.deleteElement(coin);
				i--;
			}
			
		}
	}
	if (rest > 0) {
		for (int i = 0; i < coins.size(); i++) {
			this->repoCoin.addElement(coins[i]);
		}
		amount = -1;
	}
}

