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
	Vector<Discipline> list;
public:
	Student();
	double avarage();
	void printList();
	bool passedAllExams();
	const String getName() const;
	size_t getFacultyNumber() const;//polzvame
	size_t getCourse() const;//polzvame
	const String getSpecialty() const;
	size_t getGroup() const;
	const String getStatus() const;

	void enroll(size_t _facultyNumber, const Specialty& _specialty, size_t _group, const String& _name);
	void advance();
	void change();
	void graduate();
	void interrupt();
	void resume();
	void print();
	void takeUpDiscipline(const Discipline& discipline);
	void addMark(const Discipline& discipline, double mark);
	void examsInfo();
	void protocol(const Discipline& discipline);
};