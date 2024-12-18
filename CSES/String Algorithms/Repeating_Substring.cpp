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
const int BASE1 = 31;
const int BASE2 = 37;

void solve(){
    string s; cin >> s;
    int n = s.length();
    
    vector<int> p1(n + 1), p2(n + 1);
    p1[0] = 1, p2[0] = 1;
    for (int i = 1; i <= n; i++){
        p1[i] = (p1[i - 1] * BASE1) % MOD1;
        p2[i] = (p2[i - 1] * BASE2) % MOD2;
    }

    vector<int> h1(n + 1), h2(n + 1);
    for (int i = 1; i <= n; i++){
        h1[i] = (h1[i - 1] * BASE1 + (s[i - 1] - 'a' + 1)) % MOD1;
        h2[i] = (h2[i - 1] * BASE2 + (s[i - 1] - 'a' + 1)) % MOD2;
    }

    auto get_hash = [&](int l, int r) -> pii {
        int hash1 = ((h1[r + 1] - h1[l] * p1[r - l + 1]) % MOD1 + MOD1) % MOD1;
        int hash2 = ((h2[r + 1] - h2[l] * p2[r - l + 1]) % MOD2 + MOD2) % MOD2;
        return {hash1, hash2};
    };

    pii ans = {-1, -1};
    map<pii, int> mp;
    int l = 1, r = n;
    while (l <= r){
        int mid = (l + r) / 2;

        int idx = -1;
        for (int i = 0; i < n - mid + 1; i++){
            if (++mp[get_hash(i, i + mid - 1)] > 1){
                idx = i;
                break;
            }
        }

        if (idx != -1){
            ans = {idx, mid};
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        mp.clear();
    }

    if (ans.fi == -1){
        cout << "-1\n";
    } else {
        cout << s.substr(ans.fi, ans.se) << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}