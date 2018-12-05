#include<iostream>

int partition(int *li, int left, int right) {
    int l = left, r = right;
    int pivot = li[l];
    while (l < r) {
        while (l < r && li[r] >= pivot) {
            r--;
        }
        if (l < r) {
            li[l] = li[r];
            l++;
        }
        while (l < r && li[l] <= pivot) {
            l++;
        }
        if (l < r) {
            li[r] = li[l];
            r--;
        }
    }
    li[l] = pivot;
    return l;
}

void quickSort(int *li, int left, int right) {
    if (left < right) {
        int pivot = partition(li, left, right);
        quickSort(li, left, pivot - 1);
        quickSort(li, pivot + 1, right);
    }
}

const int max_len = 1e4 + 7;

int A[max_len], B[max_len];
int lenA, lenB;

int main() {
    std::cin >> lenA >> lenB;
    for (int i = 1; i <= lenA; i++) {
        std::cin >> A[i];
    }
    for (int i = 1; i <= lenB; i++) {
        std::cin >> B[i];
    }

    quickSort(A, 1, lenA);
    quickSort(B, 1, lenB);

    int count = 0;

    int topA = lenA;
    int topB = lenB;

    while (topA && topB) {
        if (A[topA] > B[topB]) {
            topA--;
            topB--;
            count+=2;
        }else{
            topB--;
        }
    }
    if(topA){
        count += topA;
    }
    std::cout<<count;
    return 0;
}