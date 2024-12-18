#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

int di[4] = {0, 0, -1, 1};
int dj[4] = {-1, 1, 0, 0};

void solve(){
    int k; cin >> k;

    auto valid = [&](int i, int j) -> bool {
        return i >= 0 && i < 8 && j >= 0 && j < 8;
    };

    vector<vector<ld>> dp(8, vector<ld>(8, 1));
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            vector<vector<ld>> dp2(8, vector<ld>(8));
            dp2[i][j] = 1;
            for (int _ = 1; _ <= k; _++){
                vector<vector<ld>> next(8, vector<ld>(8));
                for (int i2 = 0; i2 < 8; i2++){
                    for (int j2 = 0; j2 < 8; j2++){
                        vector<pii> valid_squares;
                        for (int dir = 0; dir < 4; dir++){
                            int ii = i2 + di[dir], jj = j2 + dj[dir];
                            if (valid(ii, jj)) valid_squares.push_back({ii, jj});
                        }
                        for (auto [ii, jj] : valid_squares){
                            next[ii][jj] += dp2[i2][j2] / valid_squares.size();
                        }
                    }
                }
                dp2 = next;
            }
            for (int i2 = 0; i2 < 8; i2++){
                for (int j2 = 0; j2 < 8; j2++){
                    dp[i2][j2] *= (1 - dp2[i2][j2]);
                }
            }
        }
    }

    ld ans = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            ans += dp[i][j];
        }
    }
    cout << fixed << setprecision(6) << ans << '\n';

    /*
    1. How does it work?
        * we create a dp matrix denoting the probability that square (i, j) is empty
        * for each possible robot,
            we find the probability it reaches square (i, j)
            then we add its contribution to the final dp matrix
    2. How could I have come up with it myself?
        * Observe that we need to know the probability that each square is empty
          and by linearity: EV(dp[1])+...EV(dp[64]) = EV(dp[1]...dp[64])
        * Observe that we cannot calculate all robots simultaneously,
          for we would then obtain the EV of robots on a square,
          which can't be used to calculate the probability that a square is empty
          Therefore:
            we have to calculate for each robot individually
    3. What can I do to make sure I can come up with it next time it appears?
        * Remember that the linearity of EV applies to both independent and dependent variables
        * More oftenly consider contributions to solve EV problems (or math in general)
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}