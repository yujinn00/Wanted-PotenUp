#include<iostream>

//void TestFunction(char string[]) //�迭�� �ѱ涧�� �ּҸ� ���̳ѱ�� �ƴϸ� ���� �����ͷ� �Ѱܾ� ��?
//{
//   //size_t length = strlen(string);
//   int count = sizeof(string) / sizeof(string[0]);
//   std::cout << "count: " << count << "\n";
//}

//������(Entry Point)
int main()
{
    ////auto testString = "Hello";
    //const char* testString = "Hello";
    //char charArray[] = "Hello";

    ////�����Ҵ�
    ////long long ->__int64 ���� Ÿ��
    //size_t length = strlen("hongjun") + 1; //typedef
    //char* name = new char[length];
    //strcpy_s(name, length, "hongjun");

    ////�׽�Ʈ ���
    //std::cout << testString << "\n";
    //std::cout << charArray << "\n";
    //std::cout << name << "\n";
    //
    //delete[] name;
 //------------------------------------------------------
    //�����迭 vector / HashTable
    //�˻�.
    // 
    //����
    char charactor = 'a';

    //���ڿ�
    char charArray[] = "hel\0lo";

    //auto rawString = "hello";
    const char* rawString = "Hello c++";
    //const char* rawString = charArray;

    std::cout << rawString << *rawString << std::endl;

    int length = 0;
    while (1)
    {
        if (rawString[length] == '\0')
        {
            break;
        }
        ++length;
    }

    std::cout << length << std::endl;

    //�Լ��� ���� ���ϱ�
    size_t length1 = strlen(rawString);

    std::cout << length1 << std::endl;

    //�� - �����޸� - å��
    char* heapString = new char[length1 + 1];

    //���ڿ� ����
    //strcpy_s(heapString, length1 + 1, rawString);

    //�޸� ����
    memcpy(heapString, rawString, sizeof(char) * (length + 1));
    //heapString[length] = '\0';

    //concaternate
    //strcat_s(); //���ڿ� ���ϱ� ���� ������ ���� ���� �ƴ�

    std::cout << heapString << std::endl;
    std::cout << charArray[1] << "\n";
    std::cout << *(rawString + 1) << "\n";

    std::cout << sizeof(*rawString) << "\n";

    delete[] heapString;

    //�ǹ̴� ����
    std::cin.get();
}