#include <iostream>
#include <vector>
#include <string>
#include <queue>

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
//int mapSize = 6;
//char startMark = 'e';
//char destinationMark = 'x';
//std::vector<std::vector<char>> map =
//{
//	{'1','1','1','1','1','1'},
//	{'e','0','1','0','0','1'},
//	{'1','0','0','0','1','1'},
//	{'1','0','1','0','1','1'},
//	{'1','0','1','0','0','x'},
//	{'1','1','1','1','1','1'}
//};
int mapSize = 6;
char startMark = 'e';
char destinationMark = 'x';
std::vector<std::vector<char>> map;

// �̵� ���� ���� �Ǵ� �Լ�
bool IsValidLocation(int row, int col)
{
	if (row <= 0 || row >= mapSize || col <= 0 || col >= mapSize)
	{
		return false;
	}

	return map[row][col] == '0' || map[row][col] == destinationMark;
}

// �� ��� �� ���� ���� �˻� �Լ�
void FindStartLocation(int& row, int& col)
{
	// ��
	for (int ix = 0; ix < mapSize; ++ix)
	{
		// ��
		for (int jx = 0; jx < mapSize; ++jx)
		{
			// ���� ������ ��Ÿ���� ���� �˻�
			if (map[ix][jx] == startMark)
			{
				row = ix;
				col = jx;
			}

			// �� ���
			std::cout << map[ix][jx] << " ";
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

	// ť ����
	std::queue<Location2D> queue;
	queue.emplace(Location2D(row, col));

	// �̷� Ž��
	while (!queue.empty())
	{
		// ���� ��ġ ��ȯ
		Location2D current = queue.front();
		queue.pop();

		// Ž�� ��ġ ���
		std::cout << "(" << current.row << "," << current.col << ") ";

		// Ż�� ���� Ȯ��
		if (map[current.row][current.col] == destinationMark)
		{
			std::cout << "\n�̷� Ž�� ����\n";
			return;
		}

		// Ž�� ���� (�湮�� ���� ��ġ�� ��湮 ������ ���� ǥ��)
		map[current.row][current.col] = '.';

		// �����¿� ��ġ �� �̵� ������ ��ġ�� ť�� ����   
		if (IsValidLocation(current.row - 1, current.col))
		{
			queue.emplace(Location2D(current.row - 1, current.col));
		}
		if (IsValidLocation(current.row + 1, current.col))
		{
			queue.emplace(Location2D(current.row + 1, current.col));
		}
		if (IsValidLocation(current.row, current.col - 1))
		{
			queue.emplace(Location2D(current.row, current.col - 1));
		}
		if (IsValidLocation(current.row, current.col + 1))
		{
			queue.emplace(Location2D(current.row, current.col + 1));
		}
	}

	std::cout << "\n�̷� Ž�� ����\n";
}

// ���� �ҷ��� �Ľ�
bool ParseMap(const char* path, char& startMark, char& destinationMark)
{
	// ���� ����
	FILE* fp = nullptr;
	fopen_s(&fp, path, "r");

	if (fp)
	{
		// ù �� �б�
		char buf[256] = { };
		if (!fgets(buf, 256, fp))
		{
			fclose(fp);
			return false;
		}

		// �� ũ�� ���� �� ����/���� ���� ���� ����
		sscanf_s(buf, "size: %d start: %c destination: %c", &mapSize, &startMark, 1, &destinationMark, 1);

		// �� ������ ������ ���� �ӽ� �迭 ����
		std::vector<std::string> lines;
		lines.reserve(mapSize);

		// ������ ���� ��ġ
		auto currentPosition = ftell(fp);

		// ������ ��ġ�� �̵�
		fseek(fp, 0, SEEK_END);

		// ��ġ ����
		auto endPosition = ftell(fp);

		// ũ�� ���
		int size = (int)(endPosition - currentPosition);

		// rewind
		fseek(fp, currentPosition, SEEK_SET);

		// ������ �б�
		fread_s(buf, 2048, size, 1, fp);

		// ���� �Ľ�
		char* context = nullptr;
		char* token = strtok_s(buf, "\n", &context);
		if (token)
		{
			lines.emplace_back(token);
		}

		while (context)
		{
			token = strtok_s(nullptr, "\n", &context);
			if (!token)
			{
				break;
			}
			lines.emplace_back(token);
		}

		// ���κ� �Ľ� ������ ����
		std::vector<char> line;
		line.reserve(mapSize);

		// ������ ���� nullptr ����
		token = nullptr;

		// ���� �迭�� ��ȸ�ϸ鼭 �Ľ� ó��
		for (auto& item : lines)
		{
			// ������ ���� nullptr ����
			context = nullptr;

			// ù ĭ ó��
			token = strtok_s(const_cast<char*>(item.c_str()), ",", &context);
			if (token)
			{
				line.emplace_back(token[0]);
			}

			// �� ��° ĭ���ʹ� ����
			while (context)
			{
				token = strtok_s(nullptr, ",", &context);
				if (!token)
				{
					break;
				}
				line.emplace_back(token[0]);
			}

			// ó���� ������ ������ �ʿ� �߰�
			map.emplace_back(line);
			line.clear();
		}

		// ���� �ݱ�
		fclose(fp);
		return true;
	}

	return false;
}

int main()
{
	if (ParseMap("../Assets/Map2.txt", startMark, destinationMark))
	{
		EscapeMaze();
	}

	return 0;
}
