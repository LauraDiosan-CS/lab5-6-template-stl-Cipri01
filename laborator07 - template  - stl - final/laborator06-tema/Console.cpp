#include "Console.h"
#include <iostream>
using namespace std;

void Console::menu() {
	cout << "---MENU---" << endl;
	cout << "1 -> Adding a product..." << endl;
	cout << "2 -> Show all products..." << endl;
	cout << "3 -> Update a product..." << endl;
	cout << "4 -> Delete a product..." << endl;
	cout << "x -> EXIT!..." << endl;
}

//Descr: read option methods
//In: -
//Out: the option
char Console::read_option() {
	cout << "Give the option:  ";
	char option;
	cin >> option;
	return option;
}

//Descr: read method for integer
//In: -
//Out: an integer
float Console::read_float() {
	float number;
	cin >> number;
	return number;
}

//Descr: read method for pointers
//In: -
//Out: a pointer
char* Console::read_char_pointer() {
	char ch[100];
	cin >> ch;
	char* ch_p = new char[strlen(ch) + 1];
	strcpy_s(ch_p, strlen(ch) + 1, ch);
	return ch_p;
}

int Console::run() {
	while (true) {
		this->menu();
		char option = read_option();
		switch (option)
		{
		case'1':
			this->handle_add_product();
			break;
		case'2':
			this->handle_show_all();
			break;
		case '3':
			this->handle_update_product();
			break;
		case '4':
			this->handle_delete_product();
			break;
		case'x':
			return 0;
		default:
			break;
		}
	}
}

//Descr: handle method for add
//In: -
//Out: -
void Console::handle_add_product() {
	float price;
	char* code;
	char* name;
	cout << "Give the code for product:  ";
	code = read_char_pointer();
	cout << "Give the name for product:  ";
	name = read_char_pointer();
	cout << "Give the price for product:  ";
	price = read_float();
	this->service_for_products.addProduct(code, name, price);
}

//Descr: handle method for show all
//In: -
//Out: -
void Console::handle_show_all() {
	int length = this->service_for_products.getSizeProducts();
	cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < length; i++) {
		cout << this->service_for_products.getAllProducts()[i];
	}
	cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Console::handle_update_product(){
	char* codeUPD;
	cout << "Give the product code for update:  ";
	codeUPD = read_char_pointer();
	float price;
	char* code;
	char* name;
	cout << "Give the code for new product:  ";
	code = read_char_pointer();
	cout << "Give the name for new product:  ";
	name = read_char_pointer();
	cout << "Give the price for new product:  ";
	price = read_float();
	this->service_for_products.updateProductByCode(codeUPD, code, name, price);
}

void Console::handle_delete_product(){
	char* codeDEL;
	cout << "Give the product code for delete:  ";
	codeDEL = read_char_pointer();
	this->service_for_products.deleteProductByCode(codeDEL);
}

void Console::run_test() {
	TestRepo r;
	TestService s;
	cout << "_________________________________" << endl; 
	cout << "|     START TEST...             |" << endl;
	testProduct();
	r.testAll();
	s.testAll();
	cout << "|     END... IT'S OK            |" << endl;
	cout << "_________________________________" << endl;
	cout << endl;
}
