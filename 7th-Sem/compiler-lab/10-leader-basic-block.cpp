#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

set<int> get_leaders(vector<string>);
map<int, pair<int, int>> get_basic_blocks(vector<string>, set<int>);
void create_cfg(map<int, pair<int, int>>);

int main()
{
	ifstream tacFile;
	tacFile.open("tac.txt", ios::in);
	auto line_number = 0;
	cout << "The input TAC is: \n";
	string line;
	// Stores the entire tac. This is bad but can be done for small programs.
	vector<string> tac;
	while (getline(tacFile, line))
	{
		tac.push_back(line);
		// Print the program itself.
		cout << line_number << ": " << line << "\n";
		line_number++;
	}
	auto leaders = get_leaders(tac);
	auto basic_blocks = get_basic_blocks(tac, leaders);
	create_cfg(basic_blocks);
	getchar();
}

set<int> get_leaders(vector<string> tac)
{
	// Stores line numbers to mark leaders.
	set<int> leaders;

	// First line is always a leader.
	leaders.insert(0);
	auto line_number = 0;
	for (auto line : tac)
	{
		// Tokenise and find goto's.
		line_number++;
		istringstream line_stream(line);
		do
		{
			string token;
			line_stream >> token;
			if (token == "goto")
			{
				line_stream >> token;
				// Target of goto label is a leader.
				leaders.insert(atoi(token.c_str()));
				// Line after a jump is also a leader.
				leaders.insert(line_number);
			}
		} while (line_stream);
	}
	cout << endl;

	// Print out leaders.
	cout << "Leaders are: \n";
	for (auto leader : leaders)
	{
		cout << leader << ": " << tac.at(leader) << "\n";
	}
	cout << endl;
	return leaders;
}

map<int, pair<int, int>> get_basic_blocks(vector<string> tac, set<int> leaders)
{
	// Print out basic blocks.
	cout << "Basic blocks are: \n";
	auto block_number = 0;
	map<int, pair<int, int>> basic_blocks;
	auto leaderHead = leaders.begin();
	for (auto i = 0; i < tac.size(); i++)
	{
		auto found = leaders.find(i);
		if (found != leaders.end())
		{
			cout << block_number << ":\n";
			if (++leaderHead != leaders.end())
			{
				basic_blocks[block_number] = { i, *leaderHead - 1 };
			}
			else
			{
				basic_blocks[block_number] = { i, i };
			}
			cout << "\t" << i << ": " << tac.at(i) << "\n";
			block_number++;
		}
		else
		{
			cout << "\t" << i << ": " << tac.at(i) << "\n";
		}
	}
	cout << endl;
}

void create_cfg(map<int, pair<int, int>> basic_blocks)
{
	map<int, set<int>> cfg;
	// A basic block is encoded as <block_number, <start, end>>.
	// CFG will be basic_block_number -> set of connected basic_block_numbers.
	for (auto basic_block : basic_blocks)
	{
		set<int> temp;
		for (auto basic_block_inner : basic_blocks)
		{
			// Consecutive basic blocks are connected.
			if (basic_block_inner.second.first == basic_block.second.second + 1)
			{
				temp.insert(basic_block_inner.first);
				break;
			}
		}
		cfg[basic_block.first] = temp;
	}
}
