//the idea is that you store the dictionary words in a hashset
//then try replacing each character in the search word
//and see if it is in the hashset
//since TL is long and data is relatively small
//this will pass
#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<std::string> A(N);

    std::vector<char> rep; //replacement characters, here i am making an alphabet
    char x = 'a';
    for (;x != '{';x++) 
        rep.push_back(x);
    
    std::unordered_set<std::string> map; //this is the hastset
    
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        map.insert(A[i]);
    }

    int M;
    std::cin >> M;

    std::vector<std::string> Q(M); //query words

    for (int i = 0; i < M; ++i) {
        std::cin >> Q[i];
    }
    
    for (int i = 0; i < M; ++i) {
        if (map.find(Q[i]) != map.end()) {//the word is already there
            std::cout << Q[i] << '\n';
        } else {
            bool found = false;
            for (int j = 0; j < (int) Q[i].size(); ++j) {
                std::string alt_ver = Q[i];
                for (int k = 0; k < 26; ++k) {
                    alt_ver[j] = rep[k];
                    if (map.find(alt_ver) != map.end()) {
                        found = true;
                        std::cout << alt_ver << '\n';
                        goto out;
                    }
                }
            }
out:
            if (not found) std::cout << "?\n";
        }
    }


    return 0;
}

