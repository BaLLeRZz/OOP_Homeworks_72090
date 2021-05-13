#pragma once
#include "Coin.h"
class AmericanCoin : public Coin
{
public:
	AmericanCoin() : Coin(HEAD, "American", 0) {};
	AmericanCoin(const size_t& _value) : Coin(HEAD, "American", _value)
	{
		if (_value != 1 && _value != 5 && _value != 10 && _value != 25 && _value != 50 && _value != 100)
		{
			std::cout << "No such coin exists!" << std::endl;
			this->value = 0;
		}
	}

	void evaluate() const
	{
		std::cout << this->value << " American Coin = " << (double) 1 / 3 * this->value << " Bulgarian Coin" << std::endl;
		std::cout << this->value << " American Coin = " << (double) 5 / 2 * this->value << " German Coin" << std::endl;
	}

	void flip() override
	{
		if (rand() % 10 < 8)
			this->side = HEAD;
		else
			this->side = TAIL;
	}
};