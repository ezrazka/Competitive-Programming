#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

template<class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int MOD = 998244353;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD - 2);
}

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int inversions = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) inversions++;
        }
    }

    int ans = 0;
    ordered_set<int> st;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            ans += st.order_of_key(a[i] * b[j]);
        }
        for (int j = 0; j < n; j++) {
            st.insert(a[i] * b[j]);
        }
    }
    ans -= n * inversions;
    ans %= MOD; ans *= inv(n * (n - 1) % MOD); ans %= MOD;
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
