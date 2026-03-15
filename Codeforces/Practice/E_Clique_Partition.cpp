#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    for (int i = 0; i < n; i += k){
        int sz = min(k, n - i);
        reverse(p.begin() + i, p.begin() + i + (sz - 1) / 2);
        reverse(p.begin() + i + (sz - 1) / 2, p.begin() + i + sz);
    }

    for (int i = 0; i < n; i++){
        cout << p[i] << " \n"[i == n - 1];
    }
    cout << (n + k - 1) / k << '\n';
    for (int i = 0; i < n; i++){
        cout << i / k + 1 << " \n"[i == n - 1];
    }

    // int n = 8;
    // vector<int> p(n);
    // iota(p.begin(), p.end(), 1);
    // do {
    //     int mx = 0;
    //     for (int i = 0; i < n; i++){
    //         for (int j = i + 1; j < n; j++){
    //             mx = max(mx, abs(i - j) + abs(p[i] - p[j]));
    //         }
    //     }
    //     if (mx == 8){
    //         for (int i = 0; i < n; i++){
    //             cout << p[i] << " \n"[i == n - 1];
    //         }
    //     }
    // } while (next_permutation(p.begin(), p.end()));
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}