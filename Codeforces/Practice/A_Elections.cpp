#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int calc(vector<int> &p, vector<int> &c, int m, int x){
    int n = p.size();

    int need = x;
    for (int i = 0; i < n; i++){
        if (p[i] == 1) need--;
    }

    vector<int> freq(m + 1);
    for (int i = 0; i < n; i++){
        if (p[i] == 1) continue;
        freq[p[i]]++;
    }

    vector<bool> vis(n);
    int cost = 0;
    for (int i = 0; i < n; i++){
        if (p[i] == 1) continue;
        if (freq[p[i]] >= x){
            freq[p[i]]--;
            cost += c[i];
            vis[i] = true;
            need--;
        }
    }

    if (need <= 0){
        return cost;
    }

    for (int i = 0; i < n; i++){
        if (p[i] == 1 || vis[i]) continue;
        cost += c[i];
        need--;
        if (need == 0){
            return cost;
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].fi >> v[i].se;
    }
    sort(v.begin(), v.end(), [&](const pair<int, int> &a, const pair<int, int> &b){
        return a.se < b.se;
    });

    vector<int> p(n), c(n);
    for (int i = 0; i < n; i++){
        p[i] = v[i].fi, c[i] = v[i].se;
    }

    if (m == 1){
        cout << 0 << '\n';
        return;
    }

    int ans = 1e18;
    for (int x = n / m + 1; x <= n; x++){
        ans = min(ans, calc(p, c, m, x));
    }
    cout << ans << '\n';

    /*
    let x be the number votes we will have to win the election
    if we fix x, we can solve the problem in 2 steps:
    1. buy out all parties with votes >= x
    2. buy out the cheapest voters

    we can find x with ternary seach with n log_{2}n
    O(n * log_{2}n * log_{3/2}n)
    or we can use binary search with n log_{2}n
    O(n * log^{2}_{2}n)
    or we can use 2 fenwick trees iterating over x from n to n / m + 1
    O(n log_{2} n)
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