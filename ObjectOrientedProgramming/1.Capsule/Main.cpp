#include "Shapes.h"
#include "Time.h"
#include "NameCard.h"

#include <iostream>

int main()
{
	//// Problem 1
	//Rectangle rectangle = Rectangle(3.f, 4.f); // ����, ���� ���� ����
	//std::cout << "����: " << rectangle.GetArea() << "\n";
	//std::cout << "�ѷ�: " << rectangle.GetSize() << "\n";

	//Circle circle = Circle(5.f); // ���� ������ ����
	//std::cout << "����: " << circle.GetArea() << "\n";
	//std::cout << "�ѷ�: " << circle.GetSize() << "\n";



	//// Problem 2
	//Time time1 = Time(10);            // 10�� 0�� 0��
	//Time time2 = Time(10, 20);        // 10�� 20�� 0��
	//Time time3 = Time(10, 20, 30);    // 10�� 20�� 30��

	//time2.ShowTime();
	//time2.ShowTimeInSeconds();



	// Problem 3
	NameCard jang = NameCard("Jang Se Yun", "010-1111-1111", "�����...", "Freelancer");
	jang.ShowData();
}
