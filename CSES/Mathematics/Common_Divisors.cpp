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
    vector<int> freq(1e6 + 1);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    for (int i = 1e6; i >= 1; i--){
        int cnt = 0;
        for (int j = i; j <= 1e6; j += i){
            cnt += freq[j];
        }
        if (cnt >= 2){
            cout << i << '\n';
            return;
        }
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