#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

vector<int> spf(1e5 + 1);

void init(){
    iota(spf.begin(), spf.end(), 0);
    spf[0] = -1, spf[1] = -1;
    for (int i = 2; i * i <= 1e5; i++){
        if (spf[i] == i){
            for (int j = i * i; j <= 1e5; j += i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int m = __lg(n);
    vector<vector<int>> next(n + 1, vector<int>(m + 1, n + 1));
    {
        map<int, int> mp;
        for (int i = n; i >= 1; i--){
            int temp = a[i];
            while (temp > 1){
                int prime = spf[temp];
                if (mp.find(prime) != mp.end()){
                    next[i][0] = min(next[i][0], mp[prime]);
                }
                mp[prime] = i;
                while (temp % prime == 0){
                    temp /= prime;
                }
            }
        }
        for (int i = n - 1; i >= 1; i--){
            next[i][0] = min(next[i][0], next[i + 1][0]);
        }
    }
    for (int bit = 1; bit <= m; bit++){
        for (int i = 1; i <= n; i++){
            if (next[i][bit - 1] <= n){
                next[i][bit] = next[next[i][bit - 1]][bit - 1];
            }
        }
    }

    while (q--){
        int l, r; cin >> l >> r;

        int ans = 0;
        int cur = l;
        for (int bit = m; bit >= 0; bit--){
            if (next[cur][bit] <= r){
                cur = next[cur][bit];
                ans += 1 << bit;
            }
        }
        cout << ans + 1 << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    init();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}