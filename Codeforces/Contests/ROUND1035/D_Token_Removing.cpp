#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

struct mint {
    int val;
    static int MOD;

    static void init(int _MOD){
        MOD = _MOD;
    }

    mint(int _val = 0) {
        val = (_val % MOD + MOD) % MOD;
    }

    mint operator+(const mint& other) const {
        return mint(val + other.val);
    }

    mint& operator+=(const mint& other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    mint operator*(const mint& other) const {
        return mint(val * other.val % MOD);
    }

    mint& operator*=(const mint& other) {
        val = val * other.val % MOD;
        return *this;
    }

    mint operator+(int other) const {
        return mint(val + other);
    }

    mint& operator+=(int other) {
        val += other;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    mint operator*(int other) const {
        return mint(val * (other % MOD));
    }

    mint& operator*=(int other) {
        val = val * (other % MOD) % MOD;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const mint& m) {
        return os << m.val;
    }
};

int mint::MOD = 1;

void solve(){
    int n, MOD; cin >> n >> MOD;
    mint::init(MOD);

    vector<vector<mint>> dp(n + 1, vector<mint>(n + 1)); // dp[i][j], ways at i where there are j 0s
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= i; j++){
            if (j >= 1){ // if a[i] == 0
                dp[i][j] += dp[i - 1][j - 1];
            }
            if (j <= i - 1){ // if a[i] != 0
                dp[i][j] += dp[i - 1][j] * (n - i + 1) * (j + 1);
            } // (n - i + 1) * (j + 1) comes from
        }
    }
    cout << accumulate(dp[n].begin(), dp[n].end(), mint(0)) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}