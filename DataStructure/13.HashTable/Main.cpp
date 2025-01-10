#include <iostream>
#include "HashTable.h"

int main()
{
	// 해시 테이블 객체
	HashTable table;

	table.Add("Park", "Yujin");
	table.Add("Shin", "Jiryeong");
	table.Add("An", "Hongjun");
	table.Add("Shin", "Jiryeong");

	table.Print();

	Pair<std::string, std::string> value;
	if (table.Find("Shin", value))
	{
		std::cout << "키: Shin 항목을 찾았습니다.\n";
	}
	else
	{
		std::cout << "키: Shin 항목을 못 찾았습니다.\n";
	}

	table.Delete("Shin");
	
	std::cout << "===== 삭제 후 출력 =====\n";
	table.Print();
}
