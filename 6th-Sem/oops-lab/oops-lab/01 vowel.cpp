#include <iostream>

int countVowels(char* str)
{
	char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	int numVowels = 10, count = 0;
	for (int i = 0; *(str + i) != '\0'; i++)
	{
		for (int j = 0; j < numVowels; j++)
		{
			if (*(str + i) == vowels[j])
				count++;
		}
	}
	return count;
}

int countDistinctVowels(char* str)
{
	char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	int numVowels = 10, count = 0;
	for (int i = 0; *(str + i) != '\0'; i++)
	{
		for (int j = 0; j < numVowels; j++)
		{
			if (*(str + i) == vowels[j])
			{
				count++;
				// Replace the visited vowels with '\0' to ensure they don't match again
				vowels[j] = vowels[j + 5] = '\0';
			}
		}
	}
	return count;
}

int main()
{
	char str[100];
	std::cout << "Enter the string to count vowels in: ";
	std::cin.getline(str, 100);

	std::cout << "Total vowels: " << countVowels(str) << std::endl;
	std::cout << "Disctinct vowels: " << countDistinctVowels(str) << std::endl;

	return 0;
}
