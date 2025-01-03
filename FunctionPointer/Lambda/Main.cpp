#include <iostream>
#include <functional> // c++ 11

// 함수 포인터
typedef void (*functionPointer)();
using usingFP = void (*)();
std::function<void()> newFunctionPointer; // functional

int main()
{
    // Lambda 함수 (무명 함수)
    // 선언하면서 호출
    //[]() { std::cout << "Hello Lambda\n"; }();

    // 람다 함수 저장
    int count = 0;
    auto function = [&count](/*int count*/) { ++count; };

    // 함수 포인터를 사용한 람다 함수 저장
    functionPointer function2 = []() { std::cout << "Hello\n"; };
    function2();

    newFunctionPointer = function2;
    newFunctionPointer();

    // 람다 함수 호출
    //auto returnValue = function();

    // CPU 자료를 GPU한테 넘기고 -> GPU가 그리기 -> 백버퍼(Backbuffer)
    //   Backbuffer: 이미지 (Texture2D) -> Color[]

    function();
    function();
    function();
    function();

    std::cout << "Count: " << count << "\n";
}
