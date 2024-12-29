#pragma once

#include <iostream>

class Printer
{
public:
	Printer();
	~Printer();
	void SetString(const char* inp);
	void ShowString();

private:
	char* str;
};
