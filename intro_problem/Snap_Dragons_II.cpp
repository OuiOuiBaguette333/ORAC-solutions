#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(false);
        
        freopen("snapin.txt", "r", stdin);
        freopen("snapout.txt", "w", stdout);
        
        int R, C, rR, cR, rS, cS;
        cin >> R >> C >> rR >> cR >> rS >> cS;

        cout << ((abs(rR - rS) + abs(cR - cS) & 1) ? "ROSE" : "SCARLET");

        return 0;
}
