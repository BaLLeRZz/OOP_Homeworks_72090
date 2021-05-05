#include "SmartFunc.h"
template<class T>
bool isOdd(T element)
{
	return element % 2 != 0;
}

template<class T>
int plusTwo(T element)
{
	return element + 2;
}

template<class T>
T product(Vector<T> vec)
{
	T product = 1;
	for (size_t i = 0; i < vec.getSize(); i++)
		product *= vec[i];

	return product;
}

int main()
{
	Vector<int> a;
	a.add(1);
	a.add(2);
	a.add(3);
	SmartFunc<int> b;
	b.setFilter(isOdd);
	b.useFilter(a);
	a.print();
	std::cout << std::endl;
	b.setMap(plusTwo);
	b.useMap(a);
	a.print();
	std::cout << std::endl;
	b.setReduce(product);
	b.useReduce(a);
	std::cout << std::endl;
	b.useFilterWithMap(a);
	a.print();

	return 0;
}