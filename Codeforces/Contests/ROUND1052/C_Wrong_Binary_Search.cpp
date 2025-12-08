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
    string s; cin >> s;

    bool ok = true;
    vector<int> vans(n);
    iota(vans.begin(), vans.end(), 1);
    {
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '0') cnt++;
            else {
                if (cnt == 1) ok = false;
                reverse(vans.begin() + i - cnt, vans.begin() + i);
                cnt = 0;
            }
        }
        if (cnt == 1) ok = false;
        reverse(vans.begin() + n - cnt, vans.begin() + n);
    }
    
    if (!ok){
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
    for (int i = 0; i < n; i++){
        cout << vans[i] << " \n"[i == n - 1];
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