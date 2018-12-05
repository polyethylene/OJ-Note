#include <iostream>

const int max_len = 407;

bool mat[max_len][max_len];
bool tmp[max_len];
int zeroNum[max_len];
long long size;

void cpyCol(int x) {
    for (int i = 1; i <= size; i++) {
        tmp[i] = mat[x][i];
    }
}

void addCol(int x) {
    for (int i = 1; i <= size; i++) {
        tmp[i] ^= mat[x][i];
    }
}

long long calTmp() {
    long long ret = 0;
    int count = 0, onePos = 1;
    for (int i = 1; i <= size; i++) {
        count++;
        if (tmp[i] == 1) {
            zeroNum[onePos++] = count;
            count = 0;
        }
    }
    if (onePos == 0) {
        return ret;
    }
    zeroNum[onePos++] = count + 1;
    for (int i = 0; i < onePos; i++) {
        for (int j = i + 1; j < onePos; j += 2) {
            ret += (zeroNum[i] * zeroNum[j]);
        }
    }
    return ret;
}

int main() {
    std::cin >> size;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            long long tmp;
            std::cin >> tmp;
            mat[i][j] = tmp % 2;
        }
    }
    long long oddNum = 0;
    for (int i = 1; i <= size; i++) {
        cpyCol(i);
        oddNum += calTmp();
        for (int j = i + 1; j <= size; j++) {
            addCol(j);
            oddNum += calTmp();
        }
    }
    long long evenNum = size * size * (size + 1) * (size + 1) / 4 - oddNum;
    std::cout << oddNum << ' ' << evenNum;
    return 0;
}