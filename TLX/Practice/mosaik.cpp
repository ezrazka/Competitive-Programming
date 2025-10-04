#include <bits/stdc++.h>
using namespace std;
#define int long long

random_device rd;
mt19937_64 rng(rd());

int rnd(int x, int y){
  return uniform_int_distribution<int>(x, y)(rng);
}

signed main(){
    for (int tc = 1; tc <= 5; tc++){
        freopen(("inputs/mosaik_" + to_string(tc) + ".in").c_str(), "r", stdin);
        freopen(("outputs/mosaik_" + to_string(tc) + ".out").c_str(), "w", stdout);
        int n, m; cin >> n >> m;
        vector<vector<char>> v(n, vector<char>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> v[i][j];
            }
        }
        cout << tc << '\n';
    }
}