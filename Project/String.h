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

	size_t getLength() const;
	bool operator==(const String& other) const;
	bool operator!=(const String& other) const;
	char operator[](size_t index) const;

	friend std::ostream& operator<<(std::ostream& out, const String& str)
	{
		out << str.name;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, const String& str)
	{
		in >> str.name;
		return in;
	}
};