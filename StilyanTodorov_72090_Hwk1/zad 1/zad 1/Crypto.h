#pragma once
#include<iostream>
#include<cstring>
class Crypto
{
private:
	char* name;
	double lastPrice;
	double currentPrice;
public:
	Crypto();
	Crypto(const char* _name, double _lastPrice, double _currentPrice);
	
	void setName(const char* _name);
	void setLastPrice(double _lastPrice);
	void setCurrentPrice(double _currentPrice);

	const char* getName() const;
	double getLastPrice() const;
	double getCurrentPrice() const;

	void input();
	double priceDifference() const;
	void print() const;
};