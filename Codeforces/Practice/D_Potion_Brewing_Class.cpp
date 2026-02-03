#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;
constexpr int N = 2e5;

vector<int> spf(N + 1);
vector<int> inv(N + 1);

struct fraction {
    int num, denom;
};

struct element {
    int value = 1, sum = 0;
    map<int, int> primes;

    void transition(element &other, fraction &frac){ 
        if (primes.size() < other.primes.size()){
            swap(primes, other.primes);
        }

        map<int, int> offset;
        {
            int &n = frac.num;
            while (n > 1){
                int prime = spf[n];
                offset[prime]++;
                n /= prime;
            }
        }
        {
            int &n = frac.denom;
            while (n > 1){
                int prime = spf[n];
                offset[prime]--;
                n /= prime;
            }
        }

        /* update value, sum, primes */
        // int a = 1, b = 1;
        // for (auto [prime, cnt] : other.primes){
        //     {
        //         int times = max(0ll, (cnt - primes[prime]) + offset[prime]);
        //         while (times--){
        //             primes[prime]++;
        //             a *= prime;
        //             a %= MOD;
        //         }
        //     }
        // }

        
    }
};

void init(){
    iota(spf.begin(), spf.end(), 0);
    spf[0] = -1, spf[1] = -1;
    for (int i = 2; i * i <= N; i++){
        if (spf[i] == i){
            for (int j = i * i; j <= N; j += i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }

    inv[0] = -1, inv[1] = 1;
    for (int a = 2; a <= N; a++){
        inv[a] = MOD - (MOD / a) * inv[MOD % a] % MOD;
    }
}

void solve(){
    int n; cin >> n;
    vector<vector<pair<int, fraction>>> adj(n);
    for (int _ = 0; _ < n - 1; _++){
        int i, j, x, y; cin >> i >> j >> x >> y; i--, j--;
        adj[i].emplace_back(j, fraction{x, y});
        adj[j].emplace_back(i, fraction{y, x});
    }

    vector<element> dp(n);
    auto dfs = [&](auto self, int node, int parent) -> void {
        for (auto [child, frac] : adj[node]){
            if (child != parent){
                self(self, child, node);
                dp[node].transition(dp[child], frac);
            }
        }
    };
    dfs(dfs, 0, -1);

    cout << dp[0].sum << '\n';

    /*
    tree dp,
    each node stores the answer for its subtree, and a map of the nodes value
    at each transition, 
    */

    /*
    the problem is basically just a tree based lcm problem MOD mod

    so its just a (somewhat) simple tree dp,

    an issue: i can't determine the lcm because mod loses information
        * maybe every node should store the current value in a
          prime factorization map, handle with small to large merging
        * 
    */
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