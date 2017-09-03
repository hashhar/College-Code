#include<iostream>

#define MAX 20

using namespace std;

class ProcessInfo
{
public:
	int pid;
	int bt;
	int at;
	int t;
	int tbt;

	int wt;
	int tat;
};

int main()
{
	ProcessInfo p[MAX];
	int n, quanta = 1, totalTime;
	float avgWT = 0.0, avgTAT = 0.0;
	cout << "Enter the number of processes: ";
	cin >> n;
	cout << "Enter the value of the time quantum: ";
	cin >> quanta;
	for (int i = 0; i < n; i++)
	{
		p[i].pid = i;

		cout << "Burst Time for P[" << i << "]: ";
		cin >> p[i].bt;
		p[i].tbt = p[i].bt;
		p[i].wt = p[i].tat = p[i].t = 0;
		cout << "Arrival Time for P[" << i << "]: ";
		cin >> p[i].at;
	}
	//Sort in order of at time
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (p[j].at > p[j + 1].at)
			{
				ProcessInfo temp;
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	totalTime = 0;
	for (int i = 0; i < n; i++)
	{
		totalTime += p[i].bt;
	}
	int rrg[99];
	for (int i = 0, j = 0, k = 0; j < totalTime; j++)
	{
		if (k == 0 && p[i].bt != 0)
		{
			p[i].wt = j;
			if (p[i].t != 0)
			{
				p[i].wt -= quanta*p[i].t;
			}
		}
		if (p[i].bt != 0 && k != quanta)
		{
			rrg[j] = p[i].pid;
			p[i].bt -= 1;
			k++;
		}
		else
		{
			if (k == quanta && p[i].bt != 0)
			{
				p[i].t += 1;
			}
			i = i + 1;
			if (i == n)
			{
				i = 0;
			}
			k = 0;
			j = j - 1;
		}
	}
	cout << endl;
	for (int j = 0; j < totalTime; j++)
	{
		cout << " | " << rrg[j];
	}
	cout << endl;
	int twt = 0;
	int ttt = 0;
	cout << endl << "PID\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
	for (int i = 0; i < n; i++)
	{
		p[i].tat = p[i].wt + p[i].bt;
		ttt += p[i].tat;
		twt += p[i].wt;
		cout << endl << p[i].pid << "\t\t" << p[i].bt << "\t\t" << p[i].wt << "\t\t" << p[i].tat;
	}
	cout << endl << "Average Waiting Time: " << float(twt) / n;
	cout << endl << "Average Turn Around Time: " << float(ttt) / n;
}
