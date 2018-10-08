#include "MyStack.h"

enum key { BEGIN,IF };

int main()
{
	mystack<key> keywordsA(15);
	mystack<key> keywordsB(15);
	char word[100];
	bool cond = true;
	while (std::cin >> word)
	{
		if (!strcmp(word, "begin"))
		{
			keywordsA.push(BEGIN);
		}
		else if (!strcmp(word, "end"))
		{
			if (keywordsA.back() != BEGIN)
			{
				std::cout << "Error!";
				cond = false;
				break;
			}
			else
				keywordsA.pop();
		}
		else if (!strcmp(word, "if"))
			keywordsA.push(IF);
		else if (!strcmp(word, "then"))
		{
			if (keywordsA.back() != IF)
			{
				std::cout << "Error!";
				cond = false;
				break;
			}
			else
			{
				keywordsB.push(IF);
				keywordsA.pop();
			}
		}
		else if (!strcmp(word, "else"))
		{
			if (keywordsB.isempty())
			{
				std::cout << "Error!";
				cond = false;
				break;
			}
			else
				keywordsB.pop();
		}
	}
	if (cond && keywordsA.isempty())
		std::cout << "Match!";
	else if (cond && !keywordsA.isempty())
		std::cout << "Error!";
	return 0;
}