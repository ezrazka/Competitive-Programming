#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>> a(n + 1);
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        a[y].push_back(x);
    }

    multiset<int> ms;
    vector<int> pref(n + 1);
    int sum = 0, best = 0;
    for (int min_y = n; min_y >= 0; min_y--){
        for (int x : a[min_y]){
            ms.insert(x);
            sum += x;
        }
        while (ms.size() > min_y + 1){
            sum -= *ms.begin();
            ms.erase(ms.begin());
        }
        best = max(best, sum);
        pref[min_y] = (ms.size() == min_y + 1 ? sum - *ms.begin() : sum);
    }

    for (int i = 2; i <= n; i++){
        pref[i] = max(pref[i], pref[i - 1]);
    }

    while (q--){
        int x, y; cin >> x >> y;
        cout << max(best, pref[y] + x) << " \n"[q == 0];
    }
    /*
    reactivity Y -> allows at most Y other particles
    the number of particles <= minY + 1

    brute force: check all possible number of particles and in each check greedily choose largest energy

    for each of m find minimum of:
    (1) answer if dont take
    (2) answer if take (choose k other particles with a Y >= its Y)

    (1) can be precomputed by sequentially adding possible particles and using a multiset
    (2) offline queries check during calculation of (1)

    missed observation:
    each query contributes to all Y <= its Y
    every min_y should keep its max value with 1 less maximum amount of particles
    then the queries just prefix max
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