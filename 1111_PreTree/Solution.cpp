#include<iostream>
#include<cstring>

const int max_size = 1e3 + 7;
char ret[max_size];

struct Node {
    char val;
    Node *left;
    Node *right;

    Node(char v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

Node *rebuild(char *NLR, int fbeg, int fend, char *LNR, int sbeg, int send);

char NLR[max_size];
char LNR[max_size];
Node *queue[max_size];
int front = 0;
int rear = 0;


int main() {
    std::cin.getline(NLR, max_size);
    std::cin.getline(LNR, max_size);
    int len = strlen(NLR);
    Node *root = rebuild(NLR, 0, len - 1, LNR, 0, len - 1);
    queue[rear++] = root;
    int i = 0;
    while (rear < max_size && front != rear) {
        if (queue[front] != nullptr) {
            queue[rear++] = queue[front]->left;
            queue[rear++] = queue[front]->right;
            ret[i++] = queue[front++]->val;
        } else {
            ret[i++] = '@';
            queue[rear++] = nullptr;
            queue[rear++] = nullptr;
            front++;
        }
    }
    int k = 0;
    for (int j = 0; j < i; j++) {
        if (ret[j] != '@') {
            for (int l = 0; l < k; l++) {
                std::cout << "NULL ";
            }
            std::cout << ret[j] << " ";
            k = 0;
        } else
            k++;
    }
    return 0;
}

Node *rebuild(char *NLR, int fbeg, int fend, char *LNR, int sbeg, int send) {
    if ((fbeg > fend) || (sbeg > send))
        return nullptr;
    char rootval = NLR[fbeg];
    Node *root = new Node(rootval);
    int sindex = 0;
    for (int i = sbeg; i <= send; i++) {
        if (LNR[i] == rootval) {
            sindex = i;
            break;
        }
    }
    int llen = sindex - sbeg;
    root->left = rebuild(NLR, fbeg + 1, fbeg + llen, LNR, sbeg, sindex - 1);
    root->right = rebuild(NLR, fbeg + llen + 1, fend, LNR, sindex + 1, send);
    return root;
}