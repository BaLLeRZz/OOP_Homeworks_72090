#include "Rational.h"

Rational::Rational()
{
	this->numerator = 0;
	this->denominator = 1;
}

Rational::Rational(int _numerator, int _denominator)
{
	this->numerator = _numerator;
	if (_denominator == 0)
		this->denominator = 1;
	else
	    this->denominator = _denominator;
}

void Rational::setNumerator(int _numerator)
{
	this->numerator = _numerator;
}

void Rational::setDenominator(int _denominator)
{
	if (_denominator == 0)
		this->denominator = 1;
	else
		this->denominator = _denominator;
}

int Rational::getNumerator() const
{
	return this->numerator;
}

int Rational::getDenominator() const
{
	return this->denominator;
}

void Rational::input()
{
	std::cout << "Numerator: ";
	std::cin >> this->numerator;
	std::cout << "Denominator: ";
	std::cin >> this->denominator;
	while (this->denominator == 0)
	{
		std::cout << "Invalid input!" << std::endl;
		std::cout << "Denominator: ";
		std::cin >> this->denominator;
	}
	print();
}

void Rational::print() const
{
	if (this->numerator == 0)
		std::cout << "Your Rational Number: " << 0 << std::endl;
	else
	    std::cout << "Your Rational Number: " << this->numerator << "/" << this->denominator << std::endl;
}

void Rational::operator+(const Rational& other)
{
	int num, denom;
	if (this == &other)
	{
		num = this->numerator * 2;
		denom = this->denominator;
		std::cout << num << "/" << denom << std::endl;
		return;
	}

	if (this->denominator == other.denominator)
	{
		num = this->numerator + other.numerator;
		denom = this->denominator;
		std::cout << num << "/" << denom << std::endl;
		return;
	}

	if (this->denominator < other.denominator)
	{
			if (other.denominator % this->denominator == 0)
			{
				num = this->numerator * (other.denominator / this->denominator) + other.numerator;
				denom = this->denominator * (other.denominator / this->denominator);
				std::cout << num << "/" << denom << std::endl;
				return;
			}
			else
			{
				num = (this->numerator * other.denominator) + (other.numerator * this->denominator);
				denom = this->denominator * other.denominator;
				std::cout << num << "/" << denom << std::endl;
				return;
			}
	}
	
	else
		if (this->denominator > other.denominator)
		{
			if (this->denominator % other.denominator == 0)
			{
				num = this->numerator + other.numerator * (this->denominator / other.denominator);
				denom = this->denominator;
				std::cout << num << "/" << denom << std::endl;
				return;
			}
			else
			{
				num = (this->numerator * other.denominator) + (other.numerator * this->denominator);
				denom = this->denominator * other.denominator;
				std::cout << num << "/" << denom << std::endl;
				return;
			}
		}
}

void Rational::operator-(const Rational& other)
{
	int num, denom;
	if (this == &other)
	{
		std::cout << 0 << std::endl;
		return;
	}

	if (this->denominator == other.denominator)
	{
		num = this->numerator - other.numerator;
		denom = this->denominator;
		std::cout << num << "/" << denom << std::endl;
		return;
	}

	if (this->denominator < other.denominator)
	{
		if (other.denominator % this->denominator == 0)
		{
			num = this->numerator * (other.denominator / this->denominator) - other.numerator;
			denom = this->denominator * (other.denominator / this->denominator);
			std::cout << num << "/" << denom << std::endl;
			return;
		}
		else
		{
			num = (this->numerator * other.denominator) - (other.numerator * this->denominator);
			denom = this->denominator * other.denominator;
			std::cout << num << "/" << denom << std::endl;
			return;
		}
	}

	else
		if (this->denominator > other.denominator)
		{
			if (this->denominator % other.denominator == 0)
			{
				num = this->numerator - other.numerator * (this->denominator / other.denominator);
				denom = this->denominator;
				std::cout << num << "/" << denom << std::endl;
				return;
			}
			else
			{
				num = (this->numerator * other.denominator) - (other.numerator * this->denominator);
				denom = this->denominator * other.denominator;
				std::cout << num << "/" << denom << std::endl;
				return;
			}
		}
}

void Rational::operator*(const Rational& other)
{
	int num, denom;
	num = this->numerator * other.numerator;
	denom = this->denominator * other.denominator;
	std::cout << num << "/" << denom << std::endl;
}

void Rational::operator/(const Rational& other)
{
	int num, denom;
	num = this->numerator * other.denominator;
	denom = this->denominator * other.numerator;
	std::cout << num << "/" << denom << std::endl;
}

bool Rational::operator>(const Rational& other)
{
	if (this == &other)
		return true;

	if (((double)this->numerator / this->denominator) > ((double)other.numerator / other.denominator))
		return true;
	else
		return false;
}

bool Rational::operator<(const Rational& other)
{
	if (this == &other)
		return true;

	if (((double)this->numerator / this->denominator) < ((double)other.numerator / other.denominator))
		return true;
	else
		return false;
}

bool Rational::operator==(const Rational& other)
{
	if (this == &other)
		return true;

	if (((double)this->numerator / this->denominator) == ((double)other.numerator / other.denominator))
		return true;
	else
		return false;
}

bool Rational::operator!=(const Rational& other)
{
	if (this == &other)
		return false;

	if (((double)this->numerator / this->denominator) != ((double)other.numerator / other.denominator))
		return true;
	else
		return false;
}

Rational& Rational::operator=(const Rational& other)
{
	if (this != &other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	return *this;
}

void Rational::operator+=(const Rational& other)
{
	if (this == &other)
	{
		this->numerator *= 2;
		std::cout << this->numerator << "/" << this->denominator << std::endl;
		return;
	}

	if (this->denominator == other.denominator)
	{
		this->numerator += other.numerator;
		std::cout << this->numerator << "/" << this->denominator << std::endl;
		return;
	}

	if (this->denominator < other.denominator)
	{
		if (other.denominator % this->denominator == 0)
		{
			this->numerator = this->numerator * (other.denominator / this->denominator) + other.numerator;
			this->denominator *= (other.denominator / this->denominator);
			std::cout << this->numerator << "/" << this->denominator << std::endl;
			return;
		}
		else
		{
			this->numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
			this->denominator *= other.denominator;
			std::cout << this->numerator << "/" << this->denominator << std::endl;
			return;
		}
	}

	else
		if (this->denominator > other.denominator)
		{
			if (this->denominator % other.denominator == 0)
			{
				this->numerator += other.numerator * (this->denominator / other.denominator);
				std::cout << this->numerator << "/" << this->denominator << std::endl;
				return;
			}
			else
			{
				this->numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
				this->denominator *= other.denominator;
				std::cout << this->numerator << "/" << this->denominator << std::endl;
				return;
			}
		}
}

void Rational::operator-=(const Rational& other)
{
	if (this == &other)
	{
		this->numerator = 0;
		this->denominator = 1;
		std::cout << this->numerator / this->denominator << std::endl;
		return;
	}

	if (this->denominator == other.denominator)
	{
		this->numerator -= other.numerator;
		std::cout << this->numerator << "/" << this->denominator << std::endl;
		return;
	}

	if (this->denominator < other.denominator)
	{
		if (other.denominator % this->denominator == 0)
		{
			this->numerator = this->numerator * (other.denominator / this->denominator) - other.numerator;
			this->denominator *= (other.denominator / this->denominator);
			std::cout << this->numerator << "/" << this->denominator << std::endl;
			return;
		}
		else
		{
			this->numerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
			this->denominator *= other.denominator;
			std::cout << this->numerator << "/" << this->denominator << std::endl;
			return;
		}
	}

	else
		if (this->denominator > other.denominator)
		{
			if (this->denominator % other.denominator == 0)
			{
				this->numerator -= other.numerator * (this->denominator / other.denominator);
				std::cout << this->numerator << "/" << this->denominator << std::endl;
				return;
			}
			else
			{
				this->numerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
				this->denominator *= other.denominator;
				std::cout << this->numerator << "/" << this->denominator << std::endl;
				return;
			}
		}
}

void Rational::operator*=(const Rational& other)
{
	this->numerator *= other.numerator;
	this->denominator *= other.denominator;
	std::cout << this->numerator << "/" << this->denominator << std::endl;
}

void Rational::operator/=(const Rational& other)
{
	this->numerator *= other.denominator;
	this->denominator *= other.numerator;
	std::cout << this->numerator << "/" << this->denominator << std::endl;
}
