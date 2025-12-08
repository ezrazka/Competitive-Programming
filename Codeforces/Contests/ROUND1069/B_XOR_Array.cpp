#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

// int get_xor(vector<int>&a, int l, int r){
//     int xor_sum = 0;
//     for (int k = l; k <= r; k++){
//         xor_sum ^= a[i];
//     }
//     return
// }

void solve(){
    int n, l, r; cin >> n >> l >> r; l--, r--;
    vector<int> a(n);
    for (int i = 0; i <= r; i++){
        a[i] = (i + 1) & -(i + 1);
    }

    int xor_sum = 0;
    for (int i = l; i <= r; i++){
        xor_sum ^= a[i];
    }
    a[r] ^= xor_sum;

    if (r + 1 < n){
        a[r + 1] = 1 << (__lg(n) + 2);
    }

    for (int i = r + 2; i < n; i++){
        a[i] = (i - r - 1) & -(i - r - 1);
    }

    for (int i = 0; i < n; i++){
        cout << a[i] << " \n"[i == n - 1];
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