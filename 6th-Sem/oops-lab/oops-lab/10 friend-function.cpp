#include <iostream>

// Forward declaration for friend function in TwoNumbers
class ThreeNumbers;

class TwoNumbers
{
public:
	TwoNumbers(int _a, int _b) : a(_a),
	                             b(_b) {}
	TwoNumbers(const TwoNumbers& t) : a(t.a),
	                                  b(t.b) {}
	TwoNumbers operator=(const TwoNumbers&);

	friend double computeAverage(TwoNumbers, ThreeNumbers);

private:
	int a, b;
};

TwoNumbers TwoNumbers::operator=(const TwoNumbers& t)
{
	a = t.a;
	b = t.b;
	return *this;
}

class ThreeNumbers
{
public:
	ThreeNumbers(int _a, int _b, int _c) : a(_a),
	                                       b(_b),
	                                       c(_c) {}
	ThreeNumbers(const ThreeNumbers& t) : a(t.a),
	                                      b(t.b),
	                                      c(t.c) {}
	ThreeNumbers operator=(const ThreeNumbers&);

	friend double computeAverage(TwoNumbers, ThreeNumbers);

private:
	int a, b, c;
};

ThreeNumbers ThreeNumbers::operator=(const ThreeNumbers& t)
{
	a = t.a;
	b = t.b;
	c = t.c;
	return *this;
}

double computeAverage(TwoNumbers tw, ThreeNumbers th)
{
	return ((tw.a + tw.b + th.a + th.b + th.c) / 5);
}

int main()
{
	int a, b, c;
	std::cout << "Enter two numbers for first class: ";
	std::cin >> a >> b;
	TwoNumbers tw(a, b);

	std::cout << "Enter three numbers for second class: ";
	std::cin >> a >> b >> c;
	ThreeNumbers th(a, b, c);

	std::cout << "The average is: " << computeAverage(tw, th) << std::endl;

	return 0;
}
