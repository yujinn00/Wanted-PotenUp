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
		std::cout << "���¸� �� �̻� ������ �� �����ϴ�.\n\n";
		return;
	}

	if (id < 0 || id >= 100)
	{
		std::cout << "���� ��ȣ�� 0���� 99 ������ ���̾�� �մϴ�.\n\n";
		return;
	}

	for (int i = 0; i < 100; ++i)
	{
		if (account[i] != nullptr && account[i]->GetId() == id)
		{
			std::cout << "�ߺ��� ���� ��ȣ�Դϴ�.\n\n";
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
		std::cout << "��ȿ���� ���� ���� �Է��ϼ̽��ϴ�.\n";
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
		std::cout << "�������� �ʴ� ���� ��ȣ�Դϴ�.\n\n";
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
		std::cout << "��ȿ���� ���� �ݾ��Դϴ�.\n\n";
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
		std::cout << "�������� �ʴ� ���� ��ȣ�Դϴ�.\n\n";
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
					std::cout << "�ܾ��� �����մϴ�.\n\n";
					return;
				}

				account[i]->SetBalance(money, '-');
			}
		}
	}
	else
	{
		std::cout << "��ȿ���� ���� �ݾ��Դϴ�.\n\n";
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
			std::cout << "���� ��ȣ: " << account[i]->GetId() << "\n";
			std::cout << "��     ��: " << account[i]->GetName() << "\n";
			std::cout << "��     ��: " << account[i]->GetBalance() << "\n";

			if (account[i]->GetDonation() > 0)
			{
				std::cout << "��� �ݾ�: " << account[i]->GetDonation() << "\n";
			}

			std::cout << "\n";
		}
	}
}
