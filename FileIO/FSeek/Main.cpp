#include <iostream>
#include <fstream>

//int main()
//{
//	//// �׽�Ʈ ���ڿ�
//	//const char* stringValue = "id: 10 name: seyunjang balance: 1000000";
//
//	//// ���ڿ����� Ư�� �� ��������
//	//int id = 0;
//	//char name[256];
//	//int balance = 0;
//	//sscanf_s(stringValue, "id: %d name: %s balance: %d", &id, name, 256, &balance);
//
//	//std::cout << "id: " << id << "\n";
//	//std::cout << "name: " << name << "\n";
//	//std::cout << "balance: " << balance << "\n";
//
//
//
//
//
//	// ������ ����
//	int id = 10;
//	const char* name = "ronniejang";
//	int balance = 50000000;
//
//	// ���ڿ��� �����
//	// ������ ����
//	char data[1024] = { };
//	snprintf(data, 1024, "id: %d name: %s balance: %d", id, name, balance);
//
//	// �׽�Ʈ ���
//	std::cout << data << "\n";
//
//	//// ���Ϸ� ����
//	//FILE* file = nullptr;
//	//fopen_s(&file, "AccountData.txt", "wb");
//	//if (file != nullptr)
//	//{
//	//	fwrite(data, 1024, 1, file);
//	//	fclose(file);
//	//}
//
//
//
//	// �б�
//	FILE* file = nullptr;
//	fopen_s(&file, "AccountData.txt", "rb");
//
//	// ��ü ���ڿ� ����
//	if (file != nullptr)
//	{
//		char total[2048] = { };
//		char buffer[1024];
//
//		while (!feof(file))
//		{
//			fgets(buffer, 1024, file);
//			//std::cout << buffer;
//
//			// ���ڿ� ��ġ��
//			strcat_s(total, buffer);
//		}
//
//		std::cout << total;
//
//		// �� ��������
//		int id1 = 0;
//		char name1[256] = { };
//		int balance1 = 0;
//
//		// %d: decimal (����)
//		// %f: float (�Ǽ�)
//		// %s: string
//		// %c: char
//		sscanf_s(total, "id: %d name: %s balance: %d", &id1, name1, 256, &balance1);
//
//		std::cin.get();
//	}
//
//
//
//
//
//	//std::ofstream output;
//	//std::ifstream input;
//
//	//// ���� ����
//	//FILE* file = nullptr;
//
//	//// ���� ����
//	//fopen_s(&file, "Test.txt", "rt");
//
//	//// ���� ó��
//	//if (file != nullptr)
//	//{
//	//	// ���� ����
//	//	// ó������ 24����Ʈ �̵�
//	//	fseek(file, 24, SEEK_SET);
//
//	//	// ����
//	//	char buffer[256];
//
//		//while (!feof(file))
//		//{
//
//		//	// ������ �б�
//		//	fgets(buffer, 256, file);
//
//		//	// ���
//		//	std::cout << buffer;
//		//}
//
//	//	// ���� �ݱ�
//	//	fclose(file);
//	//}
//
//	//return 0;
//}

int main()
{
    // �׽�Ʈ ���ڿ�.
//const char* stringValue = "id: 10 name: seyunjang balance: 1000000";

//// ���ڿ����� Ư�� �� ��������.
//int id = 0;
//char name[256];
//int balance = 0;
//sscanf_s(stringValue, "id: %d name: %s balance: %d", &id, name, 256, &balance);

//std::cout << "id: " << id << "\n";
//std::cout << "name: " << name << "\n";
//std::cout << "balance: " << balance << "\n";

// ������ ����.
    int id = 10;
    const char* name = "ronniejang";
    int balance = 50000000;

    // ���ڿ��� �����.
    // ������ ����.
    char data[1024] = { };
    snprintf(data, 1024, "id: %d name: %s balance: %d", id, name, balance);

    // �׽�Ʈ ���.
    std::cout << data << "\n";

    // ���Ϸ� ����.
    //FILE* file = nullptr;
    //fopen_s(&file, "AccountData.txt", "wb");
    //size_t length = strlen(data);
    //if (file != nullptr)
    //{
    //    //fwrite(data, 1024, 1, file);
    //    fwrite(data, length, 1, file);
    //    fclose(file);
    //}

    // �б�.
    FILE* file = nullptr;
    fopen_s(&file, "AccountData.txt", "rb");

    // ��ü ���ڿ� ����.
    if (file != nullptr)
    {
        char total[2048] = { };
        char buffer[1024];

        while (!feof(file))
        {
            fgets(buffer, 1024, file);
            //std::cout << buffer;

            // ���ڿ� ��ġ��.
            strcat_s(total, buffer);
        }

        std::cout << total;

        // �� ��������.
        int id1 = 0;
        char nameBuffer[256] = { };
        int balance1 = 0;

        // %d: decimal (����).
        // %f: float (�Ǽ�/RealNumber).
        // %s: string.
        // %c: char.
        sscanf_s(total, "id: %d name: %s balance: %d", &id1, nameBuffer, 256, &balance1);

        std::cin.get();
    }
}
