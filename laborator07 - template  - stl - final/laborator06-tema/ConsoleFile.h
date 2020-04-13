#pragma once
 #include "Service.h"

class ConsoleFile {
private:
	Service service;
	void displayMenu();
	void uiAddProduct(string cmd);
	void uiAddCoin(string cmd);
	void uiShowAllProducts();
	void uiShowAllCoins();
	void uiShowAtPosition(string cmd);
	void uiUpdateByCode(string cmd);
	void uiDeleteByCode(string cmd);
	void uiBuyProduct(string cmd);
public:
	ConsoleFile();
	ConsoleFile(Service& service);
	void runUI();
};