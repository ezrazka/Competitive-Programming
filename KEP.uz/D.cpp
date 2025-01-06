#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

vector<bool> is_prime(1e6 + 1, true);

void init(){
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= 1e6; i++){
        if (is_prime[i]){
            for (int j = i * i; j <= 1e6; j += i){
                is_prime[j] = false;
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> freq(1e6 + 1);
    for (int i = 0; i < n; i++){
        if (is_prime[v[i]]){
            freq[v[i]]++;
        }
    }

    for (int i = 1; i <= 1e6; i++){
        if (is_prime[freq[i]]){
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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