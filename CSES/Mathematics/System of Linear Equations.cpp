#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int MOD = 1e9 + 7;

int binpow(int a, int b){
    int res = 1;
    while (b){
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int inv(int a){
    return binpow(a, MOD - 2);
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    vector<int> b(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> A[i][j];
        }
        cin >> b[i];
    }
    
    vector<int> pivot_col(n, -1);
    int k = 0;
    for (int l = 0; l < m && k < n; l++){
        int pivot = -1;
        for (int i = k; i < n; i++){
            if (A[i][l] != 0){
                pivot = i;
                break;
            }
        }

        if (pivot == -1) continue;
        swap(A[k], A[pivot]);
        swap(b[k], b[pivot]);
        pivot_col[k] = l;
        
        int inv_pivot = inv(A[k][l]);
        for (int i = k + 1; i < n; i++){
            int coef = A[i][l] * inv_pivot % MOD;
            for (int j = l; j < m; j++){
                A[i][j] = (A[i][j] - A[k][j] * coef % MOD + MOD) % MOD;
            }
            b[i] = (b[i] - b[k] * coef % MOD + MOD) % MOD;
        }
        k++;
    }
    
    for (int i = k; i < n; i++){
        if (b[i] != 0){
            cout << "-1\n";
            return;
        }
    }
    
    vector<int> x(m);
    for (int i = k - 1; i >= 0; i--){
        int l = pivot_col[i];
        int need = b[i];
        for (int j = l + 1; j < m; j++){
            need = (need - A[i][j] * x[j] % MOD + MOD) % MOD;
        }
        x[l] = need * inv(A[i][l]) % MOD;
    }
    
    for (int j = 0; j < m; j++){
        cout << x[j] << " \n"[j == m - 1];
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
