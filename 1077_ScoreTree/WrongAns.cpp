#include<iostream>
#include<cstring>

struct Node {
    int val;
    int num;
    Node *left;
    Node *right;

    Node() : val(0), num(0), left(nullptr), right(nullptr) {}

    Node(int v, int n, Node *l = nullptr, Node *r = nullptr) : val(v), num(n), left(l), right(r) {}
};

const int max_size = 40;
Node *li[max_size];

Node *buildTree(Node **li, int beg, int end);

int find_max(Node **li, int beg, int end);

long long score(Node *root);

void NLR(Node *root);

int main() {
    int size;
    std::cin >> size;
    int temp;
    for (int i = 0; i < size; i++) {
        std::cin >> temp;
        li[i] = new Node(temp, i + 1);
    }
    Node *res = buildTree(li, 0, size - 1);
    std::cout << score(res) << std::endl;
    NLR(res);
    return 0;
}

Node *buildTree(Node **li, int beg, int end) {
    if (beg <= end) {
        int ind = find_max(li, beg, end);
        li[ind]->left = buildTree(li, beg, ind - 1);
        li[ind]->right = buildTree(li, ind + 1, end);
        return li[ind];
    }
    return nullptr;
}

int find_max(Node **li, int beg, int end) {
    int min = 101, ind = 0;
    for (int i = beg; i <= end; i++) {
        if (li[i]->val < min) {
            min = li[i]->val;
            ind = i;
        }
    }
    return ind;
}

long long score(Node *root) {
    if (root->left && root->right) {
        return root->val + score(root->left) * score(root->right);
    } else if (root->left) {
        return root->val + score(root->left);
    } else if (root->right) {
        return root->val + score(root->right);
    } else {
        return root->val;
    }
}

void NLR(Node *root) {
    std::cout << root->num << " ";
    if (root->left) {
        NLR(root->left);
    }
    if (root->right) {
        NLR(root->right);
    }
}