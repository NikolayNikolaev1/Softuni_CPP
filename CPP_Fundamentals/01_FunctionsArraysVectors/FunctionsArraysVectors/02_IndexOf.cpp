#include <iostream>
#include <vector>

using namespace std;

vector<int> createArray(int size);
int indexOfElement(vector<int> array, int element);

void indexOf()
{
	int arraySize, element;

	cout << "Enter array size: ";
	cin >> arraySize;

	vector<int> array = createArray(arraySize);

	cout << "Enter element of the array: ";
	cin >> element;

	cout << indexOfElement(array, element);
}

// Creates vector array with given size.
vector<int> createArray(int size)
{
	vector<int> array;

	cout << "Enter array elements: ";

	for (int i = 0; i < size; i++)
	{
		int arrayElement;
		cin >> arrayElement;

		array.push_back(arrayElement);
	}

	return array;
}

// Finds the index of element in array, returns -1 if the number does not appear.
int indexOfElement(vector<int> array, int element)
{
	int index = 0;
	for (int currentElement : array)
	{
		if (element == currentElement)
		{
			return index;
		}

		index++;
	}

	return -1;
}