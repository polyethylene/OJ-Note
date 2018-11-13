#include <iostream>
#include <cstring>

const int max_len = 5e4 + 7;
int heap[max_len];
int top = 1;
char ctrl[20];
int t;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insert(int n) {
    heap[top++] = n;
    int temp = top - 1;

    while (temp != 1 && heap[temp] < heap[temp >> 1]) {
        swap(heap[temp], heap[temp >> 1]);
        temp >>= 1;
    }
}

int find(int n, int i) {
/*    if (i <= top) {
        if (n < heap[i]) {
            return i;
        } else {
            int l = find(n, i << 1);
            int r = find(n, i << 1 | 1);
            if (l == -1) {
                return r;
            } else if (r == -1) {
                return l;
            }
            if (heap[l] > heap[r]) {
                return r;
            } else {
                return l;
            }
        }
    } else
        return -1;*/
    int ind = 1, min_v = 0x7fffffff;
    for (int i = 1; i < top; i++) {
        if (heap[i] > n && heap[i] < min_v) {
            min_v = heap[i];
            ind = i;
        }
    }
    return ind;
}

void decrease(int i, int val) {
    heap[i] -= val;
    int temp = i;
    while (temp != 1 && heap[temp] < heap[temp >> 1]) {
        swap(heap[temp], heap[temp >> 1]);
        temp >>= 1;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> ctrl;
        if (!strcmp(ctrl, "insert")) {
            int a;
            std::cin >> a;
            insert(a);
        } else if (!strcmp(ctrl, "find")) {
            int a;
            std::cin >> a;
            std::cout << find(a, 1) << "\n";
        } else if (!strcmp(ctrl, "decrease")) {
            int a, b;
            std::cin >> a >> b;
            decrease(a, b);
        }
    }
    std::cout << std::flush;
    return 0;
}