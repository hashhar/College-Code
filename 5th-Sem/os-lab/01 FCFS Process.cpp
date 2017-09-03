#include <iostream>

#define MAX 20

using namespace std;

class ProcessInfo
{
public:
	int pid;
	int bt;
	int at;

	int wt;
	int tat;
};

int main()
{
	ProcessInfo p[MAX];
	int n;
	float avgWT = 0.0, avgTAT = 0.0;
	cout << "Enter the number of processes: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p[i].pid = i;

		cout << "Burst Time for P[" << i << "]: ";
		cin >> p[i].bt;

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
	cout << endl << "PID\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
	p[0].wt = 0;
	//Calculate the waiting time
	for (int i = 0; i < n; i++)
	{
		p[i].wt = 0;
		for (int j = 0; j < i; j++)
		{
			p[i].wt += p[j].bt;
		}
	}
	//Calculate the turnaround time
	for (int i = 0; i < n; i++)
	{
		p[i].tat = p[i].bt + p[i].wt;
		avgWT += p[i].wt;
		avgTAT += p[i].tat;
		//Print the results
		cout << endl << "P[" << i + 1 << "]" << "\t\t" << p[i].bt << "\t\t" << p[i].wt << "\t\t" << p[i].tat << endl;
	}
	avgWT /= n;
	avgTAT /= n;
	cout << endl << "Average Waiting Time: " << avgWT;
	cout << endl << "Average Turnaround Time: " << avgTAT;
}
