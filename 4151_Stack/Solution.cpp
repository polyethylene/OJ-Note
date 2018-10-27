#include <iostream>

using namespace std;

const int max_len = 1e6 + 7;
int times;
int top = 0;
int stack[max_len];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool test;
    cin >> times;
    for (int i = 0; i < times; i++) {
        int max = 0;
        test = true;
        top = 0;
        int len;
        cin >> len;
        for (int j = 0; j < len; j++) {
            cin >> n;
            if (test) {
                if (n > max) {
                    for (int j = max + 1; j < n; j++) {
                        stack[top++] = j;
                    }
                    max = n;
                } else {
                    if (stack[top-1]==n)
                        top--;
                    else
                        test = false;
                }
            }
        }
        if (test)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    cout << flush;
    return 0;
}