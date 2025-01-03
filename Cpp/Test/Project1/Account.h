#pragma once

#include <iostream>

class Account
{
public:
	Account(int id, const char* name, int balance);
	~Account();

	int GetId() const;
	const char* GetName() const;
	void SetBalance(int balance);
	int GetBalance() const;

private:
	int id;
	char* name;
	int balance;
};
