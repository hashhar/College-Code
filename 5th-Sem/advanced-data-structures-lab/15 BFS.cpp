/* Implement BFS */
#include <iostream>
#include <ctime>

using namespace std;

struct node
{
	int info;
	node* next;
};

class Queue
{
	node* front;
	node* rear;
public:
	Queue()
	{
		front = nullptr;
		rear = nullptr;
	}

	~Queue()
	{
		delete front;
	}

	bool isEmpty()
	{
		return (front == nullptr);
	}

	void push(int);
	int pop();
	void display();
};

void Queue::display()
{
	node* p = new node;
	p = front;
	if (front == nullptr)
	{
		cout << "\nNothing to Display\n";
	}
	else
	{
		while (p != nullptr)
		{
			cout << endl << p->info;
			p = p->next;
		}
	}
}

void Queue::push(int data)
{
	node* temp = new node();
	temp->info = data;
	temp->next = nullptr;
	if (front == nullptr)
		front = temp;
	else
		rear->next = temp;
	rear = temp;
}

int Queue::pop()
{
	node* temp = new node();
	int value;
	if (front == nullptr)
	{
		cout << "\nQueue is Emtpty!" << endl;
		return -1;
	}
	temp = front;
	value = temp->info;
	front = front->next;
	delete temp;
	return value;
}

class Graph
{
	int n;
	int** A;
public:
	Graph(int size = 2);
	~Graph();

	bool isConnected(int u, int v)
	{
		return (A[u - 1][v - 1] == 1);
	}

	void addEdge(int u, int v)
	{
		A[u - 1][v - 1] = A[v - 1][u - 1] = 1;
	}

	void BFS(int);
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

void Graph::BFS(int s)
{
	Queue Q;
	// Keeps track of visited vertices
	bool* explored = new bool[n + 1];
	// Initialise all vertices as unexplored
	for (int i = 1; i <= n; ++i)
		explored[i] = false;

	// Push initial vertex to the queue
	Q.push(s);
	explored[s] = true;
	cout << "Breadth first search starting from vertex ";
	cout << s << " : " << endl;

	while (!Q.isEmpty())
	{
		int v = Q.pop();
		// Display the explored vertices
		cout << v << " ";
		// From the explored vertex v try to explore all the connected vertices
		for (int w = 1; w <= n; ++w)
			// Explore the vertex w if it is connected to v and if it is unexplored
			if (isConnected(v, w) && !explored[w])
			{
				Q.push(w);
				explored[w] = true;
			}
	}
	cout << endl;
	delete[] explored;
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
	/*cout << "Enter the destination node: ";
	int dest;
	cin >> dest;*/
	cout << endl << endl;
	// Explores all vertices findable from the source
	g.BFS(source);
}

