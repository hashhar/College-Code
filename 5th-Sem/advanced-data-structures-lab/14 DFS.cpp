/* Implement DFS */
#include <iostream>
#include <fstream>

using namespace std;

struct node
{
	int info;
	struct node* next;
};

class stack
{
	struct node* top;
public:
	stack()
	{
		top = nullptr;
	}

	void push(int);
	int pop();

	bool isEmpty()
	{
		return (top == nullptr);
	}

	void display();
};

void stack::push(int data)
{
	node* p;
	if ((p = new node) == nullptr)
	{
		cout << "Memory Exhausted";
		exit(0);
	}
	p = new node;
	p->info = data;
	p->next = nullptr;
	if (top != nullptr)
		p->next = top;
	top = p;
}

int stack::pop()
{
	struct node* temp;
	int value;
	if (top == nullptr)
	{
		cout << "\nThe stack is Empty" << endl;
		return -1;
	}
	temp = top;
	top = top->next;
	value = temp->info;
	delete temp;
	return value;
}

void stack::display()
{
	struct node* p = top;
	if (top == nullptr)
		cout << "\nNothing to Display\n";
	else
	{
		cout << "\nThe contents of Stack\n";
		while (p != nullptr)
		{
			cout << p->info << endl;
			p = p->next;
		}
	}
}

class Graph
{
	int n;
	int** A;
public:
	Graph(int size = 2);
	~Graph();

	bool isConnected(int x, int y)
	{
		return (A[x - 1][y - 1] == 1);
	}

	void addEdge(int x, int y)
	{
		A[x - 1][y - 1] = A[y - 1][x - 1] = 1;
	}

	void DFS(int, int);
};

Graph::Graph(int size)
{
	int i, j;
	if (size < 2)
		n = 2;
	else
		n = size;
	A = new int*[n];
	for (i = 0; i < n; ++i)
		A[i] = new int[n];
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			A[i][j] = 0;
}

Graph::~Graph()
{
	for (int i = 0; i < n; ++i)
		delete[] A[i];
	delete[] A;
}

void Graph::DFS(int x, int required)
{
	stack s;
	// Boolean array to track visited nodes
	bool* visited = new bool[n + 1];
	int i;
	// Mark all as unvisited
	for (i = 0; i <= n; i++)
		visited[i] = false;
	s.push(x);
	visited[x] = true;
	if (x == required)
		return;
	cout << "Depth first Search starting from vertex ";
	cout << x << " : " << endl;
	while (!s.isEmpty())
	{
		int k = s.pop();
		if (k == required)
			break;
		cout << k << " ";
		for (i = n; i >= 0; --i)
			if (isConnected(k, i) && !visited[i])
			{
				s.push(i);
				visited[i] = true;
			}
	}
	cout << endl;
	delete[] visited;
}

int main()
{
	FILE* inFile;
	fopen_s(&inFile, "vertex.txt", "r+");
	int size, matrix[20][20];
	fscanf_s(inFile, "%d", &size);
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			fscanf_s(inFile, "%d", &matrix[i][j]);
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	Graph g(size);
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
			if (matrix[i][j] != 0)
				g.addEdge(i, j);
	cout << "Enter the starting node: ";
	int source;
	cin >> source;
	cout << "Enter the destination node: ";
	int dest;
	cin >> dest;
	cout << endl << endl;
	g.DFS(source, dest);
}

