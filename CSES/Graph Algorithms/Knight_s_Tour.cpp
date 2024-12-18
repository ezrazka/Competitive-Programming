#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

pii moves[8] = {
    make_pair(1, 2),
    make_pair(2, 1),
    make_pair(-1, 2),
    make_pair(2, -1),
    make_pair(1, -2),
    make_pair(-2, 1),
    make_pair(-1, -2),
    make_pair(-2, -1)
};

void solve(){
    int x, y; cin >> y >> x; x--, y--;
    int n = 8;

    auto valid = [&](int i, int j) -> bool {
        return i >= 0 && i < n && j >= 0 && j < n;
    };

    vector<vector<int>> available(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (pii move : moves){
                if (valid(i + move.fi, j + move.se)){
                    available[i][j]++;
                }
            }
        }
    }

    vector<vector<int>> vans(n, vector<int>(n, -1));
    bool found = false;
    auto dfs = [&](auto self, int i, int j, int depth) -> void {
        if (found) return;

        vans[i][j] = depth;
        if (depth == n * n){
            found = true;
            return;
        };

        vector<pii> squares;
        for (pii move : moves){
            pii square = {i + move.fi, j + move.se};
            if (valid(square.fi, square.se) && vans[square.fi][square.se] == -1){
                available[square.fi][square.se]--;
                squares.push_back(square);
            }
        }
        sort(squares.begin(), squares.end(), [&](pii a, pii b){
            return available[a.fi][a.se] < available[b.fi][b.se];
        });
        
        for (pii square : squares){
            self(self, square.fi, square.se, depth + 1);
            if (found) return;
        }

        for (pii square : squares){
            available[square.fi][square.se]++;
        }

        vans[i][j] = -1;
    };
    dfs(dfs, x, y, 1);
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
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