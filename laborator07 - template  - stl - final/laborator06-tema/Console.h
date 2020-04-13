#pragma once
#include "Service.h"
#include "ProductTest.h"
#include "RepoTest.h"
#include "ServiceTest.h"

class Console {
private:
	Service service_for_products;
public:
	void menu();
	int run();
	char read_option();
	float read_float();
	char* read_char_pointer();
	void handle_add_product();
	void handle_show_all();
	void handle_update_product();
	void handle_delete_product();
	void run_test();
};