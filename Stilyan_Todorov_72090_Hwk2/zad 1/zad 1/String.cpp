#include "String.h"

void String::resize()
{
	this->capacity *= 2;
	char* biggerString = new char[this->capacity];
	for (size_t i = 0; i < this->size; i++)
		biggerString[i] = this->infinite[i];
	this->erase();
	this->infinite = biggerString;
}

void String::copy(const String& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->infinite = new char[strlen(other.infinite) + 1];
	strcpy_s(this->infinite, strlen(other.infinite) + 1, other.infinite);
}

void String::erase()
{
	delete[] this->infinite;
}

String::String()
{
	this->size = 0;
	this->capacity = 10;
	this->infinite = new char[this->capacity];
	this->infinite[0] = '\0';
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

void String::print()
{
	std::cout << "Your string: " << this->infinite << std::endl;
	std::cout << "Length: " << this->getLength() << std::endl;
}

void String::setString(const char* _infinite)
{
	this->erase();
	this->size = strlen(_infinite);
	this->infinite = new char[this->size + 1];
	strcpy_s(this->infinite, this->size + 1, _infinite);
}

const char* String::getInfinite() const
{
	return this->infinite;
}

void String::add(char _newElement)
{
	if(this->size >= this->capacity)
	   this->resize();
	this->infinite[this->size++] = _newElement;
	this->infinite[this->size++] = '\0';
}

size_t String::getLength()
{
	this->size = strlen(this->infinite);
	int count = 0;
	for (size_t i = 0; i < this->size; i++)
		count++;
	return count;
}

void String::insertAt(char _newSymbol, size_t index)
{
	if (index > this->size)
		return;
	if(this->size >= this->capacity)
	   this->resize();
    for (size_t i = this->size; i > index; i--)
		this->infinite[i] = this->infinite[i - 1];
	this->infinite[index] = _newSymbol;
	this->infinite[++this->size] = '\0';
}

void String::removeAt(size_t index)
{
	if (index > this->size)
		return;
	for (size_t i = index; i < this->size; i++)
		this->infinite[i] = this->infinite[i + 1];
	this->infinite[--this->size] = '\0';
}

void String::trimStart()
{
	this->removeAt(0);
}

void String::trimEnd()
{
	this->removeAt(this->size);
}

void String::trimStartElements(size_t count)
{
	if (count > this->size)
		return;
	for (size_t i = 0; i < count; i++)
		this->trimStart();
}

void String::trimEndElements(size_t count)
{
	if (count > this->size)
		return;
	for (size_t i = 0; i < count; i++)
		this->trimEnd();
}

char* String::operator+(const String& other)
{
	if (this == &other)
		return this->infinite;
	if (this->size >= this->capacity)
		this->resize();
	char* a = new char[this->size + other.size];
	a = this->infinite;
	for (size_t i = 0; i < other.size; i++)
		a[size++] = other.infinite[i];
	return a;
}

String& String::operator+=(const String& other)
{
	if (this == &other)
		return *this;
	if(this->size >= this->capacity)
	   this->resize();
	for (size_t i = 0; i < other.size; i++)
	{
		this->infinite[this->size++] = other.infinite[i];
	}
	this->infinite[this->size] = '\0';
	return *this;
}

bool String::operator==(const String& other)
{
	if (this == &other)
		return true;

	if (this->size != other.size)
		return false;

	for (size_t i = 0; i < this->size; i++)
		if (this->infinite[i] != other.infinite[i])
			return false;
	return true;
}

bool String::operator!=(const String& other)
{
	if (this->size != other.size)
		return true;

	for (size_t i = 0; i < this->size; i++)
		if (this->infinite[i] != other.infinite[i])
			return true;
	return false;
}

char String::operator[](size_t index)
{
	if (index > this->size)
		return 0;

	return this->infinite[index];
}
