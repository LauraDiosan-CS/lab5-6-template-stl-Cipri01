#include "ConsoleFile.h"
#include <iostream>
#include <string>
#include <string.h>
#include <iterator>
#include <map>

using namespace std;

ConsoleFile::ConsoleFile() {

}

ConsoleFile::ConsoleFile(Service& service) {
	this->service = service;
}

void ConsoleFile::displayMenu()
{
	cout << "1. Write \"addProduct {{code}} {{name}} {{price}}\" to add a product\n";
	cout << "2. Write \"showProducts\" to display all products\n";
	cout << "3. Write \"pos {{i}}\" to display the product from position i\n";
	cout << "4. Write \"update {{oldCode}} {{newCode}} {{newName}} {{newPrice}}\" to update the product with the code {{oldCode}}\n";
	cout << "5. Write \"delete {{code}}\" to delete the product with code {{code}}\n";
	cout << "6. Write \"buy {{code}} {{name}} {{price}} {{money}} to buy a product\n";
	cout << "7. Write \"addCoin {{value}} {{number}}\" to add a coin\n";
	cout << "8. Write \"showCoins\" to display all coins\n";
	cout << "x. Write\"exit\" to close the application\n";
	cout << "\nGive option: \n";
}

void ConsoleFile::uiAddProduct(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* code = new char[token.length() + 1];
	strcpy_s(code, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* name = new char[token.length() + 1];
	strcpy_s(name, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	float price = stof(token);

	this->service.addProduct(code, name, price);
}

void ConsoleFile::uiAddCoin(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	//cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	float value = stof(token);
	
	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int number = stoi(token);

	this->service.addCoin(value, number);
}

void ConsoleFile::uiShowAllProducts() {
	cout << endl;
	vector<Product> products = this->service.getAllProducts();
	int size = products.size();
	for (int i = 0; i < size; i++) {
		cout << products[i];
	}
	cout << endl;
}

void ConsoleFile::uiShowAllCoins() {
	cout << endl;
	vector<Coin> coins = this->service.getAllCoins();
	int size = coins.size();
	for (int i = 0; i < size; i++) {
		cout << coins[i];
	}
	cout << endl;
}

void ConsoleFile::uiShowAtPosition(string cmd) {
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());
	int position = stoi(cmd);
	Product p = this->service.getProductAtPosition(position);
	cout << p;
}

void ConsoleFile::uiUpdateByCode(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* oldCode = new char[token.length() + 1];
	strcpy_s(oldCode, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* newCode = new char[token.length() + 1];
	strcpy_s(newCode, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* newName = new char[token.length() + 1];
	strcpy_s(newName, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	float newPrice = stof(token);

	this->service.updateProductByCode(oldCode, newCode, newName, newPrice);
}

void ConsoleFile::uiDeleteByCode(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* code = new char[token.length() + 1];
	strcpy_s(code, token.length() + 1, token.c_str());

	this->service.deleteProductByCode(code);
}

void ConsoleFile::uiBuyProduct(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* code = new char[token.length() + 1];
	strcpy_s(code, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* name = new char[token.length() + 1];
	strcpy_s(name, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	float price = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	float amount = stoi(token);

	Product p(code, name, price);

	map<float, int> money;

	this->service.getRest(amount, p, money);

	if (amount == -1) {
		cout << "No rest can be given! " << endl;
	}
	else {
		cout << "Rest: " << endl;
		map<float, int>::iterator itr;
		for (itr = money.begin(); itr != money.end(); ++itr) {
			cout << itr->first << ": " << itr->second << endl;
		}
	}
	
}

void ConsoleFile::runUI() {
	bool shouldRun = true;
	string cmd;
	while (shouldRun) {
		this->displayMenu();
		getline(cin, cmd);
		if (cmd.find("addProduct") != string::npos) { //string::npos = -1
			this->uiAddProduct(cmd);
		}
		if (cmd.find("showProducts") != string::npos) {
			this->uiShowAllProducts();
		}
		if (cmd.find("pos") != string::npos) {
			this->uiShowAtPosition(cmd);
		}
		if (cmd.find("update") != string::npos) {
			this->uiUpdateByCode(cmd);
		}
		if (cmd.find("delete") != string::npos) {
			this->uiDeleteByCode(cmd);
		}
		if (cmd.find("buy") != string::npos) {
			this->uiBuyProduct(cmd);
		}
		if (cmd.find("addCoin") != string::npos) {
			this->uiAddCoin(cmd);
		}
		if (cmd.find("showCoins") != string::npos) {
			this->uiShowAllCoins();
		}
		if (cmd.find("exit") != string::npos) {
			shouldRun = false;
		}
	}
}