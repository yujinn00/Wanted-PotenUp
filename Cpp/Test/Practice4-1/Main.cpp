#include "Student.h"

int main()
{
	setlocale(LC_ALL, "");

	Student Jang1 = Student(20, L"Jang Se Yun", L"Computer Science");
	Jang1.ShowData();

	Student Jang2 = Jang1;
	Jang2.ShowData();

	return 0;
}
