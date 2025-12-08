#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;

    vector<bool> bits(30);
    for (int bit = 0; bit < 30; bit++){
        bits[bit] = (n & (1 << bit));
    }
    
    vector<int> a, b;
    bool zero = false;
    int cnt = 0;
    for (int i = find(bits.begin(), bits.end(), true) - bits.begin(); i < 30; i++){
        if (zero && bits[i]){
            if (cnt) b.push_back(cnt);
            cnt = 0;
            zero = false;
        } else if (!zero && !bits[i]){
            if (cnt) a.push_back(cnt);
            cnt = 0;
            zero = true;
        }
        cnt++;
    }
    if (!zero && cnt) a.push_back(cnt);
    int m = a.size();
    assert(a.size() == b.size() + 1);

    if (k >= 30){
        int ans = k + m - 1;
        for (int i = 0; i < m; i++){
            ans += a[i] - 1;
        }
        cout << ans << '\n';
        return;
    }
    
    int dp[m + 1][61][2];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 0; j <= 60; j++){
            // do nothing
            dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1]);

            // take normally
            int cost_take = 1;
            int value_take = a[i - 1];
            if (j - value_take >= 0){
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - value_take][0] + cost_take);
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - value_take][1] + cost_take);
            }

            // take and merge previous
            if (i > 1){
                int cost_take_and_merge = b[i - 2];
                int value_take_and_merge = a[i - 1] + b[i - 2];
                if (j - value_take_and_merge >= 0){
                    dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - value_take_and_merge][1] + cost_take_and_merge);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 60; i >= 0; i--){
        if (min(dp[m][i][0], dp[m][i][1]) <= k){
            ans = max(ans, i + (k - min(dp[m][i][0], dp[m][i][1])));
        }
    }
    cout << ans << '\n';
    // knapsack dp[index][value][is_take][is_merge] -> cost
    /*
    what is the largest index with a cost (0-30) less than k to get a certain value (0-60)?

    */

    /*
    ans is always >= k

    optimally, always first choose the islands with size >1, from biggest to smallest
    we can save stuff if we fill in the gaps between islands taken

    if k >= 30, just go left to right

    the question is, which islands do we take,
    and which islands do we merge

    dp?
    we always merge with something adjacent

    simplify:
    a[m] island sizes, with m islands
    b[m-1] island gaps, with m-1 gaps

    then dp take / no take + merge / no merge
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