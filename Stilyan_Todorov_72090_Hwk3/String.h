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
	bool operator==(const String& other) const;
	char operator[](size_t index) const;
	friend std::ostream& operator<<(std::ostream& out, const String& str)
	{
		out << str.name;
		return out;
	}
	friend std::istream& operator>>(std::istream& in, const String& str)
	{
		for(size_t i = 0; i < strlen(str.name); i++)
		    in >> str.name[i];
		return in;
	}
};