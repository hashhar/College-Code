#include <iostream>

int reverse(int num)
{
	int n = 0;
	while (num)
	{
		int digit = num % 10;
		num /= 10;
		n = (n * 10) + digit;
	}
	return n;
}

int main()
{
	int num;
	std::cout << "Enter a number: ";
	std::cin >> num;

	std::cout << reverse(num) << std::endl;

	return 0;
}
