#include<iostream>

int main()
{
	long long n, m, k, x;
	std::cin >> n >> m >> k >> x;

	long long step = m;
	int times = k / 6;
	int rest = k % 6;
	for (int i = 0; i < times; i++)
	{
		step *= 1000000;
		step %= n;
	}
	for (int i = 0; i < rest; i++)
	{
		step *= 10;
	}
	step %= n;
	std::cout << (x + step) % n;
	return 0;
}