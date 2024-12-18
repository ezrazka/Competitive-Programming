#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

vector<int> dp(1223);

int mex(vector<int> v){
    sort(v.begin(), v.end());
    int mex = 0;
    for (int i = 0; i < v.size(); i++){
        if (v[i] > mex) return mex;
        else if (v[i] == mex) mex++;
    }
    return mex;
}

void init(){
    dp[1] = false, dp[2] = false;
    for (int i = 3; i <= 1222; i++){
        vector<int> nums;
        for (int j = 1; j < i - j; j++){
            nums.push_back(dp[j] ^ dp[i - j]);
        }
        dp[i] = mex(nums);
    }
}

void solve(){
    int n; cin >> n;
    if (n > 1222){
        cout << "first\n";
        return;
    }
    cout << (dp[n] ? "first\n" : "second\n");
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