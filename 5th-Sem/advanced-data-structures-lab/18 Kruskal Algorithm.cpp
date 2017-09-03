#include <iostream>

using namespace std;

int main()
{
	int i, j, k, n, visit, l, v, count = 0, count1, vst, p;
	int weight[10][10], visited[10];
	int dup1, dup2;
	FILE* f;
	fopen_s(&f, "vertex.txt", "r+");
	fscanf_s(f, "%d", &n);
	// Read all the weights
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			fscanf_s(f, "%d", &weight[i][j]);
	// Print the weight matrix
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			cout << " " << weight[i][j] << "\t";
		cout << endl;
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (weight[i][j] == 0)
				weight[i][j] = INT_MAX;
	visit = 1;
	while (visit < n)
	{
		v = INT_MAX;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (weight[i][j] != INT_MAX && weight[i][j] < v
					&& weight[i][j] != -1)
				{
					int count = 0;
					for (p = 1; p <= n; p++)
					{
						if (visited[p] == i || visited[p] == j)
							count++;
					}
					if (count >= 2)
					{
						for (p = 1; p <= n; p++)
							if (weight[i][p] != INT_MAX && p != j)
								dup1 = p;
						for (p = 1; p <= n; p++)
							if (weight[j][p] != INT_MAX && p != i)
								dup2 = p;

						if (weight[dup1][dup2] == -1)
							continue;
					}
					l = i;
					k = j;
					v = weight[i][j];
				}
		cout << endl;
		cout << "Edge from " << char(l + 'a' - 1) << "->" << char(k + 'a' - 1)
			<< endl;
		weight[l][k] = -1;
		weight[k][l] = -1;
		visit++;
		count1 = 0;
		for (i = 1; i <= n; i++)
		{
			if (visited[i] == l)
				count++;
			if (visited[i] == k)
				count1++;
		}
		if (count == 0)
			visited[++vst] = l;
		if (count1 == 0)
			visited[++vst] = k;
	}
}

