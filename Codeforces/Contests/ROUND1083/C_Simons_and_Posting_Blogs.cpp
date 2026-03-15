// 
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int N = 1e6;
vector<bool> found(N + 1);

void solve(){
    int n; cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++){
        int l; cin >> l;
        for (int j = 0; j < l; j++){
            int x; cin >> x;
            a[i].push_back(x);
        }
    }

    auto merge = [&](const vector<int> &x, const vector<int> &y){
        vector<int> res(y.rbegin(), y.rend());
        for (int v : y) found[v] = true;
        for (int v : x){
            if (found[v]) continue;
            res.push_back(v);
        }
        for (int v : y) found[v] = false;
        return res;
    };

    for (int i = 0; i < n; i++){
        vector<int> fixed;
        for (int j = a[i].size() - 1; j >= 0; j--){
            if (found[a[i][j]]) continue;
            fixed.push_back(a[i][j]);
            found[a[i][j]] = true;
        }
        for (int j = 0; j < a[i].size(); j++){
            found[a[i][j]] = false;
        }
        reverse(fixed.begin(), fixed.end());
        a[i] = fixed;
    }

    vector<int> ord(n);
    vector<bool> vis(n);
    for (int k = 0; k < n; k++){
        int idx = -1;
        for (int i = 0; i < n; i++){
            if (vis[i]) continue;
            if (idx == -1){
                idx = i;
                continue;
            }
            for (int j = a[i].size() - 1, l = a[idx].size() - 1;;){
                while (j >= 0 && found[a[i][j]]) j--;
                while (l >= 0 && found[a[idx][l]]) l--;
                if (j < 0 || l < 0){
                    if (j < 0 && l >= 0) idx = i;
                    break;
                }
                if (a[i][j] != a[idx][l]){
                    if (a[i][j] < a[idx][l]) idx = i;
                    break;
                } else {
                    j--, l--;
                }
            }
        }
        ord[(n - 1) - k] = idx;
        vis[idx] = true;
        for (int j = 0; j < a[idx].size(); j++){
            found[a[idx][j]] = true;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = a[i].size() - 1; j >= 0; j--){
            found[a[i][j]] = false;
        }
    }
    
    vector<int> vans;
    for (int i = 0; i < n; i++){
        vans = merge(vans, a[ord[i]]);
    }
    
    for (int i = 0; i < vans.size(); i++){
        cout << vans[i] << " \n"[i == vans.size() - 1];
    }

    /*
    3000 * sqrt(3000) = 164k
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}