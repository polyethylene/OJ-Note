#include<iostream>

const int max_len = 256;
int set[max_len], temp[max_len];
int len = 0;
int size = 0;
char ctrl;

int findEqual(int n) {
    if (len == 0) {
        return -1;
    }
    int l = 0, r = len - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (set[r] == n) {
            return r;
        } else if (n < set[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (set[r] == n) {
        return r;
    } else {
        return -1;
    }
}

int findLastSmaller(int n) {
    int l = 0, r = len - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (n < set[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

void Insert(int n) {
    if (findEqual(n) == -1) {
        int index = findLastSmaller(n) + 1;
        int temp = len;
        len++;
        while (temp != index) {
            set[temp] = set[temp - 1];
            temp--;
        }
        set[index] = n;
    }
}

void Delete(int n) {
    int index = findEqual(n);
    if (index != -1) {
        int temp = index;
        len--;
        while (temp != len) {
            set[temp] = set[temp + 1];
            temp++;
        }
    }
}

void traverse(int *li, int s) {
    for (int i = 0; i < s; i++) {
        std::cout << li[i] << ' ';
    }
}

void clear() {
    len = 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> ctrl;
        switch (ctrl) {
            case '+': {
                int s, n;
                std::cin >> s;
                for (int j = 0; j < s; j++) {
                    std::cin >> n;
                    Insert(n);
                }
                traverse(set, len);
                std::cout<<"\n";
                break;
            }
            case '-': {
                int s, n;
                std::cin >> s;
                for (int j = 0; j < s; j++) {
                    std::cin >> n;
                    Delete(n);
                }
                traverse(set, len);
                std::cout<<"\n";
                break;
            }
            case '*': {
                int s, n;
                int count = 0;
                std::cin >> s;
                for (int j = 0; j < s; j++) {
                    std::cin >> n;
                    int index = findEqual(n);
                    if (index != -1) {
                        temp[count++] = n;
                    }
                }
                clear();
                for (int j = 0; j < count; j++) {
                    Insert(temp[j]);
                }
                traverse(set, len);
                std::cout<<"\n";
                break;
            }
            default:
                break;
        }
    }
    std::cout<<std::flush;
    return 0;
}