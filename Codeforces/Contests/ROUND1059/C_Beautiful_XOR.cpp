#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int a, b; cin >> a >> b;

    if (__lg(b) > __lg(a)){
        cout << -1 << '\n';
        return;
    }

    vector<int> vans;
    for (int i = __lg(a); i >= 0; i--){
        if ((a ^ b) & (1 << i) && (b & (1 << i))){
            vans.push_back(1 << i);
        }
    }
    for (int i = __lg(a); i >= 0; i--){
        if ((a ^ b) & (1 << i) && (a & (1 << i))){
            vans.push_back(1 << i);
        }
    }

    cout << vans.size() << '\n';
    for (int i = 0; i < vans.size(); i++){
        cout << vans[i] << " \n"[i == vans.size() - 1];
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}