#include "Student.h"

Student::Student() : name("Empty"), facultyNumber(0), course(0), group(0), status("None") {}

void Student::addMark(const Discipline& discipline, double mark)
{
	
}

void Student::takeUpDiscipline(const Discipline& discipline)
{
	this->list.add(discipline);
}


void Student::protocol() const
{
	std::cout << "Student: " << this->name << std::endl;
	std::cout << "Faculty number: " << this->facultyNumber << std::endl;
	std::cout << "Course: " << this->course << std::endl;
	std::cout << "Specialty: " << this->specialty.getName() << std::endl;
	std::cout << "Group: " << this->group << std::endl;
	std::cout << "Status: " << this->status << std::endl;
	//std::cout << "Avarage: " << avarage() << std::endl;
}

//double Student::avarage()
//{
//	double sum = 0;
//	
//}
