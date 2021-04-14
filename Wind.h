#pragma once
#include"String.h"
class Wind
{
private:
	String name;
	size_t startPower;
	size_t bonusPower;
	size_t cardType;
public:
	Wind();
	Wind(const String _name, size_t _startPower, size_t _bonusPower, size_t _cardType);
	friend std::ostream& operator<<(std::ostream& out, const Wind& wind)
	{
		out << "Card Name: " << wind.name << std::endl;
		out << "Start Power: " << wind.startPower << std::endl;
		out << "Bonus Power: " << wind.bonusPower << std::endl;
		out << "Card Type: " << wind.cardType << " -> Wind" << std::endl;
		return out;
	}
};