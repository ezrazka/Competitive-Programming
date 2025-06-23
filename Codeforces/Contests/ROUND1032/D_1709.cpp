#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n); for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int, int>> ops;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1; j++){
            if (a[j] > a[j + 1]){
                ops.emplace_back(1, j + 1);
                swap(a[j], a[j + 1]);
            }
        }
    }
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1; j++){
            if (b[j] > b[j + 1]){
                ops.emplace_back(2, j + 1);
                swap(b[j], b[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (a[i] > b[i]){
            ops.emplace_back(3, i + 1);
            swap(a[i], b[i]);
        }
    }

    cout << ops.size() << '\n';
    for (int i = 0; i < ops.size(); i++){
        cout << ops[i].fi << ' ' << ops[i].se << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}