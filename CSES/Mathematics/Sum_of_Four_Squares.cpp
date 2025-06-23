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

    for (int i = (int) sqrt(n); i >= 0; i--){
        for (int j = (int) sqrt(n); j >= i; j--){
            for (int k = (int) sqrt(n); k >= j; k--){
                for (int l = (int) sqrt(n); l >= k; l--){
                    if (i * i + j * j + k * k + l * l == n){
                        cout << i << ' ' << j << ' ' << k << ' ' << l << '\n';
                        return;
                    }
                }
            }
        }
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