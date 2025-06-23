#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;

    vector<vector<int>> vans(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            vector<int> freq(i + j);
            for (int k = 0; k < i; k++){
                freq[vans[k][j]]++;
            }
            for (int k = 0; k < j; k++){
                freq[vans[i][k]]++;
            }
            for (int k = 0; k < i + j; k++){
                if (freq[k] > 0) vans[i][j] = k + 1;
                else break;
            }
            cout << vans[i][j] << " \n"[j == n - 1];
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}