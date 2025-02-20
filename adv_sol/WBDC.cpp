//trans rights
#include <bits/stdc++.h>
using namespace std;
#ifndef DEBUG
#define open(name) \
        freopen(#name "in.txt", "r", stdin); \
freopen(#name "out.txt", "w", stdout)
#else
#define open(name)
#endif
 
 
#ifdef LOCAL 
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        open(bus);
        int N, K;
        cin >> N >> K;
        
        vector<bool> ok(N + 1, false);
        vector<int> A(N), B(K);
        for (int i = 0; i < N; ++i) {
                cin >> A[i];
        }
        for (int i = 0; i < K; ++i) {
                cin >> B[i];
                ok[B[i]] = true;
        }
         
        vector<bool> ok2 = ok;
        vector<pair<int, int>> game;
        for (int i = 0; i < N; i += 2) {
                game.push_back({i + 1, i + 2});
        }
       
        vector<pair<int, int>> good(N - 1, {0, 0});
 
        int cum = 0, prev = N;
        while ((int) game.size() < N - 1) {
                for (int i = cum; i < (int) game.size(); i += 2) {
                        pair<int, int> dec;
                        if (A[game[i].first - 1] > A[game[i].second - 1]) {
                                dec.first = game[i].first;
                        } else {
                                dec.first = game[i].second;
                        }
                        if (A[game[i + 1].first - 1] > A[game[i + 1].second - 1]) {
                                dec.second = game[i + 1].first;
                        } else {
                                dec.second = game[i + 1].second;
                        }
                        if (dec.second && dec.first) game.push_back(dec);
                }
                prev /= 2;
                cum = game.size() - prev;
                debug(game);
        }
        
        for (int i = 0; i < (int) game.size(); ++i) { 
                if (game[i].first && game[i].second) {
                        if (ok2[game[i].first] && ok2[game[i].second]) {
                                ok2[game[i].first] = false, ok2[game[i].second] = false;
                                good[i].first = 2;
                                good[i].second = i + 1;
                        } else if (ok2[game[i].first] || ok2[game[i].second]) {
                                good[i].first = 1;
                                good[i].second = i + 1;
                        } else {
                                good[i].second = i + 1;
                        }
                }
        }
        int cnt = 0;
 
        vector<pair<int, int>> freq(N - 1);
        sort(good.rbegin(), good.rend());
        debug(good);
        for (int i = 0; i < N - 1; ++i) {
                freq[i] = game[good[i].second - 1];
        }
        debug(freq);

 
        for (int i = 0; i < (int) freq.size(); ++i) {
                if (ok[freq[i].first] && ok[freq[i].second]) {
                        ok[freq[i].first] = false, ok[freq[i].second] = false;
                        ++cnt;
                } else if (ok[freq[i].first]) {
                        ok[freq[i].first] = false;
                        ++cnt;
                } else if (ok[freq[i].second]) {
                        ok[freq[i].second] = false;
                        ++cnt;
                }
        }
 
 
        cout << cnt;
 
 
        return 0;
}
