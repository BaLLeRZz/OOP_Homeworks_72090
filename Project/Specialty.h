#pragma once
#include "Discipline.h" 
#include "Vector.h"
class Specialty
{
private:
	String name;
	Vector<Discipline> list;
public:
	Specialty() : name("None") {};
	Specialty(const String _name) : name(_name) {};

	const String getName() const
	{
		return this->name;
	}

	size_t getListSize() const
	{
		return this->list.getSize();
	}

	bool isDisciplineInList(const Discipline& discipline) const
	{
		for (size_t i = 0; i < this->list.getSize(); i++)
			if (discipline == this->list[i])
				return true;

		return false;
	}

	void addDiscipline(const Discipline& discipline)
	{
		for (size_t i = 0; i < this->list.getSize(); i++)
			if (this->list[i] == discipline)
				return;

		this->list.add(discipline);
	}

	void print() const
	{
		std::cout << "Specialty: " << this->name << std::endl;
		std::cout << "Disciplines: " << this->list.getSize() << std::endl << std::endl;
		this->list.print();
	}

	Specialty& operator=(const Specialty& other)
	{
		if (this != &other)
		{
			this->name = other.name;
			this->list = other.list;
		}
		return *this;
	}

	bool operator==(const Specialty& other) const
	{
		if (this == &other)
			return true;

		if (this->name == other.name)
			return true;

		return false;
	}

	friend std::ostream& operator<<(std::ostream& out, const Specialty& spec)
	{
		out << spec.name << std::endl;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, const Specialty& spec)
	{
		in >> spec.name;
		return in;
	}
};