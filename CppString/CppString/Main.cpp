#include <iostream>

int main() {
	// ���� �Ҵ�
	const char* testString = "Yujin";
	char charArray[] = "Hello";

	// ���� �Ҵ�
	size_t length = strlen("Ronnie") + 1;
	char* name = new char[length];
	strcpy_s(name, length, "Ronnie");

	std::cout << testString << "\n";
	std::cout << charArray << "\n";
	std::cout << name << "\n";

	delete[] name;

	return 0;
}