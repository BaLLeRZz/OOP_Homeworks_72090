#include "Water.h"

Water::Water()
{
	this->startPower = 0;
	this->bonusPower = 0;
	this->cardType = 1;
}

Water::Water(const String _name, size_t _startPower, size_t _bonusPower)
{
	this->name = _name;
	this->startPower = _startPower;
	this->bonusPower = _bonusPower;
	this->cardType = 1;
}

const String& Water::getName() const
{
	return this->name;
}

const size_t Water::getStartPower() const
{
	return this->startPower;
}

const size_t Water::getBonusPower() const
{
	return this->bonusPower;
}

const size_t Water::getType() const
{
	return this->cardType;
}
