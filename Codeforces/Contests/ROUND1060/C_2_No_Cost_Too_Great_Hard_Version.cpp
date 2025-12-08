#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

vector<vector<int>> prime_factors(2e5 + 2);

void init(){
    for (int i = 2; i <= 2e5 + 1; i++){
        if (prime_factors[i].empty()){
            for (int j = i; j <= 2e5 + 1; j += i){
                prime_factors[j].push_back(i);
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return b[i] < b[j];
    });

    map<int, int> freq;
    for (int i = 0; i < n; i++){
        for (int prime : prime_factors[a[i]]){
            freq[prime]++;
        }
    }

    for (auto [prime, cnt] : freq){
        if (cnt >= 2){
            cout << 0 << '\n';
            return;
        }
    }
    
    int ans = b[ord[0]] +  b[ord[1]];
    for (int i = 1; i < n; i++){
        for (int prime : prime_factors[a[ord[i]] + 1]){
            if (freq.find(prime) != freq.end()){
                ans = min(ans, b[ord[i]]);
            }
        }
    }
    for (auto [prime, cnt] : freq){
        if (cnt == 1 && a[ord[0]] % prime == 0) continue;
        ans = min(ans, ((prime - a[ord[0]] % prime) % prime) * b[ord[0]]);
    }
    cout << ans << '\n';
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