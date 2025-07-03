#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int f(int x, int y){
    return (x % y) + (y % x);
}

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> vans(n);
    int mx = v[0];
    for (int i = 1; i < n; i++){
        if (v[i] <= mx){
            vans[i] = max(vans[i - 1], f(v[i], mx));
        } else if (v[i] < 2 * mx){
            vans[i] = v[i];
        } else {
            for (int j = 0; j < i; j++){
                vans[i] = max(vans[i], f(v[i], v[j]));
            }
        }
        mx = max(mx, v[i]);
    }

    for (int i = 0; i < n; i++){
        cout << vans[i] << " \n"[i == n - 1];
    }

    /*
    1. How does it work?
        * iterate one by one,
        * if v[i] <= max(v[:i]): update with f(v[i], max(v[:1]))
        * else if v[i] > 2 * max(v[:i]): for j < i, update with f(v[i], v[j])
        * else: update with v[i]
    2. How could I have come up with it myself?
        * Notice that answer always involves max(v)
        * Notice that if v[i] is more than half of and less than max(v), ans is max(v)
        * Having to manually check all previous pair-completers only happens when v[i] > max(v[:i]),
          therefore is done at most log2(A) times
    3. What can I do to make sure I can come up with it next time it appears?
        * Try to discover and prove lemmas as stepping stones for solving hard problems
        * Consider amortized analysis
        * Remember 1e6 can still have log time complexity
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}