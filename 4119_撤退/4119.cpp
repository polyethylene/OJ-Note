#include <iostream>

using namespace std;

const int inf = 0x7fffffff;

const int max_node_size = 2e4 + 7;

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
int dis[3][max_node_size];
int n, bg[3];

void init() {
    for (int j = 0; j < 3; j++) {
        for (int i = 1; i <= n; i++) {
            dis[j][i] = inf;
        }
    }
    dis[0][bg[0]] = dis[1][bg[1]] = dis[2][bg[2]] = 0;
}

void calc() {
    my_queue Q[3];
    for (int i = 0; i < 3; i++) {
        Q[i].enQueue(bg[i]);
        while (!Q[i].empty()) {
            int tmp = Q[i].deQueue();
            list_node *nt = li[tmp].next_list.head->next;
            while (nt != li[tmp].next_list.tail) {
                if (dis[i][nt->val.first] > dis[i][tmp] + nt->val.second) {
                    Q[i].enQueue(nt->val.first);
                    dis[i][nt->val.first] = dis[i][tmp] + nt->val.second;
                }
                nt = nt->next;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> bg[0] >> bg[1] >> bg[2];
    for (int i = 0; i < n - 1; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        li[a].next_list.push_f({b, p});
        li[b].next_list.push_f({a, p});
    }
    init();
    calc();
    int d = inf, ret;
    for (int i = 1; i <= n; i++) {
        int tmp = dis[0][i] + dis[1][i] + dis[2][i];
        if (tmp < d) {
            ret = i;
            d = tmp;
        }
    }
    cout << ret << '\n' << d;
    cout << flush;
    return 0;
}