#include <iostream>

template<typename T>
void connect(T *a, T *b) {
    a->next = b;
    b->prev = a;
}

struct node {
    int val;
    node *next;
    node *prev;

    node() : next(nullptr), prev(nullptr) {};

    node(int v) : val(v), next(nullptr), prev(nullptr) {};
};

struct linkList {
    node *head;
    node *tail;
    int size;

    linkList() : head(new node()), tail(new node()), size(0) {
        connect(head, tail);
    }

    void push(int val) {
        node *ins = new node(val);
        node *tmp = tail->prev;
        connect(tmp, ins);
        connect(ins, tail);
        size++;
    }
};


const int max_len = 1e5 + 7;

linkList *N[max_len];
int SIZE[max_len];
bool nroot[max_len];

int presize(int pos) {
    if (N[pos]->size == 0) {
        SIZE[pos] = 1;
        return 1;
    }
    node *tmp = N[pos]->head->next;
    SIZE[pos] = 0;
    for (int i = 1; i <= N[pos]->size; i++) {
        SIZE[pos] += presize(tmp->val);
        tmp = tmp->next;
    }
    SIZE[pos]++;
    return SIZE[pos];
}

int main() {
    int size;
    std::cin >> size;
    for (int i = 1; i <= size; i++) {
        N[i] = new linkList();
    }
    for (int i = 1; i <= size - 1; i++) {
        int x, b;
        std::cin >> x >> b;
        N[x]->push(b);
        nroot[b] = true;
    }
    int r;
    for (int i = 1; i <= size; i++) {
        if (!nroot[i]) {
            r = i;
            break;
        }
    }
    presize(r);
    for (int i = 1; i <= size; i++) {
        bool cond = true;
        node *tmp = N[i]->head->next;
        int left = size;
        for (int j = 1; j <= N[i]->size; j++) {
            if (SIZE[tmp->val] > size / 2) {
                cond = false;
                break;
            }
            left -= SIZE[tmp->val];
            tmp = tmp->next;
        }
        if ((left - 1) <= size / 2 && cond) {
            std::cout << i << '\n';
        }
    }
    return 0;
}