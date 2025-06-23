#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;

    if (m < n || m > n * (n + 1) / 2){
        cout << "-1\n";
        return;
    }

    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    reverse(v.begin(), v.end());

    int temp = n * (n + 1) / 2 - m;
    for (int i = n - 1; i >= 0; i--){
        int removed = min(n - i - 1, temp);
        v[i] -= removed;
        temp -= removed;
    }

    vector<bool> added(n + 1);
    cout << v[0] << '\n';
    added[v[0]] = true;
    for (int i = 0; i < n - 1; i++){
        if (v[i] == 1 && v[i + 1] == 1) break;
        cout << v[i] << ' ' << v[i + 1] << '\n';
        added[v[i + 1]] = true;
    }

    for (int i = 1; i <= n; i++){
        if (!added[i]){
            cout << 1 << ' ' << i << '\n';
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