#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

vector<bool> is_prime(1000 + 1, true);
vector<int> primes;

void init(){
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= 1000; i++){
        if (is_prime[i]){
            for (int j = i * i; j <= 1000; j += i){
                is_prime[j] = false;
            }
        }
    }

    for (int i = 1; i <= 1000; i++){
        if (is_prime[i]){
            primes.push_back(i);
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int prime : primes){
        bool found = false;
        for (int i = 0; i < n; i++){
            if (a[i] % prime != 0){
                found = true;
                break;
            }
        }
        if (found){
            cout << prime << '\n';
            return;
        }
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