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
        open(dict);

        int d, w;
        cin >> d >> w;

        map<int, int> dict;

        _forI (i, 0, d) {
                int a, b;
                cin >> a >> b;

                dict[a] = b;
        }

        _forI (i, 0, w) {
                int y;
                cin >> y;

                if (dict.find(y) != dict.end()) {
                        cout << dict[y] << '\n';
                } else {
                        cout << "C?\n";
                }

        }


        
        return 0;
}

