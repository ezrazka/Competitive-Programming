#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int BASE1 = 31;
const int BASE2 = 37;

void solve(){
    string s; cin >> s;
    int n = s.length();
    int m; cin >> m;
    vector<string> words(m);
    for (int i = 0; i < m; i++){
        cin >> words[i];
    }

    set<pii> hashes;
    for (int i = 0; i < m; i++){
        int hash1 = 0, hash2 = 0;
        int pow1 = 1, pow2 = 1;
        for (char c : words[i]){
            hash1 = (hash1 + (c - 'a' + 1) * pow1) % MOD1;
            hash2 = (hash2 + (c - 'a' + 1) * pow2) % MOD2;
            pow1 = (pow1 * BASE1) % MOD1;
            pow2 = (pow2 * BASE2) % MOD2;
        }
        hashes.insert({hash1, hash2});
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        int hash1 = 0, hash2 = 0;
        int pow1 = 1, pow2 = 1;
        for (int j = i; j < n; j++){
            hash1 = (hash1 + (s[j] - 'a' + 1) * pow1) % MOD1;
            hash2 = (hash2 + (s[j] - 'a' + 1) * pow2) % MOD2;
            pow1 = (pow1 * BASE1) % MOD1;
            pow2 = (pow2 * BASE2) % MOD2;
            if (hashes.find({hash1, hash2}) != hashes.end()){
                dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
            }
        }
    }
    cout << dp[n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}