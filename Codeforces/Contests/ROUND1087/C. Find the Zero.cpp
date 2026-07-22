#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    for (int i = 1; i <= 2 * n - 2; i += 2){
        cout << "? " << i << ' ' << i + 1 << endl;
        int q; cin >> q;
        if (q == 1){
            cout << "! " << i << endl;
            return;
        }
    }
    {
        cout << "? " << 2 * n - 1 << ' ' << 2 * n - 3 << endl;
        int q; cin >> q;
        if (q == 1){
            cout << "! " << 2 * n - 1 << endl;
            return;
        }
    }
    {
        cout << "? " << 2 * n - 1 << ' ' << 2 * n - 2 << endl;
        int q; cin >> q;
        if (q == 1){
            cout << "! " << 2 * n - 1 << endl;
            return;
        }
    }
    cout << "! " << 2 * n << endl;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
