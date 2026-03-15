#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int B = 450;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (a[i] < B) continue;
        for (int j = i - a[i]; j >= 0; j -= a[i]){
            if (a[i] * a[j] == i - j) ans++;
        }
        for (int j = i + a[i]; j < n; j += a[i]){
            if (a[i] * a[j] == j - i) ans++;
        }
    }
    for (int i = 0; i < n; i++){
        if (a[i] >= B) continue;
        for (int aj = 1; aj < B; aj++){
            int j = i - a[i] * aj;
            if (j < 0) break;
            if (a[j] == aj) ans++;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}