#pragma once
#include"Specialty.h"
class Student
{
private:
	String name;
	size_t facultyNumber;
	size_t course;
	Specialty specialty;
	size_t group;
	String status;
	List<Discipline> list;
public:
	Student();
	void addMark(const Discipline& discipline, double mark);
	void takeUpDiscipline(const Discipline& discipline);
	void protocol() const;
	void marksCheck() const;
	double avarage();
};