#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int INF = 1e18;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> start(4);
    for (int i = 0; i < 4; i++){
        cin >> start[i];
    }
    sort(start.begin(), start.end());
    vector<vector<bool>> valid(k + 1, vector<bool>(k + 1));
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= k; j++){
            char x; cin >> x;
            valid[i][j] = x - '0';
        }
    }
    vector<int> libraries = {0};
    vector<vector<int>> pref(k + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++){
        int qq; cin >> qq;
        if (qq == 1){
            int element; cin >> element;
            pref[element][i]++;
        } else {
            libraries.push_back(i);
        }
    }
    libraries.push_back(n + 1);
    for (int i = 1; i <= k; i++){
        for (int j = 2; j <= n; j++){
            pref[i][j] += pref[i][j - 1];
        }
    }
    int m = libraries.size() - 1;

    int dp[m + 1][k + 1][k + 1][k + 1][k + 1];
    int killed[k + 1][k + 1][k + 1][k + 1];
    for (int i = 1; i <= k; i++){
        for (int j = i + 1; j <= k; j++){
            for (int l = j + 1; l <= k; l++){
                for (int o = l + 1; o <= k; o++){
                    dp[0][i][j][l][o] = -INF;
                }
            }
        }
    }
    dp[0][start[0]][start[1]][start[2]][start[3]] = 0;
    vector<int> s(4), t(4);
    for (int i = 1; i <= m; i++){
        for (s[0] = 1; s[0] <= k; s[0]++){
            for (s[1] = s[0] + 1; s[1] <= k; s[1]++){
                for (s[2] = s[1] + 1; s[2] <= k; s[2]++){
                    for (s[3] = s[2] + 1; s[3] <= k; s[3]++){
                        killed[s[0]][s[1]][s[2]][s[3]] = 0;
                        for (int element = 1; element <= k; element++){
                            if (!valid[s[0]][element] && !valid[s[1]][element] && !valid[s[2]][element] && !valid[s[3]][element]) continue; 
                            killed[s[0]][s[1]][s[2]][s[3]] += pref[element][libraries[i] - 1] - pref[element][libraries[i - 1]];
                        }
                    }
                }
            }
        }
        for (s[0] = 1; s[0] <= k; s[0]++){
            for (s[1] = s[0] + 1; s[1] <= k; s[1]++){
                for (s[2] = s[1] + 1; s[2] <= k; s[2]++){
                    for (s[3] = s[2] + 1; s[3] <= k; s[3]++){
                        dp[i][s[0]][s[1]][s[2]][s[3]] = -INF;
                        for (int added = 1; added <= k; added++){
                            for (int removed = 0; removed < 4; removed++){
                                if (added != s[removed] && (added == s[0] || added == s[1] || added == s[2] || added == s[3])) continue;
                                t[0] = s[0];
                                t[1] = s[1];
                                t[2] = s[2];
                                t[3] = s[3];
                                for (int j = removed; j < 3; j++) t[j] = t[j+1];
                                t[3] = added;
                                if (t[0] > t[1]) swap(t[0], t[1]);
                                if (t[2] > t[3]) swap(t[2], t[3]);
                                if (t[0] > t[2]) swap(t[0], t[2]);
                                if (t[1] > t[3]) swap(t[1], t[3]);
                                if (t[1] > t[2]) swap(t[1], t[2]);
                                int cur = dp[i - 1][t[0]][t[1]][t[2]][t[3]];
                                if (cur == -INF) continue;
                                cur += killed[t[0]][t[1]][t[2]][t[3]];
                                dp[i][s[0]][s[1]][s[2]][s[3]] = max(dp[i][s[0]][s[1]][s[2]][s[3]], cur);
                            }
                        }
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= k; i++){
        for (int j = i + 1; j <= k; j++){
            for (int l = j + 1; l <= k; l++){
                for (int o = l + 1; o <= k; o++){
                    ans = max(ans, dp[m][i][j][l][o]);
                }
            }
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}