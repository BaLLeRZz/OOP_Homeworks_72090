#include "Buyer.h"
int main()
{
	Buyer b;
	b.addMoneyBG(50);
	b.addMoneyDE(20);
	b.addMoneyUS(10);
	b.addMoneyUS(10);
	b.addMoneyBG(5);
	b.printCoins();
	std::cout << std::endl << std::endl;
	Product p1("Bread", 10, 8, HEAD);
	Product p2("Milk", 20, 5, TAIL);
	Product p3("Phone", 200, 10, TAIL);
	Product p4("Waffle", 5, 3, HEAD);
	b.buy(p1);
	std::cout << std::endl;
	b.buy(p2);
	std::cout << std::endl;
	b.buy(p3);
	std::cout << std::endl;
	b.buy(p4);
	std::cout << std::endl;
	b.printCoins();
	return 0;
}