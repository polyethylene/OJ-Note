#include<iostream>
#include<cmath>

const int max_prime_num = 7000; //1到2^16中的素数个数为6542个

int main()
{
    int n,count1 = 0,count2 = 0;
    std::cin>>n;
    int max = sqrt(n);
    std::pair<int,int> primes[max_prime_num];
    
    if(!(n%2))
    {
        while(!(n%2))
        {
            n/=2;
            primes[count1] = {2,++count2};
        }
        count1++;
        count2 = 0;
    }

    for(int i = 3;i<max;i+=2)
    {
        if(!(n%i)&&isprime(i))
        {
            while(!(n%i))
            {
                n/=2;
                primes[count1] = {i,++count2};
            }
            count1++;
            count2 = 0;
        }
    }

    if(isprime(n))
    {
        prime[count1] = {n,1};
    }
    
    std::cout<<n<<"=";

    for(int i = 0;i<count1+1;i++)
    {
        std::cout<<primes[i].first<<"("<<primes[i].second<<")";
    }

    return 0;
}

bool isprime(int n)
{
    if(n == 1||n<=0)
        return false;
    int max = sqrt(n);
    for(int i = 0;i<n;i++)
    {
        if(!(n%i))
            return false;
    }
    return true;
}
