#pragma once
#include "String.h"
class Mob
{
protected:
	String name;
	double health;
	double damage;
	bool isAlive;
	String type;
public:
	Mob();
	Mob(const String, double, double);
	virtual void attack(Mob*&) = 0;
	void die();
	const String& getType() const;
	double getHealth() const;
	bool getAlive() const;
	virtual void takeDamage(const double);
	virtual const size_t getSquadSize() const;
	virtual Mob*& operator[](size_t);
	virtual void add(Mob*&);
};