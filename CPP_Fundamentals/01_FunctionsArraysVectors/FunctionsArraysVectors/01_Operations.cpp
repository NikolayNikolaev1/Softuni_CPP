#include <iostream>

using namespace std;

const int OPERATIONS_COUNT = 4;
const char ADDITION_OPERATOR = '+';
const char SUBSTRACTION_OPERATOR = '-';
const char MULTIPLICATION_OPERATOR = '*';
const char DIVISION_OPERATOR = '/';
const char OPERATIONS[OPERATIONS_COUNT] =
{
	ADDITION_OPERATOR,
	SUBSTRACTION_OPERATOR,
	MULTIPLICATION_OPERATOR,
	DIVISION_OPERATOR
};

int firstNumber, secondNumber;
char symbol;

double calculate();
bool isOperationValid();
void readInput();

void operations()
{
	readInput();

	while (!isOperationValid())
	{
		// Reads input for symbol until it is valid.
		cout << "Operation is not valid! Try again: ";
		cin >> symbol;
	}

	cout << "Result: " << calculate();
}

// Performs operation with numbers based on the operator input.
double calculate()
{
	switch (symbol)
	{
	case ADDITION_OPERATOR:
		return (double)firstNumber + secondNumber;
	case SUBSTRACTION_OPERATOR:
		return (double)firstNumber - secondNumber;
	case MULTIPLICATION_OPERATOR:
		return (double)firstNumber * secondNumber;
	case DIVISION_OPERATOR:
		return (double)firstNumber / secondNumber;
	}
}

// Checks if symbol from input exists in the operations array.
bool isOperationValid()
{
	for (char operation : OPERATIONS)
	{
		if (symbol == operation)
		{
			return true;
		}
	}

	return false;
}

// Get input first number, second number and operation choice from user.
void readInput()
{
	cout << "Enter first and second number: ";
	cin >> firstNumber >> secondNumber;
	cout << "Enter desired operation(symbol): ";
	cin >> symbol;
}