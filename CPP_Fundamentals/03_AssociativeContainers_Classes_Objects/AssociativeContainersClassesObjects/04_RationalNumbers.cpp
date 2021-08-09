/*
* Write a program, use a Class Rational Numbers.
* The class should have Numerator and Denominator, the variables should be INT.
*
* Methods in the Class:
*	Setters, Getters, Print.
* Note - The set method of the Denominator for a given 0 the function should set 1.
*
* Implement External Methods: Sum, Difference, Multiplication, Division.
*/
#include <iostream>

using namespace std;

class RationalNumber
{
private:
	int numerator;
	int denominator;

public:
	RationalNumber() :
		numerator(0),
		denominator(0) { }

	// Getters
	int getNumerator() { return this->numerator; }
	int getDenominator() { return this->denominator; }

	// Setters
	void setNumerator(int numerator) { this->numerator = numerator; }
	void setDenominator(int denominator)
	{
		if (denominator == 0)
		{
			this->denominator = 1;
			return;
		}

		this->denominator = denominator;
	}

	void Print()
	{
		cout << this->numerator << "/" << this->denominator << endl;
	}
};

RationalNumber createRationalNumber(int numerator, int denominator);
RationalNumber divideRationalNumbers(RationalNumber firstNum, RationalNumber secondNum);
RationalNumber multiplyRationalNumbers(RationalNumber firstNum, RationalNumber secondNum);
RationalNumber sumRationalNumbers(RationalNumber firstNum, RationalNumber secondNum);
RationalNumber subtractRationalNumbers(RationalNumber firstNum, RationalNumber secondNum);

void rationalNumbers()
{
	int numerator, denominator;

	cout << "Enter first rational number numerator: ";
	cin >> numerator;
	cout << "Enter first rational number denominator: ";
	cin >> denominator;
	RationalNumber firstRationalNumber = createRationalNumber(numerator, denominator);

	cout << "Enter second rational number numerator: ";
	cin >> numerator;
	cout << "Enter second rational number denominator: ";
	cin >> denominator;
	RationalNumber secondRationalNumber = createRationalNumber(numerator, denominator);

	RationalNumber summedRationalNumber = sumRationalNumbers(firstRationalNumber, secondRationalNumber);
	summedRationalNumber.Print();
	RationalNumber subtractedRationalNumber = subtractRationalNumbers(firstRationalNumber, secondRationalNumber);
	subtractedRationalNumber.Print();
	RationalNumber multipliedRationalNumber = multiplyRationalNumbers(firstRationalNumber, secondRationalNumber);
	multipliedRationalNumber.Print();
	RationalNumber dividedRationalNumber = divideRationalNumbers(firstRationalNumber, secondRationalNumber);
	dividedRationalNumber.Print();
}

// Creates Rational Number with numerator and denominator.
RationalNumber createRationalNumber(int numerator, int denominator)
{
	RationalNumber rationalNumber = RationalNumber();
	rationalNumber.setNumerator(numerator);
	rationalNumber.setDenominator(denominator);

	return rationalNumber;
}

// Divides the 2 given Rational Numbers and returns result as Rational Number.
RationalNumber divideRationalNumbers(RationalNumber firstNum, RationalNumber secondNum)
{
	RationalNumber resultNum = RationalNumber();
	int firstNumNumerator = firstNum.getNumerator();
	int firstNumDenominator = firstNum.getDenominator();
	int secondNumNumerator = secondNum.getNumerator();
	int secondNumDenominator = secondNum.getDenominator();

	resultNum.setNumerator(firstNumNumerator * secondNumDenominator);
	resultNum.setDenominator(firstNumDenominator * secondNumNumerator);

	return resultNum;
}

// Multiplies the 2 given Rational Numbers and returns result as Rational Number.
RationalNumber multiplyRationalNumbers(RationalNumber firstNum, RationalNumber secondNum)
{
	RationalNumber resultNum = RationalNumber();
	int firstNumNumerator = firstNum.getNumerator();
	int firstNumDenominator = firstNum.getDenominator();
	int secondNumNumerator = secondNum.getNumerator();
	int secondNumDenominator = secondNum.getDenominator();

	resultNum.setNumerator(firstNumNumerator * secondNumNumerator);
	resultNum.setDenominator(firstNumDenominator * secondNumDenominator);

	return resultNum;
}

int getResultDenominator(
	int& firstNumNumerator,
	int& secondNumNumerator,
	int firstNumDenominator,
	int secondNumDenominator);

// Subtracts the 2 given Rational Numbers and returns result as Rational Number.
RationalNumber subtractRationalNumbers(RationalNumber firstNum, RationalNumber secondNum)
{
	RationalNumber resultNum = RationalNumber();
	int firstNumNumerator = firstNum.getNumerator();
	int firstNumDenominator = firstNum.getDenominator();
	int secondNumNumerator = secondNum.getNumerator();
	int secondNumDenominator = secondNum.getDenominator();

	int resultNumDenominator = getResultDenominator(
		firstNumNumerator,
		secondNumNumerator,
		firstNumDenominator,
		secondNumDenominator);

	// Always substract the 2 nums numerators (includes when equal denominators).
	resultNum.setNumerator(firstNumNumerator - secondNumNumerator);
	resultNum.setDenominator(resultNumDenominator);

	return resultNum;
}

// Sums the 2 given Rational Numbers and returns result as Rational Number.
RationalNumber sumRationalNumbers(RationalNumber firstNum, RationalNumber secondNum)
{
	RationalNumber resultNum = RationalNumber();
	int firstNumNumerator = firstNum.getNumerator();
	int firstNumDenominator = firstNum.getDenominator();
	int secondNumNumerator = secondNum.getNumerator();
	int secondNumDenominator = secondNum.getDenominator();


	int resultNumDenominator = getResultDenominator(
		firstNumNumerator,
		secondNumNumerator,
		firstNumDenominator,
		secondNumDenominator);

	// Always sum the 2 nums numerators (includes when equal denominators).
	resultNum.setNumerator(firstNumNumerator + secondNumNumerator);
	resultNum.setDenominator(resultNumDenominator);

	return resultNum;
}

// Find bigger denominator, while adds the absolute difference between the 2 num denominators to the lower one's numinator.
// Can be used for both Sum and Substract.
// TODO: Maybe needs refactoring?
// TODO2: Remember how to properly do sum and substract of rational numbers!!
int getResultDenominator(
	int& firstNumNumerator,
	int& secondNumNumerator,
	int firstNumDenominator,
	int secondNumDenominator)
{
	int difference, resultNumDenominator;

	if (firstNumDenominator > secondNumDenominator)
	{
		// When first num denominator is bigger, adds the absolute difference between the 2 denominators to the second numinator.
		difference = firstNumDenominator - secondNumDenominator;
		secondNumNumerator += difference;
		resultNumDenominator = firstNumDenominator;
	}
	else if (firstNumDenominator < secondNumDenominator)
	{
		// When second num denominator is bigger, adds the absolute difference between the 2 denominators to the second numinator.
		difference = secondNumDenominator - firstNumDenominator;
		firstNumNumerator += difference;
		resultNumDenominator = secondNumDenominator;
	}

	return resultNumDenominator;
}