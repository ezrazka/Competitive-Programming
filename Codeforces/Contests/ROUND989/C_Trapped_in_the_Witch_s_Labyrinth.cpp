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
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    vector<vector<bool>> bad(n, vector<bool>(m)), vis(n, vector<bool>(m)), in_stack(n, vector<bool>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (v[i][j] == '?'){
                if (i + 1 < n && v[i + 1][j] == '?') bad[i][j] = true, vis[i][j] = true;
                if (i - 1 >= 0 && v[i - 1][j] == '?') bad[i][j] = true, vis[i][j] = true;
                if (j + 1 < m && v[i][j + 1] == '?') bad[i][j] = true, vis[i][j] = true;
                if (j - 1 >= 0 && v[i][j - 1] == '?') bad[i][j] = true, vis[i][j] = true;
            }
        }
    }

    stack<pii> st;
    auto dfs = [&](auto self, int i, int j) -> void {
        st.push({i, j});
        if (vis[i][j] && !bad[i][j]) return;
        if (in_stack[i][j] || bad[i][j] || (v[i][j] == '?' && st.size() > 1)){
            while (!st.empty()){
                bad[st.top().fi][st.top().se] = true;
                st.pop();
                in_stack[i][j] = false;
            }
            return;
        }
        in_stack[i][j] = true;
        vis[i][j] = true;
        if (v[i][j] == 'D' && i + 1 < n) self(self, i + 1, j);
        if (v[i][j] == 'U' && i - 1 >= 0) self(self, i - 1, j);
        if (v[i][j] == 'R' && j + 1 < m) self(self, i, j + 1);
        if (v[i][j] == 'L' && j - 1 >= 0) self(self, i, j - 1);
    };

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!vis[i][j]){
                dfs(dfs, i, j);
                while (!st.empty()) st.pop(), in_stack[i][j] = false;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (v[i][j] == '?'){
                if (i + 1 < n && bad[i + 1][j]) bad[i][j] = true;
                if (i - 1 >= 0 && bad[i - 1][j]) bad[i][j] = true;
                if (j + 1 < m && bad[i][j + 1]) bad[i][j] = true;
                if (j - 1 >= 0 && bad[i][j - 1]) bad[i][j] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (bad[i][j]) ans++;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}