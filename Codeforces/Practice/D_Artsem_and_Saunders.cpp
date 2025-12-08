#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> f[i];
    }
    vector<int> h = f;
    sort(h.begin() + 1, h.end());
    h.erase(unique(h.begin() + 1, h.end()), h.end());
    int m = h.size() - 1;

    vector<int> g(n + 1);
    for (int i = 1; i <= n; i++){
        g[i] = lower_bound(h.begin(), h.end(), f[i]) - h.begin();
    }

    for (int i = 1; i <= n; i++){
        if (h[g[i]] != f[i]){
            cout << "-1\n";
            return;
        }
    }
    for (int i = 1; i <= m; i++){
        if (g[h[i]] != i){
            cout << "-1\n";
            return;
        }
    }
    
    cout << m << '\n';
    for (int i = 1; i <= n; i++){
        cout << g[i] << " \n"[i == n];
    }
    for (int i = 1; i <= m; i++){
        cout << h[i] << " \n"[i == m];
    }

    /*
        g[h[i]] = i...(1)
        h[g[i]] = f[i]...(2)
        h[g[i]] = f[g[h[i]]]...(3)

        observation 1:
        * m must be at least the number of unique elements
            otherwise, g[i] can't correspond to a value in h[i], contradicting g[h[i]] = i
        * m cannot exceed the number of unique elements
            otherwise, 
        observation 2:
        * if a fix an h, there only exists exactly one corresponding g
        * so i must find an h such that for each i in [1, m],
            h[g[i]] = f[i]
        observation 3:
        * the permutation of h does not affect the correctness
            because h[g[i]] to f[i] regardless of which i is selected
            so a value will always correspond to the same other value regardless of the permutation
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