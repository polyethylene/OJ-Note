const int max_size = 1000;

int main()
{
    int times;
    std::cin>>times;
    for(int i = 0;i<times;i++)
    {
        int m,n;
        std::cin>>n>>m;
        int out[max_size];
        for(int j = 0;j<n;j++)
        {
            std::cin>>out[j];
        }
        mystack<int> station(m);
        int count1=0,count2=0;
        bool cond = true;
        while(count2!=n+1)
        {
            while(count1 != out[count2])
            {
                if(!station.isempty()&&station.back() == out[count2])
                {    
                    station.pop();
                    count2++;
                }
                else if(station.isfull())
                {
                    std::cout<<"NO"<<std::endl;
                    cond = false;
                    break;
                }
                else
                {
                    station.push(count1);
                    count1++;
                }
            }
            if(!cond)
                break;
            count2++;
        }
        if(cond)
            std::cout>>"YES"<<std::endl;
    }
    return 0;
}