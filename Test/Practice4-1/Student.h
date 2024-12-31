#pragma once

#include "Person.h"

class Student : public Person
{
public:
	Student(int age, const wchar_t* name, const wchar_t* major);
	Student(const Student& student);
	~Student();
	
	void ShowData() const;

private:
	wchar_t* major;
};
