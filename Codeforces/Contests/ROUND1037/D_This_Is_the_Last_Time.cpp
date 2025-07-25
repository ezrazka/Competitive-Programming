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
    vector<int> l(n), r(n), real(n);
    for (int i = 0; i < n; i++){
        cin >> l[i] >> r[i] >> real[i];
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return l[i] < l[j];
    });

    set<int> reachable = {k};
    for (int i = 0; i < n; i++){
        if (reachable.lower_bound(l[ord[i]]) != reachable.end() && *reachable.lower_bound(l[ord[i]]) <= r[ord[i]]){
            reachable.insert(real[ord[i]]);
        }
    }
    cout << *reachable.rbegin() << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}