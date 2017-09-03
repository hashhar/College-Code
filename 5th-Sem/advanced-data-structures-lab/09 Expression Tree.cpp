/* Evaluate a postfix expression using expression tree */
#include <iostream>

using namespace std;

struct tree
{
	char data;
	tree* left;
	tree* right;
};

int top = -1;
tree* stack[20];
tree* node;

void push(tree* node)
{
	stack[++top] = node;
}

tree* pop()
{
	return stack[top--];
}

int check(char c)
{
	// Return 2 if operator otherwise 1
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return 2;
	return 1;
}

int cal(tree* node)
{
	int ch;
	// Check if operand or operator
	ch = check(node->data);
	// If it is an operand, convert it to the corresponding integer by
	// subtracting 48 from it's ascii value
	if (ch == 1)
		return (node->data - 48);
	if (ch == 2)
	{
		if (node->data == '+')
			return (cal(node->left) + cal(node->right));
		if (node->data == '-')
			return (cal(node->right) - cal(node->left));
		if (node->data == '*')
			return (cal(node->left) * cal(node->right));
		if (node->data == '/')
			return (cal(node->right) / cal(node->left));
	}
}

void operands(char b)
{
	node = new tree;
	node->data = b;
	node->left = nullptr;
	node->right = nullptr;
	push(node);
}

void operators(char a)
{
	node = new tree;
	node->data = a;
	node->left = pop();
	node->right = pop();
	push(node);
}

// Perform in-order traversal to evaulate the expression tree
void traverse(tree* node)
{
	if (node != nullptr)
	{
		traverse(node->right);
		printf("%c", node->data);
		traverse(node->left);
	}
}

int main()
{
	int i, p, ans;
	char s[20];
	cout << "Enter the expression tree in postfix form: ";
	fgets(s, 19, stdin);
	for (i = 0; s[i] != '\n'; i++)
	{
		p = check(s[i]);
		if (p == 1)
			operands(s[i]);
		else if (p == 2)
			operators(s[i]);
	}
	ans = cal(stack[top]);
	cout << endl << "The value of the postfix expression = " << ans << endl;
	cout << "The actual traversal will be:" << endl;
	traverse(stack[top]);
}

