#include "String.h"

int main()
{
	String string("RonnieJ");

	std::cout << string << "\n";

	string = "Test String."; // 12��
	std::cout << string << "\n";
	std::cout << string.Length() << "\n"; // �� ���� ���� 12�� �� ��µ�

	auto result = string == "RonnieJ" ? "True" : "False";
	std::cout << result << "\n";
	std::cout << ((string != "RonnieJ") ? "True" : "False") << "\n";

	return 0;
}