#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

vector<bool> is_prime(1e5 + 1, true);

void init(){
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= 1e5; i++){
        if (is_prime[i]){
            for (int j = i * i; j <= 1e5; j += i){
                is_prime[j] = false;
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    vector<bool> vis(n);

    for (int i = n; i >= 1; i--){
        if (!is_prime[i]) continue;
        vector<int> nums;
        for (int j = i; j <= n; j += i){
            if (!vis[j - 1]){
                nums.push_back(j);
                vis[j - 1] = true;
            }
        }
        for (int i = 0; i < nums.size() - 1; i++){
            swap(v[nums[i] - 1], v[nums[i + 1] - 1]);
        }
    }

    for (int i = 0; i < n; i++){
        cout << v[i] << " \n"[i == n - 1];
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