#include <iostream>
#include <string>

using namespace std;
const int big_prime = 1e9 + 7;
const int max_len = 1e5 + 7;
string Sdata[max_len];
int dataHash[max_len];
int subdataHash[max_len];
int pos[max_len][2];

int getPreHash(const string &str, int n) {
    int ret = 0, p = 1;
    for (int i = 0; i < n; i++) {
        ret += str[i] * p;
        p *= 27;
    }
    return ret % big_prime;
}

int getSubHash(const string &str, int n) {
    int ret = 0, p = 1, size = str.size();
    for (int i = 0; i < n; i++) {
        ret += str[size - i - 1] * p;
        p *= 27;
    }
    return ret;
}

bool findEqual(int x) {
    if (x == 1) {
        return false;
    }
    for (int i = x - 1; i >= 1; i--) {
        if (dataHash[pos[i][1]] == dataHash[pos[x][1]]) {
            return true;
        }
    }
    return false;
}

int findPrefix(int x, int y) {
    int r = (Sdata[x].size() < Sdata[y].size()) ? Sdata[x].size() : Sdata[y].size();
    int l = 0, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (dataHash[pos[x][0] + mid] == dataHash[pos[y][0] + mid]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

int findSubfix(int x, int y) {
    int r = (Sdata[x].size() < Sdata[y].size()) ? Sdata[x].size() : Sdata[y].size();
    int l = 0, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (subdataHash[pos[x][0] + mid] == subdataHash[pos[y][0] + mid]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int size;
    int count = 0;
    cin >> size;
    for (int i = 1; i <= size; i++) {
        cin >> Sdata[i];
        int tmpSize = Sdata[i].size();
        pos[i][0] = count;
        pos[i][1] = count + tmpSize - 1;
        for (int j = 0; j < tmpSize; j++) {
            dataHash[count] = getPreHash(Sdata[i], j + 1);
            subdataHash[count] = getSubHash(Sdata[i], j + 1);
            count++;
        }
    }
    cin >> size;
    int op, x, y;
    for (int i = 1; i <= size; i++) {
        cin >> op;
        switch (op) {
            case 1: {
                cin >> x;
                if (findEqual(x)) {
                    cout << "yes\n";
                } else {
                    cout << "no\n";
                }
                break;
            }
            case 2: {
                cin >> x >> y;
                cout << findPrefix(x, y) + 1 << '\n';
                break;
            }
            case 3: {
                cin >> x >> y;
                cout << findSubfix(x, y) + 1 << '\n';
                break;
            }
        }
    }
    cout << flush;
    return 0;
}