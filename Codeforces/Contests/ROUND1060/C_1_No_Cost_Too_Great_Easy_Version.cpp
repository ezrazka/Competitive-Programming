#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"


vector<int> spf(2e5 + 2);

void init(){
    iota(spf.begin(), spf.end(), 0);
    spf[0] = -1;
    spf[1] = -1;
    for (int i = 2; i * i <= 2e5 + 1; i++){
        if (spf[i] == i){
            for (int j = i * i; j <= 2e5 + 1; j += i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    map<int, int> primes1, primes2;
    for (int i = 0; i < n; i++){
        {
            int temp = a[i];
            while (temp > 1){
                int prime = spf[temp];
                primes1[prime]++;
                while (temp % prime == 0){
                    temp /= prime;
                }
            }
        }
        {
            int temp = a[i] + 1;
            while (temp > 1){
                int prime = spf[temp];
                primes2[prime]++;
                while (temp % prime == 0){
                    temp /= prime;
                }
            }
        }
    }

    for (auto [key, val] : primes1){
        if (val >= 2){
            cout << 0 << '\n';
            return;
        }
    }
    for (auto [key, val] : primes1){
        if (primes2[key]){
            cout << 1 << '\n';
            return;
        }
    }
    cout << 2 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    init();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}