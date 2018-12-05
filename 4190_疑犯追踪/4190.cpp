#include <iostream>

const int max_len = 1e5 + 7;
const int NOT_FOUND = 0;
int li[max_len];


template<typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

struct priorQueue {
    int data[max_len];
    int top;

    priorQueue() : top(1) {};

    void push(int val) {
        data[top++] = val;
        int tmp = top - 1;
        while (tmp != 1 && data[tmp] < data[tmp >> 1]) {
            swap(data[tmp], data[tmp >> 1]);
            tmp = tmp >> 1;
        }
    }

    int pop() {
        int ret = data[1];
        data[1] = data[--top];
        int tmp = 1;
        while ((tmp << 1 | 1) < top) {
            if (data[tmp] > data[tmp << 1] && data[tmp] > data[tmp << 1 | 1]) {
                if (data[tmp << 1] < data[tmp << 1 | 1]) {
                    swap(data[tmp << 1], data[tmp]);
                    tmp = tmp << 1;
                } else {
                    swap(data[tmp << 1 | 1], data[tmp]);
                    tmp = tmp << 1 | 1;
                }
            } else if (data[tmp] > data[tmp << 1]) {
                swap(data[tmp << 1], data[tmp]);
                tmp = tmp << 1;
            } else if (data[tmp] > data[tmp << 1 | 1]) {
                swap(data[tmp << 1 | 1], data[tmp]);
                tmp = tmp << 1 | 1;
            } else {
                break;
            }
        }
        if ((tmp << 1) < top && data[tmp] > data[tmp << 1]) {
            swap(data[tmp], data[tmp << 1 | 1]);
        }
        return ret;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int size;
    std::cin >> size;
    for (int i = 1; i <= size; i++) {
        std::cin >> li[i];
    }
    priorQueue front;
    priorQueue rear;
    int mid = li[1];
    std::cout << mid << ' ';
    for (int i = 1; i <= size - 2; i += 2) {
        int first = li[i + 1];
        int second = li[i + 2];
        if (first > mid && second > mid) {
            rear.push(first);
            rear.push(second);
            front.push(-mid);
            mid = rear.pop();
        } else if (first < mid && second < mid) {
            front.push(-first);
            front.push(-second);
            rear.push(mid);
            mid = -front.pop();
        } else {
            if (first > second) {
                front.push(-second);
                rear.push(first);
            } else {
                front.push(-first);
                rear.push(second);
            }
        }
        std::cout << mid << ' ';
    }
    std::cout << std::flush;
    return 0;
}