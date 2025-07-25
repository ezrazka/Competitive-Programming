#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int m; cin >> m;
    vector<int> n(m), l(m), r(m);
    vector<vector<int>> a(m), c(m);
    for (int i = 0; i < m; i++){
        cin >> n[i] >> l[i] >> r[i];
        for (int j = 0; j < n[i]; j++){
            int x; cin >> x;
            a[i].push_back(x);
        }
        for (int j = 0; j < n[i]; j++){
            int x; cin >> x;
            c[i].push_back(x);
        }
    }

    int sum_n = accumulate(n.begin(), n.end(), 0ll);
    int range = 1;
    for (int i = 0; i < m; i++){
        range += r[i] - l[i];
        if (range > sum_n){
            cout << 0 << '\n';
            return;
        }
    }

    int sum_l = 0, sum_r = 0;
    for (int i = 0; i < m; i++){
        sum_l += l[i];
        sum_r += r[i];
        if (sum_l > 1e17){
            cout << 0 << '\n';
            return;
        }
    }
    
    int total_freq = 0;
    map<int, int> freq, untaken;
    for (int i = 0; i < m; i++){
        int cur_total_freq = 0;
        for (int j = 0; j < n[i]; j++){
            cur_total_freq = min((int) 1e18, cur_total_freq + c[i][j]);
        }
        for (int j = 0; j < n[i]; j++){
            total_freq += c[i][j]; // overflow
            freq[a[i][j]] += c[i][j]; // overflow
            untaken[a[i][j]] = min((int) 1e18, untaken[a[i][j]] + max(0ll, l[i] - (cur_total_freq - c[i][j])));
        }
    }
    
    int ans = 1e18;
    for (int num = sum_l; num <= sum_r; num++){
        ans = min(ans, max({0ll, num - (total_freq - freq[num]), untaken[num]}));
    }
    cout << ans << '\n';

    // map<int, int> non_freq, untaken;
    // for (int i = 0; i < m; i++){
    //     int cur_total_freq = 0;
    //     for (int j = 0; j < n[i]; j++){
    //         if (cur_total_freq < 1e18){
    //             cur_total_freq += c[i][j];
    //         }
    //     }
    //     for (int j = 0; j < n[i]; j++){
    //         if (non_freq[a[i][j]] < 1e18){
    //             non_freq[a[i][j]] += cur_total_freq - c[i][j];
    //         }
    //         if (untaken[a[i][j]] < 1e18){
    //             untaken[a[i][j]] += max(0ll, l[i] - (cur_total_freq - c[i][j]));
    //         }
    //     }
    // }
    
    // int ans = 1e17; // another bug: check for numbers not in [sum(l), sum(r)] range
    // for (int i = 0; i < m; i++){
    //     for (int j = 0; j < n[i]; j++){
    //         ans = min(ans, max({0ll, a[i][j] - non_freq[a[i][j]], untaken[a[i][j]]}));
    //     }
    // }
    // cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}