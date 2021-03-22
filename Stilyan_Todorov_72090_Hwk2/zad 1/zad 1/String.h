#pragma once
#include<iostream>
#include<cstring>
class String
{
private:
	char* infinite;
	size_t size;
	size_t capacity;
	void resize();
	void copy(const String& other);
	void erase();
public:
	String();
	String(const String& other);
	String& operator=(const String& other);
	~String();

	void print();

	void setString(const char* _infinite);

	const char* getInfinite() const;

	void add(char _newElement);
	size_t getLength();
	void insertAt(char _newSymbol, size_t index);
	void removeAt(size_t index);
	void trimStart();
	void trimEnd();
	void trimStartElements(size_t count);
	void trimEndElements(size_t count);

	char* operator+(const String& other);
	String& operator+=(const String& other);
	bool operator==(const String& other);
	bool operator!=(const String& other);
	char operator[](size_t index);
};