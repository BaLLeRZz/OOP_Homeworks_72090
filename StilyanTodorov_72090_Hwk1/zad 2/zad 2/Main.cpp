#include"Film.h"
int main()
{
	Film test1, test2;
	test1.print();
	std::cout << std::endl;
	test2.setNameFilm("Star Wars");
	test2.setNameProducer("Harrison Ford");
	test2.setAwards(23);
	test2.print();
	std::cout << std::endl;
	test1 = test2;
	test1.print();
	std::cout << std::endl;
	return 0;
}