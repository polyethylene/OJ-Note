#include<iostream>

const int max = 102;

int main()
{
	int L;
	std::cin >> L;
	int box[max][max] = { 0 }, temp[max][max] = { 0 };
	for (int i = 1; i <= L; i++)
	{
		for (int j = 1; j <= L; j++)
		{
			std::cin >> box[i][j];
			temp[i][j] = box[i][j];
		}
	}
	int count = 0, i, j;
	bool cond = true;
	while (1)
	{
		for (i = 1; i<=L; i++)
		{
			for (j = 1; j<=L; j++)
			{
				if (!box[i][j])
				{
					if (box[i + 1][j] == 1 ||
						box[i][j + 1] == 1 ||
						box[i][j - 1] == 1 ||
						box[i - 1][j] == 1)
					{
						temp[i][j] = 1;
					}
				}
			}
		}
		count++;
		for (int i = 1; i <= L; i++)
		{
			for (int j = 1; j <= L; j++)
			{
				box[i][j] = temp[i][j];
			}
		}
		cond = true;
		for (i = 1; i <= L; i++)
		{
			for (j = 1; j <= L; j++)
			{
				if (!box[i][j])
				{
					cond = false;
					break;
				}
			}
			if (!cond)
			{
				break;
			}
		}
		if (cond)
		{
			break;
		}
	}
	std::cout << count;
	return 0;
}