#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>

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

class NFA
{
public:
	NFA() : initState{0},
	        numStates{0},
	        numInputs{0}
	{
	}

	bool readInput(string automataFile = "02-nfa.txt",
	               string delimiterOuter = " ",
	               string delimiterInner = ",");
	bool process(string inputFile = "02-nfa.input",
	             bool batchMode = false);

private:
	size_t initState;
	vector<size_t> finalStates;
	multimap<pair<int, int>, int> automata;
	size_t numStates;
	size_t numInputs;

	bool matchFA(string str);
};

bool NFA::readInput(string automataFile, string delimiterOuter, string delimiterInner)
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
	splitString(fields, line, delimiterOuter);
	for (auto field : fields)
		finalStates.push_back(stoi(field));

	size_t i = 0, j = 0;
	// Read the transitions.
	while (!fp.eof())
	{
		// Read a line and parse it.
		getline(fp, line, EOL);
		splitString(fields, line, delimiterOuter, split::no_empties);
		j = 0;
		for (auto field : fields)
		{
			if (field.find(",") != string::npos)
			{
				// A comma was found, so we treat this differently and split on commas.
				vector<string> innerFields;
				splitString(innerFields, field, delimiterInner, split::no_empties);
				for (auto innerField : innerFields)
					automata.insert(pair<pair<int, int>, int>(pair<int, int>(i, j), stoi(innerField)));
			}
			else
			{
				automata.insert(pair<pair<int, int>, int>(pair<int, int>(i, j), stoi(field)));
				j++;
			}
		}
		if (line.find(",") == string::npos && !line.empty())
		// No comma found and line not empty.
			numInputs = j;
		i++;
	}
	numStates = i - 1;
	return true;
}

bool NFA::matchFA(string line)
{
	set<int> curStates = {}, nextStates = {};
	// Add the initial state to the reachable current states.
	curStates.insert(initState);
	for (size_t i = 0; i < line.length(); i++)
	{
		nextStates.clear();
		auto input = line[i] - a_ASCII;
		for (auto curState : curStates)
		{
			if (curState == -1)
				continue;
			// Find all curState, input pairs in automata and add all reachable states as nextStates.
			auto iterpair = automata.equal_range(pair<int, int>(curState, input));
			for (auto it = iterpair.first; it != iterpair.second; ++it)
				nextStates.insert(it->second);
		}
		curStates = nextStates;
	}
	set<int> resSet = {};
	set<int> finals(finalStates.begin(), finalStates.end());
	set_intersection(curStates.begin(), curStates.end(), finals.begin(), finals.end(), inserter(resSet, resSet.end()));
	if (resSet.size() > 0)
		return true;
	return false;
}

bool NFA::process(string inputFile, bool batchMode)
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
	NFA fa;
	switch (argc)
	{
	case 1:
		// No arguments means the automata will be read from "02-nfa.txt" and input from stdin.
		fa.readInput();
		while (1)
			fa.process();
	case 2:
		// One argument means the automata will be read from "02-nfa.txt" and input from the file specified.
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
