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
	String& operator=(const char* _name);
	bool operator==(const String& other) const;
	bool operator==(const char* _name) const;
	bool operator!=(const String& other) const;
	bool operator!=(const char* _name) const;
	char operator[](size_t index) const;
	String& operator+=(char element);

	friend std::ostream& operator<<(std::ostream& out, const String& str)
	{
		out << str.name;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, String& str)
	{
		char symbol = ' ';
		while (symbol != '\n')
		{
			symbol = in.get();
			str += symbol;
		}
		str.name[str.getLength() - 1] = '\0';
		return in;
	}
};