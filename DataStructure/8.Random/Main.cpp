#include <iostream>
#include <stdlib.h>
#include <time.h>

// 최솟값과 최댓값 사이의 랜덤을 반환하는 함수
int RandomRange(int min, int max)
{
	// 차이
	int diff = (max - min) + 1;

	return ((rand() * diff) / (RAND_MAX + 1)) + min;
}

int main()
{
	// 시드 설정
	srand(static_cast<unsigned int>(time(nullptr)));

	std::cout << "Random Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Random Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Random Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Random Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Random Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Random Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Random Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Random Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Random Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Random Number: " << RandomRange(3, 10) << "\n";
}
