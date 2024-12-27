#include "String.h"

int main()
{
	String string("RonnieJ");

	std::cout << string << "\n";

	string = "Test String."; // 12자
	std::cout << string << "\n";
	std::cout << string.Length() << "\n"; // 널 문자 빼고 12자 잘 출력됨

	auto result = string == "RonnieJ" ? "True" : "False";
	std::cout << result << "\n";
	std::cout << ((string != "RonnieJ") ? "True" : "False") << "\n";

	return 0;
}