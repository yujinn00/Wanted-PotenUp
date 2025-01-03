#include "Calculator.h"

Calculator::Calculator()
	: addCount(0), subCount(0), mulCount(0), divCount(0) {}
Calculator::~Calculator() {}

double Calculator::Add(double a, double b) {
	addCount++;
	return a + b;
}

double Calculator::Substract(double a, double b) {
	subCount++;
	return a - b;
}

double Calculator::Multiply(double a, double b) {
	mulCount++;
	return a * b;
}

double Calculator::Divide(double a, double b) {
	divCount++;
	return a / b;
}

void Calculator::ShowOperationCount() const {
	std::cout << "µ¡¼À: " << addCount << ", »¬¼À: " << subCount << ", °ö¼À: " << mulCount << ", ³ª´°¼À: " << divCount << "\n";
}