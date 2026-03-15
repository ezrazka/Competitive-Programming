#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;
const int M = 1e6;

vector<bool> is_prime(M + 1, true);

void init(){
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= M; i++){
        if (is_prime[i]){
            for (int j = i * i; j <= M; j += i){
                is_prime[j] = false;
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<int> primes;
    {
        int temp = accumulate(a.begin(), a.end(), 0ll);
        for (int prime = 2; prime * prime <= temp; prime++){
            if (temp % prime != 0) continue;
            if (!is_prime[prime]) continue;
            while (temp % prime == 0){
                temp /= prime;
            }
            primes.push_back(prime);
        }
        if (temp > 1){
            primes.push_back(temp);
        }
    }

    int ans = INF;
    for (int prime : primes){
        int cur = 0, sum = 0;
        for (int i = 0; i < n; i++){
            sum += a[i];
            cur += min(sum % prime, prime - sum % prime);
        }
        ans = min(ans, cur);
    }
    cout << (ans == INF ? -1 : ans) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    init();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}