#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

struct unit {
    int c, d, h;

    int val() const {
        return d * h;
    }
};

struct boss {
    int d, h;

    int val() const {
        return d * h;
    }
};

void solve(){
    int n, c; cin >> n >> c;
    vector<unit> units(n);
    for (int i = 0; i < n; i++) cin >> units[i].c >> units[i].d >> units[i].h;

    int m; cin >> m;
    vector<boss> bosses(m);
    for (int j = 0; j < m; j++) cin >> bosses[j].d >> bosses[j].h;
    
    // only keep the largest d[i] * h[i] for a c[i]
    sort(units.begin(), units.end(), [&](unit &a, unit &b){
        return make_pair(a.c, a.val()) > make_pair(b.c, b.val());
    });
    units.erase(unique(units.begin(), units.end(), [&](unit &a, unit &b){
        return a.c == b.c;
    }), units.end());
    n = units.size();

    // harmonic series difference array (maximum) storing maximum d[i] * h[i] for fixed cost
    vector<int> pref(c + 1);
    for (const unit &u : units){
        for (int j = 1; j * u.c <= c; j++){
            pref[j * u.c] = max(pref[j * u.c], j * u.val());
        }
    }
    for (int i = 2; i <= c; i++){
        pref[i] = max(pref[i], pref[i - 1]);
    }

    // binary search smallest cost where pref[i] > D[i] * H[i]
    for (const boss &b : bosses){
        int idx = upper_bound(pref.begin(), pref.end(), b.val()) - pref.begin();
        cout << (idx == c + 1 ? -1 : idx) << ' ';
    }
    cout << '\n';

    /*
        we win if
        (k * d) / H > D / h

        Naive, O(n * m * C):
            for each monster:
                for each unit:
                    count how many units needed to fulfill condition
                    ans = min(ans, k) // if k <= C
        
        Optimized Naive, O(n * m):
            for each monster:
                for each unit:
                    // find smallest x, where x > (D * H) / (d * h)
                    int k = c[i] * ((D * H) / (d * h) + 1);
                    ans = min(ans, k) // if k <= C

        Optimized, O(n + m + C)?:
        * C is <= 1e12, suspicious
        * Sqrt Batching?
        Observations:
            * C never exceeds 1e6, meaning the number of units is always <= 1e6
            * In my formula, D * H and d * h can be treated as single variables
                minimize c[i] * (floor(b / a[i]) + 1)
            
    1. understand the problem
    2. simplify the problem
    3. visualize the problem

    If the problem looks like a cht problem, but floored,
    think of harmonic series
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