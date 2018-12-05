#include <iostream>

const int max_len = 2e6 + 7;

int li[max_len];
int order[max_len];
int STree[max_len << 2];

void PushUp(int rt) {
    if (li[STree[rt << 1]] < li[STree[rt << 1 | 1]]) {
        STree[rt] = STree[rt << 1];
    } else if (li[STree[rt << 1]] > li[STree[rt << 1 | 1]]) {
        STree[rt] = STree[rt << 1 | 1];
    } else {
        if (order[STree[rt << 1]] > order[STree[rt << 1 | 1]]) {
            STree[rt] = STree[rt << 1];
        } else {
            STree[rt] = STree[rt << 1 | 1];
        }
    }
}

void Build(int l, int r, int rt) {
    if (l == r) {
        STree[rt] = l;
        return;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, rt << 1);
    Build(mid + 1, r, rt << 1 | 1);
    PushUp(rt);
}

void Update(int l, int r, int rt, int id) {
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    if (id <= mid) {
        Update(l, mid, rt << 1, id);
    } else {
        Update(mid + 1, r, rt << 1 | 1, id);
    }
    PushUp(rt);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int size, times;
    std::cin >> size >> times;
    for (int i = 1; i <= size; i++) {
        std::cin >> li[i];
        order[i] = i;
    }
    int count = size + 1;
    Build(1, size, 1);
    for (int i = 0; i < times; i++) {
        int x, y;
        std::cin >> x >> y;
        order[x] = count++;
        li[x] += y;
        Update(1, size, 1, x);
        std::cout << STree[1] << '\n';
    }
    std::cout << std::flush;
    return 0;
}