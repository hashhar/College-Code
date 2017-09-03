/* Implement Merge Sort */
#include <iostream>

using namespace std;

int max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

// Left is the index of the leftmost element of the subarray.
// Right is one past the index of the rightmost element
void merge(int* input, int left, int right, int* scratch)
{
	// The non-base case, if anything other than this, it must be the base case
	// And in that case we will just return
	if (right != left + 1)
	{
		int i = 0;
		int length = right - left;
		int midpoint_distance = length / 2;
		int l = left, r = left + midpoint_distance;

		// Sort each subarray
		merge(input, left, left + midpoint_distance, scratch);
		merge(input, left + midpoint_distance, right, scratch);

		// Merge the arrays together using scratch for temporary storage
		for (i = 0; i < length; i++)
		{
			// Check to see if any elements remain in the left array
			// If so, we check if there are elements left in the right array
			// If so, we compare them. Otherwise, we know that the merge must
			// use the element from the left array
			if (l < left + midpoint_distance &&
				(r == right || max(input[l], input[r]) == input[l]))
			{
				scratch[i] = input[l];
				l++;
			}
			else
			{
				scratch[i] = input[r];
				r++;
			}
		}
		// Copy the sorted subarray back to the input
		for (i = left; i < right; i++)
			input[i] = scratch[i - left];
	}
}

bool mergesort(int* input, int size)
{
	int* scratch = new int;
	// (int *)malloc(size * sizeof(int));
	if (scratch != nullptr)
	{
		merge(input, 0, size, scratch);
		free(scratch);
		return true;
	}
	return false;
}

int main()
{
	int array[100], n;
	cout << "Enter the size of the array: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the " << i + 1 << "th element: ";
		cin >> array[i];
	}
	if (mergesort(array, n))
	{
		cout << "The sorted array is:" << endl;
		for (int i = 0; i < n; i++)
			cout << " " << array[i] << " ";
	}
	else
		cout << "The sorting failed!" << endl;
}

