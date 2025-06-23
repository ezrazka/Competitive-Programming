#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, l, r; cin >> n >> l >> r;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int an
    vector<int> a(n - n / 2), b(n / 2);
    for (int i = 0; i < n - n / 2; i++){
        a[i] = v[i];
    }
    for (int i = 0; i < n - n / 2; i++){
        a[i] = v[i];
    }

    vector<int> sum1;
    auto rec = [&](auto self, int idx, int sum) -> void {
        if (idx == n){
            sum1 += sum;
            return;
        }
    };
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}