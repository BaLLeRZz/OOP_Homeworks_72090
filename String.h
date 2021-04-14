#pragma once
#include<iostream>
#include<cstring>
class String
{
private:
	char* name;
	void copy(const String& other);
	void erase();
public:
	String();
	String(const char* _name);
	String(const String& other);
	String& operator=(const String& other);
	~String();
	friend std::ostream& operator<<(std::ostream& out, const String& str)
	{
		out << str.name;
		return out;
	}
};