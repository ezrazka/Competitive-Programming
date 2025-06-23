#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<int> w(m), l(m), h(m);
    for (int i = 0; i < m; i++){
        cin >> w[i] >> l[i] >> h[i];
    }

    vector<int> fib(n + 2);
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i <= n + 1; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int i = 0; i < m; i++){
        vector<int> nums = {w[i], l[i], h[i]};
        sort(nums.begin(), nums.end());
        cout << (nums[0] >= fib[n] && nums[2] >= fib[n + 1]);
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}