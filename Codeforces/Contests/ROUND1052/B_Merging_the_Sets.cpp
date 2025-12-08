#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n);
    map<int, int> total_freq;
    vector<map<int, int>> freq(n);
    for (int i = 0; i < n; i++){
        int len; cin >> len;
        while (len--){
            int x; cin >> x;
            v[i].push_back(x);
            total_freq[x]++;
            freq[i][x]++;
        }
    }

    int ways = 0;
    bool ok = true;
    {
        for (int i = 1; i <= m; i++){
            if (!total_freq[i]) ok = false;
        }
    }
    if (ok) ways++;
    {
        for (int i = 0; i < n; i++){
            bool ok = true;
            for (auto [key, val] : freq[i]){
                if (!(total_freq[key] - val)) ok = false;
            }
            if (ok) ways++;
        }
    }
    cout << (ok && ways >= 3 ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}