#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

template<typename T>
struct segment_tree {
    int n;
    vector<T> tree;

    segment_tree(int n){
        this->n = n;
        tree.assign(4 * n, 1e18);
    }

    void update(int pos, int low, int high, int idx, T val){
        if (low == high){
            tree[pos] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (idx <= mid){
            update(2 * pos + 1, low, mid, idx, val);
        } else {
            update(2 * pos + 2, mid + 1, high, idx, val);
        }
        tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    T query(int pos, int low, int high, int q_low, int q_high){
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }
        if (high < q_low || q_high < low){
            return 1e18;
        }

        int mid = (low + high) / 2;
        return min(query(2 * pos + 1, low, mid, q_low, q_high), query(2 * pos + 2, mid + 1, high, q_low, q_high));
    }
};

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + v[i - 1];
    }

    int l = 1, r = 1e14, res = -1;
    while (l <= r){
        int mid = (l + r) / 2;

        segment_tree<int> dp(n + 1);
        dp.update(0, 0, n, 0, 0);

        for (int i = 1; i <= n; i++){
            int pos = lower_bound(pref.begin(), pref.end(), pref[i - 1] - mid) - pref.begin();
            dp.update(0, 0, n, i, dp.query(0, 0, n, pos, i - 1) + v[i - 1]);
        }

        int best = 1e18;
        for (int i = 0; i <= n; i++){
            if (pref[n] - pref[i] <= mid){
                best = min(best, dp.query(0, 0, n, i, i));
            }
        }

        if (best > mid){
            l = mid + 1;
        } else {
            res = mid;
            r = mid - 1;
        }
    }
    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}