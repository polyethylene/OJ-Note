#include<iostream>

const int max_len = 507;

int f[max_len * max_len];
int map[max_len * max_len];
int m, n;
int rank[max_len * max_len];

void init() {
    int size = m * n;
    for (int i = 0; i < size; i++) {
        f[i] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> map[j + i * m];
            if (map[j + i * m] == -1) {
                f[j + i * m] = max_len * max_len;
            }
        }
    }
}

int find(int pos) {

    if (pos != f[pos]) {
        f[pos] = find(f[pos]);
    }
    return f[pos];
}

void uni(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j) {
        return;
    }
    if (rank[i] > rank[j]) {
        f[j] = i;
    } else {
        f[i] = j;
        if (rank[i] == rank[j]) {
            rank[j]++;
        }
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n >> m;
    init();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < n - 1 && map[j + m * i] == 0 && map[j + m * (i + 1)] == 0) {
                uni(j + m * i, j + m * (i + 1));
            }
            if (j < m - 1 && map[j + m * i] == 0 && map[j + 1 + m * i] == 0) {
                uni(j + m * i, j + 1 + m * i);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < m * n; i++) {
        if (f[i] != max_len * max_len && f[i] == i) {
            count++;
        }
    }
    std::cout << count;
    std::cout << std::flush;
    return 0;
}