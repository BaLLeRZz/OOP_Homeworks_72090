#include "Mob.h"
#include "Enemy.h"
Mob::Mob()
{
	this->name = "Empty";
	this->health = 1;
	this->damage = 0;
	this->isAlive = true;
}

Mob::Mob(const String _name, double _health, double _damage)
{
	this->name = _name;
	if (_health <= 0)
		throw 0;
	this->health = _health;
	this->damage = _damage;
	this->isAlive = true;
}

void Mob::die()
{
	this->isAlive = false;
}

const String& Mob::getType() const
{
	return this->type;
}

double Mob::getHealth() const
{
	return this->health;
}

bool Mob::getAlive() const
{
	return this->isAlive;
}

void Mob::takeDamage(const double _damage)
{
	if (!this->isAlive)
		throw 1;

	this->health -= _damage;
	std::cout << this->name << " got attacked!" << std::endl << std::endl;
	if (this->health <= 0)
	{
		this->die();
		std::cout << this->name << " has died!" << std::endl << std::endl;
	}
	std::cout << std::endl;
}

const size_t Mob::getSquadSize() const
{
	return 0;
}

Mob*& Mob::operator[](size_t index)
{
	Mob* temp = new Enemy();
	return temp;
}

void Mob::add(Mob*&)
{
	return;
}
