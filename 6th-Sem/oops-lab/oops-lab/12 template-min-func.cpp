#include <iostream>

template <class T>
T min(T a, T b)
{
	if (a < b)
		return a;
	else if (a > b)
		return b;
	else
		return (a - b);
}

int main()
{
	int ai, bi;
	char ac, bc;
	float af, bf;
	double ad, bd;

	std::cout << "Enter two integers: ";
	std::cin >> ai >> bi;
	std::cout << "Min: " << min(ai, bi) << std::endl << std::endl;
	std::cout << "Enter two characters: ";
	std::cin >> ac >> bc;
	std::cout << "Min: " << min(ac, bc) << std::endl << std::endl;
	std::cout << "Enter two floats: ";
	std::cin >> af >> bf;
	std::cout << "Min: " << min(af, bf) << std::endl << std::endl;
	std::cout << "Enter two doubles: ";
	std::cin >> ad >> bd;
	std::cout << "Min: " << min(ad, bd) << std::endl << std::endl;

	return 0;
}
