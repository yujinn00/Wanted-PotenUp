#include <iostream>

int main() {
	// 정적 할당
	const char* testString = "Yujin";
	char charArray[] = "Hello";

	// 동적 할당
	size_t length = strlen("Ronnie") + 1;
	char* name = new char[length];
	strcpy_s(name, length, "Ronnie");

	std::cout << testString << "\n";
	std::cout << charArray << "\n";
	std::cout << name << "\n";

	delete[] name;

	return 0;
}