#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MX = 5000;

// vector<vector<int>> factors(MX + 1);

void init(){
    // for (int i = 1; i <= MX; i++){
    //     for (int j = i; j <= MX; j += i){
    //         factors[j].push_back(i);
    //     }
    // }
}

signed main(){
    // init();
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<int> v;
    for (int i = 1; i * i <= a[1]; i++){
        if (a[1] % i != 0) continue;
        v.push_back(i);
        if (i != a[1] / i) v.push_back(a[1] / i);
    }
    int res = 0;
    for (int f : v){
        for (int g : v){
            if (f * g / __gcd(f, g) == a[1]) res++;
        }
    }
    cout << res << '\n';

    return 0;

    // vector<int> dp(MX + 1), ndp(MX + 1);
    // vector<int> to_move = factors[a[1]];
    // for (int f : factors[a[1]]){
    //     dp[f] = 1;
    // }
    // for (int i = 1; i <= n; i++){
    //     {
    //         for (int f : factors[a[i]]){
    //             for (int g : factors[a[i]]){
    //                 if (f * g / __gcd(f, g) != a[i]) continue;
    //                 ndp[f] += dp[g];
    //                 ndp[f] %= MOD;
    //                 // 12 -> 1 2 3 4 6 12
    //                 // 6 -> 4 12
    //                 // 4 -> 3 6 12
    //                 // 3 -> 4 12
    //                 // 2 -> 12
    //                 // 1 -> 12
    //             }
    //         }
    //     }
    //     {
    //         while (!to_move.empty()){
    //             dp[to_move.back()] = 0;
    //             to_move.pop_back();
    //         }
    //         for (int f : factors[a[i]]){
    //             to_move.push_back(f);
    //         }
    //         swap(dp, ndp);
    //     }
    // }
   
    // int ans = 0;
    // for (int f : to_move){
    //     ans += dp[f];
    //     ans %= MOD;
    // }
    // cout << ans << '\n';
}