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

    vector<int> pow1(n + 1), pow2(n + 1);
    pow1[0] = 1, pow2[0] = 1;
    for (int i = 1; i <= n; i++){
        pow1[i] = (pow1[i - 1] * BASE1) % MOD1;
        pow2[i] = (pow2[i - 1] * BASE2) % MOD2;
    }
    vector<int> pref1(n + 1), pref2(n + 1);
    for (int i = 1; i <= n; i++){
        pref1[i] = (pref1[i - 1] * BASE1 + (s[i - 1] - 'a' + 1)) % MOD1;
        pref2[i] = (pref2[i - 1] * BASE2 + (s[i - i] - 'a' + 1)) % MOD2;
    }

    for (int i = n - 1; i >= 0; i--){
        pii prefix = {pref1[i], pref2[i]};
        pii suffix = {((pref1[n] - pref1[n - i] * pow1[i]) % MOD1 + MOD1) % MOD1, ((pref2[n] - pref2[n - i] * pow2[i]) % MOD2 + MOD2) % MOD2};
        if (prefix == suffix){
            cout << n - i << ' ';
        }
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}