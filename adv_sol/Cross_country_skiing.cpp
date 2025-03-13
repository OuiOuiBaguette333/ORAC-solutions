#include <bits/stdc++.h>

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

#ifdef LOCAL 
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define int long long

int N, M, E[505][505];
int wcnt;
std::set<std::pair<int, int>> coords;
bool ok(int x, int y) {
    return x >= 1 && y >= 1 && x <= N && y <= M;
}
bool ww(int val) {
    std::queue<std::pair<int, int>> Q;
    int rn = 0;
    int ff, ss;
    bool vis[505][505];
    for (int i = 0; i <= 504; ++i) {
        for (int j = 0; j <= 504; ++j) 
            vis[i][j] = false;
    }
    std::tie(ff, ss) = *coords.begin();
    Q.push({ff, ss});
    vis[ff][ss] = true;
    
    while (Q.size()) {
        auto[a, b] = Q.front();
        Q.pop();
        if (coords.count({a, b})) rn++; 
        for (int i = 0; i < 4; ++i) {
            int nx = a + dx[i], ny = b + dy[i];

            if (ok(nx, ny) && !vis[nx][ny]) {
                int dist = std::abs(E[nx][ny] - E[a][b]);
                if (dist <= val) {
                    Q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }
    return rn == wcnt;
    
}
signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifndef DEBUG
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
#endif
    std::cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            std::cin >> E[i][j];
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            int x;
            std::cin >> x;
            if (x == 1) {
                coords.insert({i, j});
                wcnt++;
            }
        }
    }

    int mnd = INT_MAX, mxd = INT_MIN;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {

            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[i], ny = j + dy[i];
                if (ok(nx, ny)) {
                    mnd = std::min(mnd, std::abs(E[i][j] - E[nx][ny]));
                    mxd = std::max(mxd, std::abs(E[i][j] - E[nx][ny]));
                }
            }
        }
    }

    while (mnd < mxd) {
        int m = (mnd + mxd) / 2;
        if (ww(m)) mxd = m;
        else mnd = m + 1;
    }

    std::cout << mnd;

    return 0;
}

