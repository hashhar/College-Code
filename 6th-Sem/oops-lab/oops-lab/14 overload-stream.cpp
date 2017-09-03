#include <iostream>

class Student
{
public:
	Student(std::string _name = "", int _roll = 0, int _age = 0, std::string _course = "") : name(_name),
	                                                                                         roll(_roll),
	                                                                                         age(_age),
	                                                                                         course(_course) {}

	friend std::ostream& operator<<(std::ostream&, Student&);
	friend std::istream& operator>>(std::istream&, Student&);

private:
	std::string name;
	int roll;
	int age;
	std::string course;
};

std::ostream& operator<<(std::ostream& os, Student& s)
{
	os << "Name:   " << s.name   << std::endl;
	os << "Roll:   " << s.roll   << std::endl;
	os << "Age:    " << s.age    << std::endl;
	os << "Course: " << s.course << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Student& s)
{
	std::cout << "Name: ";
	std::getline(is, s.name);
	std::cout << "Roll: ";
	is >> s.roll;
	std::cout << "Age: ";
	is >> s.age;
	std::cout << "Course: ";
	// Ignore leftover characters
	std::cin.ignore(1, '\n');
	std::getline(is, s.course);
	return is;
}

int main()
{
	Student s;
	std::cin >> s;
	std::cout << std::endl << "ENTERED DATA WAS" << std::endl << "================" << std::endl;
	std::cout << s;

	return 0;
}
