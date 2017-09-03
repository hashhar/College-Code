#include <iostream>

class SelfCount
{
public:
	SelfCount()
	{
		count++;
		std::cout << "Constructor called: " << count << std::endl;
	}

	~SelfCount()
	{
		count--;
		std::cout << "Destructor called: " << count << std::endl;
	}

	static int count;
};

int SelfCount::count = 0;

int main()
{
	SelfCount a;
	std::cout << "Created a: " << a.count << std::endl;

	SelfCount b;
	std::cout << "Created b: " << b.count << std::endl;

	for (int i = 0; i < 3; i++)
	{
		SelfCount c;
		std::cout << "Creating c within a loop: " << c.count << std::endl;
	}

	std::cout << "Last statement of main(): " << a.count << std::endl;

	return 0;
}
