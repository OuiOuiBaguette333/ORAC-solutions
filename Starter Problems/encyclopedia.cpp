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
        open(ency);

        int n, q;
        cin >> n >> q;

        vi a(n);

        _forI (i, 0, n) {
                cin >> a[i];
        }

        _forI (i, 0, q) {
                int qe;
                cin >> qe;
                cout << a[qe - 1] << '\n';
        }


        
        return 0;
}

