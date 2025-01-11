#pragma once

#include <string>

class Account;

class Bank
{
public:
	Bank();
	~Bank();
	
	void CreateAccount(int id, const char* name, char option);
	void Deposit(int id, int money);
	void Withdraw(int id, int money);
	void Inquire() const;
	
	void SaveFile(const std::string& file) const;
	void LoadFile(const std::string& file);

private:
	Account* account[100];

	int count;
};
