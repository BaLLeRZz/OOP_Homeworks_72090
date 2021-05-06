#include "Student.h"

Student::Student() : name("Empty"), facultyNumber(0), course(0), group(0), status("None") {};

double Student::avarage()
{
	if (this->status != "Registered")
		return 0;

	if (this->list.getSize() == 0)
		return 0;

	double sum = 0;
	for (size_t i = 0; i < this->list.getSize(); i++)
		sum += this->list[i].getMark();

	return ceil(100 * ((double)sum / this->list.getSize())) / 100;
}

void Student::printList()
{
	if (this->status != "Registered")
		return;
	for (size_t i = 0; i < this->list.getSize(); i++)
		std::cout << this->list[i] << std::endl;
}

bool Student::passedAllExams()
{
	for (size_t i = 0; i < this->list.getSize(); i++)
		if (this->list[i].getMark() < 3)
			return false;

	return true;
}

const String Student::getName() const
{
	return this->name;
}

size_t Student::getFacultyNumber() const
{
	return this->facultyNumber;
}

size_t Student::getCourse() const
{
	return this->course;
}

const String Student::getSpecialty() const
{
	return this->specialty.getName();
}

size_t Student::getGroup() const
{
	return this->group;
}

const String Student::getStatus() const
{
	return this->status;
}

void Student::enroll(size_t _facultyNumber, const Specialty& _specialty, size_t _group, const String& _name)
{
	this->name = _name;
	this->facultyNumber = _facultyNumber;
	this->course = 1;
	this->specialty = _specialty;
	this->group = _group;
	this->status = "Registered";
}

void Student::advance()
{
	if (this->course == 4)
		return;

	this->course++;
}

void Student::graduate()
{
	if (this->course == 4 && this->passedAllExams() && this->status == "Registered")
		this->status = "Graduated";
}

void Student::interrupt()
{
	if (this->status == "Registered")
		this->status = "Dropout";
}

void Student::resume()
{
	if (this->status == "Dropout")
		this->status = "Registered";
}

void Student::print()
{
	if (this->status != "Registered")
		return;

	std::cout << "Student: " << this->name << std::endl;
	std::cout << "Faculty Number: " << this->facultyNumber << std::endl;
	std::cout << "Course: " << this->course << std::endl;
	std::cout << "Specialty: " << this->specialty << std::endl;
	std::cout << "Group: " << this->group << std::endl;
	std::cout << "Status: " << this->status << std::endl;
	std::cout << "Avarage: " << this->avarage() << std::endl;
}

void Student::takeUpDiscipline(const Discipline& discipline)
{
	if (this->status != "Registered")
		return;

	if (this->course != discipline.getCourse())
		return;

	for (size_t i = 0; i < this->list.getSize(); i++)
		if (this->list[i] == discipline)
			return;

	this->list.add(discipline);
}

void Student::addMark(const Discipline& discipline, double mark)
{
	if (this->status != "Registered")
		return;

	if (mark < 2 || mark > 6)
		return;

	for (size_t i = 0; i < this->list.getSize(); i++)
		if (discipline == this->list[i])
		{
			int temp = floor(10 * mark);
			if (temp % 10 >= 5)
			{
				this->list[i].setMark(ceil(mark));
				return;
			}
			else
			{
				this->list[i].setMark(floor(mark));
				return;
			}
		}
}

void Student::examsInfo()
{
	if (this->status != "Registered")
		return;

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "-------------------------------------        " << ">>>Passed exams<<<" << std::endl;
	std::cout << "-------------------------------------        ******************" << std::endl << std::endl;
	for (size_t i = 0; i < this->list.getSize(); i++)
	{
		if (this->list[i].getMark() >= 3)
		{
			std::cout << this->list[i];
			std::cout << "-------------------------------------        " << "|Grade: " << this->list[i].getMark() << std::endl << std::endl;
		}
	}
	std::cout << "-------------------------------------        " << std::endl << std::endl;
	std::cout << "-------------------------------------        " << ">>>Failed exams<<<" << std::endl;
	std::cout << "-------------------------------------        ******************" << std::endl << std::endl;
	for (size_t i = 0; i < this->list.getSize(); i++)
	{
		if (this->list[i].getMark() < 3)
		{
			this->list[i].setMark(2);
			std::cout << this->list[i];
			std::cout << "-------------------------------------        " << "|Grade: " << this->list[i].getMark() << std::endl << std::endl;
		}
	}
	std::cout << "-------------------------------------        " << "Avarage: " << this->avarage() << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void Student::protocol(const Discipline& discipline)
{
	if (this->status != "Registered")
		return;

	for(size_t i = 0; i < this->list.getSize(); i++)
		if (this->list[i] == discipline && this->course == discipline.getCourse())
		{
			this->print();
			return;
		}
	
}
