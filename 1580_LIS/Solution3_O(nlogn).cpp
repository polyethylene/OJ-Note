#include <iostream>

const int max_len = 1e6 + 7;
int minOfMax[max_len];
int li[max_len];
int size, len = 1;

int findFirstNotBigger(int *li, int len, int x) {
    int l = 0, r = len - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (li[mid] >= x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;

}

int main() {
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> li[i];
    }

    minOfMax[0] = li[0];
    for (int i = 1; i < size; i++) {
        if (li[i] > minOfMax[len - 1]) {
            minOfMax[len++] = li[i];
        } else {
            int index = findFirstNotBigger(minOfMax, len, li[i]);
            if (minOfMax[index] > li[i]) {
                minOfMax[index] = li[i];
            }
        }
    }

    std::cout << len;
    return 0;
}