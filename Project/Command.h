#pragma once
#include "Student.h"

class Command
{
private:
	String command;
	size_t iterator;
	Vector<Student> students;
	Vector<Specialty> specialties;
	Vector<Discipline> disciplines;
public:
	Command();
	void commandList() const;
	void chooseCommand();
	void executeCommand();
	bool checkFn(size_t facultyNumber);
	bool checkSpec(Specialty specialty);
	bool checkDisc(const Discipline& discipline);

	void enroll(size_t facultyNumber, const Specialty& specialty, size_t group, const String name);
	void advance(size_t facultyNumber);
	//void change(size_t facultyNumber, option, value);
	void graduate(size_t facultyNumber);
	void interrupt(size_t facultyNumber);
	void resume(size_t facultyNumber);
	void print(size_t facultyNumber);
	void printAll(const Specialty& specialty, size_t course);
	void enrollIn(size_t facultyNumber, const Discipline& discipline);
	void addGrade(size_t facultyNumber, const Discipline& discipline, double grade);
	void protocol(const Discipline& discipline);
	void report(size_t facultyNumber);
};