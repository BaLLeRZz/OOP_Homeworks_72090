#pragma once
#include "Discipline.h" 
#include "List.h"
class Specialty
{
private:
	String name;
	List<Discipline> list;
public:
	Specialty() : name("None") {};
	Specialty(const String& _name) : name(_name) {};
	const String getName() const
	{
		return this->name;
	}
	void addDiscipline(const Discipline& discipline)
	{
		this->list.add(discipline);
	}
	void print() const
	{
		std::cout << "Specialty: " << this->name << std::endl;
		std::cout << "Disciplines: " << this->list.getSize() << std::endl << std::endl;
		this->list.print();
	}
	friend std::ostream& operator<<(std::ostream& out, const Specialty& spec)
	{
		out << spec.name << std::endl;
		return out;
	}
};