#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, kk, ll; cin >> n >> kk >> ll;
    vector<vector<int>> v(2, vector<int>(n));
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    vector<vector<int>> contribution(2, vector<int>(n));
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < 2; k++){
                for (int l = 0; l < n; l++){
                    if (i != k || j != l){
                        contribution[k][l] += (abs(i - k) + abs(j - l)) * (kk - v[i][j]);
                    }
                }
            }
        }
    }

    pii mx = {-1, -1};
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            if (mx.fi == -1 || contribution[i][j] < contribution[mx.fi][mx.se]) {
                mx = {i, j};
            }
        }
    }
    cout << mx.fi + 1 << ' ' << mx.se + 1 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}