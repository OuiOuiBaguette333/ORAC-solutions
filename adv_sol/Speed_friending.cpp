#include <bits/stdc++.h>
using namespace std;

int p[200005];
int main() {
        cin.tie(0)->sync_with_stdio(false);
        set<pair<int, int>> st;
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
                cin >> p[i];
                st.insert({p[i], i});
        }
        int Q;
        cin >> Q;
        while (Q--) {
                int t;
                cin >> t;
                if (t == 1) {
                        int s;
                        cin >> s;
                        auto [mn, a] = *st.begin();
                        auto [mx, b] = *st.rbegin();
                        if (s == a || s == b) cout << (a + b - 2 * s > 0 ? N : 1) << '\n';
                        else if (abs(mn - p[s]) == abs(mx - p[s]) && (a < s) != (b < s)) cout << "-1\n";
                        else cout << ((abs(mn - p[s]) > abs(mx - p[s]) ? a : b) - s > 0 ? N : 1) << '\n';
                } else {
                        int s, x;
                        cin >> s >> x;
                        st.erase({p[s], s});
                        p[s] = x;
                        st.insert({p[s], s});
                }
        }
        return 0;
}
