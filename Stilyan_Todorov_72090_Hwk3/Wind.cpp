#include "Wind.h"

Wind::Wind()
{
	this->startPower = 0;
	this->bonusPower = 0;
	this->cardType = 4;
}

Wind::Wind(const String _name, size_t _startPower, size_t _bonusPower)
{
	this->name = _name;
	this->startPower = _startPower;
	this->bonusPower = _bonusPower;
	this->cardType = 4;
}

const String& Wind::getName() const
{
	return this->name;
}

const size_t Wind::getStartPower() const
{
	return this->startPower;
}

const size_t Wind::getBonusPower() const
{
	return this->bonusPower;
}

const size_t Wind::getType() const
{
	return this->cardType;
}
