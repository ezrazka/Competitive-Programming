#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"
 
void solve(){
    int n; cin >> n;
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    stable_sort(v.begin(), v.end(), [&](int i, int j){
        cout << "? " << i + 1 << ' ' << j + 1 << endl;
        string s; cin >> s;
        return s == "YES";
    });
 
    vector<int> vans(n, 1);
    cout << "! ";
    for (int i = 0; i < n; i++){
        vans[v[i]] = i + 1;
    }
    for (int i = 0; i < n; i++){
        cout << vans[i] << ' ';
    }
    cout << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}