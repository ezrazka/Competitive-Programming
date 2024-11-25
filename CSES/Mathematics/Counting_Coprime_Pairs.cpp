#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"
 
vector<int> spf(1e6 + 1);
 
void init(){
    iota(spf.begin(), spf.end(), 0);
    spf[0] = -1;
    spf[1] = -1;
    for (int i = 2; i * i <= 1e6; i++){
        if (spf[i] == i){
            for (int j = i * i; j <= 1e6; j += i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}
 
vector<int> get_prime_factors(int n){
    set<int> st;
    while (n != 1){
        st.insert(spf[n]);
        n /= spf[n];
    }
    vector<int> res;
    for (int num : st){
        res.push_back(num);
    }
    return res;
}
 
vector<int> get_factors(int n){
    vector<int> res;
    for (int i = 1; i * i <= n; i++){
        if (i * i == n){
            res.push_back(i);
        } else if (n % i == 0){
            res.push_back(i);
            res.push_back(n / i);
        }
    }
    return res;
}
 
void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++){
        mp[v[i]]++;
    }
 
    vector<int> factor_count(1e6 + 1);
    for (auto [num, freq] : mp){
        vector<int> factors = get_factors(num);
        for (int factor : factors){
            factor_count[factor] += freq;
        }
    }
 
    int ans = 0;
    auto rec = [&](auto self, vector<int>& prime_factors, int idx, int cnt, int val) -> void {
        if (idx == prime_factors.size()){
            if (cnt & 1){
                ans -= factor_count[val];
            } else {
                ans += factor_count[val];
            }
            return;
        }
        self(self, prime_factors, idx + 1, cnt, val);
        self(self, prime_factors, idx + 1, cnt + 1, val * prime_factors[idx]);
    };
 
    for (int i = 0; i < n; i++){
        if (v[i] == 1){
            ans += n - 1;
            continue;
        }
        vector<int> prime_factors = get_prime_factors(v[i]);
        rec(rec, prime_factors, 0, 0, 1);
    }
    ans = ans / 2;
    cout << ans << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}