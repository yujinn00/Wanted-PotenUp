#include "CreditAccount.h"

#include <iostream>

CreditAccount::CreditAccount(int id, const char* name, int balance)
	: Account(id, name, balance)
{
}

void CreditAccount::SetBalance(int balance, char option)
{
	if (option == '+')
	{
		this->balance += balance + (balance / 100);
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

const char* CreditAccount::GetType() const
{
	return "CreditAccount";
}
