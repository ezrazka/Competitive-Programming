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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    string x; cin >> x;
    string s(n, '0');

    int mn = min_element(a.begin(), a.end()) - a.begin();
    int mx = max_element(a.begin(), a.end()) - a.begin();

    vector<int> vans;
    for ()
    
    /*
    find index with max num
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