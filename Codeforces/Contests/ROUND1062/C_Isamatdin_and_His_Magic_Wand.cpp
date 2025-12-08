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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    bool ok = false;
    {
        bool even = false, odd = false;
        for (int i = 0; i < n; i++){
            even = even || v[i] % 2 == 0;
            odd = odd || v[i] % 2 == 1;
        }
        if (even && odd) ok = true;
    }

    if (ok){
        sort(v.begin(), v.end());
    }
    
    for (int i = 0; i < n; i++){
        cout << v[i] << " \n"[i == n - 1];
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