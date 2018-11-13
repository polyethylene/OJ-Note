#include <iostream>
#include <cstring>

#define map temp
const int max = 1e3 + 7;

static int map[max][max];
int m, n;

inline bool check(int x, int y, int val);
int shortest(int begx, int begy, int endx, int endy);

int main()
{
    std::cin >> n >> m;
    int beg_posx, beg_posy, p_posx[max], p_posy[max], end_posx, end_posy;
    int count = 0;
    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<n; j++)
        {
            std::cin >> map[i][j];
            if (map[i][j] == 4)
            {
                p_posx[count] = i;
                p_posy[count] = j;
                count++;
            }
            else if (map[i][j] == 3)
            {
                end_posx = i;
                end_posy = j;
            }
            else if (map[i][j] == 2)
            {
                beg_posx = i;
                beg_posy = j;
            }
        }
    }
    int res = max * max;
    for (int i = 0; i<count; i++)
    {
        int first = shortest(beg_posx, beg_posy, p_posx[i], p_posy[i]);
        int second = shortest(p_posx[i], p_posy[i], end_posx, end_posy);
        if (first>0 && second>0 && first + second<res)
        {
            res = first + second;
        }
    }
    std::cout << res;
    return 0;
}


std::pair<int,int> A[max*max];
int dir[max*max];
int head=0,dhead=0;

int shortest(int begx, int begy, int endx, int endy)
{
    std::pair<int, int> plot;
    map[begx][begy] = 0;
    int min = 0;
    A[head++] = { begx,begy };
    dir[dhead++] = 0;
    while (head)
    {
        plot = A[head-1];
        if (plot.first == endx&&plot.second == endy)
        {
            if (!min)
            {
                min = head;
            }
            else if (head<min)
            {
                min = head;
                map[plot.first][plot.second] = 0;
                head--;
                continue;
            }
        }

        if (dir[dhead-1] < 1 && plot.first < m - 1)
        {

            dir[dhead-1] = 1;
            plot.first++;
            if (check(plot.first, plot.second, 1))
            {
                A[head++]=plot;
                dir[dhead++] = 0;
                map[plot.first][plot.second] = 1;
                continue;
            }
            plot.first--;
        }

        if (dir[dhead-1] < 2 && plot.first > 0)
        {
            dir[dhead-1] = 2;

            plot.first--;
            if (check(plot.first, plot.second, 1))
            {
                A[head++]=plot;
                dir[dhead++] = 0;
                map[plot.first][plot.second] = 1;
                continue;
            }
            plot.first++;
        }

        if (dir[dhead-1] < 3 && plot.second < n - 1)
        {
            dir[dhead-1] = 3;

            plot.second++;
            if (check(plot.first, plot.second, 1))
            {
                A[head++]=plot;
                dir[dhead++] = 0;
                map[plot.first][plot.second] = 1;
                continue;
            }
            plot.second--;
        }

        if (dir[dhead-1] < 4 && plot.second > 0)
        {
            dir[dhead-1] = 4;
            plot.second--;
            if (check(plot.first, plot.second, 1))
            {
                A[head++]=plot;
                dir[dhead++] = 0;
                map[plot.first][plot.second] = 1;
                continue;
            }
            plot.second++;
        }

        map[plot.first][plot.second] = 0;
        head--;
        dhead--;
    }

    if (!head)
    {
        return min-1;
    }
    return -1;
}

inline bool check(int x, int y, int val)
{
    return map[x][y] != val;
}