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
        open(dish);

        int n;
        cin >> n;

        vi a(n);

        int sum = 0;

        _forI (i, 0, n) {
                cin >> a[i];
        }


        int mine = *min_element(all(a));
        int maxe = *max_element(all(a));

        for (int it : a) {
                sum += it;
        }

        int mean = (sum) / n;

        cout << mine << ' ' << maxe << ' ' << mean;
        
        return 0;
}

