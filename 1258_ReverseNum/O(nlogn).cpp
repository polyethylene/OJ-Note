#include <iostream>

const int max_size = 1e5 + 7;
int seq[max_size];
int q[max_size];
int ret = 0;

void mergeArray(int *li, int beg, int mid, int end, int *temp) {
    int i = beg, j = mid + 1, k = 0;
    while (i < mid + 1 && j < end + 1) {
        if (li[i] <= li[j])
            temp[k++] = li[i++];
        else {
            temp[k++] = li[j++];
            ret += mid - i + 1;
        }
    }

    while (i < mid + 1)
        temp[k++] = li[i++];
    while (j < end + 1)
        temp[k++] = li[j++];
    for (int i = 0; i < k; i++)
        li[beg + i] = temp[i];
}

void sortSeq(int *li, int beg, int end, int *temp) {
    int mid = (beg + end) / 2;
    if (beg + 1 < end) {
        sortSeq(li, beg, mid, temp);
        sortSeq(li, mid + 1, end, temp);
    }
    mergeArray(li, beg, mid, end, temp);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int size;
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> seq[i];
    }
    sortSeq(seq, 0, size - 1, q);
    std::cout << ret << std::flush;
    return 0;
}