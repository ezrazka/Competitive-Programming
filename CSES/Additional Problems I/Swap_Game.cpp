#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    vector<vector<int>> v(3, vector<int>(3));
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> v[i][j];
        }
    }

    vector<int> pow10(10);
    pow10[0] = 1;
    for (int i = 1; i <= 9; i++){
        pow10[i] = pow10[i - 1] * 10;
    }

    auto encode = [&](vector<vector<int>> v) -> int {
        string flattened;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                flattened += '0' + v[i][j];
            }
        }
        return stoll(flattened);
    };

    auto swap = [&](int hash, pii a, pii b){
        int idx_a = a.fi * 3 + a.se;
        int idx_b = b.fi * 3 + b.se;
        int num_a = hash / pow10[8 - idx_a] % 10;
        int num_b = hash / pow10[8 - idx_b] % 10;
        int res = hash;
        res -= num_a * pow10[8 - idx_a];
        res -= num_b * pow10[8 - idx_b];
        res += num_a * pow10[8 - idx_b];
        res += num_b * pow10[8 - idx_a];
        return res;
    };

    unordered_map<int, int> dist;
    queue<int> q;
    dist[encode(v)] = 0;
    q.push(encode(v));
    while (!q.empty()){
        int node = q.front(); q.pop();
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 3; j++){
                int child = swap(node, {i, j}, {i + 1, j});
                if (dist.find(child) == dist.end()){
                    dist[child] = dist[node] + 1;
                    q.push(child);
                }
            }
        }
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 2; j++){
                int child = swap(node, {i, j}, {i, j + 1});
                if (dist.find(child) == dist.end()){
                    dist[child] = dist[node] + 1;
                    q.push(child);
                }
            }
        }
    }
 
    cout << dist[123456789] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}