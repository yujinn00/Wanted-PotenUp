#include "String.h"

String::String(const char* string)
{
    // 길이 확인
    // 삼항 연산자
    //length = string == nullptr ? 1 : (int)strlen(string);
    length = string == nullptr ? 1 : static_cast<int>(strlen(string)); // 1. 널 문자 빼고 길이를 알려줌

    // 동적 할당 및 문자열 복사
    data = new char[length + 1]; // 2. 그래서 1을 더하는 거임
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
    // 메모리 해제
    delete[] data;
}

String& String::operator=(const String& other)
{
    // 기존의 data 제거
    delete[] data;

    length = other.length;
    data = new char[length + 1];
    strcpy_s(data, length + 1, other.data);

    return *this;
}

bool String::operator==(const String& other)
{
    // 문자열 비교 C 라이브러리 함수: strcmp
    return strcmp(data, other.data) == 0; // 0이면 같음
}

bool String::operator!=(const String& other)
{
    return strcmp(data, other.data) != 0; // 0이 아니면 다름
    //return !(*this == other); // 위랑 같은 맥락임
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
