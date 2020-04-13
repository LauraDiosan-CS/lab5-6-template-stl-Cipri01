#include <iostream>
#include "ProductTest.h"
#include "RepoTest.h"
#include "ServiceTest.h"
#include "ConsoleFile.h"
#include "RepoFileTest.h"
#include "CoinTest.h"

int main() {
	testProduct();

	testCoin();

	TestRepo r;
	r.testAll();
	
	TestRepoFile rf;
	rf.testAll();

	TestService s;
	s.testAll();

	cout << endl;

	RepoFile<Product> repoProduct("products.txt");
	RepoFile<Coin> repoCoin("coins.txt");
	Service service(repoProduct, repoCoin);
	ConsoleFile c(service);

	c.runUI();

	return 0;
};