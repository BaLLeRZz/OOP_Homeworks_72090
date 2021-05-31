#include "Enemy.h"

Enemy::Enemy() : Mob()
{
	this->type = "enemy";
	this->size = enemyType::SMALL;
}

Enemy::Enemy(const String _name, double _health, double _damage, size_t _size) : Mob(_name, _health, _damage)
{
	this->type = "enemy";
	switch (_size)
	{
	case 1:
		this->size = enemyType::SMALL;
		break;
	case 2:
		this->size = enemyType::AVARAGE;
		this->damage *= 1.5;
		break;
	case 3:
		this->size = enemyType::BIG;
		this->damage *= 2;
		break;
	default:
		this->size = enemyType::SMALL;
		break;
	}
}

void Enemy::attack(Mob*& other)
{
	if (!this->isAlive)
		throw 1;

	if (this->type == other->getType() || this->type == "enemies")
		throw 2;

	other->takeDamage(this->damage);
}