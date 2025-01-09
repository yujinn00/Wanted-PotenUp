#include <iostream>
#include "Location2D.h"
#include "Stack.h"

// Sleep (�и� ������)
#include <Windows.h>

// �� ������ ����
const size_t MAZE_SIZE = 20;

// 0: �̵� ����
// 1: �̵� �Ұ�
// s: ���� ��ġ
// e: ��ǥ ��ġ
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

// �̵��Ϸ��� ��ġ�� ��ȿ�� ��ġ���� Ȯ��
bool IsValidLocation(int row, int column)
{
	// ���� ������ ������� Ȯ��
	// ������� ����
	if (row >= MAZE_SIZE || column >= MAZE_SIZE)
	{
		return false;
	}

	if (row < 0 || column < 0)
	{
		return false;
	}

	// ��ȿ�� Ȯ��
	// �̵��Ϸ��� ��ġ�� 0�̰ų�, e��� �̵� ���� ��ȯ
	return map[row][column] == '0' || map[row][column] == 'e';
}

// ȭ�� ����� �Լ�
void ClearScreen()
{
	// Ŀ�� ���� ������ ���� ����ü ����
	CONSOLE_CURSOR_INFO info = { };
	info.dwSize = 1;
	info.bVisible = FALSE;

	// �ܼ� ��� ���� �ڵ� ������ ��������
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ŀ�� ������
	SetConsoleCursorInfo(handle, &info);

	// ȭ�� ��ǥ �ű��
	SetConsoleCursorPosition(handle, { 0, 0 });

	// �� ���� ���
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

// �� ��� �Լ�
void PrintLocation(int row, int column, int delay)
{
	// ������
	Sleep(delay);

	// ȭ�� �����
	ClearScreen();

	for (int i = 0; i < MAZE_SIZE; ++i)
	{
		for (int j = 0; j < MAZE_SIZE; ++j)
		{
			// ���� �湮 ���� ��ġ�� Ư�� ���ڷ� ���
			if (i == row && j == column)
			{
				std::cout << "P ";
				continue;
			}

			// ���
			std::cout << map[i][j] << " ";
		}

		std::cout << "\n";
	}
}

int main()
{
	// ���� ��ġ �˻�
	int startRow = 0;
	int startColumn = 0;

	// �̷��� ���� ���� �˻�
	for (int i = 0; i < MAZE_SIZE; ++i)
	{
		for (int j = 0; j < MAZE_SIZE; ++j)
		{
			// ���
			std::cout << map[i][j] << " ";

			// ���� �����̶�� ��ġ ����
			if (map[i][j] == 's')
			{
				startRow = i;
				startColumn = j;
			}
		}

		std::cout << "\n";
	}

	// ���� ������ Ž���ϱ� ���� ���ÿ� ����
	Stack<Location2D> stack;
	stack.Push(Location2D(startRow, startColumn));

	// �̷� Ž��
	while (!stack.IsEmpty())
	{
		// ���� �ֻ����� �ִ� ��ġ ��ȯ
		Location2D current;
		stack.Pop(current);

		int row = current.row;
		int column = current.column;

		// Ž���� ��ġ ���
		//std::cout << "(" << row << ", " << column << ") ";

		PrintLocation(row, column, 500);

		// �����ߴ��� Ȯ��
		if (map[row][column] == 'e')
		{
			std::cout << "\n�̷� Ž�� ����\n";
			return 0;
		}

		// �湮�� ���� �ٸ� ���ڷ� ����
		map[row][column] = '.';

		// �����¿� ��ġ �� �̵������� ��ġ�� ���ÿ� ����
		if (IsValidLocation(row - 1, column))
		{
			stack.Push(Location2D(row - 1, column));
		}
		if (IsValidLocation(row + 1, column))
		{
			stack.Push(Location2D(row + 1, column));
		}
		if (IsValidLocation(row, column - 1))
		{
			stack.Push(Location2D(row, column - 1));
		}
		if (IsValidLocation(row, column + 1))
		{
			stack.Push(Location2D(row, column + 1));
		}
	}

	std::cout << "\n�̷� Ž�� ����\n";
}
