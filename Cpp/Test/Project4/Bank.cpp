#include "Bank.h"
#include "Account.h"
#include "CreditAccount.h"
#include "DonationAccount.h"

#include <iostream>
#include <fstream>

Bank::Bank()
	: count(0)
{
	for (int i = 0; i < 100; ++i)
	{
		account[i] = nullptr;
	}

	LoadFile("data.txt");
}

Bank::~Bank()
{
	SaveFile("data.txt");

	for (int i = 0; i < 100; ++i)
	{
		if (account[i] != nullptr)
		{
			delete account[i];
			account[i] = nullptr;
		}
	}
}

void Bank::SaveFile(const std::string& file) const
{
	std::ofstream fout(file, std::ios::out);

	if (!fout.is_open())
	{
		std::cerr << "���� ���� ����\n";
		return;
	}

	for (int i = 0; i < 100; ++i)
	{
		if (account[i])
		{
			fout << account[i]->GetType() << " | ID: " << account[i]->GetId() << " | Name: " << account[i]->GetName() << " | Balance: " << account[i]->GetBalance() << " | Donation: " << account[i]->GetDonation() << "\n";
		}
	}

	fout.close();
}

void Bank::LoadFile(const std::string& file)
{
	std::ifstream fin(file, std::ios::in);

	if (!fin.is_open())
	{
		std::cout << "���� ���� ����\n";
		return;
	}

	char type[100], name[100], delimiter, label[100];
	int id, balance, donation;
	
	while (fin >> type >> delimiter >> label >> id >> delimiter >> label >> name >> delimiter >> label >> balance >> delimiter >> label >> donation)
	{
		if (strcmp(type, "Account") == 0)
		{
			account[id] = new Account(id, name, balance);
		}
		else if (strcmp(type, "CreditAccount") == 0)
		{
			account[id] = new CreditAccount(id, name, balance);
		}
		else if (strcmp(type, "DonationAccount") == 0)
		{
			account[id] = new DonationAccount(id, name, balance, donation);
		}
		else
		{
			system("cls"); 
			std::cout << "��ȿ���� ���� ���Դϴ�.\n";
			return;
		}
	}

	fin.close();
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
