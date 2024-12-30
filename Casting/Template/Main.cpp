#include <iostream>

//// int Ÿ�� �� �ٲٱ�
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//// float Ÿ�� �� �ٲٱ�
//void Swap(float& a, float& b)
//{
//	float tmp = a;
//	a = b;
//	b = tmp;
//}

// ���ø�
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int num1 = 11;
	int num2 = 22;

	//Swap(num1, num2);
	Swap<int>(num1, num2); // ����� Good
	std::cout << num1 << " : " << num2 << "\n";



	float num3 = 11.11f;
	float num4 = 22.22f;

	//Swap(num3, num4);
	Swap<float>(num3, num4); // ����� Good
	std::cout << num3 << " : " << num4 << "\n";



	double num5 = 11.11;
	double num6 = 22.22;

	//Swap(num5, num6);
	Swap<double>(num5, num6); // ����� Good
	std::cout << num5 << " : " << num6 << "\n";
}
