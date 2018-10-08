#include<iostream>

int main()
{
    int N,X,Y;
    std::cin>>N>>Y>>X;
    int res = 0,count = N-1,x = 0,y= 0;
    while(1)
    {
        for(int i = 0;i<count;i++)
        {
            if(x == X&& y == Y)
                break;
            x++;
            res++;
        }
        if(x == X&& y == Y)
            break;
        for(int i = 0;i<count;i++)
        {
            if(x == X&& y == Y)
                break;
            y++;
            res++;
        }
        if(x == X&& y == Y)
            break;
        for(int i = 0;i<count-1;i++)
        {
            if(x == X&& y == Y)
                break;
            x--;
            res++;
        }
        if(x == X&& y == Y)
            break;
        for(int i = 0;i<count-1;i++)
        {
            if(x == X&& y == Y)
                break;
            y--;
            res++;
        }
        if(x == X&& y == Y)
            break;
        count--;
    }
    std::cout<<res;
    return 0;
}