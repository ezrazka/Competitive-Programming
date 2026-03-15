#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> freq(n * n + 1);
    bool ok = true;
    for (int i = 0; i < n * n; i++){
        int x; cin >> x;
        freq[x]++;
        if (freq[x] > n * (n - 1)) ok = false;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
