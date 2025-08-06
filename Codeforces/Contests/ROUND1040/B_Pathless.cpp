#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, s; cin >> n >> s;
    map<int, int> mp;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x]++;
    }

    int sum = mp[1] + 2 * mp[2];

    if (s < sum){
        for (int i = 0; i <= 2; i++){
            for (int j = 0; j < mp[i]; j++){
                cout << i << ' ';
            }
        }
        cout << '\n';
        return;
    }

    if (s != sum + 1){
        cout << -1 << '\n';
        return;
    }

    for (int i : {0, 2, 1}){
        for (int j = 0; j < mp[i]; j++){
            cout << i << ' ';
        }
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}