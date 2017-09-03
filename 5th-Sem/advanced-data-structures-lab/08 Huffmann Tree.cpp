#include <iostream>
#include <string>
#include <fstream>
#include <array>

// Maximum height of the Huffman Tree
#define MAX_TREE_HT 100

using namespace std;

class Huffman
{
public:
	// A Huffman Tree node
	struct minHeapNode
	{
		char data;
		int freq;
		minHeapNode* left;
		minHeapNode* right;
	};

	// The Huffman Tree itself
	struct minHeap
	{
		int current_size;
		int capacity;
		minHeapNode** array; // Array of minHeap node pointers
	};

	// Allocate a new minHeap node with passed character and freq
	minHeapNode* newNode(unsigned char, int);
	// Create a minHeap of passed capacity
	minHeap* create(int);
	// Swap two minHeap nodes
	void swapNode(minHeapNode**, minHeapNode**);
	// Heapify
	void heapify(minHeap*, int);

	// Returns true if current size of minHeap is 1
	bool isSizeOne(minHeap* min_heap)
	{
		if (min_heap->current_size == 1)
			return true;
		return false;
	}

	// Find minimum node
	minHeapNode* getMin(minHeap*);
	// Insert a new node in the minHeap
	void insert(minHeap*, minHeapNode*);
	// Build a minHeap
	void build(minHeap*);

	// Return true if it a leaf
	bool isLeaf(minHeapNode* root)
	{
		if (!root->left && !root->right)
			return true;
		return false;
	}

	// Creates a minHeap of capacity equal to size and insert all character of
	// data[] in minHeap. Initially size of minHeap is equal to capacity.
	minHeap* generate(unsigned char[], int[], int);
	// The main function that builds Huffman tree
	minHeapNode* buildHuffmanTree(unsigned char[], int[], int);
	// Print the huffman coded input
	void printCodes(minHeapNode*, int[], int);
	// Builds a Huffman Tree and print codes by traversing it
	void huffmanCodes(unsigned char[], int[], int);
};

Huffman::minHeapNode* Huffman::newNode(unsigned char data, int freq)
{
	// Initialise a node with the passed parameters
	minHeapNode* new_node = new minHeapNode;
	new_node->left = new_node->right = nullptr;
	new_node->data = data;
	new_node->freq = freq;
	return new_node;
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

Huffman::minHeap* Huffman::create(int capacity)
{
	minHeap* min_heap = new minHeap;
	min_heap->current_size = 0; // current size is 0
	min_heap->capacity = capacity;
	min_heap->array = new minHeapNode*;
	// (minHeapNode**)malloc(min_heap->capacity * sizeof(minHeapNode*));
	return min_heap;
}

void Huffman::swapNode(minHeapNode** a, minHeapNode** b)
{
	minHeapNode* t = *a;
	*a = *b;
	*b = t;
}

void Huffman::heapify(minHeap* minHeap, int idx)
{
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;
	// The standard heapify algorithm
	if (left < minHeap->current_size &&
		minHeap->array[left]->freq < minHeap->array[smallest]->freq)
		smallest = left;

	if (right < minHeap->current_size &&
		minHeap->array[right]->freq < minHeap->array[smallest]->freq)
		smallest = right;

	if (smallest != idx)
	{
		swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
		heapify(minHeap, smallest);
	}
}

Huffman::minHeapNode* Huffman::getMin(minHeap* min_heap)
{
	minHeapNode* minimum = min_heap->array[0];
	min_heap->array[0] = min_heap->array[min_heap->current_size - 1];
	min_heap->current_size--;
	heapify(min_heap, 0);
	return minimum;
}

void Huffman::insert(minHeap* min_heap, minHeapNode* min_heapNode)
{
	++min_heap->current_size;
	int i = min_heap->current_size - 1;
	while (i && min_heapNode->freq < min_heap->array[(i - 1) / 2]->freq)
	{
		min_heap->array[i] = min_heap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	min_heap->array[i] = min_heapNode;
}

void Huffman::build(minHeap* min_heap)
{
	int n = min_heap->current_size - 1;
	for (int i = (n - 1) / 2; i >= 0; --i)
		heapify(min_heap, i);
}

Huffman::minHeap* Huffman::generate(unsigned char data[], int freq[], int size)
{
	minHeap* min_heap = create(size);
	for (int i = 0; i < size; ++i)
		min_heap->array[i] = newNode(data[i], freq[i]);
	min_heap->current_size = size;
	build(min_heap);
	return min_heap;
}

Huffman::minHeapNode* Huffman::buildHuffmanTree(unsigned char data[], int freq[], int size)
{
	minHeapNode *left, *right, *top;

	// Create a min heap of capacity equal to size.  Initially, there are
	// modes equal to size.
	minHeap* minHeap = generate(data, freq, size);

	// Iterate while size of heap doesn't become 1
	while (!isSizeOne(minHeap))
	{
		// Extract the two minimum freq items from min heap
		left = getMin(minHeap);
		right = getMin(minHeap);

		// Create a new internal node with freq equal to the
		// sum of the two nodes frequencies. Make the two extracted node as
		// left and right children of this new node.
		// Add this node to the min heap
		top = newNode('$', left->freq + right->freq);
		// Unused symbol $ to mark internal nodes
		top->left = left;
		top->right = right;
		insert(minHeap, top);
	}
	// The remaining node is the root node and the tree is complete.
	return getMin(minHeap);
}

void Huffman::printCodes(minHeapNode* root, int arr[], int top)
{
	// Assign 0 to left edge and recurse
	if (root->left)
	{
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}

	// Assign 1 to right edge and recurse
	if (root->right)
	{
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}

	// If this is a leaf node, then it contains one of the input
	// characters, print the character and its code from arr[]
	if (isLeaf(root))
	{
		cout << root->data << " ";
		printArray(arr, top);
	}
}

void Huffman::huffmanCodes(unsigned char data[], int freq[], int size)
{
	minHeapNode* root = buildHuffmanTree(data, freq, size);
	int arr[MAX_TREE_HT], top = 0;
	printCodes(root, arr, top);
}

int main()
{
	cout << "Enter the filename of the file to be Huffman coded: ";
	string inputFile;
	cin >> inputFile;
	ifstream inFile(inputFile);
	string inputbuffer;
	unsigned char tokens[255];
	int freq[255];
	for (int i = 0; i < 255; i++)
	{
		freq[i] = 0;
		tokens[i] = i;
	}
	Huffman hf;
	while (!inFile.eof())
	{
		getline(inFile, inputbuffer);
		// Find frequency of all possible 256 characters
		for (unsigned int i = 0; i < inputbuffer.length(); i++)
		{
			tokens[inputbuffer[i]] = inputbuffer[i];
			freq[inputbuffer[i]]++;
		}
		unsigned char new_tokens[255];
		int new_freq[255];
		int numoftokens = 0;
		// Filter out only those tokens which have a non-zero frequency
		for (int i = 0; i < 255; i++)
		{
			if (freq[i] != 0)
			{
				new_tokens[numoftokens] = tokens[i];
				new_freq[numoftokens] = freq[i];
				numoftokens++;
			}
		}
		int size = sizeof new_tokens / sizeof new_tokens[0];
		// Encode and print the coded output
		hf.huffmanCodes(new_tokens, new_freq, numoftokens);
	}
}

