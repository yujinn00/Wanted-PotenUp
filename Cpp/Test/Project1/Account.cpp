#include "Account.h"

Account::Account(int id, const char* name, int balance)
	: id(id), balance(balance)
{
	size_t len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}

Account::~Account()
{
	if (name != nullptr) {
		delete[] name;
		name = nullptr;
	}
}

int Account::GetId() const
{
	return id;
}

const char* Account::GetName() const
{
	return name;
}

void Account::SetBalance(int balance)
{
	this->balance = balance;
}

int Account::GetBalance() const
{
	return balance;
}
