#include "Bank.h"
#include "Account.h"
#include "CreditAccount.h"
#include "DonationAccount.h"

#include <iostream>

Bank::Bank()
	: count(0)
{
	for (int i = 0; i < 100; ++i)
	{
		account[i] = nullptr;
	}
}

Bank::~Bank()
{
	for (int i = 0; i < 100; ++i)
	{
		if (account[i] != nullptr)
		{
			delete account[i];
			account[i] = nullptr;
		}
	}
}

void Bank::CreateAccount(int id, const char* name, char option)
{
	if (count > 100)
	{
		std::cout << "계좌를 더 이상 개설할 수 없습니다.\n\n";
		return;
	}

	if (id < 0 || id >= 100)
	{
		std::cout << "계좌 번호는 0에서 99 사이의 값이어야 합니다.\n\n";
		return;
	}

	for (int i = 0; i < 100; ++i)
	{
		if (account[i] != nullptr && account[i]->GetId() == id)
		{
			std::cout << "중복된 계좌 번호입니다.\n\n";
			return;
		}
	}

	switch (option)
	{
	case '1':
		account[id] = new Account(id, name, 0);
		std::cout << "\n";
		break;

	case '2':
		account[id] = new CreditAccount(id, name, 0);
		std::cout << "\n";
		break;

	case '3':
		account[id] = new DonationAccount(id, name, 0, 0);
		std::cout << "\n";
		break;

	default:
		system("cls");
		std::cout << "유효하지 않은 값을 입력하셨습니다.\n";
		return;
	}
}

void Bank::Deposit(int id, int money)
{
	bool isAccount = false;

	for (int i = 0; i < 100; ++i)
	{
		if (account[i] != nullptr && account[i]->GetId() == id)
		{
			isAccount = true;
		}
	}

	if (!isAccount)
	{
		std::cout << "존재하지 않는 계좌 번호입니다.\n\n";
		return;
	}

	if (money > 0)
	{
		for (int i = 0; i < 100; ++i)
		{
			if (account[i] != nullptr && account[i]->GetId() == id)
			{
				account[i]->SetBalance(money, '+');
			}
		}
	}
	else
	{
		std::cout << "유효하지 않은 금액입니다.\n\n";
		return;
	}
	
	std::cout << "\n";
}

void Bank::Withdraw(int id, int money)
{
	bool isAccount = false;

	for (int i = 0; i < 100; ++i)
	{
		if (account[i] != nullptr && account[i]->GetId() == id)
		{
			isAccount = true;
		}
	}

	if (!isAccount)
	{
		std::cout << "존재하지 않는 계좌 번호입니다.\n\n";
		return;
	}

	if (money > 0)
	{
		for (int i = 0; i < 100; ++i)
		{
			if (account[i] != nullptr && account[i]->GetId() == id)
			{
				if (account[i]->GetBalance() < money)
				{
					std::cout << "잔액이 부족합니다.\n\n";
					return;
				}

				account[i]->SetBalance(money, '-');
			}
		}
	}
	else
	{
		std::cout << "유효하지 않은 금액입니다.\n\n";
		return;
	}

	std::cout << "\n";
}

void Bank::Inquire() const
{
	for (int i = 0; i < 100; ++i)
	{
		if (account[i])
		{
			std::cout << "계좌 번호: " << account[i]->GetId() << "\n";
			std::cout << "이     름: " << account[i]->GetName() << "\n";
			std::cout << "잔     액: " << account[i]->GetBalance() << "\n";

			if (account[i]->GetDonation() > 0)
			{
				std::cout << "기부 금액: " << account[i]->GetDonation() << "\n";
			}

			std::cout << "\n";
		}
	}
}
