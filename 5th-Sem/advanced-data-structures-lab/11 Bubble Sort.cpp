/* Implement Bubble Sort */
#include <iostream>

using namespace std;

int main()
{
	cout << "Enter the number of elements in the array: ";
	int n;
	cin >> n;
	int array[50];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the " << i + 1 << "th element: ";
		cin >> array[i];
	}
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				int temp = array[y + 1];
				array[y + 1] = array[y];
				array[y] = temp;
			}
		}
	}
	cout << "The Sorted Array is:" << endl;
	for (int i = 0; i < n; i++)
		cout << " " << array[i] << " ";
}

