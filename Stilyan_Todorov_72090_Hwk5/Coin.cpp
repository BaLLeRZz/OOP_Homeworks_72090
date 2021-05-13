#include "Coin.h"

void Coin::copy(const Coin& other)
{
	this->side = other.side;
	this->nationality = new char[strlen(other.nationality) + 1];
	strcpy_s(this->nationality, strlen(other.nationality) + 1, other.nationality);
	this->value = other.value;
}

void Coin::erase()
{
	delete[] this->nationality;
}

Coin::Coin()
{
	this->side = HEAD;
	this->nationality = new char[1];
	this->nationality[0] = '\0';
	this->value = 0;
}

Coin::Coin(const Coin& other)
{
	this->copy(other);
}

Coin::Coin(const Side& _side, const char* _nationality, const size_t& _value)
{
	this->side = _side;
	this->nationality = new char[strlen(_nationality) + 1];
	strcpy_s(this->nationality, strlen(_nationality) + 1, _nationality);
	this->value = _value;
}

Coin& Coin::operator=(const Coin& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

Coin::~Coin()
{
	this->erase();
}

size_t Coin::getValue() const
{
	return this->value;
}

const char* Coin::enumToString(const Side& _side)
{
	if (_side)
		return "TAIL";
	else
		return "HEAD";
}

Side Coin::getSide() const
{
	return this->side;
}

void Coin::flip()
{
	srand(time(NULL));
	if (rand() % 2)
		this->side = HEAD;
	else
		this->side = TAIL;
}

void Coin::print()
{
	std::cout << "Coin Side: " << this->enumToString(this->side) << std::endl;
	std::cout << "Nationality: " << this->nationality << std::endl;
	std::cout << "Value: " << this->value << std::endl;
}

bool Coin::operator==(const Coin& other)
{
	if (this == &other)
		return true;

	if (this->value != other.value)
		return false;

	for (size_t i = 0; i < strlen(this->nationality); i++)
		if (this->nationality[i] != other.nationality[i])
			return false;

	return true;
}
