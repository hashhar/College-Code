#include <iostream>

class Math
{
public:
	double getA()
	{ return a; }

	void   setA(double);

	double getB()
	{ return b; }

	void   setB(double);

	double add()
	{ return (a + b); }

	double subtract()
	{ return (a - b); }

	double multiply()
	{ return (a * b); }

	double divide();
	double modulus();

private:
	double a, b;
};

void Math::setA(double num)
{
	// Store as an integer if an integer was input
	if (static_cast<int>(num) == num)
		a = static_cast<int>(num);
	else
		a = num;
}

void Math::setB(double num)
{
	// Store as an integer if an integer was input
	if (static_cast<int>(num) == num)
		b = static_cast<int>(num);
	else
		b = num;
}

double Math::divide()
{
	if (b == 0)
	{
		std::cerr << "Division by 0 not allowed!" << std::endl;
		// a / b equals 0 only when a = 0. We use this to detect error.
		return 0;
	}
	return (a / b);
}

double Math::modulus()
{
	// If the value casted to an integer is the same as the original value, the value is an integer.
	if (static_cast<int>(a) == a && static_cast<int>(b) == b && static_cast<int>(b) != 0)
		return (static_cast<int>(a) % static_cast<int>(b));
	std::cerr << "Modulus is defined only for integers!" << std::endl;
	// Since a % b never equals b, returning b indicated error.
	return b;
}

int main()
{
	Math maths;
	double num;
	std::cout << "Enter first number: ";
	std::cin >> num;
	maths.setA(num);
	std::cout << "Enter second number: ";
	std::cin >> num;
	maths.setB(num);

	std::cout << "Sum: "        << maths.add()      << std::endl;
	std::cout << "Difference: " << maths.subtract() << std::endl;
	std::cout << "Product: "    << maths.multiply() << std::endl;

	if (maths.divide() != 0 && maths.getA() != 0)
		std::cout << "Division: " << maths.divide() << std::endl;

	if (maths.modulus() != maths.getB())
		std::cout << "Modulus: " << maths.modulus() << std::endl;

	return 0;
}
