#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> found(k);
    int cnt_k = 0;
    for (int i = 0; i < n; i++){
        if (v[i] < k) found[v[i]] = 1;
        else if (v[i] == k) cnt_k++;
    }
    cout << max(cnt_k, k - accumulate(found.begin(), found.end(), 0ll)) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}