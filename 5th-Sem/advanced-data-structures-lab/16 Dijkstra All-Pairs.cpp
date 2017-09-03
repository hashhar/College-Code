/* Find the shortest path between a given vertex and
all other vertices in a graph */
#include <iostream>
#define PERM 1
#define TEMP 0
#define INF INT_MAX

using namespace std;

struct node
{
	int pre;
	int dist;
	bool status;
};

int dijkstra(int s, int d, int path[], int weight[][10], int* len, int n)
{
	// s is the source, d is the destination
	// path will store the shortest path, len will give the length of the path
	struct node node[10];
	int i, current, min, u, v, count = 0, newdist;
	*len = 0;
	// Set all vertices' status to temporary and assign infinite weights
	for (i = 1; i <= n; i++)
	{
		node[i].pre = 0;
		node[i].status = TEMP;
		node[i].dist = INF;
	}
	// Force the first vertex to be selected
	node[s].pre = 0;
	node[s].dist = 0;
	node[s].status = PERM;
	current = s;
	// Until we reach the destination node, keep repeating
	while (current != d)
	{
		for (i = 1; i <= n; i++)
		{
			// For all unvisited vertices find the tentative distance and
			// assign whichever is smaller among the tentative distance and
			// the currently assigned distance
			if (weight[current][i] > 0 && node[i].status == TEMP)
			{
				newdist = node[current].dist + weight[current][i];
				if (newdist < node[i].dist)
				{
					node[i].dist = newdist;
					node[i].pre = current;
				}
			}
		}
		current = 0;
		min = INF;
		// Select the unvisited vertex with the smallest tentative distance
		// Mark it as the current vertex
		for (i = 1; i <= n; i++)
		{
			if (node[i].status == TEMP && node[i].dist < min)
			{
				min = node[i].dist;
				current = i;
			}
		}
		// If there is no such vertex, the algorithm was unable to find a path
		if (current == 0)
			return 0;
		// Mark the selected vertex as visited
		node[current].status = PERM;
	}
	// Populate the path matrix and the count of elements in path
	while (current != 0)
	{
		count++;
		path[count] = current;
		current = node[current].pre;
	}
	// Find the path length by traversing in reverse order
	for (i = count; i > 1; i--)
	{
		u = path[i];
		v = path[i - 1];
		*len += weight[u][v];
	}
	// Return the number of elements in the path matrix
	return count;
}

int main()
{
	int i, j, n, weight[10][10], s, d, len, count, path[20];
	char ch1;
	// Open the file containing the adjacency matrix
	FILE* f;
	fopen_s(&f, "vertex.txt", "r+");
	fscanf_s(f, "%d", &n);
	// Read the weights from the file
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			fscanf_s(f, "%d", &weight[i][j]);
	}
	// Print the adjacency matrix
	cout << "\nWeight Matrix:" << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			cout << " " << weight[i][j] << "\t";
		cout << endl;
	}
	// Ask for the source node
	cout << "\nEnter the source node: ";
	cin >> ch1;
	// Convert the entered character into it corresponding alphabet
	s = ch1 - 'a' + 1;
	// Run the algorithm over the set of all possible destination vertices
	for (int c = 1; c <= n; c++)
	{
		d = c;
		count = dijkstra(s, d, path, weight, &len, n);
		// If the path exists, print it out
		if (len > 0)
		{
			cout << "\n\nShortest Path between " << char(s + 'a' - 1)
				<< " (SOURCE) and " << char(d + 'a' - 1)
				<< " (DESTINATION) is: ";
			for (i = count; i >= 1; i--)
				cout << char(path[i] + 'a' - 1);
			cout << "\n\nLength of the shortest path is: " << len;
		}
		else
			cout << "\n\nNo Path exists between the nodes "
			<< char(s + 'a' - 1) << " and " << char(d + 'a' - 1);
	}
}

