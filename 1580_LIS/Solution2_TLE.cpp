#include <iostream>

const int max_len = 1e6 + 7;

int li[max_len];
int LIS[max_len];
int size;

int main() {
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> li[i];
        LIS[i] = 1;
    }

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (li[i] > li[j] && LIS[i] < LIS[j] + 1)
                LIS[i] = LIS[j] + 1;
        }
    }

    int max = 0;
    for (int i = 0; i < size; i++) {
        if (LIS[i] > max) {
            max = LIS[i];
        }
    }

    std::cout << max;

    return 0;
}