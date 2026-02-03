#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int MOD = 1e9 + 7;
constexpr int INV_2 = (MOD + 1) / 2;

int binpow(int a, int b){
    int res = 1;
    while (b){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
    int m; cin >> m;
    vector<int> p(m);
    for (int i = 0; i < m; i++){
        cin >> p[i];
    }

    map<int, int> freq;
    for (int i = 0; i < m; i++){
        freq[p[i]]++;
    }
    
    bool is_square = true;
    for (auto [prime, cnt] : freq){
        if (cnt & 1){
            is_square = false;
        }
    }
    
    if (is_square){
        int n = 1;
        {
            for (auto [prime, cnt] : freq){
                cnt /= 2;
                while (cnt--){
                    n = (n * prime) % MOD;
                }
            }
        }
        int power = 1;
        {
            for (auto [prime, cnt] : freq){
                power = (power * (cnt + 1)) % (MOD - 1);
            }
        }
        cout << binpow(n, power) << '\n';
    } else {
        int n = 1;
        {
            for (auto [prime, cnt] : freq){
                while (cnt--){
                    n = (n * prime) % MOD;
                }
            }
        }
        int power = 1;
        {
            bool halved = false;
            for (auto [prime, cnt] : freq){
                if (!halved && (cnt & 1)){
                    power = (power * ((cnt + 1) / 2)) % (MOD - 1);
                    halved = true;
                } else {
                    power = (power * (cnt + 1)) % (MOD - 1);
                }
            }
        }
        cout << binpow(n, power) << '\n';
    }
    /*

    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}