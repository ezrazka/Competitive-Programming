#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> b(m, vector<int>(n));
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            cin >> b[j][i];
        }
    }
    vector<int> order(n * m + 1);
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            order[b[j][i]] = i;
        }
    }
    sort(a.begin(), a.end(), [&](const vector<int> &x, const vector<int> &y){
        return order[x[0]] < order[y[0]];
    });
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << " \n"[j == m - 1];
        }
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