#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

map<pair<int, int>, int> memo;
ordered_set<int> extra;

int query(int l, int r){
    int extra_cnt = extra.order_of_key(r + 1);
    if (memo.find({l, r}) != memo.end()){
        return memo[{l, r}] + extra_cnt;
    }
    cout << "? " << l << ' ' << r << endl;
    int q; cin >> q;
    return (memo[{l, r}] = q - extra_cnt) + extra_cnt;
}

void answer(int i){
    cout << "! " << i << endl;
}

void solve(){
    int n, t; cin >> n >> t;
    while (t--){
        int k; cin >> k;
        int l = 1, r = n, res = -1;
        while (l <= r){
            int mid = (l + r) / 2;

            int zeros = mid - query(1, mid);

            if (zeros < k){
                l = mid + 1;
            } else {
                r = mid - 1;
                res = mid;
            }
        }
        answer(res);
        extra.insert(res);
    }
    /*
    1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + min(16384, 1e4)
    + min(32768, 1e4) + min(65536, 1e4) = 46383
    46383 <= 6e4

    just binary search and memoize queries
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}