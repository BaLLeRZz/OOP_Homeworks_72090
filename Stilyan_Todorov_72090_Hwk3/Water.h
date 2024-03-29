#pragma once
#include"String.h"
class Water
{
private:
	String name;
	size_t startPower;
	size_t bonusPower;
	size_t cardType;
public:
	Water();
	Water(const String _name, size_t _startPower, size_t _bonusPower);
	const String& getName() const;
	const size_t getStartPower() const;
	const size_t getBonusPower() const;
	const size_t getType() const;
	friend std::ostream& operator<<(std::ostream& out, const Water& water)
	{
		out << "Card Name: " << water.name << std::endl;
		out << "Start Power: " << water.startPower << std::endl;
		out << "Bonus Power: " << water.bonusPower << std::endl;
		out << "Card Type: " << water.cardType << " -> Water" << std::endl;
		return out;
	}
};