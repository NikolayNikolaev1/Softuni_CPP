#include <iostream>

using namespace std;

string getDozensText(int number);
string getNumberText(int number);
string getSpecialDozensText(int number);

void printNameOfNumber()
{
	int number;
	cout << "Enter number[0, 9999]: ";
	cin >> number;

	while (number < 0 || number > 9999)
	{
		cout << "Invalid number!";
		cout << "Enter number[0, 9999]: ";
		cin >> number;
	}

	// Get every digit.
	int thousands = number / 1000;
	int hundreds = (number % 1000) / 100;
	int dozens = (number % 100) / 10;
	int unit = (number % 10);

	string result;

	if (thousands == 0
		&& hundreds == 0
		&& dozens == 0
		&& unit == 0)
	{
		result = "zero";
	}
	else
	{
		if (thousands != 0)
		{
			// Gets the text number for the thousands.
			result = result.append(getNumberText(thousands) + " thousand ");
		}

		if (hundreds != 0)
		{
			// Gets the text number for thehundreds.
			result = result.append(getNumberText(hundreds) + " hundred ");
		}

		if (dozens != 0)
		{
			if (dozens == 1)
			{
				// Gets the text for the numbers between 10 and 19.
				result = result.append(getSpecialDozensText(unit) + " ");
			}
			else
			{
				// Gets the text for the numbers between 20 and 99
				result = result.append(getDozensText(dozens) + " ");

				if (unit != 0)
				{
					// Gets the text number for units.
					result = result.append(getNumberText(unit));
				}
			}
		}
	}

	cout << result;
}

string getDozensText(int number)
{

	switch (number)
	{
	case 2:
		return "twenty";
	case 3:
		return "thirty";
	case 4:
		return "fourty";
	case 5:
		return "fifty";
	case 6:
		return "sixty";
	case 7:
		return "seventy";
	case 8:
		return "eighty";
	case 9:
		return "ninety";
	}
}


string getNumberText(int number)
{
	switch (number)
	{
	case 1:
		return "one";
	case 2:
		return "two";
	case 3:
		return "three";
	case 4:
		return "four";
	case 5:
		return "five";
	case 6:
		return "six";
	case 7:
		return "seven";
	case 8:
		return "eight";
	case 9:
		return "nine";
	case 0:
		return "ten";
	}
}

string getSpecialDozensText(int number)
{
	switch (number)
	{
	case 1:
		return "eleven";
	case 2:
		return "twelve";
	case 3:
		return "thirteen";
	case 4:
		return "fourteen";
	case 5:
		return "fifteen";
	case 6:
		return "sixteen";
	case 7:
		return "seventeen";
	case 8:
		return "eighteen";
	case 9:
		return "nineteen";
	}
}