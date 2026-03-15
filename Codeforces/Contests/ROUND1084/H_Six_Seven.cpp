#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    auto rec = [&](auto self, vector<int> a) -> int {
        if (a.empty()) return 0;

        int gcd = 0;
        for (int i = 0; i < a.size() - 1; i++){
            gcd = __gcd(gcd, abs(a[i] - a[i + 1]));
        }
        if (gcd % 6 != 0) return INF;

        int mn = INF;
        for (int x = 0; x < 42; x += 6){
            int k = ((6 - a[0]) % 6 + 6) % 6 + x;
            vector<int> b;
            for (int i = 0; i < a.size(); i++){
                if ((a[i] + k) % 42 == 0){
                    b.push_back((a[i] + k) / 42);
                }
            }
            if (a != b){
                int res = self(self, b);
                if (res != INF) mn = min(mn, k + 42 * res);
            }
        }
        return mn;
    };
    int ans = rec(rec, a);
    cout << (ans == INF ? -1 : ans) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}