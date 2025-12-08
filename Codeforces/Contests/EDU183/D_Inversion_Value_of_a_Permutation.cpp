#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

bool inv(int* a, int *b){
    int mx = 0;
    for (int* i = a; i < b; i++){
        if (mx > *i) return true;
        mx = max(mx, *i);
    }
    return false;
}

void solve(){
    int n, k; cin >> n >> k;

    vector<bool> possible(n * (n - 1) / 2 + 1);
    vector<bool> possible2(n * (n - 1) / 2 + 1);
    {
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        do {
            int invs = 0;
            for (int l = 0; l < n; l++){
                for (int r = l; r < n; r++){
                    invs += inv(&p[0] + l, &p[0] + r + 1);
                }
            }
            possible[invs] = true;
        } while (next_permutation(p.begin(), p.end()));
    }
    // vector<pair<int, int>> possible(n * (n - 1) / 2 + 1, {-1, -1});
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            swap(p[i], p[j]);
            int invs = 0;
            for (int l = 0; l < n; l++){
                for (int r = l; r < n; r++){
                    invs += inv(&p[0] + l, &p[0] + r + 1);
                }
            }
            possible2[invs] = true;
            swap(p[i], p[j]);
        }
    }

    for (int i = 0; i <= n * (n - 1) / 2; i++){
        if (possible[i] != possible2[i]){
            cout << i << '\n';
            cout << possible[i] << ' ' << possible2[i] << '\n';
        }
    }
    /*
    * No test case limits: You might have to precompute values
    * Please don't forget about finding the complement
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