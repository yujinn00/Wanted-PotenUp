#pragma once

#include <iostream>
#include <string>

class NameCard
{
public:
	NameCard(const std::string& name, const std::string& phone, const std::string& address, const std::string& position)
		: name(name), phone(phone), address(address), position(position)
	{
	}

	void ShowData()
	{
		std::cout << "이    름: " << name << "\n"
			<< "전화번호: " << phone << "\n"
			<< "주    소: " << address << "\n"
			<< "직    급: " << position << "\n";
	}

private:
	std::string name;
	std::string phone;
	std::string address;
	std::string position;
};
