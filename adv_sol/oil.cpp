#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct Point {
        int x, y;
};
bool isValid(int x, int y, int R, int C) {
        return x >= 0 && x < R && y >= 0 && y < C;
}
void bfs(int R, int C, int K, vector<string>& grid) {
        queue<Point> q;



        for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) {
                        if (grid[i][j] == '$') {
                                q.push({i, j});
                        }
                }
        }

        while (K--) {
                int size = q.size();
                while (size--) {
                        Point curr = q.front();
                        q.pop();

                        for (int dir = 0; dir < 4; ++dir) {
                                int newX = curr.x + dx[dir];
                                int newY = curr.y + dy[dir];

                                if (isValid(newX, newY, R, C) && grid[newX][newY] == '.') {
                                        grid[newX][newY] = '*'; 
                                        q.push({newX, newY}); 
                                }
                        }
                }
        }
}
int main() {
        cin.tie(0)->sync_with_stdio(false);

        freopen("oilin.txt", "r", stdin);
        freopen("oilout.txt", "w", stdout);

        int R, C, K;
        cin >> R >> C >> K;

        vector<string> grid(R);
        for (int i = 0; i < R; ++i) {
                cin >> grid[i];
        }

        bfs(R, C, K, grid);

        for (int i = 0; i < R; ++i) {
                cout << grid[i] << '\n';
        }

        return 0;
}
