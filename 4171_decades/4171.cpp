#include <iostream>

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

const int max_len = 1e6 + 7;
int A[max_len];
int B[max_len];
int heap[max_len];
int li[max_len];
int top = 1;
bool em = false;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

inline bool cmp(int i, int j) {
    return (A[heap[i]] + B[li[heap[i]]]) > (A[heap[j]] + B[li[heap[j]]]);
}

void ins(int i) {
    if (em) {
        int tmp = 1;
        heap[1] = i;
        while ((tmp << 1 | 1) < top) {
            if (cmp(tmp, tmp << 1) && cmp(tmp, tmp << 1 | 1)) {
                if (cmp(tmp << 1, tmp << 1 | 1)) {
                    swap(heap[tmp], heap[tmp << 1 | 1]);
                    tmp = tmp << 1 | 1;
                } else {
                    swap(heap[tmp], heap[tmp << 1]);
                    tmp = tmp << 1;
                }
            } else if (cmp(tmp, tmp << 1)) {
                swap(heap[tmp], heap[tmp << 1]);
                tmp = tmp << 1;
            } else if (cmp(tmp, tmp << 1 | 1)) {
                swap(heap[tmp], heap[tmp << 1 | 1]);
                tmp = tmp << 1 | 1;
            } else {
                break;
            }
        }
        if ((tmp << 1) < top && cmp(tmp, tmp << 1)) {
            swap(heap[tmp], heap[tmp << 1]);
        }
        em = false;
    } else {
        int tmp = top;
        heap[top++] = i;
        while (tmp != 1 && A[heap[tmp]] + B[li[heap[tmp]]] < A[heap[tmp >> 1]] + B[li[heap[tmp >> 1]]]) {
            swap(heap[tmp], heap[tmp >> 1]);
            tmp >>= 1;
        }
    }
}

int pop() {
    em = true;
    int tmp = heap[1];
    int tmp2 = li[tmp];
    li[tmp]++;
    ins(tmp);
    return A[tmp] + B[tmp2];
}

int main() {
    int size;
    std::cin >> size;
    for (int i = 1; i <= size; i++) {
        std::cin >> A[i];
        li[i] = 1;
    }
    for (int i = 1; i <= size; i++) {
        std::cin >> B[i];
    }
    quickSort(A, 1, size);
    quickSort(B, 1, size);
    for (int i = 1; i <= size; i++) {
        ins(i);
    }
    for (int i = 1; i <= size; i++) {
        std::cout << pop() << ' ';
    }
    std::cout << std::flush;
    return 0;
}