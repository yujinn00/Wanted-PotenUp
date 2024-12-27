#include <iostream>
#include "Log.h"

// ��ũ��
//#define Square(x) ((x) * (x))

// �ζ���
//inline int Square(int x) {
//	return x * x;
//}

// ��ũ�� �ζ��� ������
#define FORCEINLINE __forceinline
FORCEINLINE int Square(int x) {
	return x * x;
}

int main() {
	int a = 5;
	int& ref = a;
	ref = 10;

	std::cout << Square(10) << "\n";

	std::cin.get();
}