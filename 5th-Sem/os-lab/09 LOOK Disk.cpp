#include<iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter your queue size:";
	cin >> n;
	int ub, lb = 0;
	cout << "Enter your upper bound:";
	cin >> ub;
	int queue[3];
	int head;
	cout << "Enter your head:";
	cin >> head;
	int minindex;
	int temp, len = 0, i, j, lrem[5], t;
	int rrem[5], prev = ub, current = 0, qsize = n, lrsize = 0, rrsize = 0;
	for (i = 0; i < n; i++)
	{
		cout << "Enter value for queue:";
		cin >> queue[i];
		if (queue[i] > head)
		{
			rrem[rrsize] = i;
			rrsize = rrsize + 1;
		}
		else
		{
			lrem[lrsize] = i;
			lrsize = lrsize + 1;
		}
	}
	//sorting of both lrem & rrem
	for (i = 0; i < lrsize - 1; i++)
	{
		for (j = i; j<lrsize; j++)
		{
			if (queue[lrem[i]] > queue[lrem[j]])
			{
				t = lrem[i];
				lrem[i] = lrem[j];
				lrem[j] = t;
			}
		}
	}
	for (i = 0; i < rrsize - 1; i++)
	{
		for (j = i; j<rrsize; j++)
		{
			if (queue[rrem[i]] > queue[rrem[j]])
			{
				t = rrem[i];
				rrem[i] = rrem[j];
				rrem[j] = t;
			}
		}
	}
	int vr, val;
	current = head;
	val = current - queue[rrem[rrsize - 1]];
	vr = queue[rrem[rrsize - 1]] - queue[lrem[0]];

	len = val + vr;
	cout << "Head movement: ";
	cout << len;
}
