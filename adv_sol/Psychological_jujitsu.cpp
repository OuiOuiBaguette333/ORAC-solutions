#include <bits/stdc++.h>
using namespace std;

int b, ans, tmp, card[14];
int main() {
        cin.tie(0)->sync_with_stdio(false);
        
#ifndef DEBUG
        freopen("psychin.txt", "r", stdin);
        freopen("psychout.txt", "w", stdout);
#endif
        
        for (int i = 1; i < 14; ++i) {
                cin >> b;
                card[b] = i;
        }

        for (int i = 2; i < 14; ++i) {
                tmp += card[i - 1];
                ans = max(ans, tmp - card[i]);
        }

        cout << ans;

        return 0;
}

