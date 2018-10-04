#include <iostream>

int main()
{
	int size;
	std::cin >> size;
	int* times = new int[size - 1];
	for (int i = 0; i<size - 1; i++)
	{
		std::cin >> times[i];
	}
	int ret = 0;
	for (int i = 2; i <= size; i++)
	{
		std::cin >> times;
		ret = (ret + times[size - i]) % i;
	}
	std::cout << ret + 1;
	return 0;
}
