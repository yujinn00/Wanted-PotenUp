#include "String.h"

#include <iostream>
#include <string>

int main()
{
	String name = String("Ronnie");
	name += " Jang";

	std::cout << name << "\n";

	if (name == "Ronnie Jang")
	{
		std::cout << "���ڿ� ��ġ\n";
	}
	else
	{
		std::cout << "���ڿ� ����ġ\n";
	}

	String information = "Information ";
	String communication = "Communication ";
	String engineering = "Engineering";
	String major = information + communication + engineering;

	std::cout << major << "\n";

	//String inputString;
	//getline(std::cin, inputString);
	////std::cin.getline >> inputString;

	//std::cout << "�Էµ� ��: " << inputString << "\n";
}
