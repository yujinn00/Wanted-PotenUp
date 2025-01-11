#pragma once

#include "Account.h"

class DonationAccount : public Account
{
public:
	DonationAccount(int id, const char* name, int balance, int total);

	void SetBalance(int balance, char option) override;
	int GetDonation() const override;
	const char* GetType() const override;

private:
	int total;
};
