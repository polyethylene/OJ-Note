#include<iostream>

const int max_len = 1e5 + 7;
int a[max_len];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int m, n;
    std::cin >> m >> n;
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }
    int tmp, count = 0;
    std::cin >> tmp;
    while (count < m && n > 0) {
        if (a[count] < tmp) {
            std::cout << a[count++] << ' ';
        } else {
            std::cout << tmp << ' ';
            if (--n > 0)
                std::cin >> tmp;
        }
    }
    while (count < m) {
        std::cout << a[count++] << ' ';
    }
    while (n > 0) {
        std::cout << tmp << ' ';
        if (--n > 0)
            std::cin >> tmp;
    }
    std::cout << std::flush;
    return 0;
}