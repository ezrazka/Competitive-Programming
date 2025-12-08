#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    map<int, int> freq;
    for (int i = 1; i <= n; i++){
        freq[a[i]]++;
    }

    map<int, int> dp;
    multiset<pair<int, int>> ms;
    multiset<array<int, 3>, greater<array<int, 3>>> ms2;
    int q; cin >> q;
    while (q--){
        int idx, val; cin >> idx >> val;
        freq[a[idx]]--;
        if (freq[a[idx]] == 0) freq.erase(a[idx]);
        a[idx] = val;
        freq[a[idx]]++;

        dp.clear();
        ms.clear();
        ms2.clear();

        // use a multiset instead, then we count the offset
        // so we store 1 multiset, for removal
        // when it expires, we add it to a variable with an offset (dp[key] + key)
        // to access it we just do expired + expired_key
        int expired = 1e18, expired_key = 1e18;
        int prev_key = n + 1, prev_val = 0;
        for (auto x = freq.rbegin(); x != freq.rend(); x++){
            auto [key, val] = *x;
            if (key > n) continue;
            if (val > 0){
                ms.insert({dp[prev_key] + (prev_key - key - 1), key - val});
                ms2.insert({key - val, dp[prev_key] + (prev_key - key - 1), key});
            }
            while ((*ms2.begin())[0] >= key){
                if ((*ms2.begin())[1] + (*ms2.begin())[2] < expired + expired_key){
                    expired = (*ms2.begin())[1];
                    expired_key = (*ms2.begin())[2];
                    cout << "! " << expired << ' ' << expired_key << '\n';
                }
                ms.erase(ms.find({(*ms2.begin())[1], (*ms2.begin())[0]}));
                ms2.erase(ms2.begin());
            }
            dp[key] = min(dp[prev_key] + (prev_key - key), expired + expired_key - key - 1);
            if (!ms.empty()) dp[key] = min(dp[key], ms.begin()->first);
            cout << dp[prev_key] << ' ' << prev_key << ' ' << key << ' ' << expired << ' ' << expired_key << '\n';
            if (!ms.empty()) cout << ms.begin()->first << '-' << ms.begin()->second << '\n';
            cout << key << ' ' << val << ' ' << dp[key] << '\n';
            prev_key = key, prev_val = val;
        }
        if (prev_key != 1){
            int key = 1, val = freq[1];
            {
                if (key > n) continue;
                if (val > 0){
                    ms.insert({dp[prev_key] + (prev_key - key - 1), key - val});
                    ms2.insert({key - val, dp[prev_key] + (prev_key - key - 1), key});
                }
                while ((*ms2.begin())[0] >= key){
                    if ((*ms2.begin())[1] + (*ms2.begin())[2] < expired + expired_key){
                        expired = (*ms2.begin())[1];
                        expired_key = (*ms2.begin())[2];
                        // cout << "! " << expired << ' ' << expired_key << '\n';
                    }
                    ms.erase(ms.find({(*ms2.begin())[1], (*ms2.begin())[0]}));
                    ms2.erase(ms2.begin());
                }
                dp[key] = min(dp[prev_key] + (prev_key - key), expired + expired_key - key - 1);
                if (!ms.empty()) dp[key] = min(dp[key], ms.begin()->first);
                // cout << dp[prev_key] << ' ' << prev_key << ' ' << key << ' ' << expired << ' ' << expired_key << '\n';
                // if (!ms.empty()) cout << ms.begin()->first << '-' << ms.begin()->second << '\n';
                // cout << key << ' ' << val << ' ' << dp[key] << '\n';
                prev_key = key, prev_val = val;
            }
        }
        cout << dp[1] << '\n';
    }
}