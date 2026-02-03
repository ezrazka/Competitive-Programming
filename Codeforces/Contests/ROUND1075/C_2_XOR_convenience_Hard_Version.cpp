#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;

    if (__builtin_popcount(n + 1) > 1){
        cout << "-1\n";
        return;
    }

    vector<int> p(n);
    p[n - 1] = n;
    for (int i = n - 2; i >= 0; i--){
        p[i] = p[n - 1] ^ (i + 1);
    }

    for (int i = 0; i < n; i++){
        cout << p[i] << " \n"[i == n - 1];
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