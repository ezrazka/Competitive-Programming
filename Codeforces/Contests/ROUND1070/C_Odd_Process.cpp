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
    vector<int> odd, even;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x & 1){
            odd.push_back(x);
        } else {
            even.push_back(x);
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    if (!odd.size()){
        for (int i = 1; i <= n; i++){
            cout << 0 << " \n"[i == n];
        }
        return;
    }

    if (!even.size()){
        for (int i = 1; i <= n; i++){
            cout << (i & 1 ? odd.back() : 0) << " \n"[i == n];
        }
        return;
    }

    vector<int> pref(even.size() + 1);
    for (int i = 1; i <= even.size(); i++){
        pref[i] = pref[i - 1] + even[even.size() - i];
    }

    vector<int> vans(n + 1);
    for (int i = 1; i <= even.size() + 1; i++){
        vans[i] = odd.back() + pref[i - 1];
    }
    for (int j = 0; j < (odd.size() - 1) / 2; j++){
        vans[even.size() + 1 + 2 * j + 1] = vans[even.size() + 1] - even[0];
        vans[even.size() + 1 + 2 * j + 2] = vans[even.size() + 1];
    }

    for (int i = 1; i <= n; i++){
        cout << vans[i] << " \n"[i == n];
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