#include "Buyer.h"

void Buyer::addMoneyBG(const size_t& _value)
{
	BulgarianCoin b(_value);
	this->bg.add(b);
}

void Buyer::addMoneyUS(const size_t& _value)
{
	AmericanCoin a(_value);
	this->us.add(a);
}

void Buyer::addMoneyDE(const size_t& _value)
{
	GermanCoin g(_value);
	this->de.add(g);
}

size_t Buyer::sumBG()
{
	size_t sum = 0;
	size_t size = this->bg.getSize();
	for (size_t i = 0; i < size; i++)
		sum += this->bg[i].getValue();
	return sum;
}

size_t Buyer::sumUS()
{
	size_t sum = 0;
	size_t size = this->us.getSize();
	for (size_t i = 0; i < size; i++)
		sum += this->us[i].getValue();
	return sum;
}

size_t Buyer::sumDE()
{
	size_t sum = 0;
	size_t size = this->de.getSize();
	for (size_t i = 0; i < size; i++)
		sum += this->de[i].getValue();
	return sum;
}

void Buyer::removeMoneyBG(size_t _value)
{
	size_t size = this->bg.getSize();
	size_t sum = this->sumBG();

	if (sum < _value)
	{
		std::cout << "You do not have enough money in the wallet!" << std::endl;
		return;
	}
	
	for(size_t i = 0; i < size; i++)
		if (this->bg[i].getValue() == _value)
		{
			this->bg.remove(i);
			std::cout << "Purchased successfully!" << std::endl;
			return;
		}

	for (size_t i = 0; i < size; i++)
		if (this->bg[i].getValue() > _value)
		{
			this->bg.remove(i);
			std::cout << "Purchased successfully!" << std::endl;
			return;
		}
}

void Buyer::removeMoneyUS(const size_t& _value)
{
	size_t size = this->us.getSize();
	size_t sum = this->sumUS();

	if (sum < _value)
	{
		std::cout << "You do not have enough money in the wallet!" << std::endl;
		return;
	}

	for (size_t i = 0; i < size; i++)
		if (this->us[i].getValue() == _value)
		{
			this->us.remove(i);
			std::cout << "Purchased successfully!" << std::endl;
			return;
		}

	for (size_t i = 0; i < size; i++)
		if (this->us[i].getValue() > _value)
		{
			this->us.remove(i);
			std::cout << "Purchased successfully!" << std::endl;
			return;
		}
}

void Buyer::removeMoneyDE(const size_t& _value)
{
	size_t size = this->de.getSize();
	size_t sum = this->sumDE();

	if (sum < _value)
	{
		std::cout << "You do not have enough money in the wallet!" << std::endl;
		return;
	}

	for (size_t i = 0; i < size; i++)
		if (this->de[i].getValue() == _value)
		{
			this->de.remove(i);
			std::cout << "Purchased successfully!" << std::endl;
			return;
		}
	
	for (size_t i = 0; i < size; i++)
		if (this->de[i].getValue() > _value)
		{
			this->de.remove(i);
			std::cout << "Purchased successfully!" << std::endl;
			return;
		}
}

void Buyer::buy(Product& product)
{
	size_t price = product.getPrice();
	size_t percentage = product.getPercentage();
	srand(time(NULL));
	size_t x = rand() % 3;
	if (x == 0)
	{
		std::cout << "Price is in Bulgarian currency!" << std::endl;
		std::cout << "Price: " << price << std::endl;
		BulgarianCoin b;
		b.flip();
		if (b.getSide() == product.getChance())
		{
			std::cout << "Congratulations! You get a discount of " << percentage << "% !" << std::endl;
			product.setPrice(price - price * percentage / 100);
			price = product.getPrice();
			std::cout << "New price: " << price << std::endl;
		}
		this->removeMoneyBG(price);
	}
	else
		if (x == 1)
		{
			std::cout << "Price is in American currency!" << std::endl;
			std::cout << "Price: " << price << std::endl;
			AmericanCoin a;
			a.flip();
			if (a.getSide() == product.getChance())
			{
				std::cout << "Congratulations! You get a discount of " << percentage << "% !" << std::endl;
				product.setPrice(price - price * percentage / 100);
				price = product.getPrice();
				std::cout << "New price: " << price << std::endl;
			}
			this->removeMoneyUS(price);
		}
		else
			if (x == 2)
			{
				std::cout << "Price is in German currency!" << std::endl;
				std::cout << "Price: " << price << std::endl;
				GermanCoin g;
				g.flip();
				if (g.getSide() == product.getChance())
				{
					std::cout << "Congratulations! You get a discount of " << percentage << "% !" << std::endl;
					product.setPrice(price - price * percentage / 100);
					price = product.getPrice();
					std::cout << "New price: " << price << std::endl;
				}
				this->removeMoneyDE(price);
			}
}

void Buyer::printCoins() const
{
	size_t sizeBG = this->bg.getSize();
	size_t sizeUS = this->us.getSize();
	size_t sizeDE = this->de.getSize();
	if (sizeBG + sizeUS + sizeDE == 0)
	{
		std::cout << "No coins in the wallet!" << std::endl;
		return;
	}

	if (sizeBG == 0)
		std::cout << "No Bulgarian Coins in the wallet!";
	else
	{
		std::cout << "Bulgarian Coins: " << std::endl;
		for (size_t i = 0; i < sizeBG; i++)
			std::cout << this->bg[i].getValue() << " | ";
	}
	std::cout << std::endl << std::endl;

	if (sizeUS == 0)
		std::cout << "No American Coins in the wallet!";
	else
	{
		std::cout << "American Coins: " << std::endl;
		for (size_t i = 0; i < sizeUS; i++)
			std::cout << this->us[i].getValue() << " | ";
	}
    std::cout << std::endl << std::endl;

	if (sizeDE == 0)
		std::cout << "No German Coins in the wallet!";
	else
	{
		std::cout << "German Coins: " << std::endl;
		for (size_t i = 0; i < sizeDE; i++)
			std::cout << this->de[i].getValue() << " | ";
	}
	std::cout << std::endl << std::endl;
}
