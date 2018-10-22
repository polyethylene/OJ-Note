#include <iostream>

const int MaxSize = 1e6 + 7;

char stackA[MaxSize], stackB[MaxSize];
bool test[MaxSize] = {0};
int size, Asize = 0, Bsize = 0;

/*bool isLeft(char ch){
    return (ch == '(' || ch == '[' || ch == '{');
}*/

/*char getRight(char ch){
    if (ch == '(') return ')';
    else if (ch == '[') return ']';
    else if (ch == '{') return '}';
    else return ' ';
}*/

/*char getLeft(char ch){
    if (ch == ')') return '(';
    else if (ch == ']') return '[';
    else if (ch == '}') return '{';
    else return ' ';
}*/

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> size;
    for(int i = 0;i < size;i++)
    {
        int input;
        char syn;
        std::cin >> input;
        switch(op)
        {
        case 1:
            cin >> syn;
            stackA[Asize++] = syn;
            if (syn == '('||syn == '['||syn == '('){
                stackB[Bsize++] = syn;
                test[Asize - 1] = true;
            }
            else{
                char temp = stackB[Bsize - 1];
                char tempRight = (temp == '(')?')':(temp == '[')?']':(temp == '{')?'}':' ';
                if (Bsize != 0 && temp && syn == tempRight){
                    --Bsize;
                    Bstack[Bsize - 1] = true;
                }
                else{
                    Bstack[isize++] = syn;
                    test[fsize - 1] = false;
                }
            }
            break;
        case 2:
            if (Asize == 0)
                break;
            syn = stackA[Asize - 1];
            if (syn=='('||syn == '['||syn == '{')
                --Bsize;
            else{
                if (test[Asize - 1])
                {
                    char temp = (ch == '(')?')':(ch == '[')?']':(ch == '{')?'}':' ';
                    Bstack[Bsize++] = temp;
                }
                else
                    --Bsize;
            }
            --Asize;
            break;
        case 3:
            if (Asize != 0)
                cout << full[Asize - 1] << '\n';
            break;
        case 4:
            if (Bsize)
                std::cout << "NO\n";
            else
                std::cout << "YES\n";
            break;
        }
    }
    return 0;
}