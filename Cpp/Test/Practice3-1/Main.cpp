#include "NameCard.h"

int main()
{
	NameCard Jang = NameCard("JangSeYun", "010-000-0000", "abd@def.com", "Lecturer");
	NameCard Jang2 = NameCard(Jang);
	Jang2.ShowData();
}
