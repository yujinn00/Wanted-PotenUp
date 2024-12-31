#pragma once

#include <iostream>

class NameCard
{
public:
	NameCard(const char* name, const char* phone, const char* email, const char* job);
	NameCard(const NameCard& nameCard);
	~NameCard();

	void ShowData() const;

private:
	char* card[4];
};
