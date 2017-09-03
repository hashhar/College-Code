#include <fstream>
#include <iostream>
#include <cstdlib>

bool addContact()
{
	std::string name;
	std::string mobileNo;

	std::cout << "Enter Name: ";
	std::getline(std::cin, name);
	std::cout << "Enter Mobile No: ";
	// Ignore leftover characters
	std::cin.ignore(1, '\n');
	std::getline(std::cin, mobileNo);

	std::ofstream contactFile("contacts.txt", std::ios::app | std::ios::out );
	contactFile << name << "\n" << mobileNo << std::endl ;

	return true;
}

bool deleteContact()
{
	std::string name, line;

	std::cout << "Enter name to be deleted: ";
	std::getline(std::cin, name);

	std::ifstream contactFile;
	std::ofstream newFile;

	contactFile.open("contacts.txt");
	newFile.open("newFile.txt");

	while (getline(contactFile, line))
	{
		if (line != name)
			newFile << line << std::endl;
		else
		{
			std::cout << "The name was present and deleted successfully.";
			std::getline(contactFile, line);
			std::getline(contactFile, line);
		}
	}

	std::remove("contacts.txt");
	std::rename("newFile.txt", "contacts.txt");

	return true;
}

bool searchContact()
{
	std::string name, line;
	std::cout << "Enter the name to be searched : ";
	std::getline(std::cin, name);

	std::ifstream contactFile("contacts.txt");

	while (std::getline(contactFile, line))
	{
		if (line == name)
		{
			std::cout << "Search successful!" << std::endl;
			std::cout << line << " : ";
			getline(contactFile, line);
			std::cout << line;
			return true;
		}
	}
	std::cout << "Search unsuccessful. Contact not found.";
	return false;
}

int main()
{
	int choice;

	while (true)
	{
		std::cout << "\nMenu" << std::endl;

		std::cout << "1. Add\n2. Delete\n3. Search\n4. Exit" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch(choice)
		{
			case 1:
				addContact();
				break;
			case 2:
				deleteContact();
				break;
			case 3:
				searchContact();
				break;
			case 4:
				exit(1);
			default:
				std::cout << "Invalid choice. Try Again";
				break;
		}
	}

	return 0;
}
