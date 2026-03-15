#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

vector<int> spf(1e6 + 1);

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
    int n, m; cin >> n >> m;
    int k = n + m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> divisors(k + 1);
    for (int i = 0; i < n; i++){
        divisors[a[i]]++;
    }
    for (int i = k; i >= 1; i--){
        for (int j = 2 * i; j <= k; j += i){
            divisors[j] += divisors[i];
        }
    }
    
    int both = 0, alice_only = 0, bob_only = 0;
    for (int i = 0; i < m; i++){
        bool can_alice = divisors[b[i]] >= 1;
        bool can_bob = (n - divisors[b[i]] >= 1);
        if (can_alice && can_bob) both++;
        else if (can_alice && !can_bob) alice_only++;
        else if (!can_alice && can_bob) bob_only++;
    }
    cout << (alice_only + (both & 1) > bob_only ? "Alice\n" : "Bob\n");
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