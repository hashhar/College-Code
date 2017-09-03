#include <iostream>
#include <string>

class Company
{
public:
	Company operator+(Company);

	Company operator-(Company);

	void setName(std::string _name)
	{ name = _name; }

	void setRevenue(int _revenue)
	{ revenue = _revenue; }

	void setEmployees(int _employees)
	{ employees = _employees; }

	std::string getName()
	{ return name; }

	int getRevenue()
	{ return revenue; }

	int getEmployees()
	{ return employees; }

private:
	std::string name;
	int revenue;
	int employees;
};

Company Company::operator+(Company a)
{
	Company ret;
	ret.name.assign(this->name);
	ret.name += " ";
	ret.name += a.name;

	ret.revenue = this->revenue + a.revenue;

	ret.employees = this->employees + a.employees;
	return ret;
}

Company Company::operator-(Company)
{
	Company ret;
	ret.name.assign(this->name);

	ret.revenue = this->revenue;

	ret.employees = this->employees;
	return ret;
}

int main()
{
	Company a, b;

	std::cout << "We will add two companies to create a third company." << std::endl;
	std::string _name;
	int _revenue, _employees;
	std::cout << "Enter name of first company: ";
	getline(std::cin, _name);

	std::cout << "Enter the revenue of the company: ";
	std::cin >> _revenue;

	std::cout << "Enter the number of employees in the company: ";
	std::cin >> _employees;

	a.setName(_name);
	a.setRevenue(_revenue);
	a.setEmployees(_employees);

	std::cout << "Enter name of second company: ";
	// Ignore leftover characters
	std::cin.ignore(1, '\n');
	getline(std::cin, _name);

	std::cout << "Enter the revenue of the company: ";
	std::cin >> _revenue;

	std::cout << "Enter the number of employees in the company: ";
	std::cin >> _employees;

	b.setName(_name);
	b.setRevenue(_revenue);
	b.setEmployees(_employees);

	Company c;
	c = a + b;

	std::cout << "Merged comapny details" << std::endl;
	std::cout << "Name: " << c.getName() << std::endl;
	std::cout << "Revenue: " << c.getRevenue() << std::endl;
	std::cout << "Employees: " << c.getEmployees() << std::endl;

	return 0;
}
