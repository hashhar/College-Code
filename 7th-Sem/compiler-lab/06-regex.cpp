#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

set<int> expression;
set<int>::iterator it;

int main()
{
	ifstream file("06-regex.txt");

	string line;

	// Separating the units combined with a dot
	getline(file, line);
	istringstream line_stream(line);
	string dot_sep;
	while (getline(line_stream, dot_sep, '.'))
		expression.insert(atoi(dot_sep.c_str()));

	it = expression.begin();
	while (it != expression.end())
	{
		cout << *it << endl;
		++it;
	}
	getchar();
}
