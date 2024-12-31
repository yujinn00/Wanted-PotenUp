#include "Student.h"

Student::Student(int age, const wchar_t* name, const wchar_t* major)
	: Person(age, name)
{
	size_t len = wcslen(major) + 1;
	this->major = new wchar_t[len];
	wcscpy_s(this->major, len, major);
}

Student::Student(const Student& student)
	: Person(student.age, student.name)
{
	size_t len = wcslen(student.major) + 1;
	this->major = new wchar_t[len];
	wcscpy_s(this->major, len, student.major);
}

Student::~Student()
{
	if (major != nullptr)
	{
		delete[] major;
		major = nullptr;
	}
}

void Student::ShowData() const
{
	std::wcout << L"이름: " << name << L"\n";
	std::wcout << L"나이: " << age << L"\n";
	std::wcout << L"전공: " << major << L"\n";
}
