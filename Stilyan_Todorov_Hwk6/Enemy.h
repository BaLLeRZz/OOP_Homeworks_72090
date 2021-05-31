#pragma once
#include "Mob.h"
enum class enemyType
{
	SMALL, AVARAGE, BIG
};
class Enemy : public Mob
{
private:
	enemyType size;
public:
	Enemy();
	Enemy(const String, double, double, size_t);
	void attack(Mob*&);
};