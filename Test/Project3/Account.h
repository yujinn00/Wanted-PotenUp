#pragma once

class Account
{
public:
	Account(int id, const char* name, int balance);
	Account(const Account& account);
	virtual ~Account();

	int GetId() const;
	const char* GetName() const;
	int GetBalance() const;

	virtual void SetBalance(int balance);
	virtual int GetDonation() const;

protected:
	int id;
	char* name;
	int balance;
};
