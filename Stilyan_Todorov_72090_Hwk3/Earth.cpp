#include "Earth.h"

Earth::Earth()
{
	this->startPower = 0;
	this->bonusPower = 0;
	this->cardType = 3;
}

Earth::Earth(const String _name, size_t _startPower, size_t _bonusPower)
{
	this->name = _name;
	this->startPower = _startPower;
	this->bonusPower = _bonusPower;
	this->cardType = 3;
}

const String& Earth::getName() const
{
	return this->name;
}

const size_t Earth::getStartPower() const
{
	return this->startPower;
}

const size_t Earth::getBonusPower() const
{
	return this->bonusPower;
}

const size_t Earth::getType() const
{
	return this->cardType;
}
