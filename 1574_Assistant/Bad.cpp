#include<iostream>
#include<cmath>

int main()
{
    int n,m,k,x;
    std::cin>>n>>m>>k>>x;
    std::cout>>(x+pow(10,k)*m)%n;
    return 0;
}