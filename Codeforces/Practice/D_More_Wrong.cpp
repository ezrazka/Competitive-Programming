#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int M = 2000;
vector<vector<int>> memo(M, vector<int>(M, -1));

int query(int i, int j){
    if (i == j) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    int x; cin >> x;
    return memo[i][j] = x;
}

void answer(int i){
    cout << "! " << i + 1 << endl;
}

void solve(){
    int n; cin >> n;
    vector<bool> a(n);

    a[0] = !!query(0, 1);
    a[n - 1] = !query(n - 2, n - 1);
    for (int i = 1; i < n - 1; i++){
        a[i] = !query(i - 1, i) && !!query(i, i + 1);
    }

    auto search = [&](){
        pair<int, int> res = {-1, n};
        int prev = -1;
        for (int i = 0; i < n; i++){
            if (!a[i]) continue;
            if (prev != -1 && i - prev < res.second - res.first) res = {prev, i};
            prev = i;
        }
        return res;
    };

    pair<int, int> cur;
    while ((cur = search()).first != -1){
        auto [l, r] = cur;
        bool left_bigger = query(l, r) - query(l, r - 1);
        if (left_bigger) a[r] = false;
        else a[l] = false;
    }

    for (int i = 0; i < n; i++){
        if (a[i]){
            answer(i);
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--){
        for (int i = 0; i < M; i++){
            for (int j = 0; j < M; j++){
                memo[i][j] = -1;
            }
        }
        solve();
    }
    return 0;
}