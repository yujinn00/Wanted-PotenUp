#include <iostream>

int main()
{
	// ���Ͽ� �߰��� ���ڿ�
	const char* message = "C ǥ�� ���̺귯���� ������ �ؽ�Ʈ";

	// ���� ��Ʈ�� ��ü ����
	FILE* file = nullptr;

	// ���� ����
	fopen_s(&file, "Test.txt", "wt");

	// ���� ����
	if (file != nullptr)
	{
		// ���ϴ� �� ����
		fputs(message, file);

		// ���� �ݱ�
		fclose(file);
	}
}
