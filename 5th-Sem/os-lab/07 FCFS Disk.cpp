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
	int temp, len = 0, i, j;
	for (i = 0; i < n; i++)
	{
		cout << "Enter value for queue:";
		cin >> queue[i];

	}
	int prev = head;
	for (i = 0; i < n; i++)
	{
		temp = abs(prev - queue[i]);
		len = len + prev;
		prev = queue[i];
	}
	cout << endl << "Total ::";
	cout << len;
	return 0;
}