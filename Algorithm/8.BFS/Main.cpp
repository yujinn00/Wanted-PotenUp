#include <iostream>
#include <vector>
#include <string>
#include <queue>

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

// 이동 가능 여부 판단 함수
bool IsValidLocation(int row, int col)
{
	if (row <= 0 || row >= mapSize || col <= 0 || col >= mapSize)
	{
		return false;
	}

	return map[row][col] == '0' || map[row][col] == destinationMark;
}

// 맵 출력 및 시작 지점 검색 함수
void FindStartLocation(int& row, int& col)
{
	// 행
	for (int ix = 0; ix < mapSize; ++ix)
	{
		// 열
		for (int jx = 0; jx < mapSize; ++jx)
		{
			// 시작 지점을 나타내는 문자 검색
			if (map[ix][jx] == startMark)
			{
				row = ix;
				col = jx;
			}

			// 맵 출력
			std::cout << map[ix][jx] << " ";
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

	// 큐 선언
	std::queue<Location2D> queue;
	queue.emplace(Location2D(row, col));

	// 미로 탐색
	while (!queue.empty())
	{
		// 현재 위치 반환
		Location2D current = queue.front();
		queue.pop();

		// 탐색 위치 출력
		std::cout << "(" << current.row << "," << current.col << ") ";

		// 탈출 조건 확인
		if (map[current.row][current.col] == destinationMark)
		{
			std::cout << "\n미로 탐색 성공\n";
			return;
		}

		// 탐색 진행 (방문한 현재 위치는 재방문 방지를 위해 표시)
		map[current.row][current.col] = '.';

		// 상하좌우 위치 중 이동 가능한 위치를 큐에 삽입   
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

	std::cout << "\n미로 탐색 실패\n";
}

// 맵을 불러와 파싱
bool ParseMap(const char* path, char& startMark, char& destinationMark)
{
	// 파일 열기
	FILE* fp = nullptr;
	fopen_s(&fp, path, "r");

	if (fp)
	{
		// 첫 줄 읽기
		char buf[256] = { };
		if (!fgets(buf, 256, fp))
		{
			fclose(fp);
			return false;
		}

		// 맵 크기 설정 및 시작/목적 지점 문자 설정
		sscanf_s(buf, "size: %d start: %c destination: %c", &mapSize, &startMark, 1, &destinationMark, 1);

		// 줄 데이터 저장을 위한 임시 배열 선언
		std::vector<std::string> lines;
		lines.reserve(mapSize);

		// 파일의 현재 위치
		auto currentPosition = ftell(fp);

		// 마지막 위치로 이동
		fseek(fp, 0, SEEK_END);

		// 위치 저장
		auto endPosition = ftell(fp);

		// 크기 계산
		int size = (int)(endPosition - currentPosition);

		// rewind
		fseek(fp, currentPosition, SEEK_SET);

		// 나머지 읽기
		fread_s(buf, 2048, size, 1, fp);

		// 라인 파싱
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

		// 라인별 파싱 데이터 저장
		std::vector<char> line;
		line.reserve(mapSize);

		// 재사용을 위한 nullptr 설정
		token = nullptr;

		// 라인 배열을 순회하면서 파싱 처리
		for (auto& item : lines)
		{
			// 재사용을 위한 nullptr 설정
			context = nullptr;

			// 첫 칸 처리
			token = strtok_s(const_cast<char*>(item.c_str()), ",", &context);
			if (token)
			{
				line.emplace_back(token[0]);
			}

			// 두 번째 칸부터는 루프
			while (context)
			{
				token = strtok_s(nullptr, ",", &context);
				if (!token)
				{
					break;
				}
				line.emplace_back(token[0]);
			}

			// 처리된 라인을 데이터 맵에 추가
			map.emplace_back(line);
			line.clear();
		}

		// 파일 닫기
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
