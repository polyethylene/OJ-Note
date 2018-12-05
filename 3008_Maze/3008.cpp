#include<iostream>

const int max_len = 107;

char maze[max_len][max_len];
bool visited[max_len][max_len];

int move[4][2] = {{1,  0},
                  {-1, 0},
                  {0,  1},
                  {0,  -1}};
int m, n;
int begx, begy, endx, endy;

struct node {
    int x;
    int y;
    int len;

    node() = default;

    node(int a, int b, int l) : x(a), y(b), len(l) {}
};

node que[max_len * max_len];
int front = 0;
int rear = 0;

void push(node &a) {
    que[rear++] = a;
}

bool empty() {
    return front == rear;
}

node pop() {
    node tmp = que[front];
    front++;
    front %= (max_len * max_len);
    return tmp;
}


void init() {
    std::cin >> n >> m >> begx >> begy >> endx >> endy;
    begx--;
    begy--;
    endx--;
    endy--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> maze[i][j];
        }
    }
}

int bfs() {
    int dx, dy;
    node beg(begx, begy, 0);
    push(beg);
    visited[beg.x][beg.y] = true;
    while (!empty()) {
        node tmp = pop();
        for (int i = 0; i < 4; i++) {
            dx = move[i][0];
            dy = move[i][1];
            if ((dx == 1 || dx == -1) && maze[tmp.x][tmp.y] == '-') {
                continue;
            }
            if ((dy == 1 || dy == -1) && maze[tmp.x][tmp.y] == '|') {
                continue;
            }
            node next(tmp.x + dx, tmp.y + dy, tmp.len + 1);
            if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m ||
                visited[next.x][next.y] || maze[next.x][next.y] == '*') {
                continue;
            }
            if ((dx == 1 || dx == -1) && maze[next.x][next.y] == '-') {
                continue;
            }
            if ((dy == 1 || dy == -1) && maze[next.x][next.y] == '|') {
                continue;
            }
            push(next);
            visited[next.x][next.y] = true;
            if (next.x == endx && next.y == endy) {
                return next.len;
            }
        }
    }
    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    init();
    std::cout << bfs();

    std::cout << std::flush;
    return 0;
}