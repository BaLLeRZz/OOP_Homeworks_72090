#include "String.h"

void String::copy(const String& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
}

void String::erase()
{
	delete[] this->name;
}

String::String()
{
	this->name = new char[1];
	this->name[0] = '\0';
}

String::String(const char* _name)
{
	this->name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name) + 1, _name);
}

String::String(const String& other)
{
	this->copy(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

String::~String()
{
	this->erase();
}

size_t String::getLength() const
{
	return strlen(this->name);
}

bool String::operator==(const String& other) const
{
	if(this == &other)
	   return true;

	if (strlen(this->name) != strlen(other.name))
		return false;

	for (size_t i = 0; i < strlen(this->name); i++)
		if (this->name[i] != other.name[i])
			return false;

	return true;
}

bool String::operator!=(const String& other) const
{
	if (this == &other)
		return false;

	if (strlen(this->name) != strlen(other.name))
		return true;

	for (size_t i = 0; i < strlen(this->name); i++)
		if (this->name[i] != other.name[i])
			return true;

	return false;
}

char String::operator[](size_t index) const
{
	if(index >= strlen(this->name))
	   return 0;

	return this->name[index];
}
