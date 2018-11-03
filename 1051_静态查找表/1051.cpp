#include<iostream>

int size, times;
int count = 0;

struct Node {
    int val;
    Node *next = nullptr;

    Node(int v, Node *n = nullptr) : val(v), next(n) {}
};

Node tail(0);
Node head(0,&tail);

void Insert(Node *n, int v) {
    if (n) {
        Node *a = new Node(v, n->next);
        n->next = a;
    }
}

void putForward(Node *n) {
    if (n!=&head&&n->next!=&tail) {
        Node *temp = n->next;
        n->next = temp->next;
        temp->next = head.next;
        head.next = temp;
    }
}

void find(int v) {
    Node *ret = &head;
    Node *temp = ret->next;
    count++;
    while (temp != &tail && temp->val != v) {
        ret = temp;
        temp = temp->next;
        count++;
    }
    if(temp == &tail){
        count--;
    }
    putForward(ret);
}

int main() {
    std::cin >> size;
    Node *temp = &head;
    int n;
    for (int i = 0; i < size; i++) {
        std::cin >> n;
        Insert(temp, n);
        temp = temp->next;
    }
    std::cin >> times;
    for (int i = 0; i < times; i++) {
        std::cin >> n;
        find(n);
    }
    std::cout << count;
    return 0;
}