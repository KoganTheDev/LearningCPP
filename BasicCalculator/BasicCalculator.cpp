#include <iostream>
using namespace std;


double addition(double firstValue, double secondValue);
double subtraction(double firstValue, double secondValue);
double multiplication(double firstValue, double secondValue);
double division(double firstValue, double secondValue);


int main() {
	double firstValue, secondValue;
	char mathOperator;
	double result;

	cout << "Welcome to the Basic-Calculator:\n" <<
		"Insert an equation that contains 2 numbers and an operator.\nMake sure to insert space between each element.\n" <<
		"e.g:\n+ for addition.\n- for substraction.\n* for multiplication.\n/ for division.\n\n";
	

	cin >> firstValue;
	cin >> mathOperator;
	cin >> secondValue;

	if (mathOperator == '/' && secondValue == 0) {
		cout << "Dividing by zero is not possible.\n";
		exit(1);
	}

	switch (mathOperator)
	{
	case '+':
		result = addition(firstValue, secondValue);
		break;
	case '-':
		result = subtraction(firstValue, secondValue);
		break;
	case '/':
		result = division(firstValue, secondValue);
		break;
	case '*':
		result = multiplication(firstValue, secondValue);
		break;
	default:
		cout << "No math operator detected.\n";
		exit(1);
		break;
	}

	printf("\n%.2lf %c %.2lf = %.2lf\n", firstValue, mathOperator, secondValue, result);

	return 0;
}


/**
 * @brief Adds two double values.
 *
 * This function takes two double values as input and returns their sum.
 *
 * @param firstValue The first double value to add.
 * @param secondValue The second double value to add.
 * @return The sum of firstValue and secondValue.
 */
double addition(double firstValue, double secondValue) {
	return (firstValue + secondValue);
}

/**
 * @brief Subtracts one double value from another.
 *
 * This function takes two double values as input and returns the result of
 * subtracting the second value from the first.
 *
 * @param firstValue The double value from which to subtract.
 * @param secondValue The double value to subtract.
 * @return The result of firstValue minus secondValue.
 */
double subtraction(double firstValue, double secondValue) {
	return (firstValue - secondValue);
}

/**
 * @brief Multiplies two double values.
 *
 * This function takes two double values as input and returns their product.
 *
 * @param firstValue The first double value to multiply.
 * @param secondValue The second double value to multiply.
 * @return The product of firstValue and secondValue.
 */
double multiplication(double firstValue, double secondValue) {
	return (firstValue * secondValue);
}

/**
 * @brief Divides one double value by another.
 *
 * This function takes two double values as input and returns the result of
 * dividing the first value by the second. If the second value is zero,
 * the behavior is undefined. It is advisable to check for zero before calling
 * this function.
 *
 * @param firstValue The double value to be divided.
 * @param secondValue The double value by which to divide.
 * @return The result of firstValue divided by secondValue.
 */
double division(double firstValue, double secondValue) {
	return (firstValue / secondValue);
}
