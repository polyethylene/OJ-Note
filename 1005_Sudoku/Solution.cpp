#include <iostream>

const int dimen = 9;

int main ()
{
    int num;
    std::cin>>num;

    bool test[dimen] = {false};
    bool cond = true;

    int sudoku[dimen][dimen];
    while(num)
    {
        for(int i = 0;i<dimen;i++)
        {
            for(int j = 0;j<dimen;j++)
            {
                std::cin>>sudoku[j][i];
            }
        }

        //row check
        for(int i = 0;i<dimen;i++)
        {
            for(int j = 0;j<dimen;j++)
            {
                test[sudoku[j][i]-1] = true;
            }
            for(int j = 0;j<dimen;j++)
            {
                if(!test[j])
                {
                    cond = false;
                    break;
                }
            }
        }
        if(!cond)
        {
            cond = true;
            std::cout>>"Wrong\n";
            n--;
            continue;
        }

        //column check
        for(int i = 0;i<dimen;i++)
        {
            for(int j = 0;j<dimen;j++)
            {
                test[sudoku[i][j]-1] = true;
            }
            for(int j = 0;j<dimen;j++)
            {
                if(!test[j])
                {
                    cond = false;
                    break;
                }
            }
        }
        if(!cond)
        {
            cond = true;
            std::cout>>"Wrong\n";
            n--;
            continue;
        }

        //block check
        for(int i = 1;i<=7;i+=3)
        {
            for(int i = 1;i<=7;i+=3)
            {
                test[sodoku[i][j-1]] = true;
                test[sodoku[i][j]] = true;
                test[sodoku[i][j+1]] = true;
                test[sodoku[i+1][j-1]] = true;
                test[sodoku[i+1][j]] = true;
                test[sodoku[i+1][j+1]] = true;
                test[sodoku[i-1][j-1]] = true;
                test[sodoku[i-1][j]] = true;
                test[sodoku[i-1][j+1]] = true;
            }
            for(int j = 0;j<dimen;j++)
            {
                if(!test[j])
                {
                    cond = false;
                    break;
                }
            }
        }
        if(!cond)
        {
            cond = true;
            std::cout>>"Wrong\n";
            n--;
            continue;
        }
        else
        {
            std::cout>>"Right\n";
            n--;
        }
    }


    return 0;
}