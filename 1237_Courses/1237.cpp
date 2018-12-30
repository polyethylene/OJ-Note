#include<iostream>

using namespace std;

const int max_len = 1e4 + 7;
const int NaN = 0xf7777777;

struct list_node {
    int val;
    list_node *next;
    list_node *prev;

    list_node(int v) : val(v), next(nullptr), prev(nullptr) {};
};

void connect(list_node *a, list_node *b) {
    a->next = b;
    b->prev = a;
}

struct link_list{
    node* head,tail;
    int size;

    link_list() : head(new list_node(0)), tail(new list_node(0)), size(0) {
        connect(head, tail);
    }

    void push_f(int i) {
        list_node *n = new list_node(i);
        list_node *tmp = head->next;
        connect(head, n);
        connect(n, tmp);
        size++;
    }
};

struct node {
    link_list next_list;
    int in_deg;

    node() : in_deg(0) {}
};

struct my_queue {
    int data[max_len];
    int head, tail;

    my_queue() : head(0), tail(0) {}

    bool empty() {
        return head == tail;
    }

    void enqueue(int i) {
        data[tail++] = i;
    }

    int dequeue() {
        return data[head++];
    }
};

node li[max_len];
my_queue Q;
int n;
int count = 0;

void push_all_zero() {
    for (int i = 1; i <= n; i++) {
        if (li[i].in_deg == 0) {
            li[i].in_deg = NaN;
            Q.enqueue(i);
        }
    }
}

void del_next_node(int i) {
    list_node *to = li[i].next_list.head->next;
    while (to != li[i].next_list.tail) {
        li[to->val].in_deg--;
        to = to->next;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        li[b].in_deg++;
        li[a].next_list.push_f(b);
    }
    push_all_zero();
    while (!Q.empty()) {
        while(!Q.empty()){
            int to = Q.dequeue();
            del_next_node(to);
        }
        push_all_zero();
        count++;
    }
    cout << count;
    return 0;
}