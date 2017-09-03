#include <iostream>

using namespace std;

const int MAX = 10;

class Heap
{
	int arr[MAX];
	int count;
public:
	Heap()
	{
		count = 0;
		for (int i = 0; i < MAX; i++)
			arr[MAX] = 0;
	}

	void Add(int num);
	void MakeHeap(int);
	void HeapSort();
	void Display();
};

void Heap::Add(int num)
{
	if (count < MAX)
	{
		arr[count] = num;
		count++;
	}
	else
		cout << endl << "Array is full!" << endl;
}

void Heap::MakeHeap(int c)
{
	for (int i = 1; i < c; i++)
	{
		int val = arr[i];
		int s = i;
		int f = (s - 1) / 2;
		while (s > 0 && arr[f] < val)
		{
			arr[s] = arr[f];
			s = f;
			f = (s - 1) / 2;
		}
		arr[s] = val;
	}
}

void Heap::HeapSort()
{
	for (int i = count - 1; i > 0; i--)
	{
		int ivalue = arr[i];
		arr[i] = arr[0];
		arr[0] = ivalue;
		MakeHeap(i);
	}
}

void Heap::Display()
{
	for (int i = 0; i < count; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

int main()
{
	Heap arr;
	int size;
	cout << "Enter the size of the heap: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		int elem;
		cout << "Enter " << i + 1 << "th element: ";
		cin >> elem;
		arr.Add(elem);
	}
	arr.MakeHeap(size);
	cout << endl << "Heap Sort:" << endl;
	cout << endl << "Before Sorting:" << endl;
	arr.Display();
	arr.HeapSort();
	cout << endl << "After Sorting:" << endl;
	arr.Display();
}

