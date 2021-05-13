#pragma once
#include "Coin.h"
class GermanCoin : public Coin
{
public:
	GermanCoin() : Coin(HEAD, "German", 0) {};
	GermanCoin(const size_t& _value) : Coin(HEAD, "German", _value)
	{
		if (_value != 1 && _value != 2 && _value != 5 && _value != 10 && _value != 20 && _value != 50 && _value != 100 && _value != 200)
		{
			std::cout << "No such coin exists!" << std::endl;
			this->value = 0;
		}
	}

	void evaluate() const
	{
		std::cout << this->value << " German Coin = " << (double) 1 / 6 * this->value << " Bulgarian Coin" << std::endl;
		std::cout << this->value << " German Coin = " << (double) 2 / 5 * this->value << " American Coin" << std::endl;
	}
};