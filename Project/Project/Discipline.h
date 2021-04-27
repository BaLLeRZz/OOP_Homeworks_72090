#pragma once
#include "String.h"
#include <cstring>
class Discipline
{
private:
	String name;
	String type;
	size_t course;
	double mark;
public:
	Discipline() : name("Empty"), type("None"), course(0), mark(0) {};
	Discipline(const String& _name, const String& _type, size_t _course) : name(_name), type(_type), course(_course) {};
	void setMark(double _mark)
	{
		this->mark = _mark;
	}
	const String getName() const
	{
		return this->name;
	}
	double getMark() const
	{
		return this->mark;
	}
	friend std::ostream& operator<<(std::ostream& out, const Discipline& disc)
	{
		out << "Discipline: " << disc.name << std::endl;
		out << "Type: " << disc.type << std::endl;
		out << "Course: " << disc.course << std::endl;
		return out;
	}
};