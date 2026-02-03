#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>> v(2, vector<int>(n));
    for (int i = 0; i < n; i++) cin >> v[0][i];
    for (int i = 0; i < n; i++) cin >> v[1][i];

    vector<vector<int>> suff(2, vector<int>(n));
    for (int i = 1; i >= 0; i--){
        for (int j = n - 1; j >= 0; j--){
            suff[i][j] = v[i][j];
            if (i + 1 < 2) suff[i][j] = max(suff[i][j], suff[i + 1][j]);
            if (j + 1 < n) suff[i][j] = max(suff[i][j], suff[i][j + 1]);
        }
    }

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + suff[0][i - 1];
    }

    while (q--){
        int l, r; cin >> l >> r;
        cout << pref[r] - pref[l - 1] << " \n"[q == 0];
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