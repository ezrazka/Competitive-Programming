#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int max_prime = 1e12 + 37;

vector<bool> is_prime(1e6 + 1, true);
vector<int> primes;

void init(){
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= 1e6; i++){
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= 1e6; j += i){
            is_prime[j] = false;
        }
    }

    for (int i = 2; i <= 1e6; i++){
        if (is_prime[i]){
            primes.push_back(i);
        }
    }
}

void solve(){
    int n; cin >> n; n++;
    while (true){
        bool ok = true;
        for (int prime : primes){
            if (prime * prime > n){
                break;
            }
            if (n % prime == 0){
                ok = false;
                break;
            }
        }
        if (ok){
            cout << n << '\n';
            return;
        }
        n++;
    }
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