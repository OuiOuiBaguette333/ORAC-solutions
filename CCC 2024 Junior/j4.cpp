#include <bits/stdc++.h>

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

#ifdef LOCAL 
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define int long long
#define dd(x) std::cout << x.first << ' ' << x.second << '\n';

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string A, B;
    std::cin >> A >> B;

    int j = 0;
    bool f = false;
    bool quiet = false;
    std::pair<char, char> e;
    char x = '-';
    for (int i = 0; i < (int) A.size() || j < (int) B.size(); ++i, ++j) {
        if (A[i] != B[j]) {
            if (!f) {
                if (A[i + 1] == B[j]) {
                    quiet = true;
                    x = A[i];
                    break;
                } else {
                    e = {A[i], B[j]};
                    f = true;
                    break;
                }
            }
        }
    }
    if (quiet) {
        std::string T = "";
        for (int i = 0; i < (int) A.size(); ++i) {
            if (A[i] != x) T += A[i];
        }
        for (int i = 0; i < (int) T.size(); ++i) {
            if (T[i] != B[i]) {
                e = {T[i], B[i]};
                break;
            }
        }
        std::cout << e.first << ' ' << e.second << '\n' << x;
        return 0;
    } else if (f) {
        std::string T = "";
        for (int i = 0; i < (int) A.size(); ++i) {
            if (i == (int) B.size()) {
                x = A[i];
                break;
            }
            if (A[i] != B[i] && e != std::make_pair(A[i], B[i])) {
                x = A[i];
                break;
            }
        }
        std::cout << e.first << ' ' << e.second << '\n' << x;
    }

    return 0;
}
