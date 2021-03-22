#include"Rational.h"
int main()
{
	Rational a, b, c;
	std::cout << "Default Constructor:" << std::endl;
	a.print();
	std::cout << std::endl;
	std::cout << "Input Functions:" << std::endl << std::endl;
	std::cout << "Input First Fraction (a):" << std::endl;
	a.input();
	std::cout << std::endl;
	std::cout << "Input Second Fraction (b):" << std::endl;
	b.input();
	std::cout << std::endl;
	std::cout << "Giving (c) the value of (a):" << std::endl;
	c = a;
	c.print();
	std::cout << std::endl;
	std::cout << "The Sum of the two fractions:" << std::endl;
	a + b;
	std::cout << std::endl;
	std::cout << "The Difference between the two fractions:" << std::endl;
	a - b;
	std::cout << std::endl;
	std::cout << "The Product of the two fractions:" << std::endl;
	a * b;
	std::cout << std::endl;
	std::cout << "The Quotient of the two fractions:" << std::endl;
	a / b;
	std::cout << std::endl;
	std::cout << "Comparing If a > b:" << std::endl;
	if (a > b)
		std::cout << "Yes";
	else
		std::cout << "No";
	std::cout << std::endl << std::endl;
	std::cout << "Comparing If a < b:" << std::endl;
	if (a < b)
		std::cout << "Yes";
	else
		std::cout << "No";
	std::cout << std::endl << std::endl;
	std::cout << "Comparing If a = b:" << std::endl;
	if (a == b)
		std::cout << "Yes";
	else
		std::cout << "No";
	std::cout << std::endl << std::endl;
	std::cout << "Comparing If a != b:" << std::endl;
	if (a != b)
		std::cout << "Yes";
	else
		std::cout << "No";
	std::cout << std::endl << std::endl;
	std::cout << "Changing the value of (a) by adding (b):" << std::endl;
	a += b;
	std::cout << std::endl;
	std::cout << "Changing the value of (a) by subtracting (b):" << std::endl;
	a -= b;
	std::cout << std::endl;
	std::cout << "Changing the value of (a) by multiplying by (b):" << std::endl;
	a *= b;
	std::cout << std::endl;
	std::cout << "Changing the value of (a) by dividing by (b):" << std::endl;
	a /= b;
	std::cout << std::endl;
	std::cout << "The final value of (a):" << std::endl;
	a.print();
	std::cout << std::endl;
	return 0;
}