#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
   int n, q; cin >> n >> q;
   vector<char> a(n);
   for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    if (!count(a.begin(), a.end(), 'B')){
        while (q--){
            int x; cin >> x;
            cout << x << '\n';
        }
        return;
    }

    while (q--){
        int x; cin >> x;
        int ans = 0;
        int i = 0;
        while (x > 0){
            if (a[i] == 'A') ans++, x--;
            else ans++, x /= 2;
            i = (i + 1) % n;
        }
        cout << ans << '\n';
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