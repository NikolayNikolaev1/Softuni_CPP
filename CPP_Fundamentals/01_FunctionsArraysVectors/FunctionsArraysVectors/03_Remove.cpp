#include <iostream>
#include <vector>

using namespace std;

vector<int> createArray2(int size);
void printArrayElements(vector<int> array);
vector<int> removeElement(vector<int> array, int element);

void remove()
{
	int arraySize, element;

	cout << "Enter array size: ";
	cin >> arraySize;

	vector<int> array = createArray2(arraySize);

	cout << "Enter element to remove: ";
	cin >> element;

	array = removeElement(array, element);

	printArrayElements(array);
}

// Creates vector array with given size.
vector<int> createArray2(int size)
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

// Print array elements separated by space.
void printArrayElements(vector<int> array)
{
	for (int currentElement : array)
	{
		cout << currentElement << " ";
	}

	cout << endl;
}

// Creates new vector array from elements of the given array in parameters, without the element given in the parameters.
vector<int> removeElement(vector<int> array, int element)
{
	vector<int> newArray;

	for (int currentElement : array)
	{
		if (currentElement != element)
		{
			newArray.push_back(currentElement);
		}
	}

	return newArray;
}