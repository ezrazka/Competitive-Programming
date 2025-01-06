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
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    bool start = false, end = false;
    for (int i = 0; i < n; i++){
        if (v[i] != 0) start = true;
        if (start && v[i] == 0) end = true;
        if (end && v[i] != 0){
            cout << 2 << '\n';
            return;
        }
    }

    cout << start << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}