#include <cmath>
#include <iostream>

using namespace std;

const char LAST_SYMBOL = '.';
const char NUMBER_SYMBOLS[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void noise()
{
	char symbol;
	string numberText = "";

	do
	{
		cin >> symbol;

		for (int currentNumberSymbol : NUMBER_SYMBOLS)
		{
			if (symbol == currentNumberSymbol)
			{
				numberText.append(1, symbol);
			}
		}
	} while (symbol != LAST_SYMBOL);

	int number = atoi(numberText.c_str()); // Converts string to int
	cout << sqrt(number);
}