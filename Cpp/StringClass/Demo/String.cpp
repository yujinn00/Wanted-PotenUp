#include "String.h"

String::String(const char* string)
{
    // ���� Ȯ��
    // ���� ������
    //length = string == nullptr ? 1 : (int)strlen(string);
    length = string == nullptr ? 1 : static_cast<int>(strlen(string)); // 1. �� ���� ���� ���̸� �˷���

    // ���� �Ҵ� �� ���ڿ� ����
    data = new char[length + 1]; // 2. �׷��� 1�� ���ϴ� ����
    if (string != nullptr)
    {
        strcpy_s(data, length + 1, string);
    }
}

String::String(const String& other)
{
    length = other.length;
    data = new char[length + 1];
    strcpy_s(data, length + 1, other.data);
}

String::~String()
{
    // �޸� ����
    delete[] data;
}

String& String::operator=(const String& other)
{
    // ������ data ����
    delete[] data;

    length = other.length;
    data = new char[length + 1];
    strcpy_s(data, length + 1, other.data);

    return *this;
}

bool String::operator==(const String& other)
{
    // ���ڿ� �� C ���̺귯�� �Լ�: strcmp
    return strcmp(data, other.data) == 0; // 0�̸� ����
}

bool String::operator!=(const String& other)
{
    return strcmp(data, other.data) != 0; // 0�� �ƴϸ� �ٸ�
    //return !(*this == other); // ���� ���� �ƶ���
}

const int String::Length() const
{
    return length;
}

const char* String::Data() const
{
    return data;
}

std::ostream& operator<<(std::ostream& os, const String& string)
{
    os << string.data;

    return os;
}
