#include "Film.h"

void Film::copy(const Film& other_film)
{
	this->nameFilm = new char[strlen(other_film.nameFilm) + 1];
	strcpy_s(this->nameFilm, strlen(other_film.nameFilm) + 1, other_film.nameFilm);
	this->nameProducer = new char[strlen(other_film.nameProducer) + 1];
	strcpy_s(this->nameProducer, strlen(other_film.nameProducer) + 1, other_film.nameProducer);
	this->awards = other_film.awards;
}

void Film::erase()
{
	delete[] this->nameFilm;
	delete[] this->nameProducer;
}
Film::Film()
{
	this->nameFilm = new char[6];
	strcpy_s(this->nameFilm, 6, "Empty");
	this->nameProducer = new char[6];
	strcpy_s(this->nameProducer, 6, "Empty");
	this->awards = 0;
}

Film::Film(const Film& other_film)
{
	this->copy(other_film);
}

Film& Film::operator=(const Film& other_film)
{
	if (this != &other_film)
	{
		this->erase();
		this->copy(other_film);
	}
	return *this;
}

Film::~Film()
{
	this->erase();
}

void Film::setNameFilm(const char* _nameFilm)
{
	delete[] this->nameFilm;
	this->nameFilm = new char[strlen(_nameFilm) + 1];
	strcpy_s(this->nameFilm, strlen(_nameFilm) + 1, _nameFilm);
}

void Film::setNameProducer(const char* _nameProducer)
{
	delete[] this->nameProducer;
	this->nameProducer = new char[strlen(_nameProducer) + 1];
	strcpy_s(this->nameProducer, strlen(_nameProducer) + 1, _nameProducer);
}

void Film::setAwards(double _awards)
{
	this->awards = _awards;
}

const char* Film::getNameFilm() const
{
	return this->nameFilm;
}

const char* Film::getNameProducer() const
{
	return this->nameProducer;
}

int Film::getAwards() const
{
	return this->awards;
}

void Film::print() const
{
	std::cout << "Film: " << this->nameFilm << std::endl;
	std::cout << "Producer: " << this->nameProducer << std::endl;
	std::cout << "Awards: " << this->awards << std::endl;
}
