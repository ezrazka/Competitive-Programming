#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

int binpow(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '(') ans = (ans + binpow(2, i)) % MOD;
    }

    vector<int> pref(n + 1);
    vector<int> pref_closed(n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + (s[i - 1] == '(' ? 1 : -1);
        pref_closed[i] = pref_closed[i - 1] + (s[i - 1] == ')');
    }

    vector<int> dp(n + 1);
    vector<int> sum(n + 1);
    dp[0] = 1;
    sum[0] = dp[0];
    int opens_sum = 0;
    for (int i = 1; i <= n; i++){
        if (s[i - 1] == '('){
            dp[i] = 0;
            sum[i] = (sum[i - 1] + dp[i]) % MOD;
            if (pref[i] >= 2) opens_sum = (opens_sum * 2 + sum[i - 1]) % MOD;
            continue;
        }

        dp[i] = opens_sum;

        sum[i] = (sum[i - 1] * 2 + dp[i]) % MOD;
        if (pref[i] < 2) opens_sum = 0;
    }
    ans = (ans + sum[n] - 1) % MOD;

    cout << ans << '\n';
    /*
    ( ( ) ( ) )
    1 2 1 2 1 0

    ( ( ) ) ( )
    1 2 1 0 1 0


    ( ( ( )
    1 2 3 2

    ) ( ( (
    -1 0 1 2


    ) ( ( )
    -1 0 1 0

    ) ) ( (
    -1 -2 -1 0


    ) ( ) ( )
    -1 0 -1 0 -1

    ) ) ( ) (
    -1 -2 -1 -2 -1

    ( ( ) ) ( )
    1 2 1 0 1 0 swap 2, 6

    ( ) ) ) ( (
    1 0 -1 -2 -1 0 swap 2, 5

    so if i swap(a, b)

    if the last char is '(', always possible
    if the last char is ')', possible when those chosen pref[i] > 0

    for each ')', find the leftmost open bracket

    ( ) ) ) ) ) ( ) )
    1 0 -1 -2 -3 -4 -3 -4 -5, (1, 3, 7, 9)

    ) ) ( ) ) ) ) ) (
    -1 -2 -1 -2 -3 -4 -5 -6 -5
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}