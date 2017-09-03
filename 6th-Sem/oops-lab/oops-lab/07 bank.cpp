#include <iostream>
#include <cstdio>

class Bank
{
public:
	Bank()
	{
		peopleInBank = 0;
		std::cout << "Bank created. People in bank: " << peopleInBank << std::endl << std::endl;
	}

	~Bank()
	{
		peopleInBank = 0;
		std::cout << "Bank destructed. People in bank: " << peopleInBank << std::endl << std::endl;
	}

	void enter()
	{
		peopleInBank++;
		std::cout << "A person entered the bank, now people in bank: " << peopleInBank << std::endl << std::endl;
	}

	void exit()
	{
		peopleInBank--;
		std::cout << "A person left the bank, now people in bank: " << peopleInBank << std::endl << std::endl;
	}

private:
	static int peopleInBank;
};

int Bank::peopleInBank = 0;

int main()
{
	Bank bank;

	char choice = 'e';
	while (true)
	{
		std::cout << "Press 'e' for person entering bank, 'x' for personn exiting bank, 'q' for quitting: ";
		std::cin >> choice;
		if (choice == 'e')
			bank.enter();
		else if (choice == 'x')
			bank.exit();
		else if (choice == 'q')
			break;
		else
			std::cout << "You entered an invalid operation. Try again.";
	}
	std::cout << "Now Bank will be destructed!" << std::endl;

	return 0;
}
