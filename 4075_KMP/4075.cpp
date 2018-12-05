#include <iostream>
#include <cstring>

const int max_A = 1e6 + 7;
const int max_B = 1e5 + 7;

char A[max_A], B[max_B];
int next[max_B];
int len_A, len_B;

void cal_next(char *str, int *next, int slen) {
    next[0] = -1;
    int k = -1;
    for (int i = 1; i < slen; i++) {
        while (k > -1 && str[k + 1] != str[i]) {
            k = next[k];
        }
        if (str[k + 1] == str[i]) {
            k++;
        }
        next[i] = k;
    }
}

int KMP(char *str, int slen, char *cstr, int clen) {
    cal_next(cstr, next, clen);
    int k = -1;
    for (int i = 0; i < slen; i++) {
        while (k > -1 && cstr[k + 1] != str[i]) {
            k = next[k];
        }
        if (cstr[k + 1] == str[i]) {
            k++;
        }
        if (k == clen - 1) {
            return i - clen + 1;
        }
    }
}

int main() {
    std::cin >> A >> B;
    len_A = strlen(A);
    len_B = strlen(B);
    std::cout << KMP(A, len_A, B, len_B);
    return 0;
}