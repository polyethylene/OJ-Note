#include<iostream>
#include<iomanip>

const int max_size = 1e6 + 7;
const int max_size2 = 1e5 + 7;

int Mqueue[max_size];
int Fqueue[max_size];
int songs[max_size2];
int Mfront = 0, Mrear = 0;
int Ffront = 0, Frear = 0;

int partition(int *li, int beg, int end) {
    int i = beg, j = end;
    int pivot = li[beg];
    while (i < j) {
        while (i < j && li[j] >= pivot)
            j--;
        if (i < j)
            li[i++] = li[j];
        while (i < j && li[i] <= pivot)
            i++;
        if (i < j)
            li[j--] = li[i];
    }
    li[i] = pivot;
    return i;
}


void quickSort(int *li, int beg, int end) {
    if (beg < end) {
        int pivot = partition(li, beg, end);
        quickSort(li, beg, pivot - 1);
        quickSort(li, pivot + 1, end);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int songNum, size, sex;
    std::cin >> songNum;
    for (int i = 0; i < songNum; i++) {
        std::cin >> songs[i];
    }
    std::cin >> size;
    for (int j = 0; j < size; j++) {
        std::cin >> sex;
        if (sex == 1) {
            std::cin >> Mqueue[Mrear++];
        } else {
            std::cin >> Fqueue[Frear++];
        }
    }

    quickSort(Mqueue, 0, Mrear - 1);
    quickSort(Fqueue, 0, Frear - 1);

    long long Mwait = 0, Fwait = 0;
    long long time = 0;

    for (int i = 0; i < songNum - 1; i++) {
        while (Mfront!=Mrear && Mqueue[Mfront] <= time && Ffront!=Frear && Fqueue[Ffront] <= time) {
            Mwait += time - Mqueue[Mfront++];
            Fwait += time - Fqueue[Ffront++];
        }
        time += songs[i];
    }

    while (Mfront != Mrear) {
        Mwait += time - Mqueue[Mfront++];
    }

    while (Ffront != Frear) {
        Fwait += time - Fqueue[Ffront++];
    }

    if (!Frear)
        Frear = 1;
    if (!Mrear)
        Mrear = 1;

    std::cout << std::fixed << std::setprecision(2) << (double) Mwait / (double) Mrear << " "
              << (double) Fwait / (double) Frear;
    std::cout << std::flush;
    return 0;
}
