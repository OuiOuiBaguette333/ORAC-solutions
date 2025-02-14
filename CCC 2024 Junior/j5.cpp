#include <bits/stdc++.h>

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

#ifdef LOCAL 
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define int long long

int R, C;
bool val(int x, int y) {
    return x >= 0 && y >= 0 && x < R && y < C;
}
signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> R >> C;
    
    std::vector<std::vector<char>> grid(R, std::vector<char> (C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> grid[i][j];
        }
    }
    
    int x, y;
    std::cin >> x >> y;
    std::vector<std::vector<bool>> vis(R, std::vector<bool> (C, false));
    std::queue<int> qx, qy;
    qx.push(x);
    qy.push(y);
    vis[x][y] = true;
    std::unordered_map<char, int> idk;
    idk['S'] = 1;
    idk['M'] = 5;
    idk['L'] = 10;
    int cnt = 0;
    while (!qx.empty()) {
        int cx = qx.front(), cy = qy.front();
        qx.pop();
        qy.pop();
        if (grid[cx][cy] != '*') cnt += idk[grid[cx][cy]];

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (val(nx, ny)) {
                if (!vis[nx][ny] && grid[nx][ny] != '*') {
                    vis[nx][ny] = true;
                    qx.push(nx);
                    qy.push(ny);
                }
            }
        }
    }

    std::cout << cnt;

    return 0;
}
