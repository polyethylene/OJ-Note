#include<iostream>

const int max_len = 1e6 + 7;

bool not_root[max_len];
int left[max_len];
int right[max_len];
int father[max_len];
int height[max_len];

int main() {
    int N, X, Y;
    std::cin >> N >> X >> Y;
    for (int i = 1; i <= N; i++) {
        std::cin >> left[i];
        std::cin >> right[i];
        not_root[left[i]] = true;
        not_root[right[i]] = true;
        father[left[i]] = i;
        father[right[i]] = i;
        height[i] = height[father[i]] + 1;
    }

    int tmp1 = height[X], tmp2 = height[Y];
    int tmpX = X, tmpY = Y;

    while (tmp1 > tmp2) {
        tmpX = father[tmpX];
        tmp1--;
    }
    while (tmp2 > tmp1) {
        tmpY = father[tmpY];
        tmp2--;
    }
    while (tmpX != tmpY) {
        tmpX = father[tmpX];
        tmpY = father[tmpY];
    }
    std::cout << tmpX;

    return 0;
}