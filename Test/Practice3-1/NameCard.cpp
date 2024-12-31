#include "NameCard.h"

NameCard::NameCard(const char* name, const char* phone, const char* email, const char* job)
{
	const char* card[4] = { name, phone, email, job };

	for (int i = 0; i < 4; ++i)
	{
		size_t len = strlen(card[i]) + 1;
		this->card[i] = new char[len];
		strcpy_s(this->card[i], len, card[i]);
	}
}

NameCard::NameCard(const NameCard& nameCard)
{
	for (int i = 0; i < 4; ++i)
	{
		size_t len = strlen(nameCard.card[i]) + 1;
		this->card[i] = new char[len];
		strcpy_s(this->card[i], len, nameCard.card[i]);
	}
}

NameCard::~NameCard()
{
	for (int i = 0; i < 4; ++i)
	{
		delete[] card[i];
	}
}

void NameCard::ShowData() const
{
	std::cout << "��    ��: " << card[0] << "\n";
	std::cout << "��ȭ��ȣ: " << card[1] << "\n";
	std::cout << "�� �� ��: " << card[2] << "\n";
	std::cout << "��    ��: " << card[3] << "\n";
}
