#pragma once

#include <iostream>

class String
{
public:
	String();
	String(const char* str);
	String(const String& other);
	~String();

	String& operator=(const String& other);
	String operator+(const String& other);
	String operator+=(const String& other);
	bool operator==(const String& other);

	friend std::ostream& operator<<(std::ostream& os, const String& other);
	friend std::istream& operator>>(std::istream& is, const String& other);

private:
	char* str;
};
