#pragma once

#include<iostream>

class Person
{
public:
	Person(int age, const wchar_t* name);
	~Person();

protected:
	int age;
	wchar_t* name;
};
