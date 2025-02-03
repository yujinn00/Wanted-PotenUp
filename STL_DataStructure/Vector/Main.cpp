#include <iostream>
#include <vector>

int main()
{
	// 벡터 변수 선언
	std::vector<int> vector;

	// 비었는지 확인
	//if (vector.size() == 0)	// 선호 X
	if (vector.empty())			// 선호 O
	{
		std::cout << "벡터가 비었습니다.\n";
	}

	// 자료 삽입
	for (int ix = 0; ix < 1000; ++ix)
	{
		//vector.push_back(ix + 1);		// 선호 X
		vector.emplace_back(ix + 1);	// 선호 O
	}

	// 요소 삭제 => end() 함수는 마지막 요소 다음 위치를 가리킴
	for (auto it = vector.begin(); it != vector.end();)
	{
		it = vector.erase(it);
		if (it != vector.end())
		{
			++it;
		}
	}

	//size_t size = vector.size();
	for (int ix = 0; ix < (int)vector.size(); ++ix)
	{
		// 랜덤 접근
		//std::cout << vector.at(ix) << " ";	// 선호 X
		std::cout << vector[ix] << " ";			// 선호 O
	}

	// 모두 소거 => 내부 저장 변수가 포인터인 경우에는 delete를 해야 함
	vector.clear();

	// 비었는지 확인
	if (vector.empty())
	{
		std::cout << "벡터가 비었습니다.\n";
	}

	/*
	데이터를 지우고 다시 채울 예정이면 → resize(0)
	대량 데이터 삽입 전에 미리 메모리 확보하면 → reserve(n)
	메모리를 최적화하고 싶다면 → shrink_to_fit()
	*/

	// 크기 조정
	vector.resize(0);

	// 공간 확보 => 재할당 방지 / 공간 최적화
	vector.reserve(0);

	// 크기 줄일 때 사용 => capacity를 줄임
	vector.shrink_to_fit();

	return 0;
}
