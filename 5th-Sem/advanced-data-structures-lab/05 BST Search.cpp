/* Implement a BST using linked lists with the search operation */
#include <iostream>

using namespace std;

class BST
{
	struct TreeNode
	{
		int data;
		TreeNode* left;
		TreeNode* right;
	};

public:
	TreeNode* root;
	// A node that can be used by non-member functions
	TreeNode* node;

	BST()
	{
		root = nullptr;
		node = nullptr;
	}

	bool IsEmpty()
	{
		return root == nullptr;
	}

	bool Inorder(TreeNode*);
	bool Insert(int);
	TreeNode* Search(int);
};

bool BST::Inorder(TreeNode* start_node)
{
	if (start_node != nullptr)
	{
		if (start_node->left)
			Inorder(start_node->left);
		cout << " " << start_node->data << " ";
		if (start_node->right)
			Inorder(start_node->right);
	}
	return true;
}

bool BST::Insert(int item)
{
	TreeNode* node = new TreeNode;
	node->data = item;
	node->left = nullptr;
	node->right = nullptr;
	TreeNode* parent = nullptr;
	if (IsEmpty())
		root = node;
	// If not, we need to find the proper to-be parent of element
	else
	{
		TreeNode* current = root;
		while (current)
		{
			parent = current;
			if (node->data > current->data)
				current = current->right;
			else
				current = current->left;
		}
		if (node->data < parent->data)
			parent->left = node;
		else
			parent->right = node;
	}
	return true;
}

BST::TreeNode* BST::Search(int item)
{
	TreeNode* current = new TreeNode();
	current = root;
	while (current != nullptr)
	{
		if (item > current->data)
			current = current->right;
		else if (item < current->data)
			current = current->left;
		if (item == current->data)
			return current;
	}
	return nullptr;
}

int main()
{
	BST bst;
	int choice_i, item_i;
	while (1)
	{
		cout << endl << endl;
		cout << "Binary Search Tree Operations" << endl;
		cout << "-----------------------------" << endl;
		cout << "1. Insertion/Creation" << endl;
		cout << "2. In-Order Traversal" << endl;
		cout << "3. Search for an element" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice_i;
		switch (choice_i)
		{
			case 1:
				cout << "Enter Number to be inserted: ";
				cin >> item_i;
				if (bst.Insert(item_i))
					cout << "The element was inserted successfully into the tree.";
				break;
			case 2:
				cout << endl;
				cout << "In-Order Traversal" << endl;
				cout << "-------------------" << endl;
				bst.Inorder(bst.root);
				break;
			case 3:
				cout << endl;
				cout << "Enter the element to search for: ";
				cin >> item_i;
				bst.node = bst.Search(item_i);
				if (bst.node != nullptr)
				{
					cout << item_i << " found in the tree!" << endl;
					cout << "Left child: " << bst.node->left->data << endl;
					cout << "Right child: " << bst.node->right->data << endl;
				}
				else
					cout << "The element " << item_i
					<< " wasn't found in the tree!" << endl;
				break;
			case 4:
				return 0;
			default:
				cout << "Invalid choice! Try again.";
		}
	}
}

