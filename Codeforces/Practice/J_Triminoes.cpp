#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<char>> directions(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] == '.') continue;
            if (a[i][j] == 'b'){
                cout << "NO\n";
                return;
            }
            if (j + 1 >= m || a[i][j + 1] == '.'){
                if (i >= n - 2){
                    cout << "NO\n";
                    return;
                }
                for (int k = 0; k < 3; k++){
                    if (a[i + k][j] == '.'){
                        cout << "NO\n";
                        return;
                    }
                    a[i + k][j] = '.';
                }
                directions[i][j] = 'v';
            } else {
                if (j >= m - 2){
                    cout << "NO\n";
                    return;
                }
                for (int k = 0; k < 3; k++){
                    if (a[i][j + k] == '.'){
                        cout << "NO\n";
                        return;
                    }
                    a[i][j + k] = '.';
                }
                directions[i][j] = 'h';
            }
        }
    }

    vector<vector<char>> vans(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (directions[i][j] == '.') continue;

            set<int> colors = {'a', 'b', 'c', 'd'};

            auto remove = [&](int i, int j){
                if (i < 0 || i >= n || j < 0 || j > m) return;
                if (vans[i][j] == '.') return;
                if (colors.find(vans[i][j]) == colors.end()) return;
                colors.erase(vans[i][j]);
            };

            if (directions[i][j] == 'v'){
                remove(i - 1, j);
                remove(i, j - 1);
                remove(i, j + 1);
                remove(i + 1, j - 1);
                remove(i + 1, j + 1);
                remove(i + 2, j - 1);
                remove(i + 2, j + 1);
                remove(i + 3, j);
                vans[i][j] = *colors.begin();
                vans[i + 1][j] = *colors.begin();
                vans[i + 2][j] = *colors.begin();
            } else {
                remove(i, j - 1);
                remove(i - 1, j);
                remove(i + 1, j);
                remove(i - 1, j + 1);
                remove(i + 1, j + 1);
                remove(i - 1, j + 2);
                remove(i + 1, j + 2);
                remove(i, j + 3);
                vans[i][j] = *colors.begin();
                vans[i][j + 1] = *colors.begin();
                vans[i][j + 2] = *colors.begin();
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << vans[i][j];
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