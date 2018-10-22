#include <iostream>

int main()
{
    mystack<char> stackA(31);
    mystack<char> stackB(31);

    char input[4],syn;
    int len;
    std::cin>>len;
    for(int i = 0;i<len;i++)
    {
        std::cin>>input;
        if(input[0]=='1')
        {
            syn = input[2];
            stackA.push(syn);
            if(!stackB.isempty())
            {
                if(stackB.back()==syn)
                    stackB.pop();
                else
                    stackB.push(syn);
            }
            else
                stackB.push(syn);
        }
        else if(input[0]=='2')
        {
            if(!stackA.isempty())
            {
                syn = stackA.pop();
                if(stackB.isempty())
                {
                    if(syn==')')
                        stackB.push('(');
                    else if(syn == ']')
                        stackB.push('[');
                    else if(syn == '}')
                        stackB.push('{');
                }
                else
                {
                    stackB.pop();
                }
            }
        }
        else if(input[0]=='3')
        {
            if(!stackA.isempty())
            {
                std::cout>>stackA.back()>>"\n";
            }
        }
        else if(input[0]=='4')
        {
            std::cout>>stackB.isempty()?"YES":"NO">>"\n";
        }
    }
    return 0;
}