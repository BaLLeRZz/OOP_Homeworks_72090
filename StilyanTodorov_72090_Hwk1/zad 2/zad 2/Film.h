#pragma once
#include<iostream>
#include<cstring>
class Film
{
private:
	char* nameFilm;
	char* nameProducer;
	int awards;
	void copy(const Film& other_film);
	void erase();
public:
	Film();
	Film(const Film& other_film);
	Film& operator=(const Film& other_film);
	~Film();

	void setNameFilm(const char* _nameFilm);
	void setNameProducer(const char* _nameProducer);
	void setAwards(double _awards);

	const char* getNameFilm() const;
	const char* getNameProducer() const;
	int getAwards() const;

	void print() const;
};