#include <iostream>
#include <cstring>

const int max_size = 26;

int size;
int pos[max_size];
int behind[max_size];
int beneath[max_size];

void cut(int up) {
    if (beneath[up] != -1) {
        behind[beneath[up]] = -1;
        beneath[up] = -1;
    } else {
        pos[up] = -1;
    }
}

bool find(int a, int b) {
    if (a == b) {
        return true;
    }
    int up = behind[a], down = beneath[a];
    while (up != -1) {
        if (up == b) {
            return true;
        }
        up = behind[up];
    }
    while (down != -1) {
        if (down == b) {
            return true;
        }
        down = beneath[down];
    }
    return false;
}


void init() {
    for (int i = 0; i < size; i++) {
        pos[i] = i;
        behind[i] = -1;
        beneath[i] = -1;
    }
}

void move_top(int n) {
    int tmp = behind[n], tmp2;
    while (tmp != -1) {
        tmp2 = tmp;
        pos[tmp] = tmp;
        tmp = behind[tmp];
        behind[tmp2] = -1;
        beneath[tmp2] = -1;
    }
    if (behind[n] != -1) {
        beneath[behind[n]] = -1;
    }
    behind[n] = -1;
}

void move_over(int a, int b) {
    if (find(a, b)) {
        return;
    }
    move_top(a);
    int tmp = b;
    while (behind[tmp] != -1) {
        tmp = behind[tmp];
    }
    cut(a);
    behind[tmp] = a;
    beneath[a] = tmp;
}

void move_onto(int a, int b) {
    if (find(a, b)) {
        return;
    }
    move_top(a);
    move_top(b);
    cut(a);
    behind[b] = a;
    beneath[a] = b;
}

void pile_over(int a, int b) {
    if (find(a, b)) {
        return;
    }
    int tmp = b;
    while (behind[tmp] != -1) {
        tmp = behind[tmp];
    }
    cut(a);
    behind[tmp] = a;
    beneath[a] = tmp;
}

void pile_onto(int a, int b) {
    if (find(a, b)) {
        return;
    }
    move_top(b);
    cut(a);
    behind[b] = a;
    beneath[a] = b;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> size;
    init();
    char c1[5], c2[5];
    int a, b;
    while (1) {
        std::cin >> c1;
        if (std::strcmp(c1, "quit") == 0) {
            break;
        }
        std::cin >> a >> c2 >> b;
        if (std::strcmp(c1, "move") == 0) {
            if (std::strcmp(c2, "onto") == 0) {
                move_onto(a, b);
            } else {
                move_over(a, b);
            }
        } else if (std::strcmp(c1, "pile") == 0) {
            if (std::strcmp(c2, "onto") == 0) {
                pile_onto(a, b);
            } else {
                pile_over(a, b);
            }
        }
    }
    for (int i = 0; i < size; i++) {
        std::cout << i << ":";
        if (pos[i] == -1) {
            std::cout << '\n';
        } else {
            int tmp = pos[i];
            while (tmp != -1) {
                std::cout << " " << tmp;
                tmp = behind[tmp];
            }
            std::cout << '\n';
        }
    }
    std::cout << std::flush;
    return 0;
}