#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    int mx = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    vector<int> cycle_sizes;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            int size = 0;
            int cur = i;
            while (!vis[cur]){
                vis[cur] = true;
                cur = v[cur] - 1;
                size++;
            }
            cycle_sizes.push_back(size);
        }
    }

    vector<bool> is_prime(mx + 1, true);
    vector<int> primes;
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= mx; i++){
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= mx; j += i){
            is_prime[j] = false;
        }
    }
    for (int i = 2; i <= mx; i++){
        if (is_prime[i]){
            primes.push_back(i);
        }
    }

    vector<int> freq(mx + 1);
    for (int size : cycle_sizes){
        for (int prime : primes){
            if (prime > size) break;
            int cnt = 0;
            while (size % prime == 0){
                cnt++;
                size /= prime;
            }
            freq[prime] = max(freq[prime], cnt);
        }
    }

    int ans = 1;
    for (int i = 2; i <= n; i++){
        for (int _ = 0; _ < freq[i]; _++){
            ans = (ans * i) % MOD;
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