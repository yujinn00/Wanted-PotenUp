#include <iostream>
#include "Location2D.h"
#include "Queue.h"

// Sleep (밀리 세컨드)
#include <Windows.h>

// 맵 데이터 선언
const size_t MAZE_SIZE = 20;

// 0: 이동 가능
// 1: 이동 불가
// s: 시작 위치
// e: 목표 위치
char map[MAZE_SIZE][MAZE_SIZE] =
{
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
    {'1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
    {'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1'},
    {'s', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
    {'1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', 'e'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

// 이동하려는 위치가 유효한 위치인지 확인
bool IsValidLocation(int row, int column)
{
	// 맵의 범위를 벗어났는지 확인
	// 벗어났으면 오류
	if (row >= MAZE_SIZE || column >= MAZE_SIZE)
	{
		return false;
	}

	if (row < 0 || column < 0)
	{
		return false;
	}

	// 유효성 확인
	// 이동하려는 위치가 0이거나, e라면 이동 가능 반환
	return map[row][column] == '0' || map[row][column] == 'e';
}

// 화면 지우는 함수
void ClearScreen()
{
	// 커서 정보 설정을 위한 구조체 변수
	CONSOLE_CURSOR_INFO info = { };
	info.dwSize = 1;
	info.bVisible = FALSE;

	// 콘솔 제어를 위한 핸들 포인터 가져오기
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// 커서 가리기
	SetConsoleCursorInfo(handle, &info);

	// 화면 좌표 옮기기
	SetConsoleCursorPosition(handle, { 0, 0 });

	// 빈 문자 찍기
	for (int y = 0; y < MAZE_SIZE; ++y)
	{
		for (int x = 0; x < MAZE_SIZE; ++x)
		{
			std::cout << " ";
		}
		
		std::cout << "\n";
	}

	SetConsoleCursorPosition(handle, { 0, 0 });
}

// 맵 출력 함수
void PrintLocation(int row, int column, int delay)
{
	// 딜레이
	Sleep(delay);

	// 화면 지우기
	ClearScreen();

	for (int i = 0; i < MAZE_SIZE; ++i)
	{
		for (int j = 0; j < MAZE_SIZE; ++j)
		{
			// 현재 방문 중인 위치를 특정 문자로 출력
			if (i == row && j == column)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
				std::cout << "P ";
				continue;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

			// 출력
			std::cout << map[i][j] << " ";
		}

		std::cout << "\n";
	}
}

int main()
{
	// 시작 위치 검색
	int startRow = 0;
	int startColumn = 0;

	// 미로의 시작 지점 검색
	for (int i = 0; i < MAZE_SIZE; ++i)
	{
		for (int j = 0; j < MAZE_SIZE; ++j)
		{
			// 시작 지점이라면 위치 저장
			if (map[i][j] == 's')
			{
				startRow = i;
				startColumn = j;
			}
		}

		std::cout << "\n";
	}

	// 시작 지점을 탐색하기 위해 스택에 삽입
	Queue<Location2D> queue;
	queue.Enqueue(Location2D(startRow, startColumn));

	// 미로 탐색
	while (!queue.IsEmpty())
	{
		// 스택 최상위에 있는 위치 반환
		Location2D current;
		queue.Dequeue(current);

		int row = current.row;
		int column = current.column;

		PrintLocation(row, column, 500);

		// 도착했는지 확인
		if (map[row][column] == 'e')
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			std::cout << "\n미로 탐색 성공\n";
			return 0;
		}

		// 방문한 곳은 다른 문자로 설정
		map[row][column] = '.';

		// 상하좌우 위치 중 이동가능한 위치를 스택에 삽입
		if (IsValidLocation(row - 1, column))
		{
			queue.Enqueue(Location2D(row - 1, column));
		}
		if (IsValidLocation(row + 1, column))
		{
			queue.Enqueue(Location2D(row + 1, column));
		}
		if (IsValidLocation(row, column - 1))
		{
			queue.Enqueue(Location2D(row, column - 1));
		}
		if (IsValidLocation(row, column + 1))
		{
			queue.Enqueue(Location2D(row, column + 1));
		}
	}

	std::cout << "\n미로 탐색 실패\n";
}
