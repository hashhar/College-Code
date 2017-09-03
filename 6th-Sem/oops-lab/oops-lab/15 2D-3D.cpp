#include <iostream>
#include <cmath>

class TwoD
{
public:
	double distance(TwoD A)
	{ return (sqrt(pow((A.x - this->x), 2) + pow((A.y - this->y), 2))); }

	TwoD() : x(0),
	         y(0) {}

	TwoD(int _x, int _y) : x(_x),
	                       y(_y) {}

private:
	int x, y;
};

class ThreeD : public TwoD
{
public:
	double distance(ThreeD A)
	{ return (sqrt(pow((A.x - this->x), 2) + pow((A.y - this->y), 2) + pow((A.z - this->z), 2))); }

	ThreeD(int _x, int _y, int _z) : TwoD(),
	                                 x(_x),
	                                 y(_y),
	                                 z(_z) {}

private:
	int x, y, z;
};

int main()
{
	int x, y, z;
	std::cout << "Enter point A: ";
	std::cin >> x >> y >> z;
	ThreeD A(x, y, z);
	std::cout << "Enter point B: ";
	std::cin >> x >> y >> z;
	ThreeD B(x, y, z);

	std::cout << "The distance is: " << B.distance(A) << std::endl;
}
