#include <iostream>

#include "Calculator.h"

int main() {
	Calculator calculator;

	std::cout << "3 + 5 = " << calculator.Add(3, 5) << "\n";
	std::cout << "3 / 5 = " << calculator.Divide(3, 5) << "\n";
	std::cout << "12 - 7 = " << calculator.Substract(12, 7) << "\n";
	std::cout << "12 x 7 = " << calculator.Multiply(12, 7) << "\n";

	calculator.ShowOperationCount();

	return 0;
}