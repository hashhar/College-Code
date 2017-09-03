#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define MAX_STATES 100
#define numInputs 2
#define numOutputs 2
#define ZERO_ASCII 48
#define EOL '\n'
#define OUTPUT_COL_INDEX 2

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

class Moore
{
public:
	Moore() : initState{0},
	          curState{0},
	          numStates{0}
	{
	}

	bool readInput(string automataFile = "05-moore.txt",
	               string delimiters = " ,");
	bool process(string inputFile = "05-moore.input",
	             bool batchMode = false);

private:
	size_t initState;
	int automata[MAX_STATES][MAX_STATES];
	int curState;
	size_t numStates;

	string runMoore(string inputs);
};

bool Moore::readInput(string automataFile, string delimiters)
{
	// Open the file for reading.
	fstream fp(automataFile, ios::in);
	string line;

	// Read the initial state.
	getline(fp, line, EOL);
	initState = stoi(line);

	// Read the automata array.
	vector<string> fields;
	size_t i = 0, j;
	while (!fp.eof())
	{
		getline(fp, line, EOL);
		splitString(fields, line, delimiters, split::no_empties);
		j = 0;
		for (auto field : fields)
		{
			automata[i][j] = stoi(field);
			j++;
		}
		i++;
	}
	numStates = i - 1;
	return true;
}

bool Moore::process(string inputFile, bool batchMode)
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
			// Process the automata.
			cout << "Output: " << runMoore(line) << endl << endl;
		}
	}
	else
	{
		string line;
		getline(cin, line);
		// If we read an empty line, we skip it.
		if (line.empty())
			return false;
		// Process the automata.
		cout << "Output: " << runMoore(line) << endl << endl;
	}
	return true;
}

// Take a string of integers as input and output corresponding outputs as string of integers.
string Moore::runMoore(string inputs)
{
	curState = initState;
	string output = "";
	for (auto input_char : inputs)
	{
		auto input = input_char - ZERO_ASCII;
		output.append(to_string(automata[curState][OUTPUT_COL_INDEX]));
		curState = automata[curState][input];
		if (curState == -1)
		{
			cout << "Invalid Input! No transitions found." << endl;
			return output;
		}
	}
	return output;
}

int main(int argc, char** argv)
{
	Moore moore;
	switch (argc)
	{
	case 1:
		// No arguments means the automata will be read from file and input from stdin.
		moore.readInput();
		while (1)
			moore.process();
	case 2:
		// One argument means the automata will be read from file and input from the file specified.
		moore.readInput();
		moore.process(argv[1], true);
		break;
	case 3:
		// Two arguments means the automata and input will be read from the arguments.
		moore.readInput(argv[2]);
		moore.process(argv[1], true);
		break;
	}
}
