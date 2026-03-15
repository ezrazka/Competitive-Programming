#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int N = 998244353;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int x; cin >> x;

        } else if (qq == 2){
            int x; cin >> x;
            
        } else {
            int x; cin >> x;

        }
    }

    /*
    observation:
        if a is sorted in non-increasing order,
        then if you miss a bit, you cant get it again
        solving queries recursively takes O(n * 60) with memoization
        after reaching x, we can freely choose all elements to the right

    * how can i optimize this?
        most likely precompute then update dp efficiently
    * but the dp array changes depending on the X queried?
        its guaranteed that it takes a maximum of 61 elements (ignoring 0 values)
        to reach a sum >= x
        which mean i have to precompute the dp for all x in O(n * 60 * 60)?
    * when a reindeer is added, how does that affect the dp array?
        if dp(i, k) stores the number of ways to handle the largest k bits with prefix [1, i]
        if a reindeer is added, at some index j, we calculate its 61 k values,
        and it will affect the dp states to the right of it
        ```
        if (kth msb is on) dp[i][k] = sum(dp[1..i-1][k-1]) 
        else dp[i][k] = sum(dp[1..i-1][k-1]) + sum(dp[1..i-1][k])
        ```
        for each of the 61 k values, we update all of the dps in front of it somehow?
        dp[i + 1..n] += dp[i][k]
    * with precomputation, can i solve for any X in O(60)?
        

    dp recurrence relation normally:
    int dp(int i, int k){

    }
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}