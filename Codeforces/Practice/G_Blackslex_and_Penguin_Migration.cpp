#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int query(int i, int j){
    cout << "? " << i << ' ' << j << endl;
    int q; cin >> q;
    return q;
}

void answer(const vector<vector<int>> &a){
    cout << "!\n";
    for (int i = 1; i < a.size(); i++){
        for (int j = 1; j < a[0].size(); j++){
            cout << a[i][j] << " \n"[j == a[0].size() - 1];
        }
    }
    cout << flush;
}

void solve(){
    int n; cin >> n;

    int corner1 = -1;
    {
        pair<int, int> best = {0, -1};
        for (int i = 1; i <= n * n; i++){
            int q = query(1, i);
            best = max(best, {q, i});
        }
        corner1 = best.second;
    }
    
    vector<int> diagonal1(n * n + 1);
    for (int i = 1; i <= n * n; i++){
        diagonal1[i] = query(corner1, i);
    }

    int corner2 = -1;
    {
        int anchor = -1;
        for (int i = 1; i <= n * n; i++){
            if (diagonal1[i] == 1){
                anchor = i;
                break;
            }
        }
        
        for (int i = 1; i <= n * n; i++){
            if  (diagonal1[i] != n - 1) continue;
            int q = query(anchor, i);
            if (q == n){
                corner2 = i;
                break;
            }
        }
    }
    
    vector<int> diagonal2(n * n + 1);
    for (int i = 1; i <= n * n; i++){
        diagonal2[i] = query(corner2, i);
    }

    vector<vector<int>> vans(n + 1, vector<int>(n + 1));
    for (int k = 1; k <= n * n; k++){
        int i = (diagonal1[k] + diagonal2[k] - (n - 1)) / 2 + 1;
        int j = (diagonal1[k] - diagonal2[k] + (n - 1)) / 2 + 1;
        vans[i][j] = k;
    }
    answer(vans);
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}