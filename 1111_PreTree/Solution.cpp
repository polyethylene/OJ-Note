#include<iostream>

const int max_size = 1e3+7;

char NLR[max_size];
char LNR[max_size];
Node* queue[max_size];
int front = 0;int rear = 0;

struct Node{
    char val;
    *Node left;
    *Node right;
    Node(char v){
        val = v;
    }
}

int main()
{
    std::cin>>NLR;
    std::cin>>LNR;
    int len = strlen(NLR);
    Node* root = rebuild(NLR,0,len,LNR,0,len);
    
    return 0;
}

*Node rebuild(char* NLR,int fbeg,int fend,char* LNR,int sbeg,int send){
    if((fbeg>fend)||(sbeg>send))
        return nullptr;
    char rootval = pre[fbeg];
    Node* root = new Node(rootval);
    root.left = nullptr;
    root.right = nullptr;
    int sindex = 0;
    for(int i = sbeg;i<send;i++)
    {
        if(LNR[i] == rootval){
            sindex = i;
            break;
        }
    }
    int llen = sindex- sbeg;
    int rlen = llen + fbeg;
    root.left = rebuild(NLR,fbeg+1,rlen,LNR,sbeg,sindex);
    root.right = rebuild(NLR,rlen,fend,LNR,sindex+1,send);
    return root;
}

void output(node* root, int len)
{
    int count = 0;
    queue[rear++] = root;
    node* mid = root;
    while(count<len){
        front++;
        if(mid)
        {
            std::cout<<mid.val<<" ";
        }
        else
            std::cout<<"NULL ";
        
    }

}