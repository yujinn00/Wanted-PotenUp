#include <iostream>
#include <vector>
#include <stack>

// 미로 탐색에 사용할 좌표 구조체
struct Location2D
{
	Location2D(int row = 0, int col = 0)
		: row(row), col(col)
	{
	}

	int row; // 행
	int col; // 열
};

// 맵 배열
int mapSize = 0;
std::vector<std::vector<char>> map;

// 이동 가능 여부 판단 함수
bool IsValidLocation(int row, int col)
{
	if (row <= 0 || row >= mapSize || col <= 0 || col >= mapSize)
	{
		return false;
	}

	return map[row][col] == '0' || map[row][col] == 'x';
}

// 시작 지점 검색 함수
void FindStartLocation(int& row, int& col)
{
	for (int ix = 0; ix < mapSize; ++ix)
	{
		for (int jx = 0; jx < mapSize; ++jx)
		{
			// 맵 출력
			std::cout << map[ix][jx] << " ";

			// 시작 지점을 나타내는 문자 검색
			if (map[ix][jx] == 'e')
			{
				row = ix;
				col = jx;
			}
		}

		std::cout << "\n";
	}
}

// 미로 탈출 함수
void EscapeMaze()
{
	// 위치 저장을 위한 변수 선언
	int row = 0;
	int col = 0;

	// 탐색 시작을 위해 시작 위치 찾기
	FindStartLocation(row, col);

	// 스택 선언
	std::stack<Location2D> stack;

	// 탐색 시작을 위해 시작 위치를 스택에 삽입
	stack.push(Location2D(row, col));

	// 미로 탐색
	while (!stack.empty())
	{
		// 현재 위치 반환
		Location2D current = stack.top();
		stack.pop();

		// 탐색 위치 출력
		std::cout << "(" << current.row << "," << current.col << ") ";

		// 탈출 조건 확인
		if (map[current.row][current.col] == 'x')
		{
			std::cout << "\n미로 탐색 성공\n";
			return;
		}

		// 탐색 진행 (방문한 현재 위치는 재방문 방지를 위해 표시)
		map[current.row][current.col] = '.';

		// 상하좌우 위치 중 이동 가능한 위치를 스택에 삽입
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

	std::cout << "\n미로 탐색 실패\n";
}

// 맵을 불러와 파싱
bool ParseMap(const char* path)
{
	FILE* fp = nullptr;
	fopen_s(&fp, path, "r");

	if (fp)
	{
		// 첫 번째 줄 읽기
		char buf[256] = { };
		if (!fgets(buf, 256, fp))
		{
			fclose(fp);
			return false;
		}

		// 맵 크기 설정
		sscanf_s(buf, "size %d", &mapSize);

		// 줄 데이터 저장을 위한 임시 배열 선언
		std::vector<char> line;
		line.reserve(mapSize);

		// 맵 데이터 해석을 위한 루프
		while (fgets(buf, 256, fp))
		{
			// 첫 번째 칸 처리
			char* context = nullptr;
			char* token = strtok_s(buf, ",", &context);

			if (token)
			{
				line.emplace_back(token[0]);
			}

			// 두 번째부터는 루프
			while (context)
			{
				token = strtok_s(nullptr, ",", &context);

				if (!token)
				{
					break;
				}

				line.emplace_back(token[0]);
			}

			// 처리된 라인 데이터를 맵에 추가.
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
	// 미로 탐색
	if (ParseMap("../Assets/Map1.txt"))
	{
		EscapeMaze();
	}

	return 0;
}
