#include<iostream>

const int max = 103;

int main()
{
/*    int box[max][max]={0},temp[max][max]={0};
    for(int i = 1;i<=L;i++)
    {    
        for(int j = 1;i<=L;i++)
        {
            std::cin>>box[i][j];
            temp[i][j]=box[i][j];
        }
    }
    int count = 1,i,j;
    bool cond = false;
    while(1)
    {
        for(int i = 0;i<L;i++)
        {
            for(int j = 0;j<L;j++)
            {
                if(!box[i][j])
                {
                    if(box[i+1][j]==1||
                    box[i+1][j+1]==1||
                    box[i+1][j-1]==1||
                    box[i][j+1]==1||
                    box[i][j-1]==1||
                    box[-1][j]==1||
                    box[i-1][j+1]==1||
                    box[i-1][j-1]==1)
                    {
                        temp[i][j] = 1;
                    }
                }
            }
        }
        for(i = 0;i<L;i++)
        {
            for(j = 0;j<L;j++)
            {
                if(!box[i][j])
                {
                    break;   
                }
            }
            if(!box[i][j])
            {
                break;   
            }
        }
        if(box[i][j])
        {
            break;
        }
        count++;
        for(int i = 1;i<=L;i++)
        {    
            for(int j = 1;i<=L;i++)
            {
                box[i][j]=temp[i][j];
            }
        }
    }*/

    int size;
    std::cin>>size;
    char[2*max+1][max] box ,char[2*max+1][max] temp;
    for(int i = 1;i<=size;i++)
    {
        std::cin>>box[i];
        strcpy(temp[i],box[i]);
    }
    while(1)
    {
        for(int i = 1;i<=2*L+1;i+=2)
        {
            for(int j = 1;j<=L;j++)
            {
                if(box[i][j]=='0')
                {
                    if(box[i+2][j]=='1'||
                    box[i+2][j+1]=='1'||
                    box[i+2][j-1]=='1'||
                    box[i][j+1]=='1'||
                    box[i][j-1]=='1'||
                    box[i-2][j]=='1'||
                    box[i-2][j+1]=='1'||
                    box[i-2][j-1]=='1')
                    {
                        temp[i][j] = '1';
                    }
                }
            }
        }
        for(int i = 1;i<=2*L+1;i+=2)
        {
            for(int j = 1;j<=L;j++)
            {
                if(!box[i][j])
                {
                    break;   
                }
            }
            if(!box[i][j])
            {
                break;   
            }
        }
        if(box[i][j])
        {
            break;
        }
        count++;
        for(int i = 1;i<=2*L+1;i+=2)
        {
            for(int j = 1;j<=L;j++)
            {
                box[i][j]=temp[i][j];
            }
        }
    }
    std::cout>>count;
    return 0;
}