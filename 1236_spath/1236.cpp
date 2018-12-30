#include <iostream>

using namespace std;

const int inf = 0x7fffffff;

const int max_edge_size = 107;
const int max_node_size = 17;

struct list_node {
    pair<int, int> val;
    list_node *next;
    list_node *prev;

    list_node(pair<int, int> v) : val(v), next(nullptr), prev(nullptr) {};
};

void connect(list_node *a, list_node *b) {
    a->next = b;
    b->prev = a;
}

struct link_list {
    list_node *head, *tail;
    int size;

    link_list() : head(new list_node({0, 0})), tail(new list_node({0, 0})), size(0) {
        connect(head, tail);
    }

    void push_f(pair<int, int> i) {
        list_node *n = new list_node(i);
        list_node *tmp = head->next;
        connect(head, n);
        connect(n, tmp);
        size++;
    }
};

struct node {
    link_list next_list;

    node() = default;
};

struct my_queue {
    int data[max_node_size];
    int front, rear;

    my_queue() : front(0), rear(0) {}

    void enQueue(int i) {
        data[rear++] = i;
        rear %= max_node_size;
    }

    int deQueue() {
        int ret = data[front++];
        front %= max_node_size;
        return ret;
    }

    bool empty() {
        return front == rear;
    }
};

node li[max_node_size];
int dis[max_node_size];
my_queue Q;
int n, bg, ed;

void init() {
    for (int i = 1; i <= n; i++) {
        dis[i] = inf;
    }
    dis[bg] = 0;
}

void calc() {
    Q.enQueue(bg);
    while (!Q.empty()) {
        int tmp = Q.deQueue();
        list_node *nt = li[tmp].next_list.head->next;
        while (nt != li[tmp].next_list.tail) {
            if (dis[nt->val.first] > dis[tmp] + nt->val.second) {
                Q.enQueue(nt->val.first);
                dis[nt->val.first] = dis[tmp] + nt->val.second;
            }
            nt = nt->next;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> n >> m >> bg >> ed;
    for (int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        li[a].next_list.push_f({b, p});
    }
    init();
    calc();
    cout << dis[ed];
    cout << flush;
    return 0;
}