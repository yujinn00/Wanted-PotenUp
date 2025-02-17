#include <iostream>
#include <vector>
#include <stack>

// �̷� Ž���� ����� ��ǥ ����ü
struct Location2D
{
	Location2D(int row = 0, int col = 0)
		: row(row), col(col)
	{
	}

	int row; // ��
	int col; // ��
};

// �� �迭
int mapSize = 0;
std::vector<std::vector<char>> map;

// �̵� ���� ���� �Ǵ� �Լ�
bool IsValidLocation(int row, int col)
{
	if (row <= 0 || row >= mapSize || col <= 0 || col >= mapSize)
	{
		return false;
	}

	return map[row][col] == '0' || map[row][col] == 'x';
}

// ���� ���� �˻� �Լ�
void FindStartLocation(int& row, int& col)
{
	for (int ix = 0; ix < mapSize; ++ix)
	{
		for (int jx = 0; jx < mapSize; ++jx)
		{
			// �� ���
			std::cout << map[ix][jx] << " ";

			// ���� ������ ��Ÿ���� ���� �˻�
			if (map[ix][jx] == 'e')
			{
				row = ix;
				col = jx;
			}
		}

		std::cout << "\n";
	}
}

// �̷� Ż�� �Լ�
void EscapeMaze()
{
	// ��ġ ������ ���� ���� ����
	int row = 0;
	int col = 0;

	// Ž�� ������ ���� ���� ��ġ ã��
	FindStartLocation(row, col);

	// ���� ����
	std::stack<Location2D> stack;

	// Ž�� ������ ���� ���� ��ġ�� ���ÿ� ����
	stack.push(Location2D(row, col));

	// �̷� Ž��
	while (!stack.empty())
	{
		// ���� ��ġ ��ȯ
		Location2D current = stack.top();
		stack.pop();

		// Ž�� ��ġ ���
		std::cout << "(" << current.row << "," << current.col << ") ";

		// Ż�� ���� Ȯ��
		if (map[current.row][current.col] == 'x')
		{
			std::cout << "\n�̷� Ž�� ����\n";
			return;
		}

		// Ž�� ���� (�湮�� ���� ��ġ�� ��湮 ������ ���� ǥ��)
		map[current.row][current.col] = '.';

		// �����¿� ��ġ �� �̵� ������ ��ġ�� ���ÿ� ����
		if (IsValidLocation(current.row - 1, current.col))
		{
			stack.push(Location2D(current.row - 1, current.col));
		}
		if (IsValidLocation(current.row + 1, current.col))
		{
			stack.push(Location2D(current.row + 1, current.col));
		}
		if (IsValidLocation(current.row, current.col - 1))
		{
			stack.push(Location2D(current.row, current.col - 1));
		}
		if (IsValidLocation(current.row, current.col + 1))
		{
			stack.push(Location2D(current.row, current.col + 1));
		}
	}

	std::cout << "\n�̷� Ž�� ����\n";
}

// ���� �ҷ��� �Ľ�
bool ParseMap(const char* path)
{
	FILE* fp = nullptr;
	fopen_s(&fp, path, "r");

	if (fp)
	{
		// ù ��° �� �б�
		char buf[256] = { };
		if (!fgets(buf, 256, fp))
		{
			fclose(fp);
			return false;
		}

		// �� ũ�� ����
		sscanf_s(buf, "size %d", &mapSize);

		// �� ������ ������ ���� �ӽ� �迭 ����
		std::vector<char> line;
		line.reserve(mapSize);

		// �� ������ �ؼ��� ���� ����
		while (fgets(buf, 256, fp))
		{
			// ù ��° ĭ ó��
			char* context = nullptr;
			char* token = strtok_s(buf, ",", &context);

			if (token)
			{
				line.emplace_back(token[0]);
			}

			// �� ��°���ʹ� ����
			while (context)
			{
				token = strtok_s(nullptr, ",", &context);

				if (!token)
				{
					break;
				}

				line.emplace_back(token[0]);
			}

			// ó���� ���� �����͸� �ʿ� �߰�.
			map.emplace_back(line);
			line.clear();
		}

		fclose(fp);
		return true;
	}

	return false;
}

int main()
{
	// �̷� Ž��
	if (ParseMap("../Assets/Map1.txt"))
	{
		EscapeMaze();
	}

	return 0;
}
