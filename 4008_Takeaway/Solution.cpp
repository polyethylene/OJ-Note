#include<iostream>
#include<cstring>

const int max = 105;

int main()
{
	char rhs[max], lhs[max];
	int res[max] = { 0 };
	std::cin >> rhs >> lhs;
	int rlen = strlen(rhs), llen = strlen(lhs);
	int len = (llen>rlen) ? llen : rlen;
	int count = len;
	int count1 = rlen-1;
	int count2 = llen-1;
	while (count)
	{
		if (count1+1&&count2+1)
		{
			res[count] = rhs[count1] - 97 + lhs[count2] - 97;
			count1--;
			count2--;
			count--;
		}
		else if (count1+1)
		{
			res[count] = rhs[count1] - 97;
			count1--;
			count--;
		}
		else
		{
			res[count] = lhs[count2] - 97;
			count2--;
			count--;
		}
	}
	res[0] = 0;
	for (int i = len; i>0; i--)
	{
		if (res[i] >= 26)
		{
			res[i] %= 26;
			res[i - 1]++;
		}
	}
	if (res[0])
	{
		std::cout << "b";
	}
	for (int i = 1; i<=len; i++)
	{
		char temp = res[i] + 97;
		std::cout << temp;
	}
	return 0;
}