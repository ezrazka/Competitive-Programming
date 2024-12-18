#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int BASE1 = 29;
const int BASE2 = 37;

void solve(){
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();

    vector<int> pow1(m + 1), pow2(m + 1);
    pow1[0] = 1, pow2[0] = 1;
    for (int i = 1; i <= m; i++){
        pow1[i] = (pow1[i - 1] * BASE1) % MOD1;
        pow2[i] = (pow2[i - 1] * BASE2) % MOD2;
    }
    vector<int> hashes1(n + 1), hashes2(n + 1);
    for (int i = 1; i <= n; i++){
        hashes1[i] = (hashes1[i - 1] * BASE1) % MOD1;
        hashes2[i] = (hashes2[i - 1] * BASE2) % MOD2;
        hashes1[i] = (hashes1[i] + (s[i - 1] - 'a' + 1)) % MOD1;
        hashes2[i] = (hashes2[i] + (s[i - 1] - 'a' + 1)) % MOD2;
    }

    int ans = 0;
    pii target;
    {
        int hash1 = 0, hash2 = 0;
        for (int i = 0; i < m; i++){
            hash1 = (hash1 * BASE1 + (t[i] - 'a' + 1)) % MOD1;
            hash2 = (hash2 * BASE2 + (t[i] - 'a' + 1)) % MOD2;
        }
        target = {hash1, hash2};
    }
    {
        for (int i = m; i <= n; i++){
            int hash1 = ((hashes1[i] - hashes1[i - m] * pow1[m]) % MOD1 + MOD1) % MOD1;
            int hash2 = ((hashes2[i] - hashes2[i - m] * pow2[m]) % MOD2 + MOD2) % MOD2;
            if (target == make_pair(hash1, hash2)){
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}