#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n;
	cout << "Enter your queue size:";
	cin >> n;
	int ub, lb = 0;
	cout << "Enter your upper bound:";
	cin >> ub;
	int queue[30];
	int head;
	cout << "Enter your head:";
	cin >> head;
	int minindex;
	int temp, len = 0, i, j, rem[3], prev = ub, current = 0, qsize = n, rsize = n;
	for (i = 0; i < n; i++)
	{
		cout << "Enter value for queue:";
		cin >> queue[i];
		rem[i] = i;
	}
	current = head;
	for (i = 0; i < n; i++)
	{
		prev = ub;
		minindex = 0;
		for (j = 0; j < rsize; j++)
		{
			temp = abs(current - queue[rem[j]]);
			if (temp < prev)
			{
				minindex = j;
				prev = temp;
			}
		}
		len = len + prev;
		cout << endl << len << endl;
		current = queue[rem[minindex]];
		for (j = minindex; j < rsize - 1; j++)
		{
			rem[j] = rem[j + 1];
		}
		rsize = rsize - 1;
	}
	cout << endl << "Total ::";
	cout << len;
}