#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(false);
        
        freopen("piratein.txt", "r", stdin);
        freopen("pirateout.txt", "w", stdout);
        
        int L, X, Y;
        cin >> L >> X >> Y;

        cout << min(X + Y, 2 * L - X - Y);

        return 0;
}

