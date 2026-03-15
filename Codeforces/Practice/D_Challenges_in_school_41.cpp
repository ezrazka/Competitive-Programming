#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    auto search = [&](string s){
        vector<int> indices;
        for (int i = 0; i < n - 1; i++){
            if (s[i] == 'R' && s[i + 1] == 'L'){
                indices.push_back(i);
            }
        }
        return indices;
    };

    int lb = 0, ub = 0;
    vector<vector<int>> indices;
    int i = 0;
    indices.push_back({});
    while (!(indices[i] = search(s)).empty()){
        for (int j : indices[i]){
            swap(s[j], s[j + 1]);
            ub++;
        }
        lb++;
        i++;
        indices.push_back({});
    }
    indices.pop_back();

    if (!(lb <= k && k <= ub)){
        cout << -1 << '\n';
        return;
    }

    int extra = k - lb;

    vector<vector<int>> vans;
    for (int i = 0; i < indices.size(); i++){
        for (int x = 0; x < indices[i].size(); x++){
            int j = indices[i][x];
            if (x + 1 < indices[i].size() && extra > 0){
                vans.push_back({j});
                extra--;
            } else {
                vans.push_back({});
                for (int y = x; y < indices[i].size(); y++){
                    int j = indices[i][y];
                    vans.back().push_back(j);
                }
                break;
            }
        }
    }

    for (int i = 0; i < vans.size(); i++){
        cout << vans[i].size() << ' ';
        for (int j : vans[i]){
            cout << j + 1 << ' ';
        }
        cout << '\n';
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