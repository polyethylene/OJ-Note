#include <iostream>

void LtoNLR(char *str, int beg, int end);

void LtoLNR(char *str, int beg, int end);

void LtoLRN(char *str, int beg, int end);

void NLRtoL(char *str, int len);

void LNRtoL(char *str, int len);

void LRNtoL(char *str, int len);

const int max_len = 1e6 + 7;
int size, len;
char ctrl[31];
char s[max_len];
char ans[max_len];
int stack[max_len];
int times[max_len];
int top;

int main() {
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> len;
        std::cin.getline(ctrl, 30);
        std::cin >> s;
        if (ctrl[2] == 'N') {
            if (ctrl[9] == 'E') {
                LtoLNR(s, 1, len);
                std::cout << "\n";
            } else if (ctrl[9] == 'D') {
                LNRtoL(s, len);
                std::cout << "\n";
            }
        } else if (ctrl[2] == 'R') {
            if (ctrl[10] == 'E') {
                LtoNLR(s, 1, len);
                std::cout << "\n";
            } else if (ctrl[10] == 'D') {
                NLRtoL(s, len);
                std::cout << "\n";
            }
        } else if (ctrl[2] == 'O') {
            if (ctrl[11] == 'E') {
                LtoLRN(s, 1, len);
                std::cout << "\n";
            } else if (ctrl[11] == 'D') {
                LRNtoL(s, len);
                std::cout << "\n";
            }
        }
    }
    return 0;
}

void LtoNLR(char *str, int n, int len) {
    if (n <= len) {
        std::cout << str[n - 1];
        LtoNLR(str, n * 2, len);
        LtoNLR(str, n * 2 + 1, len);
    }
}

void LtoLNR(char *str, int n, int len) {
    if (n <= len) {
        LtoLNR(str, n * 2, len);
        std::cout << str[n - 1];
        LtoLNR(str, n * 2 + 1, len);
    }
}

void LtoLRN(char *str, int n, int len) {
    if (n <= len) {
        LtoLRN(str, n * 2, len);
        LtoLRN(str, n * 2 + 1, len);
        std::cout << str[n - 1];
    }
}

void NLRtoL(char *str, int len) {
    int temp, i = 0;
    top = 0;
    stack[top++] = 1;
    while (top) {
        temp = stack[--top];
        ans[temp] = str[i++];
        if (temp * 2 + 1 <= len) {
            stack[top++] = temp * 2 + 1;
        }
        if (temp * 2 <= len) {
            stack[top++] = temp * 2;
        }
    }
    for (int i = 1; i <= len; i++) {
        std::cout << ans[i];
    }
}

void LNRtoL(char *str, int len) {
    int r = 1, temp, i = 0;
    top = 0;
    stack[top++] = r;
    while (top) {
        temp = stack[--top];
        if (times[temp] == 1) {
            ans[temp] = str[i++];
            times[temp] = 0;
        } else {
            times[temp] = 1;
            if (temp * 2 + 1 <= len) {
                stack[top++] = temp * 2 + 1;
            }
            stack[top++] = temp;
            if (temp * 2 <= len) {
                stack[top++] = temp * 2;
            }
        }
    }
    for (int i = 1; i <= len; i++) {
        std::cout << ans[i];
    }
}


void LRNtoL(char *str, int len) {
    int r = 1, temp, i = 0;
    top = 0;
    stack[top++] = r;
    while (top) {
        temp = stack[--top];
        if (times[temp] == 1) {
            ans[temp] = str[i++];
            times[temp] = 0;
        } else {
            times[temp] = 1;
            stack[top++] = temp;
            if (temp * 2 + 1 <= len) {
                stack[top++] = temp * 2 + 1;
            }
            if (temp * 2 <= len) {
                stack[top++] = temp * 2;
            }
        }
    }
    for (int i = 1; i <= len; i++) {
        std::cout << ans[i];
    }
}