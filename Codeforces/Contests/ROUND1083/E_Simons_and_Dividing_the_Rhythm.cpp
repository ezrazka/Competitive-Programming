#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

vector<int> prefix_function(vector<int> s){
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++){
        int j = pi[i - 1];
        while (j > 0 && s[(n - 1) - i] != s[(n - 1) - j]){
            j = pi[j - 1];
        }
        if (s[(n - 1) - i] == s[(n - 1) - j]){
            j++;
        }
        pi[i] = j;
    }
    reverse(pi.begin(), pi.end());
    return pi;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    
    vector<int> dp(n + 1);
    {
        vector<int> cur;
        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            cur.push_back(a[i]);
            vector<int> pi = prefix_function(cur);
            for (int j = 0; j <= i - 1; j++){
                if (j == i - 1 || !pi[j]){
                    dp[i] += dp[j];
                    dp[i] %= MOD;
                }
            }
        }
    }
    cout << dp[n] << '\n';
    /*
    some observations first
    1 2 3 4

    1 2 1 2
    -------
    1 1 2 2
    1 2 1 2
    1 2 2 1
    2 1 1 2
    2 1 2 1
    not allowed to swap 1 and 4

    so well remove all symmetries
    do i do this at every stage or at the end?

    we are not allowed to add if on [j + 1, i] there exists a prefix == suffix

    what if i make every element unique first?
    and then i use math to undo it

    i can solve unique with dp

    0 1 2 3 4 5
    1 1 2 4 8 16
    there is exactly 2^(n - 1) ways if all a[i] are unique

    can i undo this?

    we cannot swap in between same numbers

    // 0 1 2 0 is equivalent to 2^3 - 1 0 0 2
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