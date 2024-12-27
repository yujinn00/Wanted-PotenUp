#pragma once

#include <iostream>

class Calculator {
private:
	int addCount;
	int subCount;
	int mulCount;
	int divCount;

public:
	Calculator();
	~Calculator();
	double Add(double a, double b);
	double Substract(double a, double b);
	double Multiply(double a, double b);
	double Divide(double a, double b);
	void ShowOperationCount() const;
};