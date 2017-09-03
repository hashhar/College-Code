/* Implement a BST using linked lists with deletion operation  */
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
	bool Remove(int);
	TreeNode* SearchParent(int item);
	TreeNode* Min(TreeNode* start_node);
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

bool BST::Remove(int item)
{
	bool found = false;
	if (IsEmpty())
		return false;
	// If tree is not empty, find the element
	TreeNode* current = root;
	TreeNode* parent = nullptr;
	while (current)
	{
		if (current->data == item)
		{
			found = true;
			break;
		}
		parent = current;
		if (item > current->data)
			current = current->right;
		else
			current = current->left;
	}
	if (!found)
		return false;
	// If element was found, there can be 3 cases:
	// 1. We're removing a leaf node
	// 1.1 Is the left child of parent
	// 1.2 Is the right child of parent
	// 2. We're removing a node with only one child
	// 2.1 Only left child present
	// 2.2 Only right child present
	// 3. We're removing a node with two children

	// Node with no child
	if (current->left == nullptr && current->right == nullptr)
	{
		// Is the left child of parent or the right child?
		if (parent->left == current)
			parent->left = nullptr;
		else
			parent->right = nullptr;
		delete current;
		return true;
	}
	// Node with only left child
	if (current->left != nullptr && current->right == nullptr)
	{
		if (parent->left == current)
		{
			parent->left = current->left;
			delete current;
		}
		else
		{
			parent->right = current->left;
			delete current;
		}
		return true;
	}
	// Node with only right child
	if (current->right != nullptr && current->right == nullptr)
	{
		if (parent->left == current)
		{
			parent->left = current->right;
			delete current;
		}
		else
		{
			parent->right = current->right;
			delete current;
		}
		return true;
	}
	// Node with two children
	// ALGORITHM: Replace the deleted node with the smallest value in the right
	// sub-tree, now remove the smallest value from the right sub-tree to
	// remove the duplicate
	if (current->left != nullptr && current->right != nullptr)
	{
		TreeNode* right_subtree = current->right;
		// The right sub-tree has only a single node
		// Replace with it and remove the right sub-tree
		if (right_subtree->right == nullptr && right_subtree->left == nullptr)
		{
			current = right_subtree;
			delete right_subtree;
			current->right = nullptr;
		}
		// Right sub-tree has children, replace with the inorder predecessor
		else
		{
			// The node's right child has a left child
			if (current->right->left != nullptr)
			{
				TreeNode* minimum = Min(current->right);
				current->data = minimum->data;
				delete minimum;
				TreeNode* minimum_parent = SearchParent(minimum->data);
				minimum_parent->left = nullptr;
			}
			// The node's right child has no left child
			else
			{
				TreeNode* temp_node = current->right;
				current->data = temp_node->data;
				current->right = temp_node->right;
				delete temp_node;
			}
		}
	}
	return true;
}

BST::TreeNode* BST::SearchParent(int item)
{
	TreeNode* current = new TreeNode;
	while (current != nullptr)
	{
		if (item > current->right->data || item > current->left->data)
			current = current->right;
		else if (item < current->right->data || item < current->left->data)
			current = current->left;
		if (item == current->right->data || item == current->left->data)
			return current;
	}
	return nullptr;
}

BST::TreeNode* BST::Min(TreeNode* start_node)
{
	TreeNode* current = new TreeNode;
	current = start_node;
	// Traverse to the leftmost leaf node
	while (current->left != nullptr)
		current = current->left;
	return current;
}

int main()
{
	BST bst;
	int choice_i, item_i;
	while (1)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Operations" << endl;
		cout << " -----------------------------" << endl;
		cout << " 1. Insertion/Creation" << endl;
		cout << " 2. In-Order Traversal" << endl;
		cout << " 3. Pre-Order Traversal" << endl;
		cout << " 4. Post-Order Traversal" << endl;
		cout << " 5. Removal" << endl;
		cout << " 6. Exit" << endl;
		cout << " Enter your choice : ";
		cin >> choice_i;
		switch (choice_i)
		{
			case 1:
				cout << " Enter Number to be inserted : ";
				cin >> item_i;
				if (bst.Insert(item_i))
					cout << " The element was inserted into the tree.";
				break;
			case 2:
				cout << endl;
				cout << " In-Order Traversal" << endl;
				cout << " -------------------" << endl;
				bst.Inorder(bst.root);
				break;
			case 3:
				cout << endl;
				cout << " Pre-Order Traversal" << endl;
				cout << " -------------------" << endl;
				bst.Preorder(bst.root);
				break;
			case 4:
				cout << endl;
				cout << " Post-Order Traversal" << endl;
				cout << " --------------------" << endl;
				bst.Postorder(bst.root);
				break;
			case 5:
				cout << " Enter data to be deleted : ";
				cin >> item_i;
				if (bst.Remove(item_i))
					cout << "The element was deleted from the tree.";
				else
					cout << "The element was not found in the tree!";
				break;
			case 6:
				return 0;
			default:
				cout << " Invalid choice! Try again.";
		}
	}
}

