#include <iostream>
#include <string>

class Student
{
public:
	void getData();
	void displayData();
	friend class Average;
private:
	int roll;
	std::string name;
	double m1, m2, m3;
};

class Average
{
public:
	double computeAverage(Student& s)
	{ return (s.m1 + s.m2 + s.m3) / 3; }
};

void Student::getData()
{
	std::cout << "Roll No.: ";
	std::cin >> roll;
	std::cout << "Name: ";
	// Ignore leftover characters
	std::cin.ignore(1, '\n');
	std::getline(std::cin, name);
	std::cout << "Marks 1: ";
	std::cin >> m1;
	std::cout << "Marks 2: ";
	std::cin >> m2;
	std::cout << "Marks 3: ";
	std::cin >> m3;
}

void Student::displayData()
{
	Average a;
	std::cout << std::endl << "Roll No. : " << roll << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Marks 1: " << m1 << std::endl;
	std::cout << "Marks 2: " << m2 << std::endl;
	std::cout << "Marks 3: " << m3 << std::endl;
	std::cout << "Average: " << a.computeAverage(*this) << std::endl;
}

int main()
{
	Student s;
	s.getData();
	s.displayData();

	return 0;
}
