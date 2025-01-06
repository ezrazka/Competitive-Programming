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
    vector<string> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    map<string, vector<int>> mp;
    vector<vector<string>> to_pop(1);
    for (int i = 0; i < n; i++){
        if (v[i] == "{"){
            to_pop.push_back(vector<string>());
        } else if (v[i] == "}"){
            for (string& var : to_pop.back()){
                mp[var].pop_back();
            }
            to_pop.pop_back();
        } else {
            string var;
            int idx;
            for (int j = 0; j < v[i].length(); j++){
                if (v[i][j] == '='){
                    idx = j + 1;
                    break;
                }
                var += v[i][j];
            }
            string var2;
            for (int j = idx; j < v[i].length(); j++){
                var2 += v[i][j];
            }
            if (var2[0] == '-' || '0' <= var2[0] && var2[0] <= '9'){
                mp[var].push_back(stoi(var2));
                to_pop.back().push_back(var);
            } else {
                mp[var].push_back((mp[var2].empty() ? 0 : mp[var2].back()));
                to_pop.back().push_back(var);
            }
            cout << (mp[var].empty() ? 0 : mp[var].back()) << '\n';
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