#include <iostream>

const int max_len = 1e3 + 7;

char X[max_len], Y[max_len];
int LCS[max_len][max_len];
int xlen, ylen;

int maxV(int a, int b) {
    return a > b ? a : b;
}

int main() {
    std::cin >> xlen >> ylen;
    for (int i = 0; i < xlen; i++) {
        std::cin >> X[i];
    }
    for (int i = 0; i < ylen; i++) {
        std::cin >> Y[i];
    }

    for (int i = 0; i <= xlen; i++) {
        for (int j = 0; j <= ylen; j++) {
            if (i == 0 || j == 0) {
                LCS[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            } else {
                LCS[i][j] = maxV(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    std::cout << LCS[xlen][ylen];

    return 0;
}
