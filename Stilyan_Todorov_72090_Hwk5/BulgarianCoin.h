#pragma once
#include "Coin.h"
class BulgarianCoin : public Coin
{
public:
	BulgarianCoin() : Coin(HEAD, "Bulgarian", 0) {};
	BulgarianCoin(const size_t& _value) : Coin(HEAD, "Bulgarian", _value)
	{
		if (_value != 1 && _value != 2 && _value != 5 && _value != 10 && _value != 20 && _value != 50 && _value != 100 && _value != 200)
		{
			std::cout << "No such coin exists!" << std::endl;
			this->value = 0;
		}
	}

	void evaluate() const
	{
		std::cout << this->value << " Bulgarian Coin = " << 3 * this->value << " American Coin" << std::endl;
		std::cout << this->value << " Bulgarian Coin = " << 6 * this->value << " German Coin" << std::endl;
	}
	
	void flip() override
	{
		if (rand() % 10 < 3)
			this->side = HEAD;
		else
			this->side = TAIL;
	}
};