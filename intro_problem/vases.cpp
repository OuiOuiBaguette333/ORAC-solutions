#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(false);
        
        freopen("vasesin.txt", "r", stdin);
        freopen("vasesout.txt", "w", stdout);
        
        int N;
        cin >> N;

        if (N < 6) cout << "0 0 0";
        else cout << "1 2 " << N - 3;

        return 0;
}

