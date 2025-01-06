#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    int x, y; cin >> x >> y; x--, y--;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    string s; cin >> s;

    pii cur = {x, y};
    int houses = 0;
    for (char c : s){
        if (c == 'U' && v[cur.fi - 1][cur.se] != '#'){
            cur.fi--;
            houses += (v[cur.fi][cur.se] == '@');
            v[cur.fi][cur.se] = '.';
        }
        if (c == 'D' && v[cur.fi + 1][cur.se] != '#'){
            cur.fi++;
            houses += (v[cur.fi][cur.se] == '@');
            v[cur.fi][cur.se] = '.';
        }
        if (c == 'L' && v[cur.fi][cur.se - 1] != '#'){
            cur.se--;
            houses += (v[cur.fi][cur.se] == '@');
            v[cur.fi][cur.se] = '.';
        }
        if (c == 'R' && v[cur.fi][cur.se + 1] != '#'){
            cur.se++;
            houses += (v[cur.fi][cur.se] == '@');
            v[cur.fi][cur.se] = '.';
        }
    }
    cout << cur.fi + 1 << ' ' << cur.se + 1 << ' ' << houses << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}