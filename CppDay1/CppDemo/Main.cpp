#include <iostream>
#include "Log.h"

// 매크로
//#define Square(x) ((x) * (x))

// 인라인
//inline int Square(int x) {
//	return x * x;
//}

// 매크로 인라인 강제성
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