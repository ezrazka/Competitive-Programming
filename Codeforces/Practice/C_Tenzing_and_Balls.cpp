#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
 
        vector<int> best(n + 1, -1);
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++){
            dp[i] = dp[i - 1] + 1;
            if (best[a[i]] != -1){
                dp[i] = min(dp[i], dp[best[a[i]] - 1]);
            }
            if (best[a[i]] == -1 || dp[best[a[i]] - 1] > dp[i - 1]){
                best[a[i]] = i;
            }
        }
        cout << n - dp[n] << '\n';
    }
}