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
    string s, t; cin >> s >> t;

    int ans = 0;
    vector<int> len(n);
    for (int i = n - 1, j = n - 1; i >= 0; i--){
        while (j >= 0 && (s[j] != t[i] || j > i)) j--;
        if (j == -1){
            cout << -1 << '\n';
            return;
        }
        len[i] = i - j;
        ans = max(ans, i - j);
        if (ans > k){
            cout << -1 << '\n';
            return;
        }
    }


    cout << ans << '\n';
    string cur = s;
    for (int j = 0; j < ans; j++){
        string next = cur;
        for (int i = 1; i < n; i++){
            if (len[i] > j){
                next[i] = cur[i - 1];
            }
        }
        cur = next;
        cout << cur << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}