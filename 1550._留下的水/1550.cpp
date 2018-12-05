#include <iostream>

const int max_len = 1e3 + 7;
int a[max_len];
int main() {
    int size;
    std::cin >> size;
    char tmp;
    int h;
    std::cin.ignore(5,'[');
    for(int i=0;i<size;++i){
        h = 0;
        tmp = std::cin.get();
        while(tmp!='['&&tmp!=','&&tmp!=']'&&tmp!=' '){
            h*=10;
            h+=tmp-48;
            tmp = std::cin.get();
        }
        a[i] = h;
    }
    int max_pos = 0;
    for (int i = 1; i < size; i++) {
        if (a[i] > a[max_pos]) {
            max_pos = i;
        }
    }
    int max_left = 0, max_right = 0, ret = 0;
    for (int i = 0; i < max_pos; i++) {
        if (a[i] > max_left) {
            max_left = a[i];
        }
        ret += (max_left - a[i]);
    }
    for (int j = size - 1; j > max_pos; j--) {
        if (a[j] > max_right) {
            max_right = a[j];
        }
        ret += (max_right - a[j]);
    }
    std::cout << ret;
    return 0;
}