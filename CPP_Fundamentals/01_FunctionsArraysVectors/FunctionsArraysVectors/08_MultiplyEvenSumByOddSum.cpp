#include <iostream>

using namespace std;

void multiplyEvenSumByOddSum()
{
	int number, evenSum = 0, oddSum = 0;
	cout << "Enter number: ";
	cin >> number;

	while (number)
	{
		int currentNumber = number % 10; // Gets the last digit of the number until there are no more.

		// Checks the number if it is even or odd and sums it to the correct variable.
		currentNumber % 2
			? oddSum += currentNumber
			: evenSum += currentNumber;

		number = number / 10; // Remove the last digit.
	}

	cout << "Result: " << evenSum * oddSum;
}