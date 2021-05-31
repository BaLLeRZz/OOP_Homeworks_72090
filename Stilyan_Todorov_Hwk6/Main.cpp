#include "Enemies.h"
#include "Hero.h"
int main()
{
	try
	{
		Mob* e1 = new Enemy("Beray", 35, 15, 1);
		Mob* e2 = new Enemy("Milen", 70, 30, 2);
		Mob* e3 = new Enemy("Maria", 100, 50, 3);
		Mob* e4 = new Enemy("Daniel", 100, 99.9, 3);
		Mob* e5 = new Enemy("Ally", 100, 65, 3);
		Mob* e6 = new Enemy("Blago", 70, 45, 2);
		Mob* e7 = new Enemy("Yavor", 35, 20, 1);
		
		Mob* squad = new Enemies();
		squad->add(e1);
		squad->add(e2);
		squad->add(e3);
		squad->add(e4);
		squad->add(e5);
		squad->add(e6);
		squad->add(e7);

		Mob* h = new Hero("Stenli", 230, 60, 100, 2);

		h->attack(e7);
		h->attack(e5);
		e2->attack(h);
		e5->attack(h);
		h->attack(squad);
		e4->attack(h);
		h->attack(e4);
	}
	catch (const int ex)
	{
		switch (ex)
		{
		case 0:
			std::cout << "Invalid health input!" << std::endl;
			break;
		case 1:
			std::cout << "This mob is already dead!" << std::endl;
			break;
		case 2:
			std::cout << "Cannot attack mobs of the same type!" << std::endl;
			break;
		}
	}
	
	return 0;
}