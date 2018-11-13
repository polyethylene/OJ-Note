#include <iostream>

int partition(long long *li, int l, int r) {
    int i = l, j = r;
    long long pivot = li[l];
    while (i < j) {
        while (i < j && li[j] >= pivot) {
            j--;
        }
        if (i < j) {
            li[i] = li[j];
            i++;
        }
        while (i < j && li[i] <= pivot) {
            i++;
        }
        if (i < j) {
            li[j] = li[i];
            j--;
        }
    }
    li[i] = pivot;
    return i;
}

void quickSort(long long *li, int l, int r) {
    if (l < r) {
        int pivot = partition(li, l, r);
        quickSort(li, l, pivot - 1);
        quickSort(li, pivot + 1, r);
    }
}

long long abs(long long i) {
    return i > 0 ? i : -i;
}

void swap(long long &a, long long &b) {
    long long temp = a;
    a = b;
    b = temp;
}

long long minV(long long& a, long long& b) {
    return a > b ? b : a;
}

void reverse(long long *a, int l, int r) {
    int mid = (l + r) >> 1;
    for (int i = l; i <= mid; i++) {
        swap(a[i], a[r - i + 1]);
    }
}

const int max_len = 2007;
long long li[max_len], sli[max_len];
long long f[max_len][max_len], g[max_len][max_len];
int num;
long long ans = 1 << 30;

int main() {
    std::cin >> num;
    for (int i = 1; i <= num; i++) {
        std::cin >> li[i];
        sli[i] = li[i];
    }
    quickSort(sli, 1, num);
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++) {
            f[i][j] = g[i - 1][j] + abs(li[i] - sli[j]);
            if (j == 1)
                g[i][j] = f[i][j];
            else
                g[i][j] = minV(f[i][j], g[i][j-1]);
        }
    }
    for (int i = 1; i <= num; i++) {
        if (ans > f[num][i])
            ans = f[num][i];
    }
    reverse(sli, 1, num);
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++) {
            f[i][j] = g[i - 1][j] + abs(li[i] - sli[j]);
            if (j == 1)
                g[i][j] = f[i][j];
            else
                g[i][j] = minV(f[i][j], g[i][j-1]);
        }
    }
    for (int i = 1; i <= num; i++) {
        if (ans > f[num][i])
            ans = f[num][i];
    }
    std::cout << ans;
    return 0;
}