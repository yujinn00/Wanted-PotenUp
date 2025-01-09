#pragma once

#include <iostream>

// 스택 최대 개수
const int maxCount = 100;

// 경험치를 저장하는 스택 클래스
class ExpStack
{
public:
	ExpStack()
	{
		// 배열 0.0f로 초기화
		memset(data, 0.0f, sizeof(float) * maxCount);
	}

	// 스택을 비우는 함수
	void Clear()
	{
		count = 0;
	}

	// 스택에 저장된 요소의 수 반환 함수
	int Count() const
	{
		return count;
	}

	// 스택이 비었는지 확인하는 함수
	bool IsEmpty() const
	{
		return count == 0;
	}

	// 데이터 추가 함수 (Push)
	void Push(float exp)
	{
		// 스택이 가득 찼는지 확인
		if (count == maxCount)
		{
			// 로그
			std::cout << "스택이 가득 차서 데이터 저장에 실패했습니다.\n";
			return;
		}

		// 경험치 저장
		data[count] = exp;

		// 저장된 데이터 수 증가 처리
		++count;
	}

	//// 데이터 삭제 및 반환 함수 (Pop)
	//float Pop()
	//{
	//	// 스택이 비었으면 종료
	//	if (IsEmpty())
	//	{
	//		// 로그
	//		std::cout << "스택이 비어서 데이터 반환에 실패했습니다.\n";
	//		return 0.0f;
	//	}

	//	// 개수를 하나 감소시키고 값을 반환
	//	--count;
	//	return data[count];
	//}

	// 데이터 삭제 및 반환 함수 (Pop)
	bool Pop(float& outValue)
	{
		// 스택이 비었으면 종료
		if (IsEmpty())
		{
			// 로그
			std::cout << "스택이 비어서 데이터 반환에 실패했습니다.\n";
			return false;
		}

		// 개수를 하나 감소시키고 값을 반환
		--count;
		outValue = data[count];
		return true;
	}

private:
	// 스택의 저장소
	float data[maxCount];

	// 스택에 저장된 요소의 수 (top / head)
	int count = 0;
};
