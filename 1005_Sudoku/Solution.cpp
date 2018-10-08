#include"stdafx.h"
#include <iostream>

const int dimen = 9;

int main()
{
	int num;
	std::cin >> num;

	bool test[dimen] = { false };
	bool cond = true;
	bool res[20] = { false };

	int sudoku[dimen][dimen];

	for (int times = 0; times < num; times++)
	{
		for (int i = 0; i<dimen; i++)
		{
			for (int j = 0; j<dimen; j++)
			{
				std::cin >> sudoku[j][i];
			}
		}

		//row check
		for (int i = 0; i<dimen; i++)
		{
			for (int j = 0; j<dimen; j++)
			{
				test[sudoku[j][i] - 1] = true;
			}
			for (int j = 0; j<dimen; j++)
			{
				if (!test[j])
				{
					cond = false;
					break;
				}
			}
			for (int j = 0; j < dimen; j++)
			{
				test[j] = false;
			}
			if (!cond)
				break;
		}
		if (!cond)
		{
			cond = true;
			res[times] = false;
			continue;
		}

		//column check
		for (int i = 0; i<dimen; i++)
		{
			for (int j = 0; j<dimen; j++)
			{
				test[sudoku[i][j] - 1] = true;
			}
			for (int j = 0; j<dimen; j++)
			{
				if (!test[j])
				{
					cond = false;
					break;
				}
			}
			for (int j = 0; j < dimen; j++)
			{
				test[j] = false;
			}
			if (!cond)
				break;
		}
		if (!cond)
		{
			cond = true;
			res[times] = false;
			continue;
		}

		//block check
		for (int i = 1; i <= 7; i += 3)
		{
			for (int j = 1; j <= 7; j += 3)
			{
				test[sudoku[i][j - 1] - 1] = true;
				test[sudoku[i][j] - 1] = true;
				test[sudoku[i][j + 1] - 1] = true;
				test[sudoku[i + 1][j - 1] - 1] = true;
				test[sudoku[i + 1][j] - 1] = true;
				test[sudoku[i + 1][j + 1] - 1] = true;
				test[sudoku[i - 1][j - 1] - 1] = true;
				test[sudoku[i - 1][j] - 1] = true;
				test[sudoku[i - 1][j + 1] - 1] = true;
				for (int j = 0; j<dimen; j++)
				{
					if (!test[j])
					{
						cond = false;
						break;
					}
				}
				for (int j = 0; j < dimen; j++)
				{
					test[j] = false;
				}
				if (!cond)
					break;
			}
		}
		if (!cond)
		{
			cond = true;
			res[times] = false;
		}
		else
			res[times] = true;
	}
	for (int i = 0; i < num; i++)
	{
		if (res[i])
			std::cout << "Right\n";
		else
			std::cout << "Wrong\n";
	}
	return 0;
}