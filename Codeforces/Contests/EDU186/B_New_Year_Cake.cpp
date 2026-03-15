#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int a, b; cin >> a >> b;

    int ans = 0;
    for (int _ = 0; _ < 2; _++){
        int used_a = 0, used_b = 0;
        int i = 0;
        while (true){
            if (i % 2 == 0){
                if (used_a + (1 << i) > a) break;
                else used_a += (1 << i);
            }
            if (i % 2 == 1){
                if (used_b + (1 << i) > b) break;
                else used_b += (1 << i);
            }
            i++;
        }
        ans = max(ans, i);
        swap(a, b);
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