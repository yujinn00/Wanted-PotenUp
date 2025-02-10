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
		std::cout << "��    ��: " << name << "\n"
			<< "��ȭ��ȣ: " << phone << "\n"
			<< "��    ��: " << address << "\n"
			<< "��    ��: " << position << "\n";
	}

private:
	std::string name;
	std::string phone;
	std::string address;
	std::string position;
};
