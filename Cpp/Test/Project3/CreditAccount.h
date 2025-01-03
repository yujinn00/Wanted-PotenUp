#pragma once

#include "Account.h"

class CreditAccount : public Account
{
public:
	CreditAccount(int id, const char* name, int balance);

	void SetBalance(int balance, char option) override;
};
