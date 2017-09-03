/* Find the successors and predecessors of a given node in a BST */
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
	TreeNode* Max(TreeNode*);
	TreeNode* Min(TreeNode*);
	TreeNode* Predecessor(int, int);
	TreeNode* Successor(int, int);
	TreeNode* Search(int);
	TreeNode* SearchParent(int);
};

bool BST::Inorder(TreeNode* start_node)
{
	if (start_node != nullptr)
	{
		// Avoid recursion once the next element is found to be null
		if (start_node->left != nullptr)
			Inorder(start_node->left);
		cout << " " << start_node->data << " ";
		if (start_node->right != nullptr)
			Inorder(start_node->right);
	}
	return true;
}

bool BST::Postorder(TreeNode* start_node)
{
	if (start_node != nullptr)
	{
		// Avoid recursion once the next element is found to be null
		if (start_node->left != nullptr)
			Postorder(start_node->left);
		if (start_node->right != nullptr)
			Postorder(start_node->right);
		cout << " " << start_node->data << " ";
	}
	return true;
}

bool BST::Preorder(TreeNode* start_node)
{
	if (start_node != nullptr)
	{
		cout << " " << start_node->data << " ";
		// Avoid recursion once the next element is found to be null
		if (start_node->left != nullptr)
			Preorder(start_node->left);
		if (start_node->right != nullptr)
			Preorder(start_node->right);
	}
	return true;
}

bool BST::Insert(int item)
{
	TreeNode* new_node = new TreeNode;
	TreeNode* parent = new TreeNode;
	// Is this a new tree? If yes, new node will become the root
	if (IsEmpty())
		root = new_node;
	// If not, find the proper parent
	else
	{
		// All insertions occur as leaf nodes
		TreeNode* current = root;
		while (current != nullptr)
		{
			parent = current;
			if (new_node->data > current->data)
				current = current->right;
			else
				current = current->left;
		}
		if (new_node->data < parent->data)
			parent->left = new_node;
		else
			parent->right = new_node;
	}
	return true;
}

bool BST::Remove(int item)
{
	bool found = false;
	if (IsEmpty())
	{
		cout << "This tree is empty!" << endl;
		return false;
	}
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
	{
		cout << "Data not found in the tree!" << endl;
		return false;
	}
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

BST::TreeNode* BST::Search(int item)
{
	TreeNode* current = new TreeNode;
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

BST::TreeNode* BST::Max(TreeNode* start_node)
{
	TreeNode* current = new TreeNode;
	current = start_node;
	// Traverse to the rightmost leaf node
	while (current->right != nullptr)
		current = current->right;
	return current;
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

BST::TreeNode* BST::Predecessor(int item, int mode)
{
	// Search for the start_node
	TreeNode* start_node = new TreeNode;
	start_node = Search(item);
	switch (mode)
	{
		// Pre-Order Predecessor
		case 1:
		{
			// If start_node is root of tree, predecessor is undefined
			if (start_node == root)
				return nullptr;
			// If start_node has left sibling ls then predecessor is
			// the rightmost descendant of ls
			TreeNode* parent = SearchParent(start_node->data);
			if (parent->right == start_node && parent->left != nullptr)
				return Max(parent->left);
			// Else the parent
			return parent;
		}
		// In-Order Predecessor
		case 2:
		{
			// If start_node has left  child l, then predecessor is rightmost
			// descendant of l
			if (start_node->left != nullptr)
				return Max(start_node->left);
			// Predecessor is the closest ancestor v of start_node such that
			// start_node is in the right subtree of v
			TreeNode* parent = SearchParent(start_node->data);
			if (parent->right == start_node)
				return parent;
			// If not an immediate right child, recurse
			TreeNode* subtree_node = parent;
			while (true)
			{
				if (subtree_node->right == parent)
					return subtree_node;
				parent = subtree_node;
				// If we reached the top and still couldn't find it, give up
				if (parent == root)
					return nullptr;
				subtree_node = SearchParent(subtree_node->data);
			}
		}
		// Post-Order Predecessor
		case 3:
		{
			// If start_node has a right child
			// then the predecessor is the right child
			if (start_node->right != nullptr)
				return start_node->right;
			// If start_node has a left child
			// then the predecessor is the left child
			if (start_node->left != nullptr)
				return start_node->left;
			// If start_node has left sibling then predecessor is the sibling
			TreeNode* parent = SearchParent(start_node->data);
			if (parent->left != nullptr)
				return parent->left;
			// If start_node has an ancestor which:
			// is a right child AND has a left sibling vls then pred is vls
			TreeNode* ancestor = SearchParent(parent->data);
			if (ancestor->right == parent && ancestor->left != nullptr)
				return ancestor->left;
			// If not an immediate ancestor, recurse
			while (true)
			{
				if (ancestor->right == parent && ancestor->left != nullptr)
					return ancestor->left;
				parent = ancestor;
				// If we reached the top and still couldn't find it, give up
				if (parent == root)
					return nullptr;
				ancestor = SearchParent(ancestor->data);
			}
		}
		default:
			break;
	}
	return nullptr;
}

BST::TreeNode* BST::Successor(int item, int mode)
{
	// Search for the start_node
	TreeNode* start_node = new TreeNode;
	start_node = Search(item);
	switch (mode)
	{
		// Pre-Order Successor
		case 1:
		{
			// If start_node has a left child then successor is the left child.
			if (start_node->left != nullptr)
				return start_node->left;
			// If start_node has a right child then successor is right child
			if (start_node->right != nullptr)
				return start_node->right;
			// If the start_node is a leaf
			// 1. And a left child and has a right sibling rs, rs is successor
			TreeNode* parent = SearchParent(item);
			if (start_node == parent->left)
				if (parent->right != nullptr)
					return parent->right;
			// 2. start_node has an ancestor which is a left child and
			// has a right sibling then the sibling is the successor
			TreeNode* ancestor = SearchParent(parent->data);
			if (ancestor->left == parent && ancestor->right != nullptr)
				return ancestor->right;
			// If not an immediate ancestor, recurse
			while (true)
			{
				if (ancestor->left == parent && ancestor->right != nullptr)
					return ancestor->right;
				parent = ancestor;
				// If we reached the top and still couldn't find it, give up
				if (parent == root)
					return nullptr;
				ancestor = SearchParent(ancestor->data);
			}
		}
		// In-Order Successor
		case 2:
		{
			// If start_node has a right child then successor is the leftmost
			// descendant of start_node
			if (start_node->right != nullptr)
				return Min(start_node);
			// Else the closest ancestor of start_node such that start_node
			// is in the left subtree of the ancestor
			TreeNode* parent = SearchParent(start_node->data);
			if (parent->right == start_node)
				return parent;
			// If not an immediate right child, recurse
			TreeNode* subtree_node = parent;
			while (true)
			{
				if (subtree_node->right == parent)
					return subtree_node;
				parent = subtree_node;
				// If we reached the top and still couldn't find it, give up
				if (parent == root)
					break;
				subtree_node = SearchParent(subtree_node->data);
			}
			return nullptr;
		}
		// Post-Order Successor
		case 3:
		{
			// If start_node is the root, the successor is undefined
			if (start_node == root)
				return nullptr;
			// If start_node is a right child, the successor is it's parent
			TreeNode* parent = SearchParent(item);
			if (start_node == parent->right)
				return parent;
			// If start_node is a left child and has a right sibling rs
			// the successor is the leftmost leaf in the rs's subtree
			if (start_node == parent->left)
				if (parent->right != nullptr)
					return Min(start_node);
			// Else the successor is the parent of start_node
			return parent;
		}
		default:
			break;
	}
	return nullptr;
}

int main()
{
	BST bst;
	int choice_i, item_i, mode_i;
	while (true)
	{
		cout << endl << endl;
		cout << "Binary Search Tree Operations" << endl;
		cout << "-----------------------------" << endl;
		cout << "1. Insertion/Creation" << endl;
		cout << "2. In-Order Traversal" << endl;
		cout << "3. Pre-Order Traversal" << endl;
		cout << "4. Post-Order Traversal" << endl;
		cout << "5. Predecessor" << endl;
		cout << "6. Successor" << endl;
		cout << "7. Removal" << endl;
		cout << "8. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice_i;
		switch (choice_i)
		{
			case 1:
				cout << "Enter Number to be inserted: ";
				cin >> item_i;
				bst.Insert(item_i);
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
				cout << endl;
				cout << "Enter the element whose predecessor you want: "
					<< endl;
				cin >> item_i;
				cout << "1. Pre-Order predecessor" << endl;
				cout << "2. In-Order predecessor" << endl;
				cout << "3. Post-Order predecessor" << endl;
				cin >> mode_i;
				cout << "The predecessor of " << item_i << " is "
					<< bst.Predecessor(item_i, mode_i);
				break;
			case 6:
				cout << endl;
				cout << "Enter the element whose successor you want: "
					<< endl;
				cin >> item_i;
				cout << "1. Pre-Order successor" << endl;
				cout << "2. In-Order successor" << endl;
				cout << "3. Post-Order successor" << endl;
				cin >> mode_i;
				cout << "The successor of " << item_i << " is "
					<< bst.Successor(item_i, mode_i);
				break;
			case 7:
				cout << "Enter data to be deleted: ";
				cin >> item_i;
				bst.Remove(item_i);
				break;
			case 8:
				return 0;
			default:
				cout << "Invalid choice! Try again.";
		}
	}
}

