#include "DonationAccount.h"

#include <iostream>

DonationAccount::DonationAccount(int id, const char* name, int balance, int total)
	: Account(id, name, balance), total(0)
{
}

void DonationAccount::SetBalance(int balance)
{
	int donation = balance / 100;
	total += donation;
	this->balance = balance - donation;
}

int DonationAccount::GetDonation() const
{
	return total;
}
