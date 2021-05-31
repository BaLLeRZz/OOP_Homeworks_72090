#include "Enemies.h"

Enemies::Enemies() : Mob()
{
	this->type = "enemies";
}

void Enemies::add(Mob*& other)
{
	this->squad.add(other);
}

void Enemies::attack(Mob*& other)
{
	if (this->type == other->getType() || this->type == "enemy")
		throw 2;

	size_t squadSize = this->squad.getSize();
	for (size_t i = 0; i < squadSize; i++)
	{
		if (other->operator[](i)->getHealth() <= 0)
			return;

		this->squad[i]->attack(other);
	}
}

const size_t Enemies::getSquadSize() const
{
	return this->squad.getSize();
}

Mob*& Enemies::operator[](size_t index)
{
	return this->squad[index];
}
