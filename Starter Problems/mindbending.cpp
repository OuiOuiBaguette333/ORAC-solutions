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
        open(bend);

        int x1, y1, x2, y2;
        int x12, y12, x22, y22;

        cin >> x1 >> y1 >> x2 >> y2 >> x12 >> y12 >> x22 >> y22;

        int a1 = (x2 - x1) * (y2 - y1);
        int a2 = (x22 - x12) * (y22 - y12);

        int olx1 = max(x1, x12);
        int olx2 = min(x2, x22);
        int oly1 = max(y1, y12);
        int oly2 = min(y2, y22);

        int temp = max(0, olx2 - olx1) * max(0, oly2 - oly1);

        int ans = a1 + a2 - temp;

        cout << ans;



        
        return 0;
}

