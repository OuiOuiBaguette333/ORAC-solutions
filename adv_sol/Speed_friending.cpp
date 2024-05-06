#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define sz(x) (int)(x).size()

#define int ll
signed main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
 
        int N;
        cin >> N;
        vector<int> A(N);
        multiset<pair<int, int>> S;
        for (int i = 0; i < N; ++i) {
                cin >> A[i];
                S.insert(make_pair(A[i], i + 1));
        }
 
        
        int Q;
        cin >> Q;
 
        while (Q--) {
                int T;
                cin >> T;
 
                if (T == 1) {
                        int a;
                        cin >> a;
                        auto[j, k] = *S.begin();
                        auto[J, K] = *S.rbegin();
                        if (a == k || a == K) {
                                if (k + K - 2 * a > 0) {
                                        cout << N;
                                } else cout << 1;
                        } else if (abs(j - A[a - 1]) == abs(J - A[a - 1]) && (k < a) != (K < a)) {
                                cout << -1;
                        } else {
                                int p = -1;
                                if (abs(j - A[a - 1]) > abs(J - A[a - 1])) {
                                        p = k;
                                } else p = K;
                                if (p - a > 0) {
                                        cout << N;
                                } else cout << 1;
                        }
                        cout << '\n';
                }
                if (T == 2) {
                        int a, b;
                        cin >> a >> b;
                        --a;
                        S.erase({A[a], a + 1});
                        A[a] = b;
                        S.insert(make_pair(A[a], a + 1));
                }
        }
 
 
        return 0;
}
