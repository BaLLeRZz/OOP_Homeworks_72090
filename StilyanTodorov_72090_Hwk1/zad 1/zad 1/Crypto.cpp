#include "Crypto.h"

Crypto::Crypto()
{
	this->name = new char[6];
	strcpy_s(this->name, 6, "Empty");
	this->lastPrice = 0;
	this->currentPrice = 0;
}

Crypto::Crypto(const char* _name, double _lastPrice, double _currentPrice)
{
	this->name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name) + 1, _name);
	this->lastPrice = _lastPrice;
	this->currentPrice = _currentPrice;
}

void Crypto::setName(const char* _name)
{
	delete[] this->name;
	this->name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name) + 1, _name);
}

void Crypto::setLastPrice(double _lastPrice)
{
	this->lastPrice = _lastPrice;
}

void Crypto::setCurrentPrice(double _currentPrice)
{
	this->currentPrice = _currentPrice;
}

const char* Crypto::getName() const
{
	return this->name;
}

double Crypto::getLastPrice() const
{
	return this->lastPrice;
}

double Crypto::getCurrentPrice() const
{
	return this->currentPrice;
}

void Crypto::input()
{
	std::cout << "Name: ";
	std::cin >> this->name;
	std::cout << "Last price: ";
	std::cin >> this->lastPrice;
	std::cout << "Current price: ";
	std::cin >> this->currentPrice;
}

double Crypto::priceDifference() const
{
	if (this->lastPrice == 0)
		return 0;
	return -(100*(this->lastPrice - this->currentPrice)) / (double)this->lastPrice;
}

void Crypto::print() const
{
	std::cout << "Crypto currnecy name: " << this->name << std::endl;
	std::cout << "Last price: " << this->lastPrice << std::endl;
	std::cout << "Current price: " << this->currentPrice << std::endl;
	std::cout << "Price differnce: " << priceDifference() << "%" << std::endl;
}
