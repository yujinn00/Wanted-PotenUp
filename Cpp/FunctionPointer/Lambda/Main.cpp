#include <iostream>
#include <functional> // c++ 11

// �Լ� ������
typedef void (*functionPointer)();
using usingFP = void (*)();
std::function<void()> newFunctionPointer; // functional

int main()
{
    // Lambda �Լ� (���� �Լ�)
    // �����ϸ鼭 ȣ��
    //[]() { std::cout << "Hello Lambda\n"; }();

    // ���� �Լ� ����
    int count = 0;
    auto function = [&count](/*int count*/) { ++count; };

    // �Լ� �����͸� ����� ���� �Լ� ����
    functionPointer function2 = []() { std::cout << "Hello\n"; };
    function2();

    newFunctionPointer = function2;
    newFunctionPointer();

    // ���� �Լ� ȣ��
    //auto returnValue = function();

    // CPU �ڷḦ GPU���� �ѱ�� -> GPU�� �׸��� -> �����(Backbuffer)
    //   Backbuffer: �̹��� (Texture2D) -> Color[]

    function();
    function();
    function();
    function();

    std::cout << "Count: " << count << "\n";
}
