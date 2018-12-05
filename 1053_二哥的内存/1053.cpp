#include <iostream>

const int max_size = 1e5 + 7;

typedef std::pair<std::pair<int, int>, int> dot;

dot li[max_size];

int x[max_size];
int y[max_size];

int size;

template<typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

bool cmp(dot &a, dot &b) {
    if (a.first.first != b.first.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int find(int x, int y) {
    for (int i = 0; i < size; i++) {
        if (li[i].first.first == x && li[i].first.second == y) {
            return li[i].second;
        }
    }
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> li[i].first.first >> li[i].first.second >> li[i].second;
    }
    for (int i = 0; i < max_size; i++) {
        x[i] = y[i] = i;
    }
    int t;
    int ctrl, posx, posy;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> ctrl >> posx >> posy;
        if (ctrl == 0) {
            swap(x[posx], x[posy]);
        } else if (ctrl == 1) {
            swap(y[posx], y[posy]);
        } else {
            std::cout << find(x[posx], y[posy]) << '\n';
        }
    }
    std::cout << std::flush;
    return 0;
}
