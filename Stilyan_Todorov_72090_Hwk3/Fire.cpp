#include "Fire.h"

Fire::Fire()
{
	this->startPower = 0;
	this->bonusPower = 0;
	this->cardType = 2;
}

Fire::Fire(const String _name, size_t _startPower, size_t _bonusPower)
{
	this->name = _name;
	this->startPower = _startPower;
	this->bonusPower = _bonusPower;
	this->cardType = 2;
}

const String& Fire::getName() const
{
	return this->name;
}

const size_t Fire::getStartPower() const
{
	return this->startPower;
}

const size_t Fire::getBonusPower() const
{
	return this->bonusPower;
}

const size_t Fire::getType() const
{
	return this->cardType;
}
