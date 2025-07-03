#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 1e9 + 7;

int binpow(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int modular_inverse(int a){
    return binpow(a, MOD - 2);
}

vector<vector<int>> determinant(const vector<vector<int>> a){
    
}

vector<vector<int>> inverse(const vector<vector<int>>& a){

}

vector<vector<int>> product(const vector<vector<int>>& a, const vector<vector<int>>& b){
    int n = a.size(), m = b[0].size();
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){

            }
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> coefficient(n, vector<int>(m));
    vector<vector<int>> constant(n, vector<int>(1));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> coefficient[i][j];
        }
        cin >> constant[i][0];
    }
    
    vector<vector<int>> variable = product(inverse(coefficient), constant);

    for (int i = 0; i < n; i++){
        cout << variable[i][0] << " \n"[i == n - 1];
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}