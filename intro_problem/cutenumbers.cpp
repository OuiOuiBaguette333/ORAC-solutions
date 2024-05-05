#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(false);
        
        freopen("cutein.txt", "r", stdin);
        freopen("cuteout.txt", "w", stdout);

        int d;
        cin >> d;

        int cnt = 0;

        for (int i = 0; i < d; ++i) {
                int _;
                cin >> _;

                if (!_) ++cnt;
                else cnt = 0;
        }

        cout << cnt;

        return 0;
}
