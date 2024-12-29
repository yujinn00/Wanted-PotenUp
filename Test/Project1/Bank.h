#pragma once

class Account;

class Bank
{
public:
	Bank();
	~Bank();
	
	void CreateAccount(int id, const char* name, int balance);
	void Deposit(int id, int money);
	void Withdraw(int id, int money);
	void Inquire() const;

private:
	Account* account[100];

	int count;
};
