#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> a(4 + 1, vector<int>(n + 1));
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    
    int parked = 0;
    vector<array<int, 3>> vans;

    auto park = [&](){
        for (int j = 1; j <= n; j++){
            if (a[2][j] != 0 && a[1][j] == a[2][j]){
                vans.push_back({a[2][j], 1, j});
                a[2][j] = 0;
                parked++;
            }
        }
        for (int j = 1; j <= n; j++){
            if (a[3][j] != 0 && a[3][j] == a[4][j]){
                vans.push_back({a[3][j], 4, j});
                a[3][j] = 0;
                parked++;
            }
        }
    };

    auto turn = [&](){
        vector<pair<int, int>> order(2 * n);
        for (int i = 1; i <= n; i++) order[i - 1] = {2, i};
        for (int i = n; i >= 1; i--) order[n + (n - i)] = {3, i};

        rotate(
            order.begin(),
            find_if(
                order.begin(), order.end(),
                [&](const pair<int, int> &x){
                    auto [i, j] = x;
                    return a[i][j] == 0;
                }
            ),
            order.end()
        );

        for (int idx = 1; idx < 2 * n; idx++){
            auto [i, j] = order[idx];
            auto [pi, pj] = order[idx - 1];
            if (a[i][j] != 0){
                vans.push_back({a[i][j], pi, pj});
                swap(a[i][j], a[pi][pj]);
            }
        }
    };

    park();
    if (k == 2 * n && parked == 0){
        cout << "-1\n";
        return;
    }
    for (int _ = 0; _ < 2 * n - 1; _++){
        turn();
        park();
        if (parked == k) break;
    }

    cout << vans.size() << '\n';
    for (auto [i, r, c] : vans){
        cout << i << ' ' << r << ' ' << c << '\n';
    }

    /*
    Observations:
        * if k < 2 * n, it's always possible in <= k + k * (2 + n) moves
            strategy: we rotate all the cars clockwise, parking them if theyre adjacent
        * if k == 2 * n, if at the start any car is adjcant to its parking spot,
            the problem can be reduced to k < 2 * n
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