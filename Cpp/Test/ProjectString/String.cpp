#include "String.h"

String::String()
	: str(nullptr)
{
}

String::String(const char* str)
{
	size_t len = strlen(str) + 1;
	this->str = new char[len];
	strcpy_s(this->str, len, str);
}

String::String(const String& other)
{
	size_t len = strlen(other.str) + 1;
	this->str = new char[len];
	strcpy_s(this->str, len, other.str);
}

String::~String()
{
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		delete[] this->str;
		size_t len = strlen(other.str) + 1;
		this->str = new char[len];
		strcpy_s(this->str, len, other.str);
	}

	return *this;
}

String String::operator+(const String& other)
{
	size_t len1 = strlen(this->str);
	size_t len2 = strlen(other.str);

	size_t newLen = len1 + len2 + 1;
	char* newStr = new char[newLen];

	strcpy_s(newStr, newLen, this->str);
	strcat_s(newStr, newLen, other.str);

	return String(newStr);
}

String String::operator+=(const String& other)
{
	//*this = *this + other;
	//return *this
	size_t len1 = strlen(this->str);
	size_t len2 = strlen(other.str);

	size_t newLen = len1 + len2 + 1;
	char* newStr = new char[newLen];

	strcpy_s(newStr, newLen, this->str);
	strcat_s(newStr, newLen, other.str);

	delete[] this->str;
	this->str = newStr;

	return *this;
}

bool String::operator==(const String& other)
{
	return strcmp(this->str, other.str) == 0;
}

std::ostream& operator<<(std::ostream& os, const String& other)
{
	os << other.str;
	return os;
}

std::istream& operator>>(std::istream& is, const String& other)
{
	is >> other.str;
	return is;
}
