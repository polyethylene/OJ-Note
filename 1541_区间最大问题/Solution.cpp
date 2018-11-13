#include <iostream>
#include <cmath>
 
const int max_len = 2e5 + 7;
long long li[max_len];
long long Max[max_len][31];
long long powII[32];
long logII[max_len];
int size, width;
 
void cpow() {
    long long c = 1;
    for (int i = 0; i < 32; i++) {
        powII[i] = c;
        c <<= 1;
    }
}
 
void clog() {
    logII[1] = 0;
    logII[2] = 1;
    for (int i = 3; i <= size; i++) {
        logII[i] = logII[i / 2] + 1;
    }
}
 
int maxV(int a, int b) {
    return a > b ? a : b;
}
 
void pre() {
    for (int i = 1; i <= size; i++) {
        int j = 0;
        int k = i - 1;
        Max[i][0] = li[i];
        while (k > 0) {
            j++;
            Max[i][j] = maxV(Max[i][j - 1], Max[i - powII[j - 1]][j - 1]);
            k -= powII[j];
        }
    }
}
 
long long query(int l, int r) {
    int len = r - l + 1;
    int t = logII[len];
    return maxV(Max[l + powII[t] - 1][t], Max[r][t]);
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);;
 
    std::cin >> width;
    std::cin >> size;
 
    for (int i = 1; i <= size; i++) {
        std::cin >> li[i];
    }
    cpow();
    clog();
    pre();
    int l = 1, r = width;
    while (r <= size) {
        std::cout << query(l, r) << " ";
        l++;
        r++;
    }
    std::cout << std::flush;
    return 0;
}