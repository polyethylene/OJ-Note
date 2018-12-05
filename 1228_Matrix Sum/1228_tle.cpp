#include <iostream>
#include <cmath>

const int max_len = 407;
long long mat[max_len][max_len];
bool sum[max_len][max_len];
int size;


bool isOdd(long long n) {
    return n % 2;
}

void presum() {
    sum[1][1] = isOdd(mat[1][1]);
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            sum[i][j] = sum[i][j - 1] ^ sum[i - 1][j] ^ sum[i - 1][j - 1] ^ isOdd(mat[i][j]);
        }
    }
}

int main() {
    std::cin >> size;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            std::cin >> mat[i][j];
        }
    }
    presum();
    long long oddNum = 0, evenNum = 0;
    for (int x1 = 0; x1 < size; x1++) {
        for (int x2 = x1 + 1; x2 <= size; x2++) {
            for (int y1 = 0; y1 < size; y1++) {
                for (int y2 = y1 + 1; y2 <= size; y2++) {
                    if (sum[x2][y2] ^ sum[x1][y2] ^ sum[x2][y1] ^ sum[x1][y1])
                        oddNum++;
                }
            }
        }
    }
    long long num = size == 1 ? size : pow((size * (size + 1)) / 2, 2);
    evenNum = num - oddNum;
    std::cout << oddNum << ' ' << evenNum;
    return 0;
}