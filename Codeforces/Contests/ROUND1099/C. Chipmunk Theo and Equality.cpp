#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return x + FIXED_RANDOM;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    gp_hash_table<int, int, custom_hash> cnt, sum;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) continue;
        cnt[a[i]]++;
    }

    gp_hash_table<int, bool, custom_hash> vis;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        if (vis[a[i]]) continue;
        vis[a[i]] = true;
        pq.push(a[i] & 1 ? a[i] + 2 : a[i]);
    }
    while (!pq.empty()) {
        int k = pq.top(); pq.pop();
        if (k & 1) k -= 2;
        if (k == 1) continue;
        if (k & 1) {
            cnt[k + 1] += cnt[k];
            sum[k + 1] += sum[k] + cnt[k];
            if (!vis[k + 1]) {
                vis[k + 1] = true;
                pq.push(k + 1);
            }
        } else {
            cnt[k / 2] += cnt[k];
            sum[k / 2] += sum[k] + cnt[k];
            if (!vis[k / 2]) {
                vis[k / 2] = true;
                pq.push((k / 2) & 1 ? (k / 2) + 2 : (k / 2));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            cnt[1]++, sum[1] += 0;
            cnt[2]++, sum[2] += 1;
        }
    }

    int ans = LLONG_MAX;
    for (auto [key, val] : cnt) {
        if (val == n) ans = min(ans, sum[key]);
    }
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
