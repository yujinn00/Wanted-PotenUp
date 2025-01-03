#include "NameCard.h"

int main()
{
	NameCard* cards[3];

	for (int i = 0; i < 3; ++i)
	{
		char name[100],phone[100], email[100], job[100];

		std::cin.getline(name, 100);
		std::cin.getline(phone, 100);
		std::cin.getline(email, 100);
		std::cin.getline(job, 100);
		
		cards[i] = new NameCard(name, phone, email, job);
	}

	for (int i = 0; i < 3; ++i)
	{
		cards[i]->ShowData();
	}

	for (int i = 0; i < 3; ++i)
	{
		delete cards[i];
	}
}
