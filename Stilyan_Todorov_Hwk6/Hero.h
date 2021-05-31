#pragma once
#include "Mob.h"
enum class attackType
{
	NORMAL, SPLASH
};
class Hero : public Mob
{
private:
	attackType hit;
	int armor;
public:
	Hero();
	Hero(const String, double, double ,int, size_t);
	void attack(Mob*&);
	void takeDamage(const double) override;
};