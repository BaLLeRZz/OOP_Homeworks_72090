#pragma once
#include"String.h"
class Fire
{
private:
	String name;
	size_t startPower;
	size_t bonusPower;
	size_t cardType;
public:
	Fire();
	Fire(const String _name, size_t _startPower, size_t _bonusPower);
	const String& getName() const;
	const size_t getStartPower() const;
	const size_t getBonusPower() const;
	const size_t getType() const;
	friend std::ostream& operator<<(std::ostream& out, const Fire& fire)
	{
		out << "Card Name: " << fire.name << std::endl;
		out << "Start Power: " << fire.startPower << std::endl;
		out << "Bonus Power: " << fire.bonusPower << std::endl;
		out << "Card Type: " << fire.cardType << " -> Fire" << std::endl;
		return out;
	}
};