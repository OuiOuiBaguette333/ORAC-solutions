#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
#define speed() \
ios::sync_with_stdio(false); \
cin.tie(0)
#ifndef DEBUG
#define open(name) \
speed(); \
freopen(#name "in.txt", "r", stdin); \
freopen(#name "out.txt", "w", stdout)
#else
#define open(name) speed()
#endif
#define all(x) (x).begin(), (x).end()
#define _forI(var, start, end) for (int var = start; var < end; var++)

int main() {
        open(list);

        int f;
        cin >> f;

        map<int, set<int>> fr;

        _forI (i, 0, f) {
                int a, b;
                cin >> a >> b;
                fr[a].insert(b);
                fr[b].insert(a);
        }

        int maxF = 0;
        set<int> w;

        for (auto it : fr) {
                int fSize = it.second.size();
                if (fSize > maxF) {
                        maxF = fSize;
                        w.clear();
                        w.insert(it.first);
                } else if (fSize == maxF) {
                        w.insert(it.first);
                }

        }

        int ans = 0;

        for (int ans : w) {
                cout << ans << '\n';
        }


        
        return 0;
}

