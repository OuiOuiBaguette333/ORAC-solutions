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

    int D;
    std::cin >> D;

    int r;
    while (std::cin >> r) {
        if (r >= D) {
            std::cout << D;
            return 0;
        } else D += r;
    }


    return 0;
}
