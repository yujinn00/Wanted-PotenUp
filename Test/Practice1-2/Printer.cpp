#include "Printer.h"

Printer::Printer()
	: str(nullptr)
{
}

Printer::~Printer()
{
	delete[] str;
}

void Printer::SetString(const char* inp)
{
	if (str) {
		delete[] str;
	}

	size_t len = strlen(inp) + 1;
	str = new char[len];
	strcpy_s(str, len, inp);
}

void Printer::ShowString()
{
	if (str)
	{
		std::cout << str << "\n";
	}
	else
	{
		std::cout << "Can't show the string value" << "\n";
	}
}
