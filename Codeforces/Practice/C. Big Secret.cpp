#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<vector<int>> a(60);
    for (int i = 0; i < n; i++){
        int v; cin >> v;
        a[__lg(v)].push_back(v);
    }

    vector<int> vans, nvans;
    for (int bit = 59; bit >= 0; bit--){
        {
            int y = 0;
            for (int v : vans) if (v & (1ll << bit)) y++;
            if (a[bit].size() > y + 1) return cout << "No\n", void();
        }

        int i = 0;
        for (int v : vans){
            if (i < a[bit].size() && (v & (1ll << bit))){
                nvans.push_back(a[bit][i]);
                i++;
            }
            nvans.push_back(v);
        }
        if (i < a[bit].size()){
            nvans.push_back(a[bit][i]);
        }
        
        swap(vans, nvans);
        nvans.clear();
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++){
        cout << vans[i] << " \n"[i == n - 1];
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
