#include <iostream>

const int max_len = 30007;

int A[max_len];
int B[max_len];
int trie[max_len << 8][2];
int size = 0;

void insert(int val) {
    int tmp = 0, b;
    for (int i = 31; i >= 0; i--) {
        b = (val >> i) & 1;
        if (!trie[tmp][b]) {
            trie[tmp][b] = ++size;
        }
        tmp = trie[tmp][b];
    }
}

int find(int val) {
    int tmp = 0, b, ret = 0;
    for (int i = 31; i >= 0; i--) {
        b = 1 - (val >> i) & 1;
        ret <<= 1;
        if (trie[tmp][b]) {
            ret++;
            tmp = trie[tmp][b];
        } else {
            tmp = trie[tmp][b ^ 1];
        }
    }
    return ret;
}

int main() {
    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> B[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        insert(A[i]);
    }
    for (int i = 0; i < M; i++) {
        int tmp = find(B[i]);
        if (ans < tmp) {
            ans = tmp;
        }
    }
    std::cout << ans;
    return 0;
}