#pragma once
#include "Mob.h"
#include "Enemy.h"
#include "Vector.h"
class Enemies : public Mob
{
private:
	Vector<Mob*> squad;
public:
	Enemies();
	void add(Mob*&);
	void attack(Mob*&);
	const size_t getSquadSize() const override;
	Mob*& operator[](size_t) override;
};