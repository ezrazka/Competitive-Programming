#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n - 1), b(n);
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int k = 0;
    int last_unmatched = n - 1;
    for (int i = 0, j = 0; i < n - 1 && j < n; i++, j++){
        while (j < n && a[i] >= b[j]){
            last_unmatched = j;
            j++;
        }
        if (j < n){
            k++;
        }
    }

    int ans = (n - k) * m;
    ans -= min(m, b[last_unmatched] - 1);
    cout << ans << '\n';
    /*
    if in an optimal matching, where a (not including m) and b is sorted,
    if m is paired with b[i], and there exists an unpaired b[j], where i <= j,
    then m contributes 1 to the optimal k
    THEREFORE
    for all m < b[last_unmatched], m contributes 1
    otherwise, m contributes 0
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