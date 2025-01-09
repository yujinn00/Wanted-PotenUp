#include <iostream>
#include "Stack.h"
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
	// 난수 발생기 설정
	srand((unsigned int)time(nullptr));

	// 스택 객체
	Stack<float> stack;

	if (stack.Push((float)RandomRange(10, 300)))
	{
		std::cout << "첫 번째 게임 종료\n";
	}

	if (stack.Push((float)RandomRange(10, 300)))
	{
		std::cout << "두 번째 게임 종료\n";
	}

	if (stack.Push((float)RandomRange(10, 300)))
	{
		std::cout << "세 번째 게임 종료\n";
	}

	// 출력
	while (!stack.IsEmpty())
	{
		float value;
		if (stack.Pop(value))
		{
			std::cout << "현재 경험치: " << value << "\n";
		}
	}
}
