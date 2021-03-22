#pragma once
#include<iostream>
class Rational
{
private:
	int numerator;
	int denominator;
public:
	Rational();
	Rational(int _numerator, int _denominator);

	void setNumerator(int _numerator);
	void setDenominator(int _denominator);

	int getNumerator() const;
	int getDenominator() const;

	void input();
	void print() const;

	void operator+(const Rational& other);
	void operator-(const Rational& other);
	void operator*(const Rational& other);
	void operator/(const Rational& other);

	bool operator>(const Rational& other);
	bool operator<(const Rational& other);
	bool operator==(const Rational& other);
	bool operator!=(const Rational& other);

	Rational& operator=(const Rational& other);

	void operator+=(const Rational& other);
	void operator-=(const Rational& other);
	void operator*=(const Rational& other);
	void operator/=(const Rational& other);
};