#include<iostream>

int ffb(long long* li, int beg, int end, long long tar);

int main()
{
	std::ios::sync_with_stdio(false);

	int sizeX, sizeY;
	std::cin >> sizeX >> sizeY;

	long long *X = new long long[sizeX];
	long long *Y = new long long[sizeY];
	
	for (int i = 0; i < sizeX; i++)
	{
		std::cin >> X[i];
	}
	
	for (int i = 0; i < sizeY; i++)
	{
		std::cin >> Y[i];
	}

	for (int i = 0; i < sizeY; i++)
	{
		int pos = ffb(X, 0, sizeX, Y[i]);
		std::cout << sizeX - pos << "\n";
	}

	delete[] X;
	delete[] Y;
	return 0;
}


//find first bigger
int ffb(long long* li, int beg, int end,long long tar)
{
	while (beg + 1 < end)
	{
		int mid = (beg + end) / 2;
		if (li[mid] > tar)
			end = mid;
		else
			beg = mid;
	}
	if (li[beg] > tar)
		return beg;
	else
		return end;
}