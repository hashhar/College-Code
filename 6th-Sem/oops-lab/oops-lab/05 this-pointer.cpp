#include <iostream>
#include <string>

class PntrObj
{
public:
	int getRollNo();
	void setRollNo(int);

	std::string getName();
	void setName(std::string);

	void setObjName(char);

private:
	char objName;
	int rollNo;
	std::string name;
};

void PntrObj::setRollNo(int roll)
{ rollNo = roll; }

void PntrObj::setName(std::string _name)
{ name.assign(_name); }

void PntrObj::setObjName(char id)
{ objName = id; }

int PntrObj::getRollNo()
{
	std::cout << "get_rollNo() called by: " << this->objName << std::endl;
	return rollNo;
}

std::string PntrObj::getName()
{
	std::cout << "get_name() called by: " << this->objName << std::endl;
	return name;
}

int main()
{
	PntrObj a, b, c;

	a.setObjName('a');
	b.setObjName('b');
	c.setObjName('c');

	a.setRollNo(1);
	a.setName("Ashhar");

	b.setRollNo(2);
	b.setName("Akash");

	c.setRollNo(3);
	c.setName("Sonaal");

	std::cout << a.getName() << " " << a.getRollNo() << std::endl;
	std::cout << b.getName() << " " << b.getRollNo() << std::endl;
	std::cout << c.getName() << " " << c.getRollNo() << std::endl;

	return 0;
}
