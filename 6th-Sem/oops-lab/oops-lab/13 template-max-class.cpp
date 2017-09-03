#include <iostream>

template <class T>
class Max
{
public:
	Max(T _a, T _b) : a(_a),
	                  b(_b) {}

	T max()
	{
		if (a > b)
			return a;
		else if (a < b)
			return b;
		else
			return (a - b);
	}

private:
	T a, b;
};

int main()
{
	int ai, bi;
	char ac, bc;
	float af, bf;
	double ad, bd;

	std::cout << "Enter two integers: ";
	std::cin >> ai >> bi;
	Max<int> i(ai, bi);
	std::cout << "Max: " << i.max() << std::endl << std::endl;

	std::cout << "Enter two characters: ";
	std::cin >> ac >> bc;
	Max<char> c(ac, bc);
	std::cout << "Max: " << c.max() << std::endl << std::endl;

	std::cout << "Enter two floats: ";
	std::cin >> af >> bf;
	Max<float> f(af, bf);
	std::cout << "Max: " << f.max() << std::endl << std::endl;

	std::cout << "Enter two doubles: ";
	std::cin >> ad >> bd;
	Max<double> d(ad, bd);
	std::cout << "Max: " << d.max() << std::endl << std::endl;

	return 0;
}
