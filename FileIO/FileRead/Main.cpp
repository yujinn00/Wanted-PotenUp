#include <iostream>

int main()
{
	// �о�� �����
	char buffer[256];

	// ���� ��Ʈ�� ��ü ����
	FILE* file = nullptr;

	// ���� ����
	fopen_s(&file, "Test.txt", "rt");

	// ���� �б�
	if (file != nullptr)
	{
		// ���ۿ� ���� �о���̱�
		// ������ ������ �ʾ����� ��� �б�
		while (!feof(file))
		{
			// ����Ʈ ����ŭ ���Ͽ� ����
			fgets(buffer, 256, file);

			// ���
			std::cout << buffer;
		}

		// ���� �ݱ�
		fclose(file);
	}
}
