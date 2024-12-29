#include "Printer.h"

int main()
{
	Printer printer;
	printer.ShowString();

	printer.SetString("Hello C++");
	printer.ShowString();

	printer.SetString("I Want to be a Good Developer");
	printer.ShowString();
}
