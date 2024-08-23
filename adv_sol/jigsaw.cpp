#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define sz(x) (int)(x).size()
 
#ifdef LOCAL 
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define int double
 
 
void add(vector<pair<int, int>> og, vector<pair<int, int>>& sted, vector<vector<pair<int, int>>>& res) {
        vector<pair<int, int>> temp = og;
        sort(all(temp));
        debug(temp, sted);
        if (temp == sted) {
                res.pb(og);
                return;
        }
}
 
        
signed main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
 
#ifndef DEBUG
        freopen("jigin.txt", "r", stdin);
        freopen("jigout.txt", "w", stdout);
#endif
 
        int n;
        cin >> n;
        vector<pair<int, int>> pzz(n);
        
        for (int i = 0; i < n; ++i) {
                cin >> pzz[i].first >> pzz[i].second;
        }
        //vertical flip
        int l = 1e9, r = -1e9;
        vector<pair<int, int>> sted = pzz;
        sort(all(sted));
        for (int i = 0; i < n; ++i) {
                l = min(l, pzz[i].first);
                r = max(r, pzz[i].first);
        }
 
        int mid = (l + r) / 2;
        vector<pair<int, int>> check;
        for (int i = 0; i < n; ++i) {
                pair<int, int> reflect = make_pair((r - (pzz[i].first - l)), pzz[i].second);
                check.pb(reflect);
        }
        vector<vector<pair<int, int>>> res;
        add(check, sted, res);
        // unordered_set<pair<int, int>, pair_hash> lkup;
        // for (int i = 0; i < n; ++i) {
        //         lkup.insert(make_pair(check[i].first, check[i].second));
        // }
        // //just checking
        // bool ok = true;
        // for (int i = 0; i < n; ++i) {
        //         auto f = lkup.find(pzz[i]);
        //         if (f == lkup.end()) {
        //                 ok = false;
        //                 break;
        //         } else continue;
        // }
 
        
        // if (ok) {
        //         ++cnt;
        //         res.pb(check);
        // }
        //horizontal flip
        int up = -1e9, down = 1e9;
        for (int i = 0; i < n; ++i) {
                down = min(down, pzz[i].second);
                up = max(up, pzz[i].second);
        }
        
        int vert_cut = (up + down) / 2;
 
        vector<pair<int, int>> check2;
        for (int i = 0; i < n; ++i) {
                if (pzz[i].second < vert_cut) {
                        int dist = vert_cut - pzz[i].second;
                        pair<int, int> vert = make_pair(pzz[i].first, pzz[i].second + (dist * 2));
                        check2.pb(vert);
                }
                //on
                if (pzz[i].second == vert_cut) {
                        check2.pb(pzz[i]);
                }
                //above
                if (pzz[i].second > vert_cut) {
                        int dist = pzz[i].second - vert_cut;
                        pair<int, int> vert = make_pair(pzz[i].first, pzz[i].second - (dist * 2));
                        check2.pb(vert);
                }
        }
        add(check2, sted, res);
        //
        // unordered_set<pair<int, int>, pair_hash> vert_lkup;
        // for (int i = 0; i < n; ++i) {
        //         vert_lkup.insert(make_pair(check2[i].first, check2[i].second));
        // }
        //
        // bool ok2 = true;
        // for (int i = 0; i < n; ++i) {
        //         auto f = vert_lkup.find(pzz[i]);
        //         if (f == lkup.end()) {
        //                 ok2 = false;
        //                 break;
        //         } else continue;
        // }
        // if (ok2) {
        //         ++cnt;
        //         res.pb(check2);
        // }
 
        //rotation 
        vector<pair<int, int>> rotate = pzz;
        //counter clockwise rotation (x, y) -> (x', y') (x' = -y, y' = x)
        //remember to translate the centre point to the centre of the thing
        //mid->y coord, vert_cut->x coord
        swap(vert_cut, mid);
        for (int i = 0; i < n; ++i) {
                rotate[i].first -= vert_cut;
                rotate[i].second -= mid;
        }
        //90
        for (int i = 0; i < n; ++i) {
                pair<int, int> new_pt = make_pair(-(rotate[i].second), rotate[i].first);
                rotate[i] = new_pt;
        }
        vector<pair<int, int>> rotate_90 = rotate;
        for (int i = 0; i < n; ++i) {
                rotate_90[i].first += vert_cut;
                rotate_90[i].second += mid;
        }
        add(rotate_90, sted, res);
        //180 the code below words as well but i need to continue the processing
        // reverse(all(check));
        // res.pb(check);
        // ++cnt;
        for (int i = 0; i < n; ++i) {
                pair<int, int> new_pt = make_pair(-(rotate[i].second), rotate[i].first);
                rotate[i] = new_pt;
        }
        vector<pair<int, int>> rotate_180 = rotate;
        for (int i = 0; i < n; ++i) {
                rotate_180[i].first += vert_cut;
                rotate_180[i].second += mid;
        }
        add(rotate_180, sted, res);
        //270
        for (int i = 0; i < n; ++i) {
                pair<int, int> new_pt = make_pair(-(rotate[i].second), rotate[i].first);
                rotate[i] = new_pt;
        }
        vector<pair<int, int>> rotate_270 = rotate;
        for (int i = 0; i < n; ++i) {
                rotate_270[i].first += vert_cut;
                rotate_270[i].second += mid;
        }
        add(rotate_270, sted, res);
        //dammit i forgot diagonal
        //rotate back first
        for (int i = 0; i < n; ++i) {
                pair<int, int> new_pt = make_pair(-(rotate[i].second), rotate[i].first);
                rotate[i] = new_pt;
        }
        //Left diagonal
        for (int i = 0; i < n; ++i) {
                pair<int, int> l_diag = make_pair(rotate[i].second, rotate[i].first);
                rotate[i] = l_diag;
        }
        vector<pair<int, int>> l_flip = rotate;
        for (int i = 0; i < n; ++i) {
                l_flip[i].first += vert_cut;
                l_flip[i].second += mid;
        }
        add(l_flip, sted, res);
        //Right diagonal
        //flip back first
        for (int i = 0; i < n; ++i) {
                pair<int, int> l_diag = make_pair(rotate[i].second, rotate[i].first);
                rotate[i] = l_diag;
        }
        //now flip
        for (int i = 0; i < n; ++i) {
                pair<int, int> r_diag = make_pair(-(rotate[i].second), -(rotate[i].first));
                rotate[i] = r_diag;
        }
        vector<pair<int, int>> r_flip = rotate;
        for (int i = 0; i < n; ++i) {
                r_flip[i].first += vert_cut;
                r_flip[i].second += mid;
        }
        add(r_flip, sted, res);
        cout << sz(res) << '\n';
        for (int i = 0; i < sz(res); ++i) {
                for (int j = 0; j < n; ++j) {
                        cout << res[i][j].first << ' ' << res[i][j].second << '\n';
                }
                cout << '\n';
        }
 
        
        return 0;
}
