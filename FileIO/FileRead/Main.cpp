#include <iostream>

int main()
{
	// 읽어올 저장소
	char buffer[256];

	// 파일 스트림 객체 선언
	FILE* file = nullptr;

	// 파일 열기
	fopen_s(&file, "Test.txt", "rt");

	// 파일 읽기
	if (file != nullptr)
	{
		// 버퍼에 내용 읽어들이기
		// 파일이 끝나지 않았으면 계속 읽기
		while (!feof(file))
		{
			// 바이트 수만큼 파일에 쓰기
			fgets(buffer, 256, file);

			// 출력
			std::cout << buffer;
		}

		// 파일 닫기
		fclose(file);
	}
}
