#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(false);
        
        freopen("bankin.txt", "r", stdin);
        freopen("bankout.txt", "w", stdout);
        
        int N;
        string d;
        cin >> N >> d;

        int s = 1, m = 0;
        for (int i = 0; i < N; ++i) {
                char c = d[i];
                if (c == 'M') {
                        m += s;
                } else {
                        if (s >= N - i) m += s;
                        else s += 1;
                }
        }

        cout << m;

        return 0;
}
