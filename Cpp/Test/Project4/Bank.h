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
	
	void SaveFile(const char* file) const;
	void LoadFile(const char* file);

private:
	Account* account[100];

	int count;
};
