#include <iostream>

class c_polygon
{
public:
	virtual double area()
	{ return 0.0; }
};

class c_rectangle : public c_polygon
{
public:
	double area()
	{ return (length * breadth); }

	c_rectangle(double l, double b) : length(l),
	                                  breadth(b) {}

private:
	double length, breadth;
};

class c_triangle : public c_polygon
{
public:
	double area()
	{ return (0.5 * base * height); }

	c_triangle(double b, double h) : base(b),
	                                 height(h) {}

private:
	double base, height;
};

int main()
{
	double rl, rb, tb, th;
	std::cout << "Rectangle" << std::endl;
	std::cout << "Enter length: ";
	std::cin >> rl;
	std::cout << "Enter breadth: ";
	std::cin >> rb;
	c_rectangle rectangle(rl, rb);
	std::cout << "Area of rectangle: " << rectangle.area() << std::endl << std::endl;

	std::cout << "Triangle" << std::endl;
	std::cout << "Enter base: ";
	std::cin >> tb;
	std::cout << "Enter height: ";
	std::cin >> th;
	c_triangle triangle(rl, rb);
	std::cout << "Area of triangle: " << triangle.area() << std::endl;

	return 0;
}
