#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;

    if (__lg(k) > __lg(n)){
        cout << -1 << '\n';
        return;
    }

    int x = n >> (__lg(n) - __lg(k));
    if (x == k){
        cout << __lg(n) - __lg(k) << '\n';
        return;
    }

    bool extra = false;
    for (int i = 0; i < __lg(n) - __lg(k); i++){
        if (n & (1 << i)){
            extra = true;
            break;
        }
    }

    if (extra && (x + 1) >> (__lg(x + 1) - __lg(x)) == k){
        cout << (__lg(n) - __lg(k)) + (__lg(x + 1) - __lg(x)) << '\n';
        return;
    }

    cout << -1 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}