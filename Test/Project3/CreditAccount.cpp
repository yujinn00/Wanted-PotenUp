#include "CreditAccount.h"

CreditAccount::CreditAccount(int id, const char* name, int balance)
	: Account(id, name, balance)
{
}

void CreditAccount::SetBalance(int balance)
{
	this->balance = balance + (balance / 100);
}
