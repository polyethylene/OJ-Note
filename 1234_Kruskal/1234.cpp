#include <iostream>

using namespace std;

const int max_edge_size = 1e5 + 7;
const int max_node_size = 1e4 + 7;

typedef pair<int, pair<int, int>> EDGE;

EDGE edges[max_edge_size];
int f[max_node_size];
int r[max_node_size];
int node_size, edge_size;

int partition(EDGE *li, int l, int r) {
    int i = l, j = r;
    EDGE p = li[l];
    while (i < j) {
        while (i < j && li[j].first >= p.first) {
            j--;
        }
        if (i < j) {
            li[i] = li[j];
            i++;
        }
        while (i < j && li[i].first <= p.first) {
            i++;
        }
        if (i < j) {
            li[j] = li[i];
            j--;
        }
    }
    li[i] = p;
    return i;
}

void quick_sort(EDGE *li, int l, int r) {
    if (l < r) {
        int p = partition(li, l, r);
        quick_sort(li, l, p - 1);
        quick_sort(li, p + 1, r);
    }
}

void init() {
    for (int i = i; i <= node_size; i++) {
        f[i] = i;
    }
}

int find(int i) {
    if (f[i] != i) {
        return f[i] = find(f[i]);
    }
    return i;
}

void uni(int a, int b) {
    int m = find(a);
    int n = find(b);
    if (m == n) {
        return;
    }
    if (r[n] > r[m]) {
        f[m] = n;
    } else {
        if (r[n] == r[m]) {
            r[m]++;
        }
        f[n] = m;
    }
}

int cal() {
    int ret = 0;
    for (int i = 1; i <= edge_size; i++) {
        int bg = edges[i].second.first, ed = edges[i].second.second;
        if (find(bg) == find(ed)) {
            continue;
        }
        ret += edges[i].first;
        uni(bg, ed);
    }
    return ret;
}

int main() {
    cin >> node_size >> edge_size;
    init();

    for (int i = 1; i <= edge_size; i++) {
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }
    quick_sort(edges, 1, edge_size);

    cout << cal();

    return 0;
}