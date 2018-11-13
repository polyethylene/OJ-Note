#include <iostream>

#define ll long long
const int max_len = 1e5 + 7;
int ans = 2;

std::pair<ll, ll> data[max_len];

int partition(std::pair<ll, ll> *li, int beg, int end) {
    int i = beg, j = end;
    std::pair<ll, ll> pivot = li[beg];
    while (i < j) {
        while (i < j && li[j].first >= pivot.first)
            j--;
        if (i < j)
            li[i++] = li[j];
        while (i < j && li[i].first <= pivot.first)
            i++;
        if (i < j)
            li[j--] = li[i];
    }
    li[i] = pivot;
    return i;
}


void quickSort(std::pair<ll, ll> *li, int beg, int end) {
    if (beg < end) {
        int pivot = partition(li, beg, end);
        quickSort(li, beg, pivot - 1);
        quickSort(li, pivot + 1, end);
    }
}

int main() {
    int size;
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> data[i].first;
    }
    for (int i = 0; i < size; i++) {
        std::cin >> data[i].second;
    }
    if (size > 2) {
        quickSort(data, 0, size - 1);
        long long tmp = data[0].first;
        for (int i = 1; i < size - 1; i++) {
            if (data[i].first - data[i].second > tmp) {
                ans++;
                tmp = data[i].first;
            } else if (data[i].first + data[i].second < data[i + 1].first) {
                ans++;
                tmp = data[i].first + data[i].second;
            } else {
                tmp = data[i].first;
            }
        }
        std::cout << ans;
    } else {
        std::cout << size;
    }
    return 0;
}