#include <iostream>
#include <cstring>

const int max_size = 127;

int main()
{
	char str1[max_size], str2[max_size];
	std::cin >> str1;
	std::cin >> str2;
	int len = strlen(str1), div = 1;
	bool cond = true;
	for (div; div<max_size; div++)
	{
		if (!(len%div))
		{
			int n = len / div;
			for (int i = 0; i<div; i++)
			{
				for (int j = 0; j<n; j++)
				{
					if (str1[i + j*div] != str2[i*n + j])
					{
						cond = false;
						break;
					}
					else
						cond = true;
				}
				if (!cond)
					break;
			}
		}
		if (cond)
			break;
	}
	if (cond)
		std::cout << div;
	else
		std::cout << "No Solution";
	return 0;
}
