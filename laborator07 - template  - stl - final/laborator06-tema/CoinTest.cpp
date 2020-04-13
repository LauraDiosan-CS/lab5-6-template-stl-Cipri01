#include "CoinTest.h"
#include "Coin.h"
#include <assert.h>

void testCoin() {
	Coin c1;

	assert(c1.getNumber() == 0);
	assert(c1.getValue() == 0);

	c1.setValue(10.0);
	c1.setNumber(5);

	Coin c2(10.0, 5);
	Coin c3(c2);

	assert(c1.getNumber() == 5);
	assert(c1.getValue() == 10);
	assert(c1 == c2);
	assert(c2 == c3);

	cout << "Coin test... OK!" << endl;
}