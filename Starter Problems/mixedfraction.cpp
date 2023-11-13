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
        open(mix);
 
        int n, d;
 
        cin >> n >> d;
 
        int sol = n % d;
 
        if (sol != 0) {
                cout << n / d << ' ' << sol << '/' << d;
        } else {
                cout << n / d;
        }
        
        return 0;
}
