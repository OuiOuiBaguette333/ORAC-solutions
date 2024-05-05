#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(false);
        
        freopen("fashin.txt", "r", stdin);
        freopen("fashout.txt", "w", stdout);
        
        int T;
        cin >> T;

        int n[] = {100, 20, 5, 1};

        int cnt = 0;
        for (int i = 0; i < 4; ++i) {
                while (T >= n[i]) {
                        cnt += T / n[i];
                        T %= n[i];
                }
        }
        cout << cnt;

        return 0;
}

