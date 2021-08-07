#include <iostream>
#include <vector>

using namespace std;

vector<int> createArray(int size);
bool hasEqualAdjacentNumbers(vector<int> arr);
void printArray(vector<int> arr);
vector<int> sumAdjecentEqualNumbers(vector<int> arr);

// TODO: Fix bugs around suming the wrong way.
int main()
{
	int arrSize;

	cout << "Enter array size: ";
	cin >> arrSize;

	vector<int> arr = createArray(arrSize);

	while (hasEqualAdjacentNumbers(arr))
	{
		// Sum equal adjacent numbers in the array, while there are any.
		arr = sumAdjecentEqualNumbers(arr);
	}

	printArray(arr);

	return 0;
}

vector<int> createArray(int size)
{
	vector<int> arr;
	int number;

	cout << "Enter numbers for the array: ";

	for (int i = 0; i < size; i++)
	{
		cin >> number;
		arr.push_back(number);
	}

	return arr;
}

bool hasEqualAdjacentNumbers(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (i == 0)
		{
			// Skip the first element to avoid out of bound exception.
			continue;
		}

		if (arr[i] == arr[i - 1])
		{
			// Returns true if 2 adjacent numbers are equal.
			return true;
		}
	}

	// Returns false if there are not equal adhacent numbers.
	return false;
}

void printArray(vector<int> arr)
{
	for (int currentNum : arr)
	{
		cout << currentNum << " ";
	}
}


vector<int> sumAdjecentEqualNumbers(vector<int> arr)
{
	vector<int> newArr;
	int leftNum;

	for (int i = 0; i < arr.size(); i++)
	{
		// Push first element from old array.
		if (i == 0)
		{
			newArr.push_back(arr[i]);
			continue;
		}
		// If 2 elements are equal, remove the last added element and add the sum of the equal elements.
		if (arr[i] == arr[i - 1])
		{
			newArr.pop_back();
			newArr.push_back(arr[i] + arr[i - 1]);
		}
		else
		{
			// Push the current element to the new array.
			newArr.push_back(arr[i]);
		}
	}

	return newArr;
}
