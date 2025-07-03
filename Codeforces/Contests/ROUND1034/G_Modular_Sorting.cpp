#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int M = 5e5 + 5;
vector<int> negatives(M);

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> factors;
    for (int i = 1; i * i <= m; i++){
        if (m % i == 0){
            factors.push_back(i);
            if (i * i != m){
                factors.push_back(m / i);
            }
        }
    }

    for (int f : factors){
        for (int i = 0; i < n - 1; i++){
            int diff = (v[i + 1] % f) - (v[i] % f);
            negatives[f] += (diff < 0);
        }
    }

    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int idx, val; cin >> idx >> val; idx--;
            for (int f : factors){
                for (int i = max(0ll, idx - 1); i < min(n - 1, idx + 1); i++){
                    int diff = (v[i + 1] % f) - (v[i] % f);
                    negatives[f] -= (diff < 0);
                }
            }
            v[idx] = val;
            for (int f : factors){
                for (int i = max(0ll, idx - 1); i < min(n - 1, idx + 1); i++){
                    int diff = (v[i + 1] % f) - (v[i] % f);
                    negatives[f] += (diff < 0);
                }
            }
        } else {
            int k; cin >> k;
            int f = __gcd(k, m);
            cout << ((v[n - 1] % f) + f * negatives[f] < m ? "YES\n" : "NO\n");
        }
    }

    for (int f : factors){
        negatives[f] = 0;
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}