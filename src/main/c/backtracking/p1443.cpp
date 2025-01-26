#include <cstdio>
#include <queue>
using namespace std;

#define MAX_N 400
int dir[8][2] = {
    { 2, 1 }, { -2, 1 }, { 2, -1 }, { -2, -1 },
    { 1, 2 }, { 1, -2 }, { -1, 2 }, { -1, -2 }
};
int dis[MAX_N + 5][MAX_N + 5];
int n, m;



void dfs(int step, int x, int y) {
    if (dis[x][y] != -1 && dis[x][y] <= step) return;
    dis[x][y] = step;
    for (int k = 0; k < 8; k++) {
        int dx = x + dir[k][0];
        int dy = y + dir[k][1];
        if (dx < 1 || dx > n) continue;
        if (dy < 1 || dy > m) continue;
        dfs(step + 1, dx, dy);
    }
    return;
}


struct Node {
    Node(int x, int y, int s): x(x), y(y), s(s) {}
    int x, y, s;
};



void bfs(int n, int m, int a, int b) {
    queue<Node> q;
    q.push(Node(a, b, 0));
    dis[a][b] = 0;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        for (int k = 0; k < 8; k++) {
            int dx = now.x + dir[k][0];
            int dy = now.y + dir[k][1];
            if (dx < 1 || dx > n) continue;
            if (dy < 1 || dy > m) continue;
            if (dis[dx][dy] != -1) continue;
            q.push(Node(dx, dy, now.s + 1));
            dis[dx][dy] = now.s + 1;
        }
    }
    return;
}






int main (int argc, char *argv[]) {
    int a, b;
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dis[i][j] = -1;
        }
    }
    bfs(n, m, a, b);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j > 1) printf(" ");
            printf("%d", dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}
