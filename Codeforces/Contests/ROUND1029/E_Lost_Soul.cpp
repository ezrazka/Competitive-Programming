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
    vector<vector<int>> v(2, vector<int>(n));
    for (int j = 0; j < 2; j++){
        for (int i = 0; i < n; i++){
            cin >> v[j][i];
        }
    }

    vector<vector<int>> found_at(2, vector<int>(n, -1));
    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j < 2; j++){
            if (
                found_at[(i ^ j) & 1 ^ 1][v[j][i] - 1] != -1 ||
                found_at[(i ^ j) & 1][v[j][i] - 1] - i >= 2
            ){
                cout << i + 1 << '\n';
                return;
            }
            if (found_at[(i ^ j) & 1][v[j][i] - 1] == -1){
                found_at[(i ^ j) & 1][v[j][i] - 1] = i;
            }
        }
    }
    cout << 0 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}