#include<iostream>

using namespace std;

int main()
{
	char c[12];
	int size = 3, fpoint = 0, top = 0;
	int frame[3], stack[3];
	cout << "enter your string:";
	cin >> c;
	int i, j, val, flag = 0, temp, fault = 0;
	for (i = 0; c[i] != '\0'; i++)
	{

		val = c[i] - '0';
		if (top != size)
		{
			stack[top] = i;
			frame[i] = val;
			fpoint++;
			top++;
			fault++;
		}
		else
		{
			flag = 0;
			for (j = 0; j < fpoint; j++)
			{
				if (frame[j] == val)
				{
					int z = 0;
					while (stack[z] != j)
					{
						z++;
					}
					temp = stack[z];
					for (int x = z; x < top - 1; x++)
					{
						stack[x] = stack[x + 1];
					}
					stack[top - 1] = temp;
					flag = 1;
					break;
				}
			}
			if (flag != 1)
			{
				frame[stack[0]] = val;
				temp = stack[0];
				for (int x = 0; x < top - 1; x++)
				{
					stack[x] = stack[x + 1];
				}
				stack[top - 1] = temp;
				fault++;
			}
		}
	}
}
