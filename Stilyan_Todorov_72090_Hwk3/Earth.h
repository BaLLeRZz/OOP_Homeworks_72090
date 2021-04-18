#pragma once
#include"String.h"
class Earth
{
private:
	String name;
	size_t startPower;
	size_t bonusPower;
	size_t cardType;
public:
	Earth();
	Earth(const String _name, size_t _startPower, size_t _bonusPower);
	const String& getName() const;
	const size_t getStartPower() const;
	const size_t getBonusPower() const;
	const size_t getType() const;
	friend std::ostream& operator<<(std::ostream& out, const Earth& earth)
	{
		out << "Card Name: " << earth.name << std::endl;
		out << "Start Power: " << earth.startPower << std::endl;
		out << "Bonus Power: " << earth.bonusPower << std::endl;
		out << "Card Type: " << earth.cardType << " -> Earth" << std::endl;
		return out;
	}
};