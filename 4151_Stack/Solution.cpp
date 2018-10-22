#include<iostream>

const int max_size = 1e6 + 7;

int stack[max_size];
int seq[max_size];
int top = 0;

int main() {
    int num, size;
    std::cin >> num;
    for (int i = 0; i < num; i++) {
        std::cin >> size;
        for (int j = 0; j < size; j++) {
            std::cin >> seq[j];
        }
        int count = 0;
        int n = 1;
        top = 0;
        while (count < size) {
            if (seq[count] == n) {
                n++;
                count++;
            } else if (top != 0 && seq[count] == stack[top - 1]) {
                top--;
                count++;
            } else if (top != 0 && seq[count] < n && seq[count] != stack[top - 1]) {
                top = 1;
                break;
            } else if (n < size + 1) {
                stack[top++] = n;
                n++;
            } else {
                top = 1;
                break;
            }
        }
        if (!top)
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }
    return 0;
}