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
        open(trip);

        int n;
        cin >> n;

        vi a(n);
        vi triples;

        _forI (i, 0, n) {
                cin >> a[i];
                if (a[i] % 3 == 0) {
                        triples.push_back(i + 1);
                }
        }

        if (triples.empty()) {
                cout << "Nothing here!";
        } else {
                int k = triples.size();
                cout << k << '\n';
                _forI (i, 0, k) {
                        cout << triples[i] << ' ';
                }
        }


        
        return 0;
}

