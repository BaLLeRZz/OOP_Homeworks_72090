#pragma once
#include "BulgarianCoin.h"
#include "AmericanCoin.h"
#include "GermanCoin.h"
#include "Vector.h"
#include "Product.h"
class Buyer
{
private:
	Vector<BulgarianCoin> bg;
	Vector<AmericanCoin> us;
	Vector<GermanCoin> de;
public:
	void addMoneyBG(const size_t&);
	void addMoneyUS(const size_t&);
	void addMoneyDE(const size_t&);

	size_t sumBG();
	size_t sumUS();
	size_t sumDE();

	void removeMoneyBG(size_t);
	void removeMoneyUS(const size_t&);
	void removeMoneyDE(const size_t&);

	void buy(Product&);
	void printCoins() const;
};