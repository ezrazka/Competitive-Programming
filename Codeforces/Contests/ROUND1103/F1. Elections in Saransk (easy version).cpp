#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

const int MOD = 1e9 + 7;
const int N = 5e5;
vector<int> spf(N + 1);

void init() {
    iota(spf.begin(), spf.end(), 0);
    spf[0] = -1, spf[1] = -1;
    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> sum;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        int temp = a[i];
        while (temp > 1) {
            int prime = spf[temp];
            int cnt = 0;
            while (temp % prime == 0) temp /= prime, cnt++;
            sum[prime] += cnt;
        }
    }

    int ans = 1;
    for (auto [prime, sum] : sum) {
        ans = (ans * (sum + 1)) % MOD;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    init();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
