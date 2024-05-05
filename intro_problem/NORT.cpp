#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(false);
        
        freopen("nortin.txt", "r", stdin);
        freopen("nortout.txt", "w", stdout);
        
        int W, H;
        cin >> W >> H;

        cout << ((W * H) & 1 ? (W * H) - 1 : (W * H)); // X & 1 checks if a number is odd(1) or even(0)

        return 0;
}

