#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    auto calc = [&](bool transpose = false){
        vector<vector<char>> w;
        if (transpose){
            w.assign(m, vector<char>(n));
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    w[j][i] = v[i][j];
                }
            }
            swap(n, m);
        } else {
            w = v;
        }
        int res = n * m + 1;
        vector<vector<char>> best_cur(n, vector<char>(m));
        vector<vector<char>> cur(n, vector<char>(m));
        for (char a : {'A', 'C', 'G', 'T'}){
            for (char b : {'A', 'C', 'G', 'T'}){
                for (char c : {'A', 'C', 'G', 'T'}){
                    for (char d : {'A', 'C', 'G', 'T'}){
                        if (a == b || a == c || a == d || b == c || b == d || c == d){
                            continue;
                        }
                        if (a > b || c > d){
                            continue;
                        }

                        int cur_res = 0;
                        for (int i = 0; i < n; i++){
                            if (i & 1){
                                int cnt_ab = 0, cnt_ba = 0;
                                for (int j = 0; j < m; j += 2) if (w[i][j] != a) cnt_ab++;
                                for (int j = 1; j < m; j += 2) if (w[i][j] != b) cnt_ab++;
                                for (int j = 0; j < m; j += 2) if (w[i][j] != b) cnt_ba++;
                                for (int j = 1; j < m; j += 2) if (w[i][j] != a) cnt_ba++;
                                if (cnt_ab < cnt_ba){
                                    for (int j = 0; j < m; j++) cur[i][j] = (j & 1 ? b : a);
                                } else {
                                    for (int j = 0; j < m; j++) cur[i][j] = (j & 1 ? a : b);
                                }
                                cur_res += min(cnt_ab, cnt_ba);
                            } else {
                                int cnt_cd = 0, cnt_da = 0;
                                for (int j = 0; j < m; j += 2) if (w[i][j] != c) cnt_cd++;
                                for (int j = 1; j < m; j += 2) if (w[i][j] != d) cnt_cd++;
                                for (int j = 0; j < m; j += 2) if (w[i][j] != d) cnt_da++;
                                for (int j = 1; j < m; j += 2) if (w[i][j] != c) cnt_da++;
                                if (cnt_cd < cnt_da){
                                    for (int j = 0; j < m; j++) cur[i][j] = (j & 1 ? d : c);
                                } else {
                                    for (int j = 0; j < m; j++) cur[i][j] = (j & 1 ? c : d);
                                }
                                cur_res += min(cnt_cd, cnt_da);
                            }
                        }
                        if (cur_res < res){
                            res = cur_res;
                            best_cur = cur;
                        }
                    }
                }
            }
        }

        if (transpose){
            swap(n, m);
            vector<vector<char>> x(n, vector<char>(m));
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    x[i][j] = best_cur[j][i];
                }
            }
            return make_pair(res, x);
        } else {
            return make_pair(res, best_cur);
        }
    };
    auto [best1, vans1] = calc();
    auto [best2, vans2] = calc(true);

    auto vans = (best1 < best2 ? vans1 : vans2);
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