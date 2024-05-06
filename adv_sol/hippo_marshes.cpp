#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(false);

        int n, m;
        cin >> n >> m;

        vector<vector<int>> p1(n + 1), p2(n + 1);

        for (int i = 0, a, b; i < m; ++i) {
                cin >> a >> b;
                p1[a].push_back(b);
                p2[b].push_back(a);
        }

        vector<int> f1(n + 1), f2(n + 1);

        queue<int> q;
        q.push(1);

        while (!q.empty()) {
                int i = q.front();
                q.pop();

                f1[i] = 1;
                for (auto it : p1[i]) {
                        if (!f1[it]) q.push(it);
                }
        }

        queue<int> Q;
        Q.push(n);

        while (!Q.empty()) {
                int i = Q.front();
                Q.pop();

                f2[i] = 1;
                for (auto it : p2[i]) {
                        if (!f2[it]) Q.push(it);
                }
        }

        int cnt = 0;
        for (int i = 1; i <= n; ++i) if (f1[i] && f2[i]) ++cnt;
        
        cout << cnt;

        return 0;
}
