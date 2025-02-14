#include <bits/stdc++.h>

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

#ifdef LOCAL 
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define int long long

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for (auto& i : A) std::cin >> i;
    int m1 = -1, m2 = -1, wat = -1;
    std::sort(A.rbegin(), A.rend());
    for (int i = 0; i < N; ++i) {
        if (m1 != -1) {
            if (m2 != -1 && A[i] < m2) {
                wat = A[i];
                break;
            } else if (A[i] < m1) {
                m2 = A[i];
            }
        } else m1 = A[i];
        debug(m1, m2, i + 1, wat, A);
    }

    int cnt = 0;
    for (int i : A) if (i == wat) ++cnt;
    std::cout << wat << ' ' << cnt;
            
    return 0;
}
