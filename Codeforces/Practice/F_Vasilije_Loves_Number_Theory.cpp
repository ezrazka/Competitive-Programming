#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

vector<int> spf(1e6 + 1);

void init(){
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i <= 1e6; i++){
        if (spf[i] == i){
            for (int j = i * i; j <= 1e6; j += i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

map<int, int> get_prime_counts(int n){
    map<int, int> res;
    while (n > 1){
        res[spf[n]]++;
        n /= spf[n];
    }
    return res;
}

void solve(){
    int n, q; cin >> n >> q;

    map<int, int> prime_counts = get_prime_counts(n);

    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int x; cin >> x;
            map<int, int> x_prime_counts = get_prime_counts(x);
            for (auto [key, val] : x_prime_counts){
                prime_counts[key] += val;
            }

            map<int, int> d_prime_counts;
            for (auto [key, val] : prime_counts){
                for (auto [key2, val2] : get_prime_counts(val + 1)){
                    d_prime_counts[key2] += val2;
                }
            }

            bool ok = true;
            for (auto [key, val] : d_prime_counts){
                if (prime_counts[key] < val){
                    ok = false;
                    break;
                }
            }
            cout << (ok ? "YES\n" : "NO\n");
        } else {
            prime_counts = get_prime_counts(n);
        }
    }
    cout << '\n';
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