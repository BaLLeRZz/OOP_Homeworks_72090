#include "Earth.h"

Earth::Earth()
{
	this->startPower = 0;
	this->bonusPower = 0;
	this->cardType = 3;
}

Earth::Earth(const String _name, size_t _startPower, size_t _bonusPower, size_t _cardType)
{
	this->name = _name;
	this->startPower = _startPower;
	this->bonusPower = _bonusPower;
	this->cardType = _cardType = 3;
}
