#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cin>>n;
    int q = (1+sqrt(1+8*(double)(n))/2;
    if(q*q+q<2*n)
        q+=1;
    std::cout<<n-(q*q+q)/2<<"/"<<q;
    return 0;    
}