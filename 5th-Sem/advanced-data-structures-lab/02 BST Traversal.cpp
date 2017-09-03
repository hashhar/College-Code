/* Implement In-order, Post-Order and Pre-Order Traversal of a BST
using linked lists */
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

	BST()
	{
		root = nullptr;
	}

	bool IsEmpty()
	{
		return root == nullptr;
	}

	bool Inorder(TreeNode*);
	bool Preorder(TreeNode*);
	bool Postorder(TreeNode*);
	bool Insert(int);
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

bool BST::Preorder(TreeNode* start_node)
{
	if (start_node != nullptr)
	{
		cout << " " << start_node->data << " ";
		if (start_node->left)
			Preorder(start_node->left);
		if (start_node->right)
			Preorder(start_node->right);
	}
	return true;
}

bool BST::Postorder(TreeNode* start_node)
{
	if (start_node != nullptr)
	{
		if (start_node->left)
			Postorder(start_node->left);
		if (start_node->right)
			Postorder(start_node->right);
		cout << " " << start_node->data << " ";
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
		cout << "3. Pre-Order Traversal" << endl;
		cout << "4. Post-Order Traversal" << endl;
		cout << "5. Exit" << endl;
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
				cout << "------------------" << endl;
				bst.Inorder(bst.root);
				break;
			case 3:
				cout << endl;
				cout << "Pre-Order Traversal" << endl;
				cout << "-------------------" << endl;
				bst.Preorder(bst.root);
				break;
			case 4:
				cout << endl;
				cout << "Post-Order Traversal" << endl;
				cout << "--------------------" << endl;
				bst.Postorder(bst.root);
				break;
			case 5:
				return 0;
			default:
				cout << "Invalid choice! Try again.";
		}
	}
}

