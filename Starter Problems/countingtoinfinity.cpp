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
        open(count);

        int n;
        cin >> n;

        int ans = 0;

        _forI (i, 0, n) {
                ans++;
                cout << ans << '\n';
        }
        
        return 0;
}

