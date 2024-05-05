#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(false);
        
        freopen("ladyin.txt", "r", stdin);
        freopen("ladyout.txt", "w", stdout);

        int N;
        cin >> N;

        vector<int> A(N);
        for (auto& a : A) 
                cin >> a;
        
        sort(A.rbegin(), A.rend());
        cout << A[0] - A[N - 1] + 1;

        return 0;
}

