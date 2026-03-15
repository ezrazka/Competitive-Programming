#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

pair<int, int> merge(const pair<int, int> &a, const pair<int, int> &b){
    return make_pair(a.first, -a.second) > make_pair(b.first, -b.second) ? a : b;
}

void solve(){
    int n; cin >> n;
    vector<string> a(n);
    map<string, int> freq;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        a[i] = s;
        {
            set<string> st;
            for (int i = 0; i < s.length(); i++){
                for (int j = i; j < s.length(); j++){
                    string t(s, i, j - i + 1);
                    st.insert(t);
                }
            }
            for (string t : st){
                freq[t]++;
            }
        }
    }

    map<string, bool> winnable;
    for (int len = 30; len >= 1; len--){
        for (auto [s, _] : freq){
            if (s.length() != len) continue;
            if (!winnable[s] && len > 1){
                string t1(s, 0, len - 1);
                string t2(s, 1, len - 1);
                if (freq.find(t1) != freq.end()) winnable[t1] = true;
                if (freq.find(t2) != freq.end()) winnable[t2] = true;
            }
        }
    }

    bool ok = false;
    for (auto [s, win] : winnable){
        if (s.length() != 1) continue;
        if (!win){
            ok = true;
            break;
        }
    }

    map<string, bool> is_root;
    for (auto [s, _] : freq){
        is_root[s] = true;
    }
    for (auto [s, _] : freq){
        if (s.length() > 1){
            string t1(s, 0, s.length() - 1);
            string t2(s, 1, s.length() - 1);
            if (freq.find(t1) != freq.end()) is_root[t1] = false;
            if (freq.find(t2) != freq.end()) is_root[t2] = false; 
        }
    }

    map<string, int> val;
    for (auto [s, cnt] : freq){
        int sum = 0, mx = 0;
        for (char c : s) sum += c - 'a' + 1;
        for (char c : s) mx = max(mx, c - 'a' + 1ll);
        val[s] = sum * mx + cnt;
    }

    map<string, pair<int, int>> dp;
    for (int len = 30; len >= 1; len--){
        for (auto [s, _] : freq){
            if (s.length() != len) continue;
            if (len > 1){
                string t1(s, 0, len - 1);
                string t2(s, 1, len - 1);
                if (freq.find(t1) != freq.end() && !(winnable[s] && winnable[t1])) dp[t1] = merge(dp[t1], {val[s] + dp[s].second, dp[s].first});
                if (freq.find(t2) != freq.end() && !(winnable[s] && winnable[t2])) dp[t2] = merge(dp[t2], {val[s] + dp[s].second, dp[s].first});
            }
        }
    }
    
    pair<int, int> ans = {-1, -1};
    for (auto [s, win] : winnable){
        if (s.length() != 1) continue;
        if (win != ok){
            ans = merge(ans, {val[s] + dp[s].second, dp[s].first});
        }
    }

    cout << (ok ? "First\n" : "Second\n");
    cout << ans.first << ' ' << ans.second << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}