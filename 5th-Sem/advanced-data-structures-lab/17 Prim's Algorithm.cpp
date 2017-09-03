/* Implement Prim's algorithm to find the MST of a graph */
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int i, j, k, n, x, u = 0, v = 0, small, smallest, pos = 0, total = 0;
	int weight[10][10], visited[10], parent[10];
	/*
		n is the number of vertices in the graph
		parent is the constructed MST
	*/
	// Open the file containing the adjacency matrix
	FILE* f;
	f = fopen("vertex.txt", "r+");
	fscanf(f, "%d", &n);
	// Read all the weights
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			fscanf(f, "%d", &weight[i][j]);
	// Print the weight matrix
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			cout << " " << weight[i][j] << "\t";
		cout << endl;
	}
	/*
		Algorithm:
		Mark all nodes as unvisited and assign infinite weights to each vertex
		Select the first vertex
		While there are elements not yet selected in the MST, do:
			Pick an unvisited vertex not yet in the MST and,
			which has the shortest edge joining it to a vertex in the MST
			For all the neighbours of the vertex:
				Update the minimum edge length with the value
				of the edge length of the vertex selected earlier
			Add the picked vertex to the MST
	*/
	// Set all vertices as unvisited and the MST as empty
	for (i = 1; i <= n; i++)
	{
		parent[i] = -1;
		visited[i] = 0;
	}
	// Pick the first vertex
	x = 1;
	parent[x] = 1;
	visited[x] = 1;
	// Repeat over all remaining vertices
	for (i = 2; i <= n; i++)
	{
		k = 1;
		// The weight of the shortest edge between a vertex in the MST
		// and an unselected vertex
		smallest = 9999;
		// For all vertices cuurently in the MST
		while (parent[k] != -1)
		{
			// The weight of the vertex nearest to a vertex in the MST
			// in a given row
			small = 999;
			for (j = 1; j <= n; j++)
			{
				// Find vertex nearest (with minimum edge weight) to k
				if (weight[k][j] > 0 && visited[j] == 0 && weight[k][j] < small)
				{
					small = weight[k][j];
					pos = j;
					u = parent[k];
				}
			}
			// If the previously decided minimum weight has been beaten
			// update the global minimum
			if (small <= smallest)
			{
				smallest = small;
				v = pos;
			}
			k++;
		}
		// If we reach here means we have found the shortest edge between
		// a vertex in the MST and an unselected vertex
		// Update the cost of the MST, add the chosen vertex to the MST
		// and mark it as visited
		total += smallest;
		parent[x++] = v;
		visited[v] = 1;
		cout << "\nEdge from " << char(u + 'a' - 1) << "->" << char(v + 'a' - 1) << endl;
	}
	cout << "\n Weight of the Minimum Spanning Tree : " << total;
}

