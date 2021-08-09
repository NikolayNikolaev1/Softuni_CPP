#include <iostream>

using namespace std;

void triplesOfLatinLetters()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cout << (char)(97 + i) << (char)(97 + j) << (char)(97 + k) << endl;
			}
		}
	}
}