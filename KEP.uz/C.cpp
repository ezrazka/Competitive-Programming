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

    string s = to_string(n);
    reverse(s.begin(), s.end());
    n = s.length();

    int p = 1;
    vector<int> vans;
    for (int i = 0; i < n; i++){
        if (s[i] != '0'){
            vans.push_back((s[i] - '0') * p);
        }
        p *= 10;
    }

    cout << vans.size() << '\n';
    for (int i = 0; i < vans.size(); i++){
        cout << vans[i] << " \n"[i == vans.size() - 1];
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}