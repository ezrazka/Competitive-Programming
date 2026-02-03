#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    if (k & 1){
        for (int i = 0; i < k; i++){
            cout << n << " \n"[i == k - 1];
        }
        return;
    }

    if (k <= 2){
        cout << 0 << ' ' << n << ' ';
        for (int i = 0; i < k - 2; i++){
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }

    array<int, 3> best = {0, n, n};

    if (__builtin_popcount(n) > 1){
        int msb1 = 1 << __lg(n);
        int msb2 = 1 << __lg(n ^ msb1);
        int x = n ^ msb1 ^ (msb2 - 1);
        int y = msb1 ^ (msb2 - 1);
        int z = n;
        if (x + y + z > best[0] + best[1] + best[2]){
            best = {x, y, z};
        }
    }

    cout << best[0] << ' ' << best[1] << ' ' << best[2] << ' ';
    for (int i = 0; i < k - 3; i++){
        cout << n << ' ';
    }
    cout << '\n';
    /*
    1 2 3 4 4
    0 4 4 4 4
    
    64 64 64 64 64 65
    biggest bit
    
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}