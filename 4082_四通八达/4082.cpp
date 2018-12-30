#include <iostream>
#include <cmath>

using namespace std;

const int max_len = 1e6 + 7;

int f[max_len];
int nsize;

void init() {
    for (int i = 0; i <= nsize; i++) {
        f[i] = i;
    }
}

int find(int i) {
    if (f[i] != i) {
        return f[i] = find(f[i]);
    }
    return f[i];
}

void uni(int a, int b) {
    int m = find(a);
    int n = find(b);
    if (m != n) {
        f[n] = m;
    }
}

long long s[max_len];

long long C2(long long m) {
    return m * (m - 1) / 2;
}

int main() {
    int t;
    cin >> nsize >> t;
    init();
    int esize = t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        uni(a, b);
    }
    for (int i = 0; i <= nsize; i++) {
        int r = find(i);
        s[r]++;
    }
    long long ret = 0;
    for (int i = 0; i <= nsize; i++) {
        if (s[i] != 0) {
            ret += C2(s[i]);
        }
    }
    cout << ret - esize;
    return 0;
}
