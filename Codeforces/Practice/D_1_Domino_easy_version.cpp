#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m, h; cin >> n >> m >> h;
    int v = n * m / 2 - h;

    if (n % 2 == 0 && m % 2 == 0){
        if (v % 2 == 1 || h % 2 == 1){
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
    } else if (n % 2 == 0){
        if (v < n / 2 || h % 2 == 1 || (v - n / 2) % 2 == 1){
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
    } else {
        if (h < m / 2 || v % 2 == 1 || (h - m / 2) % 2 == 1){
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
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