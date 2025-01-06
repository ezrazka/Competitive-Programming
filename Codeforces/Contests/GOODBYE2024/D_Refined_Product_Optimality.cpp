#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

int binpow(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int inv(int a){
    return binpow(a, MOD - 2);
}

template<class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ordered_set<int> sa, sb;
    for (int i = 0; i < n; i++){
        sa.insert(a[i]);
        sb.insert(b[i]);
    }

    int ans = 1;
    for (int i = 0; i < n; i++){
        ans = (ans * min(*sa.find_by_order(i), *sb.find_by_order(i))) % MOD;
    }

    cout << ans << ' ';
    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int idx; cin >> idx; idx--;
            int old_idx = sa.order_of_key(a[idx] + 1) - 1;
            ans = (ans * inv(min(*sa.find_by_order(old_idx), *sb.find_by_order(old_idx)))) % MOD;
            int x = min(*sa.find_by_order(old_idx), *sb.find_by_order(old_idx));
            sa.erase(sa.upper_bound(a[idx]));
            a[idx]++;
            sa.insert(a[idx]);
            int new_idx = sa.order_of_key(*sa.upper_bound(a[idx]));
            ans = (ans * min(*sa.find_by_order(new_idx), *sb.find_by_order(new_idx))) % MOD;
            int y = min(*sa.find_by_order(new_idx), *sb.find_by_order(new_idx));
        } else {
            int idx; cin >> idx; idx--;
            int old_idx = sb.order_of_key(b[idx] + 1) - 1;
            ans = (ans * inv(min(*sa.find_by_order(old_idx), *sb.find_by_order(old_idx)))) % MOD;
            int x = min(*sa.find_by_order(old_idx), *sb.find_by_order(old_idx));
            sb.erase(sb.upper_bound(b[idx]));
            b[idx]++;
            sb.insert(b[idx]);
            int new_idx = sb.order_of_key(*sb.upper_bound(b[idx]));
            ans = (ans * min(*sa.find_by_order(new_idx), *sb.find_by_order(new_idx))) % MOD;
            int y = min(*sa.find_by_order(new_idx), *sb.find_by_order(new_idx));
        }
        cout << ans << " \n"[q == 0];
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