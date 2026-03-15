#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    vector<int> x(n), y(n), z(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i], k -= y[i];
    sort(a.begin(), a.end());

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return x[i] < x[j];
    });

    int ans = 0;
    multiset<int> diffs;
    int j = 0;
    for (int i = 0; i < m; i++){
        while (j < n && a[i] >= x[ord[j]]){
            diffs.insert(z[ord[j]] - y[ord[j]]);
            j++;
        }
        if (!diffs.empty()){
            diffs.erase(prev(diffs.end()));
            ans++;
        }
    }
    while (j < n){
        diffs.insert(z[ord[j]] - y[ord[j]]);
        j++;
    }
    
    while (!diffs.empty() && *diffs.begin() <= k){
        k -= *diffs.begin();
        diffs.erase(diffs.begin());
        ans++;
    }
    cout << ans << '\n';

    /*
    for each person, either pay z, or pay y and pay a box with a[j] >= x[i]
    if we know a person wont be happy, we just pay y

    initially, assume all just pay y
    then we pay z - y or we pay a box
    sort by z - y
    greedily, each box should buy out the most expensive person it can
    after that, buy out the rest using z - y
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