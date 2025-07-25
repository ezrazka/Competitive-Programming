#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int MOD = 998244353;

int binpow(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int inv(int a){
    return binpow(a, MOD - 2);
}

template<typename T>
struct segment_tree {
    int n;
    vector<T> tree;
    vector<T> lazy;

    segment_tree(int n){
        this->n = n;
        tree.assign(4 * n, 1);
        lazy.assign(4 * n, 1);
    }

    void propagate(int pos, int low, int high){
        if (lazy[pos] != 1){
            tree[pos] = (tree[pos] * lazy[pos]) % MOD;
            if (low != high){
                lazy[2 * pos + 1] = (lazy[2 * pos + 1] * lazy[pos]) % MOD;
                lazy[2 * pos + 2] = (lazy[2 * pos + 2] * lazy[pos]) % MOD;
            }
            lazy[pos] = 1;
        }
    }

    void update(int pos, int low, int high, int q_low, int q_high, T val){
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high){
            lazy[pos] = (lazy[pos] * val) % MOD;
            propagate(pos, low, high);
            return;
        }
        if (high < q_low || q_high < low){
            return;
        }

        int mid = (low + high) / 2;
        update(2 * pos + 1, low, mid, q_low, q_high, val);
        update(2 * pos + 2, mid + 1, high, q_low, q_high, val);
        tree[pos] = (tree[2 * pos + 1] + tree[2 * pos + 2]) % MOD;
    }

    T query(int pos, int low, int high, int q_low, int q_high){
        propagate(pos, low, high);
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }
        if (high < q_low || q_high < low){
            return 0;
        }

        int mid = (low + high) / 2;
        return (query(2 * pos + 1, low, mid, q_low, q_high) + query(2 * pos + 2, mid + 1, high, q_low, q_high)) % MOD;
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<int> l(n), r(n), p(n), q(n);
    vector<int> prob(n);
    for (int i = 0; i < n; i++){
        cin >> l[i] >> r[i] >> p[i] >> q[i];
        prob[i] = (p[i] * inv(q[i])) % MOD;
    }

    vector<vector<pair<int, int>>> ops(m + 2);
    vector<vector<pair<int, int>>> ops2(m + 2);
    for (int i = 0; i < n; i++){
        ops[l[i]].push_back({l[i], 1 - prob[i]});
        ops[r[i] + 1].push_back({l[i], inv(1 - prob[i])});
        ops2[r[i]].push_back({l[i], prob[i]});
    }

    segment_tree<int> dp(m + 2);
    for (int i = 1; i <= m + 1; i++){
        for (auto [idx, val] : ops[i]){
            dp.update(0, 0, m + 1, 0, idx - 1, val);
        }
        int cur = 0;
        for (auto [l, prob] : ops2[i]){
            cur += (dp.query(0, 0, m + 1, l - 1, l - 1) * ((prob * inv(1 - prob)) % MOD)) % MOD;
            cur %= MOD;
        }
        dp.update(0, 0, m + 1, i, i, cur);
        cout << (dp.query(0, 0, m + 1, i, i) + MOD) % MOD << ' ';
    }
    cout << '\n';
    
    cout << (dp.query(0, 0, m + 1, m, m) + MOD) % MOD << '\n';
}
/*
a * (1 - b) * (1 - c) + (1 - a) * b * (1 - c) + (1 - a) * (1 - b) * c
= (1 - a)(1 - b)(1 - c) * (a / (1 - a) + b / (1 - b) + c / (1 - c))

dp[r] = dp[l - 1] * (product of complements of new segments that overlap old) * undo
() -> l <= {current l - 1} < r
*/

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define ld long double
// #define fi first
// #define se second
// #define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
// #define debughere cout << "HERE\n"

// const int MOD = 998244353;

// int binpow(int a, int b){
//     int res = 1;
//     while (b > 0){
//         if (b & 1) res = (res * a) % MOD;
//         a = (a * a) % MOD;
//         b >>= 1;
//     }
//     return res;
// }

// int inv(int a){
//     return binpow(a, MOD - 2);
// }

// void solve(){
//     int n, m; cin >> n >> m;
//     vector<int> l(n), r(n), p(n), q(n);
//     vector<int> val(n);
//     for (int i = 0; i < n; i++){
//         cin >> l[i] >> r[i] >> p[i] >> q[i];
//         prob[i] = (p[i] * inv(q[i])) % MOD;
//     }

//     vector<int> vals1(m + 2, 1);
//     for (int i = 0; i < n; i++){
//         vals1[l[i]] *= (1 - prob[i]);
//         vals1[l[i]] %= MOD;
//         vals1[r[i] + 1] *= inv(1 - prob[i]);
//         vals1[r[i] + 1] %= MOD;
//     }

//     vector<int> vals2(m + 2, 0);
//     for (int i = 0; i < n; i++){
//         vals2[l[i]] += (prob[i] * inv(1 - prob[i])) % MOD;
//         vals2[l[i]] %= MOD;
//         vals2[r[i] + 1] -= (prob[i] * inv(1 - prob[i])) % MOD;
//         vals2[r[i] + 1] %= MOD;
//     }

//     vector<int> vals3(m + 2, 0);
//     for (int i = 0; i < n; i++){
//         vals3[l[i]] += 1;
//         vals3[r[i] + 1] -= 1;
//     }
//     for (int i = 1; i <= m; i++){
//         vals3[i] += vals3[i - 1];
//         if (!vals3[i]){
//             cout << 0 << '\n';
//             return;
//         }
//     }

//     int ans = 1;
//     for (int i = 1; i <= m; i++){
//         vals1[i] = (vals1[i] * vals1[i - 1]) % MOD;
//         vals2[i] = (vals2[i] + vals2[i - 1]) % MOD;
//         ans = (ans * vals1[i]) % MOD;
//         ans = (ans * vals2[i]) % MOD;
//     }
//     cout << (ans + MOD) % MOD << '\n';
// }
// // a * (1 - b) * (1 - c) + (1 - a) * b * (1 - c) + (1 - a) * (1 - b) * c
// // (1 - a)(1 - b)(1 - c) * (a / (1 - a) + b / (1 - b) + c / (1 - c))

// signed main(){
//     ios_base::sync_with_stdio(false), cin.tie(NULL);
//     int t = 1;
//     // cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }