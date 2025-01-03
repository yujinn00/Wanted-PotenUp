#include "Person.h"

Person::Person(int age, const wchar_t* name)
	: age(age)
{
	size_t len = wcslen(name) + 1;
	this->name = new wchar_t[len];
	wcscpy_s(this->name, len, name);
}

Person::~Person()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}
