#include<iostream>

const int max = 20005;
int T[max];
int B[max];
int Thead = 0,Trear = 0,Bhead = 0,Brear = 0;
int size,clock = 0;
int Btime = 0;Ttime = 0;

int main()
{
    std::cin>>size;
    for(int i = 0;i<size;i++)
    {
        bool type;
        int time;
        std::cin>>type;
        std::cin>>time;
        if(type)
        {
            T[Trear++] = time;
        }
        else
        {
            B[Brear++] = time;
        }
    }
    while(Bhead!=Brear || Thead!=Trear) 
    {
        int scount = 0;
        while((Bhead!=Brear || Thead!=Trear) && scount<10)
        {
            for(int i = 0;i<4;i++)
            {
                if(Bhead!=Brear&&B[Bhead]<clock)
                {
                    Bhead++;
                    scount++;
                }
                else
                    break;
            }
            if(Thead!=Trear&&T[Thead]<clock)
            {   
                Thead++;
                scount++;
            }
        }
        int Bcount = Bhead,Tcount = Thead;
        while(Bcount!=Brear&&B[Bcount]<clock)
        {
            Btime+=clock-B[Bcount];
            Bcount++;
        }
        while(Tcount!=Trear&&T[Tcount]<clock)
        {
            Ttime+=clock-T[Tcount];
            Tcount++;
        }
        clock+=10;
    }
    std::cout<<(double)Btime/(double)Brear<<(double)Ttime/(double)Trear;
    return 0;
}