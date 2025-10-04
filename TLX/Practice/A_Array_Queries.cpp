#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int B = 330;
const int N = 1e5;

int n;
vector<int> a;

int memo[N + 1][B + 1];
int calc(int p, int k){
    if (p > n) return 0;
    if (memo[p][k] != -1) return memo[p][k];
    return memo[p][k] = calc(p + a[p] + k, k) + 1;
}

void solve(){
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    memset(memo, -1, sizeof(memo));

    int q; cin >> q;
    while (q--){
        int p, k; cin >> p >> k;
        if (k <= B){
            cout << calc(p, k) << '\n';
        } else {
            int ans = 0;
            while (p <= n){
                p = p + a[p] + k;
                ans++;
            }
            cout << ans << '\n';
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}