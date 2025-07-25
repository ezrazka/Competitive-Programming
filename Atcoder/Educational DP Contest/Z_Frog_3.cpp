#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

struct line {
    int m, b;
    line(int m, int b) : m(m), b(b) {}
    int eval(int x){ return m * x + b; };
};

void solve(){
    int n, c; cin >> n >> c;
    vector<int> h(n);
    for (int i = 0; i < n; i++){
        cin >> h[i];
    }


    deque<line> hull;
    auto is_obsolete = [&](line a, line b, line c){
        // returns whether x[a,c] <= x[a,b]
        // x[a,c] = (b[c] - b[a]) / (m[a] - m[c])
        // x[a,b] = (b[b] - b[a]) / (m[a] - m[b])
        return (c.b - a.b) * (a.m - b.m) <= (b.b - a.b) * (a.m - c.m);
    };

    vector<int> dp(n);
    dp[0] = 0;
    hull.push_back(line(-2 * h[0], dp[0] + h[0] * h[0]));
    for (int i = 1; i < n; i++){
        while (hull.size() >= 2 && hull[0].eval(h[i]) >= hull[1].eval(h[i])){
            hull.pop_front();
        }

        dp[i] = h[i] * h[i] + c + (hull.front().eval(h[i]));

        line next_line = line(-2 * h[i], dp[i] + h[i] * h[i]);
        while (hull.size() >= 2 && is_obsolete(hull[hull.size() - 2], hull[hull.size() - 1], next_line)){
            hull.pop_back();
        }
        hull.push_back(next_line);
    }
    cout << dp[n - 1] << '\n';
    /*
    (hj - hi)^2 + c = hi^2 + hj^2 - 2 * hi * hj + c
    mx + b
    m = -2 * hj
    x = hi
    b = dp[j] + hj^2
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