#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pii> operations;
    for (int i = 0; i < n; i++){
        operations.push_back({a[i], 0});
        operations.push_back({a[i] + 1, 1});
        operations.push_back({b[i], 0});
        operations.push_back({b[i] + 1, 2});
    }
    sort(operations.begin(), operations.end());

    int ans = n;
    int cur_sales = n, cur_bad = 0;
    int ptr = 0;
    while (ptr < 4 * n){
        while (ptr < 4 * n - 1 && operations[ptr].fi == operations[ptr + 1].fi){
            if (operations[ptr].se == 1){
                cur_bad++;
            } else if (operations[ptr].se == 2){
                cur_sales--;
                cur_bad--;
            }
            ptr++;
        }
        if (operations[ptr].se == 1){
            cur_bad++;
        } else if (operations[ptr].se == 2){
            cur_sales--;
            cur_bad--;
        }
        ptr++;
        int price = operations[ptr - 1].fi;
        if (cur_bad <= k){
            ans = max(ans, price * cur_sales);
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}