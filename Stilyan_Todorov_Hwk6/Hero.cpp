#include "Hero.h"

Hero::Hero() : Mob()
{
    this->type = "hero";
    this->armor = 0;
    this->hit = attackType::NORMAL;
}

Hero::Hero(const String _name, double _health, double _damage, int _armor, size_t _hit) : Mob(_name, _health, _damage), armor(_armor)
{
    this->type = "hero";
    switch (_hit)
    {
    case 1:
        this->hit = attackType::NORMAL;
        break;
    case 2:
        this->hit = attackType::SPLASH;
        break;
    default:
        this->hit = attackType::NORMAL;
        break;
    }
}

void Hero::attack(Mob*& other)
{
    if (!this->isAlive)
        throw 1;

    if (this->type == other->getType())
        throw 2;

    if (other->getType() == "enemies")
    {
        size_t squadSize = other->getSquadSize();
        if (this->hit == attackType::SPLASH)
        {
            for (size_t i = 0; i < squadSize; i++)
                if (other->operator[](i)->getHealth() > 0)
                    other->operator[](i)->takeDamage(this->damage);
        }
        else
        {
            for (size_t i = 0; i < squadSize; i++)
                if (other->operator[](i)->getHealth() > 0)
                {
                    other->operator[](i)->takeDamage(this->damage);
                    break;
                }
        }
        return;
    }

    other->takeDamage(this->damage);
}

void Hero::takeDamage(const double _damage)
{
    if (!this->isAlive)
        throw 1;

    double difference;
    if (this->armor > 0)
    {
        std::cout << this->name << " got attacked!" << std::endl << std::endl;
        if (this->armor - _damage >= 0)
            this->armor -= _damage;
        else
        {
            difference = _damage - this->armor;
            this->armor = 0;
            std::cout << this->name << "'s armor got destroyed!" << std::endl << std::endl;
            this->health -= difference;
        }
        return;
    }

    this->health -= _damage;
    std::cout << this->name << " got attacked!" << std::endl << std::endl;
    if (this->health <= 0)
    {
        this->die();
        std::cout << this->name << " has died!" << std::endl << std::endl;
    }
    std::cout << std::endl;
}
