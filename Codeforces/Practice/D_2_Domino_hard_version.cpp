#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m, h; cin >> n >> m >> h;
    int v = n * m / 2 - h;

    if (n % 2 == 0 && m % 2 == 0){
        if (v % 2 == 1 || h % 2 == 1){
            cout << "NO\n";
            return;
        }

        vector<vector<char>> vans(n + 1, vector<char>(m + 1));
        for (int i = 1; i <= n; i += 2){
            for (int j = 1; j <= m; j += 2){
                if (v){
                    if (i % 4 == 1){
                        vans[i][j] = 'a';
                        vans[i + 1][j] = 'a';
                        vans[i][j + 1] = 'b';
                        vans[i + 1][j + 1] = 'b';
                    } else {
                        vans[i][j] = 'b';
                        vans[i + 1][j] = 'b';
                        vans[i][j + 1] = 'a';
                        vans[i + 1][j + 1] = 'a';
                    }
                    v -= 2;
                } else {
                    if (j % 4 == 1){
                        vans[i][j] = 'c';
                        vans[i][j + 1] = 'c';
                        vans[i + 1][j] = 'd';
                        vans[i + 1][j + 1] = 'd';
                    } else {
                        vans[i][j] = 'd';
                        vans[i][j + 1] = 'd';
                        vans[i + 1][j] = 'c';
                        vans[i + 1][j + 1] = 'c';
                    }
                }
            }
        }

        cout << "YES\n";
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << vans[i][j];
            }
            cout << '\n';
        }
    } else if (n % 2 == 0){
        if (v < n / 2 || h % 2 == 1 || (v - n / 2) % 2 == 1){
            cout << "NO\n";
            return;
        }
        v -= n / 2;

        vector<vector<char>> vans(n + 1, vector<char>(m + 1));
        for (int i = 1; i <= n; i += 2){
            if (i % 4 == 1){
                vans[i][m] = 'a';
                vans[i + 1][m] = 'a';
            } else {
                vans[i][m] = 'b';
                vans[i + 1][m] = 'b';
            }
        }
        for (int i = 1; i <= n; i += 2){
            for (int j = 1; j <= m - 1; j += 2){
                if (v){
                    if (i % 4 == 1){
                        vans[i][j] = 'a';
                        vans[i + 1][j] = 'a';
                        vans[i][j + 1] = 'b';
                        vans[i + 1][j + 1] = 'b';
                    } else {
                        vans[i][j] = 'b';
                        vans[i + 1][j] = 'b';
                        vans[i][j + 1] = 'a';
                        vans[i + 1][j + 1] = 'a';
                    }
                    v -= 2;
                } else {
                    if (j % 4 == 1){
                        vans[i][j] = 'c';
                        vans[i][j + 1] = 'c';
                        vans[i + 1][j] = 'd';
                        vans[i + 1][j + 1] = 'd';
                    } else {
                        vans[i][j] = 'd';
                        vans[i][j + 1] = 'd';
                        vans[i + 1][j] = 'c';
                        vans[i + 1][j + 1] = 'c';
                    }
                }
            }
        }

        cout << "YES\n";
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << vans[i][j];
            }
            cout << '\n';
        }
    } else {
        if (h < m / 2 || v % 2 == 1 || (h - m / 2) % 2 == 1){
            cout << "NO\n";
            return;
        }
        h -= m / 2;

        vector<vector<char>> vans(n + 1, vector<char>(m + 1));
        for (int i = 1; i <= m; i += 2){
            if (i % 4 == 1){
                vans[n][i] = 'c';
                vans[n][i + 1] = 'c';
            } else {
                vans[n][i] = 'd';
                vans[n][i + 1] = 'd';
            }
        }
        for (int i = 1; i <= n - 1; i += 2){
            for (int j = 1; j <= m; j += 2){
                if (v){
                    if (i % 4 == 1){
                        vans[i][j] = 'a';
                        vans[i + 1][j] = 'a';
                        vans[i][j + 1] = 'b';
                        vans[i + 1][j + 1] = 'b';
                    } else {
                        vans[i][j] = 'b';
                        vans[i + 1][j] = 'b';
                        vans[i][j + 1] = 'a';
                        vans[i + 1][j + 1] = 'a';
                    }
                    v -= 2;
                } else {
                    if (j % 4 == 1){
                        vans[i][j] = 'c';
                        vans[i][j + 1] = 'c';
                        vans[i + 1][j] = 'd';
                        vans[i + 1][j + 1] = 'd';
                    } else {
                        vans[i][j] = 'd';
                        vans[i][j + 1] = 'd';
                        vans[i + 1][j] = 'c';
                        vans[i + 1][j + 1] = 'c';
                    }
                }
            }
        }

        cout << "YES\n";
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << vans[i][j];
            }
            cout << '\n';
        }
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