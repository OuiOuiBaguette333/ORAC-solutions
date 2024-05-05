#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(false);
        
        freopen("ninjain.txt", "r", stdin);
        freopen("ninjaout.txt", "w", stdout);

        int N, K;
        cin >> N >> K;
        cout << N - (N + K) / (K + 1);

        return 0;
}

