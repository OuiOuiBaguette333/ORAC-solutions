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
 
    int N, K, X;
    std::cin >> N >> K >> X;
 
    std::vector<int> H(N);
 
    for (auto& i : H) std::cin >> i;
    
    std::queue<int> Q;
    std::unordered_set<int> V;
 
    for (int i : H) {
        if (V.count(i - X) || V.count(i + X)) {
            std::cout << "YES";
            return 0;
        }
        Q.push(i);
        if ((int) Q.size() >= K) {
            int f = Q.front();
            Q.pop();
            V.insert(f);
        }
    }
 
    std::cout << "NO";
 
 
    return 0;
}
