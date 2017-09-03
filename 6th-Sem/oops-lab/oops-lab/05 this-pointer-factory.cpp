#include <iostream>
#include <string>
#include <vector>

class Student
{
public:
	Student(char _id, std::string _name, int _rollNo) : objName(_id),
	                                                    name(_name),
	                                                    rollNo(_rollNo) {}

	int getRollNo();
	void setRollNo(int roll)
	{ rollNo = roll; }

	std::string getName();
	void setName(std::string str)
	{ name.assign(str); }

	char getObjName();

private:
	char objName;
	std::string name;
	int rollNo;
};

int Student::getRollNo()
{
	std::cerr << std::endl << "get_rollNo() called by: " << this->objName << std::endl;
	return rollNo;
}

std::string Student::getName()
{
	std::cerr << std::endl << "get_name() called by: " << this->objName << std::endl;
	return name;
}

char Student::getObjName()
{
	std::cerr << std::endl << "get_objName() called by: " << this->objName << std::endl;
	return objName;
}

int main()
{
	char choice = 'y';
	std::vector<Student> students;
	while (tolower(choice) == 'y')
	{
		char _id;
		std::cout << "Enter a single character id for the object: ";
		std::cin >> _id;

		std::string _name;
		std::cout << "Enter the name of the student: ";
		// Ignore leftover characters
		std::cin.ignore(1, '\n');
		std::getline(std::cin, _name);

		int _rollNo;
		std::cout << "Enter the roll number of the student: ";
		std::cin >> _rollNo;

		students.push_back(Student(_id, _name, _rollNo));
		std::cout << "Do you want to create more objects? (y / n): ";
		std::cin >> choice;
	}

	std::cout << std::endl;
	for (unsigned int i = 0; i < students.size(); i++)
	{
		std::cout << "================" << std::endl << "Object " << i + 1 << std::endl << "================";

		std::cout << "ID: " << students[i].getObjName() << std::endl;
		std::cout << "Name: " << students[i].getName() << std::endl;
		std::cout << "Roll No: " << students[i].getRollNo() << std::endl << std::endl;
	}

	return 0;
}
