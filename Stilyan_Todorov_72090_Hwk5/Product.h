#pragma once
#include "String.h"
class Product
{
private:
	String name;
	size_t price;
	size_t percentage;
	Side chance;
public:
	Product()
	{
		this->name = "Empty";
		this->price = 0;
		this->percentage = 0;
		this->chance = HEAD;
	}
	Product(const String _name, const size_t _price, const size_t _percentage, const Side& _chance)
	{
		this->name = _name;
		this->price = _price;
		this->percentage = _percentage;
		this->chance = _chance;
	}

	void setPrice(const size_t _price)
	{
		this->price = _price;
	}

	size_t getPrice() const
	{
		return this->price;
	}

	size_t getPercentage() const
	{
		return this->percentage;
	}

	Side getChance() const
	{
		return this->chance;
	}
};