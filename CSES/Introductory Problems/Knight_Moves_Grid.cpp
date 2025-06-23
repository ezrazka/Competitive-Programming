#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int di[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dj[8] = {-2, 2, -2, 2, -1, 1, -1, 1};

void solve(){
    int n; cin >> n;

    vector<vector<int>> board(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    board[0][0] = 0;
    while (!q.empty()){
        auto [i, j] = q.front(); q.pop();
        for (int k = 0; k < 8; k++){
            int i2 = i + di[k], j2 = j + dj[k];
            if (0 <= i2 && i2 < n && 0 <= j2 && j2 < n){
                if (board[i2][j2] == -1){
                    q.emplace(i2, j2);
                    board[i2][j2] = board[i][j] + 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << board[i][j] << " \n"[j == n - 1];
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