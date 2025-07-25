#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int block_size = min(400ll, (int) sqrt(q));
    vector<vector<vector<int>>> pref(block_size + 1);
    vector<vector<vector<int>>> triangles(block_size + 1);
    for (int d = 1; d <= block_size; d++){
        vector<vector<int>> values(d);
        for (int start = 0; start < d; start++){
            for (int idx = start; idx < n; idx += d){
                values[start].push_back(v[idx]);
            }
        }
        
        pref[d].resize(d);
        for (int start = 0; start < d; start++){
            pref[d][start].push_back(0);
            for (int value : values[start]){
                pref[d][start].push_back(pref[d][start].back() + value);
            }
        }
        
        triangles[d].resize(d);
        for (int start = 0; start < d; start++){
            triangles[d][start].push_back(0);
            int i = 1;
            for (int value : values[start]){
                triangles[d][start].push_back(triangles[d][start].back() + value * (i++));
            }
        }
    }

    while (q--){
        int a, d, n; cin >> a >> d >> n; a--;
        if (d > block_size){
            int ans = 0;
            for (int idx = a, i = 1; idx <= a + (n - 1) * d; idx += d){
                ans += v[idx] * (i++);
            }
            cout << ans << " \n"[q == 0];
        } else {
            int ans = triangles[d][a % d][a / d + n] - triangles[d][a % d][a / d] - (pref[d][a % d][a / d + n] - pref[d][a % d][a / d]) * (a / d);
            cout << ans << " \n"[q == 0];
        }
        // if d <= sqrt(n), use precomputed values
        // if d > sqrt(n), get manually
        // O(n * d + q * (n / d))
        // minimized when d = sqrt(q)
        // but memory is limited xd so i limit it at 400
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}