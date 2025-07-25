#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

vector<vector<int>> vans = {{}, {1}, {1, 2}, {1, 2, 2}, {1, 2, 2, 3}, {1, 2, 2, 3, 3}};
vector<int> vans_cnt = {0, 1, 2, 2, 3, 3, 4};

void solve(){
    int n; cin >> n;

    if (n < vans.size()){
        cout << vans_cnt[n] << '\n';
        for (int i = 0; i < n; i++){
            cout << vans[n][i] << " \n"[i == n - 1];
        }
        return;
    }

    cout << 4 << '\n';
    for (int i = 1; i <= n; i++){
        cout << (i - 1) % 4 + 1 << " \n"[i == n];
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