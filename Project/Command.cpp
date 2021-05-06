#include "Command.h"

Command::Command()
{
	this->iterator = 0;

	Specialty IS("Information Systems"), SI("Software Engineering"), MATH("Mathematics");

	Discipline DS("Discrete Structures", "Compulsory", 1);
	Discipline Algebra("Algebra", "Compulsory", 2);
	Discipline UP("Introduction to Programming", "Compulsory", 1);
	Discipline DIS("Differential and Integral Calculation", "Compulsory", 3);
	Discipline Geometry("Geometry", "Compulsory", 3);
	Discipline OOP("Object Orientated Programming", "Compulsory", 2);
	Discipline FP("Functional Programming", "Compulsory", 1);
	Discipline OIS("Basics of IS", "Eligible", 1);
	Discipline Pract("Practice", "Eligible", 1);
	Discipline AE("English", "Eligible", 2);
	Discipline DM("Discrete Math", "Compulsory", 4);
	Discipline IT("Information Technology", "Compulsory", 2);
	Discipline SD("Structures of Data", "Compulsory", 3);
	Discipline HC("Hacking Courses", "Eligible", 4);
	Discipline MT("Mind Training", "Eligible", 4);

	this->disciplines.add(DS);
	this->disciplines.add(Algebra);
	this->disciplines.add(UP);
	this->disciplines.add(DIS);
	this->disciplines.add(Geometry);
	this->disciplines.add(OOP);
	this->disciplines.add(FP);
	this->disciplines.add(OIS);
	this->disciplines.add(Pract);
	this->disciplines.add(AE);
	this->disciplines.add(DM);
	this->disciplines.add(IT);
	this->disciplines.add(SD);
	this->disciplines.add(HC);
	this->disciplines.add(MT);

	IS.addDiscipline(UP);
	IS.addDiscipline(OOP);
	IS.addDiscipline(FP);
	IS.addDiscipline(Pract);
	IS.addDiscipline(SD);

	SI.addDiscipline(OIS);
	SI.addDiscipline(AE);
	SI.addDiscipline(IT);
	SI.addDiscipline(HC);
	SI.addDiscipline(MT);

	MATH.addDiscipline(DS);
	MATH.addDiscipline(Algebra);
	MATH.addDiscipline(DIS);
	MATH.addDiscipline(Geometry);
	MATH.addDiscipline(DM);

	this->specialties.add(IS);
	this->specialties.add(SI);
	this->specialties.add(MATH);
}

void Command::commandList() const
{
	std::cout << std::endl << std::endl << "--------------------------------------------------------------------------------------------COMMANDS LIST--------------------------------------------------------------------------------------------" << std::endl << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    - Enroll -> Registers a Student in 1 Course." << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    - Advance -> Transfers a Student in a next Course." << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    - Graduate -> Marks a Student as Graduated." << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    - Interrupt -> Marks a Student as Dropout." << std::endl << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    - Resume -> Marks a Student as Registered." << std::endl << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    - Print -> Prints information about a Student." << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    - PrintAll -> Prints information about all Students." << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    - EnrollIn -> Registers a Student in a Discipline." << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    - AddGrade -> Adds a grade to a Discipline for a Student." << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    - Protocol -> Prints information about all Students, Registered in a Discipline." << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    - Report -> Academic information about all Exams of a Student." << std::endl;
	std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
}

void Command::chooseCommand()
{
	std::cout << "Command: ";
	std::cin >> this->command;

	if (command == "Enroll")
		this->iterator = 1;
	else
		if (command == "Advance")
			this->iterator = 2;
		else
			if (command == "Graduate")
				this->iterator = 3;
			else
				if (command == "Interrupt")
					this->iterator = 4;
				else
					if (command == "Resume")
						this->iterator = 5;
					else
						if (command == "Print")
							this->iterator = 6;
						else
							if (command == "PrintAll")
								this->iterator = 7;
							else
								if (command == "EnrollIn")
									this->iterator = 8;
								else
									if (command == "AddGrade")
										this->iterator = 9;
									else
										if (command == "Protocol")
											this->iterator = 10;
										else
											if (command == "Advance")
												this->iterator = 11;
}

void Command::executeCommand()
{
	String name, status;
	size_t facultyNumber, course, group;
	Specialty specialty;
	Discipline discipline;
	bool flag = false;
	switch (this->iterator)
	{
	case 1:
		std::cout << "Name: ";
		std::cin >> name;

		std::cout << "Faculty Number: ";
		std::cin >> facultyNumber;

		std::cout << "Specialty: ";
		std::cin >> specialty;

		if (!this->checkSpec(specialty))
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}

		std::cout << "Group: ";
		std::cin >> group;

		if (group < 1 || group > 5)
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}

		this->enroll(facultyNumber, specialty, group, name);
		break;
	case 2:
		std::cout << "Faculty Number: ";
		std::cin >> facultyNumber;

		if (!this->checkFn(facultyNumber))
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}

		this->advance(facultyNumber);
		break;
	case 3:
		std::cout << "Faculty Number: ";
		std::cin >> facultyNumber;

		if (!this->checkFn(facultyNumber))
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}

		this->graduate(facultyNumber);
		break;
	case 4:
		std::cout << "Faculty Number: ";
		std::cin >> facultyNumber;

		if (!this->checkFn(facultyNumber))
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}

		this->interrupt(facultyNumber);
		break;
	case 5:
		std::cout << "Faculty Number: ";
		std::cin >> facultyNumber;

		if (!this->checkFn(facultyNumber))
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}

		this->resume(facultyNumber);
		break;
	case 6:
		std::cout << "Faculty Number: ";
		std::cin >> facultyNumber;

		if (this->checkFn(facultyNumber))
			this->print(facultyNumber);
		else
			std::cout << "Invalid Input!" << std::endl;
		break;
	case 7:
		std::cout << "Specialty: ";
		std::cin >> specialty;

		if (!this->checkSpec(specialty))
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}

		std::cout << "Course: ";
		std::cin >> course;

		if (course < 1 || course > 5)
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}

		this->printAll(specialty, course);
		break;
	case 8:
		std::cout << "Faculty Number: ";
		std::cin >> facultyNumber;

		if (!this->checkFn(facultyNumber))
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}
		
		std::cout << "Discipline: ";
		std::cin >> discipline;

		if (!this->checkDisc(discipline))
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}

		for (size_t i = 0; i < this->students.getSize(); i++)
		{
			if (facultyNumber == this->students[i].getFacultyNumber())
			{
				specialty = this->students[i].getSpecialty();
				if (!specialty.isDisciplineInList(discipline))
				{
					std::cout << "Invlalid Input!" << std::endl;
					flag = false;
					break;
				}
			}
		}

		if (flag)
		    this->enrollIn(facultyNumber, discipline);
		break;
	case 9:
		std::cout << "Faculty Number: ";
		std::cin >> facultyNumber;

		if (!this->checkFn(facultyNumber))
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}
		
		std::cout << "Discipline: ";
		std::cin >> discipline;

		if (!this->checkDisc(discipline))
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}

		size_t grade;
		std::cout << "Grade: ";
		std::cin >> grade;

		if (grade < 2 || grade > 6)
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}

		this->addGrade(facultyNumber, discipline, grade);
		break;
	case 10:
		std::cout << "Discipline: ";
		std::cin >> discipline;

		if (!this->checkDisc(discipline))
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}

		this->protocol(discipline);
		break;
	case 11:
		std::cout << "Faculty Number: ";
		std::cin >> facultyNumber;

		if (!this->checkFn(facultyNumber))
		{
			std::cout << "Invalid Input!" << std::endl;
			break;
		}
        
		this->report(facultyNumber);
		break;
	default:
		std::cout << "Invalid Command!" << std::endl;
		break;
	}
}

bool Command::checkFn(size_t facultyNumber)
{
	for (size_t i = 0; i < this->students.getSize(); i++)
		if (facultyNumber == this->students[i].getFacultyNumber())
			return true;
	
	return false;
	
}

bool Command::checkSpec(Specialty specialty)
{
	for (size_t i = 0; i < this->specialties.getSize(); i++)
		if (specialty == this->specialties[i])
			return true;

	return false;
}

bool Command::checkDisc(const Discipline& discipline)
{
	for (size_t i = 0; i < this->disciplines.getSize(); i++)
		if (discipline == this->disciplines[i])
			return true;

	return false;
}

void Command::enroll(size_t facultyNumber, const Specialty& specialty, size_t group, const String name)
{
	for (size_t i = 0; i < this->students.getSize(); i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
			return;

	Student st;
	st.enroll(facultyNumber, specialty, group, name);
	this->students.add(st);
}

void Command::advance(size_t facultyNumber)
{
	for(size_t i = 0; i < this->students.getSize(); i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			this->students[i].advance();
			return;
		}
}

void Command::graduate(size_t facultyNumber)
{
	for(size_t i = 0; i < this->students.getSize(); i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			this->students[i].graduate();
			return;
		}
}

void Command::interrupt(size_t facultyNumber)
{
	for (size_t i = 0; i < this->students.getSize(); i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			this->students[i].interrupt();
			return;
		}
}

void Command::resume(size_t facultyNumber)
{
	for (size_t i = 0; i < this->students.getSize(); i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			this->students[i].resume();
			return;
		}
}

void Command::print(size_t facultyNumber)
{
	for (size_t i = 0; i < this->students.getSize(); i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			this->students[i].print();
			return;
		}
}

void Command::printAll(const Specialty& specialty, size_t course)
{
	for (size_t i = 0; i < this->students.getSize(); i++)
		if (this->students[i].getSpecialty() == specialty.getName() && this->students[i].getCourse() == course)
		{
			this->students[i].print();
			std::cout << std::endl << std::endl;
		}
}

void Command::enrollIn(size_t facultyNumber, const Discipline& discipline)
{
	for (size_t i = 0; i < this->students.getSize(); i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
			for (size_t j = 0; j < this->disciplines.getSize(); j++)
				if (this->disciplines[j] == discipline)
				{
					this->students[j].takeUpDiscipline(discipline);
					return;
				}
}

void Command::addGrade(size_t facultyNumber, const Discipline& discipline, double grade)
{
	for (size_t i = 0; i < this->students.getSize(); i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			this->students[i].addMark(discipline, grade);
			return;
		}
}

void Command::protocol(const Discipline& discipline)
{
	bool flag = false;
	for (size_t j = 0; j < this->disciplines.getSize(); j++)
		if (this->disciplines[j] == discipline)
		{
			flag = true;
			break;
		}

	if (flag == false)
		return;

	Student temp;
	for (size_t i = 0; i < this->students.getSize(); i++)
		for (size_t j = i; j < this->students.getSize(); j++)
			if (this->students[i].getFacultyNumber() > this->students[j].getFacultyNumber())
			{
				temp = this->students[i];
				this->students[i] = this->students[j];
				this->students[j] = temp;
			}

	for (size_t i = 0; i < this->students.getSize(); i++)
		this->students[i].protocol(discipline);
}

void Command::report(size_t facultyNumber)
{
	for (size_t i = 0; i < this->students.getSize(); i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			this->students[i].examsInfo();
			return;
		}
}
