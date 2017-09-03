/* Implement a BST using an array */
#include <iostream>

using namespace std;

struct BST
{
	int info;
	BST* right;
	BST* left;
} *t1, *t2;

// Inserts an element into the BST
BST* insert(BST* root)
{
	int i;
	cout << "Enter the node's value: ";
	cin >> i;
	// Empty tree
	if (root == nullptr)
	{
		root = new BST;
		root->info = i;
		root->left = root->right = nullptr;
	}
	else
	{
		t1 = root;
		t2 = nullptr;
		while ((t1->left != nullptr || t1->right != nullptr) && t2 != t1)
		{
			t2 = t1;
			while (i < t1->info && t1->left != nullptr)
				t1 = t1->left;
			while (i > t1->info && t1->right != nullptr)
				t1 = t1->right;
		}
		t2 = new BST;
		t2->info = i;
		t2->left = t2->right = nullptr;
		if (i < t1->info)
			t1->left = t2;
		else
			t1->right = t2;
	}
	return root;
}

// Push an element into the stack
int push(BST* stk[], BST* p, int top)
{
	stk[++top] = p;
	return top;
}

// Pop an element from the stack
BST* pop(BST* stk[], int* top)
{
	return stk[(*top)--];
}

// In-Order traversal of the BST
void inorder(BST* t)
{
	BST *p, *stk[20];
	int top = -1;
	p = t;
	do
	{
		while (p != nullptr)
		{
			// Push an element into the stack and move to its left
			top = push(stk, p, top);
			p = p->left;
		}
		// As long as no underflow, keep popping and moving to the right
		if (top != -1)
		{
			p = pop(stk, &top);
			cout << " \t" << p->info;
			p = p->right;
		}
	} while (top != -1 || p != nullptr);
}

int main()
{
	int ch;
	BST* root;
	root = nullptr;
menu:
	cout << "Binary Search Tree Operations" << endl;
	cout << "-----------------------------" << endl;
	cout << "1. Insertion/Creation" << endl;
	cout << "2. In-Order Traversal" << endl;
	cout << "3. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> ch;
	switch (ch)
	{
		case 1:
			root = insert(root);
			goto menu;
		case 2:
			if (root != nullptr)
				inorder(root);
			else
				cout << "No tree exists!" << endl;
			goto menu;
		case 3:
			return 0;
		default:
			goto menu;
	}
}

