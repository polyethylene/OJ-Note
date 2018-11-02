#include <iostream>

const int max_len = 1e4 + 7;

int A[max_len], B[max_len];
int LCS[max_len][max_len];
int len;

int partition(int *li, int beg, int end) {
    int i = beg, j = end;
    int pivot = li[beg];
    while (i < j) {
        while (i < j && li[j] >= pivot)
            j--;
        if (i < j)
            li[i++] = li[j];
        while (i < j && li[i] <= pivot)
            i++;
        if (i < j)
            li[j--] = li[i];
    }
    li[i] = pivot;
    return i;
}

void quickSort(int *li, int beg, int end) {
    if (beg < end) {
        int pivot = partition(li, beg, end);
        quickSort(li, beg, pivot - 1);
        quickSort(li, pivot + 1, end);
    }
}

int maxV(int a, int b) {
    return a > b ? a : b;
}

int main() {
    std::cin >> len;
    for (int i = 0; i < len; i++) {
        std::cin >> A[i];
        B[i] = A[i];
    }

    quickSort(B, 0, len - 1);

    for (int i = 0; i <= len; i++) {
        for (int j = 0; j <= len; j++) {
            if (i == 0 || j == 0) {
                LCS[i][j] = 0;
            } else if (A[i - 1] == B[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            } else {
                LCS[i][j] = maxV(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    std::cout << LCS[len][len];

    return 0;
}
