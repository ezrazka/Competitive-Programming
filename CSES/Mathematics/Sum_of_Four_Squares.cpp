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
    
    for (int i = sqrt(n); i >= 0; i--){
        for (int j = min(i, (int) sqrt(n - i * i)); j >= 0; j--){
            for (int k = min(j, (int) sqrt(n - i * i - j * j)); k >= 0; k--){
                int l = sqrt(n - i * i - j * j - k * k);
                if (i * i + j * j + k * k + l * l == n){
                    cout << i << ' ' << j << ' ' << k << ' ' << l << '\n';
                    return;
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