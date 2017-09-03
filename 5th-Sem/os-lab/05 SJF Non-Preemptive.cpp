#include<iostream>

#define MAX 100

using namespace std;

int main()
{
	int n;
	cout << "Enter the number of processes: ";
	cin >> n;
	float total, wait[MAX];
	float p[MAX], twaiting = 0, waiting = 0;
	int proc;
	int stack[MAX];
	float brust[MAX], arrival[MAX], sbrust = 0, temp[MAX], top = n;

	for (int i = 0; i < n; i++)
	{
		p[i] = i;
		stack[i] = i;
		cout << "Enter arrival time: ";
		cin >> arrival[i];
		cout << endl << "Enter burst time: ";
		cin >> brust[i];
		temp[i] = arrival[i];
		sbrust = brust[i] + sbrust;
	}
	for (int i = 0; i < sbrust; i++)
	{
		proc = stack[0];
		if (temp[proc] == i)
		{
			//temp[proc]=i+1;;
			twaiting = 0;
		}
		else
		{
			twaiting = i - temp[proc];
		}
		temp[proc] = i + 1;
		wait[proc] = wait[proc] + twaiting;
		waiting = waiting + twaiting;
		brust[proc] = brust[proc] - 1;
		if (brust[proc] == 0)
		{
			for (int x = 0; x < top - 1; x++)
			{
				stack[x] = stack[x + 1];
			}
			top = top - 1;
			for (int z = 0; z<top - 1; z++)
			{
				if (brust[stack[0]]>brust[stack[z + 1]] && arrival[stack[z + 1]] <= i + 1)
				{
					int t = stack[0];
					stack[0] = stack[z + 1];
					stack[z + 1] = t;
				}
			}
		}
	}
	cout << "Waiting:" << waiting;
}