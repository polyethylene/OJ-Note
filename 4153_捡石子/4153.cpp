#include <iostream>

const int max_len = 1e5 + 7;
long long dis[max_len], f[max_len], g[max_len];
int num, pick, k;

int partition(long long *li, int beg, int end) {
    int i = beg, j = end;
    long long pivot = li[beg];
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


void quickSort(long long *li, int beg, int end) {
    if (beg < end) {
        int pivot = partition(li, beg, end);
        quickSort(li, beg, pivot - 1);
        quickSort(li, pivot + 1, end);
    }
}

bool judgeK1(long long test) {
    int i = 0, now = 0, count = 2;
    while (i < num) {
        i++;
        if (dis[i] - dis[now] >= test && dis[num - 1] - dis[i] >= test) {
            count++;
            now = i;
        }
    }
    return count >= pick;
}

bool judgeK2(long long test) {
    int fcount = 1, gcount = 1, now = 0;
    for (int i = 0; i < num; i++) {
        if (dis[i] - dis[now] >= test) {
            fcount++;
            now = i;
        }
        f[i] = fcount;
    }
    now = num - 1;
    for (int i = num - 1; i >= 0; i--) {
        if (dis[now] - dis[i] >= test) {
            gcount++;
            now = i;
        }
        g[i] = gcount;
    }
    for (int i = 0; i < num - 1; i++) {
        if (dis[i + 1] - dis[i] <= test) {
            if (f[i] + g[i + 1] >= pick) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::cin >> num >> pick >> k;

    for (int i = 0; i < num; i++) {
        std::cin >> dis[i];
    }

    quickSort(dis, 0, num - 1);

    long long ans = 1;

    if (k == 1) {
        long long r = dis[num - 1] - dis[0], l = 1;
        long long mid;
        while (l <= r) {
            mid = (r + l) / 2;
            if (judgeK1(mid)) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
    } else if (k == 2) {
        long long r = dis[num - 1] - dis[0], l = 1;
        long long mid;
        while (l <= r) {
            mid = (r + l) / 2;
            if (judgeK2(mid)) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
    }
    std::cout << ans;

    return 0;
}