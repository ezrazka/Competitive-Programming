#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;
const int N = 1e6;

vector<int> spf(N + 1);

void init(){
    iota(spf.begin(), spf.end(), 0);
    spf[0] = -1, spf[1] = -1;
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

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (is_sorted(a.begin(), a.end())){
        cout << "Bob\n";
        return;
    }

    int smallest_prime = INF;
    for (int i = n - 1; i >= 0; i--){
        if (a[i] == 1){
            smallest_prime = 1;
            continue;
        }

        int primes = 0;
        int temp = a[i];
        while (temp > 1){
            int prime = spf[temp];
            if (prime > smallest_prime){
                cout << "Alice\n";
                return;
            }
            while (temp % prime == 0){
                temp /= prime;
            }
            smallest_prime = min(smallest_prime, prime);
            primes++;
        }
        if (primes >= 2){
            cout << "Alice\n";
            return;
        }
    }
    cout << "Bob\n";
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