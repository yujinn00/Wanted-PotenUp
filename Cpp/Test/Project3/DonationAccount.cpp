#include "DonationAccount.h"

#include <iostream>

DonationAccount::DonationAccount(int id, const char* name, int balance, int total)
	: Account(id, name, balance), total(0)
{
}

void DonationAccount::SetBalance(int balance, char option)
{
	if (option == '+')
	{
		int donation = balance / 100;
		total += donation;
		this->balance += balance - donation;
	}
	else if (option == '-')
	{
		this->balance -= balance;
	}
	else
	{
		std::cout << "��ȿ���� ���� ���Դϴ�.\n";
	}
}

int DonationAccount::GetDonation() const
{
	return total;
}
