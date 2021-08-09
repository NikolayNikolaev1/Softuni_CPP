#include <cmath>
#include <iostream>
#include <ctime>

using namespace std;

const char LAST_SYMBOL = '.';
const char NUMBER_SYMBOLS[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

string generateString();

void noiseTestGenerator()
{
	string str = generateString();

	int index = 0;
	char symbol = str[index];
	string numberText = "";

	while (symbol != LAST_SYMBOL)
	{
		for (int currentNumberSymbol : NUMBER_SYMBOLS)
		{
			if (symbol == currentNumberSymbol)
			{
				numberText.append(1, symbol);
			}
		}

		index++;
		symbol = str[index];
	}

	int number = atoi(numberText.c_str()); // Converts string to int
	cout << "Number: " << number << endl;
	cout << "Sqrt: " << sqrt(number) << endl;
}

string generateString()
{
	// Initialize generator.
	srand((unsigned)time(NULL));
	int count = ((unsigned)rand()) % 100 + 1;

	// Get the size of the random sequence.
	string str;
	for (; count; count--)
		str.push_back((char)(rand()));

	str.push_back('.');
	cout << str << endl;

	return str;
}