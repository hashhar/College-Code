#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define MAX_STATES 100
#define a_ASCII 97
#define EOL '\n'

using namespace std;

struct split
{
	enum empties_t
	{
		empties_ok,
		no_empties
	};
};

template <typename Container>
Container& splitString(Container& result,
                       const typename Container::value_type& str,
                       const typename Container::value_type& delimiters,
                       split::empties_t empties = split::empties_ok)
{
	result.clear();
	size_t current, next = -1;
	do
	{
		if (empties == split::no_empties)
		{
			next = str.find_first_not_of(delimiters, next + 1);
			if (next == Container::value_type::npos)
				break;
			next -= 1;
		}
		current = next + 1;
		next = str.find_first_of(delimiters, current);
		result.push_back(str.substr(current, next - current));
	} while (next != Container::value_type::npos);
	return result;
}

class DFA
{
public:
	DFA() : initState{0},
	        numStates{0},
	        numInputs{0}
	{
	}

	bool readInput(string automataFile = "01-dfa.txt",
	               string delimiters = " ,");
	bool process(string inputFile = "01-dfa.input",
	             bool batchMode = false);

private:
	size_t initState;
	size_t finalStates[MAX_STATES];
	int automata[MAX_STATES][MAX_STATES];
	size_t numStates;
	size_t numInputs;

	bool matchFA(string str);
};

bool DFA::readInput(string automataFile, string delimiters)
{
	// Open the file for reading and define the delimiters.
	fstream fp(automataFile, ios::in);
	string line;

	// Read the initial state.
	getline(fp, line, EOL);
	initState = stoi(line);

	// Read the final states.
	getline(fp, line, EOL);
	vector<string> fields;
	splitString(fields, line, delimiters);
	size_t i = 0;
	for (auto field : fields)
	{
		finalStates[i] = stoi(field);
		i++;
	}

	// Read the automata array.
	size_t j;
	i = 0;
	while (!fp.eof())
	{
		// Read a line and parse it.
		getline(fp, line, EOL);
		splitString(fields, line, delimiters, split::no_empties);
		j = 0;
		for (auto field : fields)
		{
			automata[i][j] = stoi(field);
			j++;
		}
		// Read j only once since it will be set to 0 on the last iteration of the while loop.
		if (i == 0)
			numInputs = j;
		i++;
	}
	numStates = i - 1;
	return true;
}

bool DFA::matchFA(string line)
{
	// Start matching the line against the automata.
	int curState = initState;
	for (size_t i = 0; i < line.length(); i++)
	{
		curState = automata[curState][line[i] - a_ASCII];
		if (curState == -1)
			return false;
	}
	for (int finalState : finalStates)
		if (curState == finalState)
			return true;
	return false;
}

bool DFA::process(string inputFile, bool batchMode)
{
	if (batchMode)
	{
		fstream fp(inputFile, ios::in);
		string line;
		while (!fp.eof())
		{
			// Read a line from input file and run it against the automata.
			getline(fp, line, EOL);
			// If we read an empty line, we skip it.
			if (line.empty())
				continue;
			if (matchFA(line))
				cout << "Matched: " << line << endl;
			else
				cout << "Not Matched: " << line << endl;
		}
	}
	else
	{
		string line;
		getline(cin, line);
		if (matchFA(line))
			cout << "Matched: " << line << endl;
		else
			cout << "Not Matched: " << line << endl;
	}
	return true;
}

int main(int argc, char** argv)
{
	DFA fa;
	switch (argc)
	{
	case 1:
		// No arguments means the automata will be read from "01-dfa.txt" and input from stdin.
		fa.readInput();
		while (1)
			fa.process();
	case 2:
		// One argument means the automata will be read from "01-dfa.txt" and input from the file specified.
		fa.readInput();
		fa.process(argv[1], true);
		break;
	case 3:
		// Two arguments means the automata and input will be read from the arguments.
		fa.readInput(argv[2]);
		fa.process(argv[1], true);
		break;
	}
}
