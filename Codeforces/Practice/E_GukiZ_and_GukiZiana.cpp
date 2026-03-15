#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

const int B = 160;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<vector<pair<int, int>>> blocks;
    vector<int> big_sum;
    for (int i = 0; i < n; i++){
        if (i % B == 0) blocks.push_back({}), big_sum.push_back(0);
        blocks.back().push_back({a[i], i});
    }

    for (vector<pair<int, int>> &block : blocks){
        sort(block.begin(), block.end());
    }

    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int l, r, x; cin >> l >> r >> x; l--, r--;
            int big_l = (l + B - 1) / B, big_r = (r + 1) / B - 1;
            for (int i = big_l; i <= big_r; i++){
                big_sum[i] += x;
            }
            if (big_l - 1 >= 0){
                vector<pair<int, int>> updated, not_updated;
                for (int i = (big_l - 1) * B; i < min(n, big_l * B); i++){
                    auto [val, idx] = blocks[i / B][i % B];
                    if (l <= idx && idx <= r) updated.push_back({val + x, idx});
                    else not_updated.push_back({val, idx});
                }
                blocks[big_l - 1].clear();
                merge(
                    updated.begin(), updated.end(),
                    not_updated.begin(), not_updated.end(),
                    back_inserter(blocks[big_l - 1])
                );
            }
            if (big_l - 1 != big_r + 1 && big_r + 1 <= blocks.size() - 1){
                vector<pair<int, int>> updated, not_updated;
                for (int i = (big_r + 1) * B; i < min(n, (big_r + 2) * B); i++){
                    auto [val, idx] = blocks[i / B][i % B];
                    if (l <= idx && idx <= r) updated.push_back({val + x, idx});
                    else not_updated.push_back({val, idx});
                }
                blocks[big_r + 1].clear();
                merge(
                    updated.begin(), updated.end(),
                    not_updated.begin(), not_updated.end(),
                    back_inserter(blocks[big_r + 1])
                );
            }
        } else if (qq == 2){
            int y; cin >> y;
            int leftmost = -1;
            for (int i = 0; i * B < n; i++){
                int idx = lower_bound(blocks[i].begin(), blocks[i].end(), make_pair(y - big_sum[i], 0ll)) - blocks[i].begin();
                if (idx < blocks[i].size() && blocks[i][idx].first == y - big_sum[i]){
                    leftmost = blocks[i][idx].second;
                    break;
                }
            }
            if (leftmost == -1){
                cout << -1 << '\n';
                continue;
            }
            int rightmost = -1;
            for (int i = (n - 1) / B; i >= 0; i--){
                int idx = lower_bound(blocks[i].rbegin(), blocks[i].rend(), make_pair(y - big_sum[i], n - 1), greater<pair<int, int>>()) - blocks[i].rbegin();
                if (idx < blocks[i].size() && blocks[i][(blocks[i].size() - 1) - idx].first == y - big_sum[i]){
                    rightmost = blocks[i][(blocks[i].size() - 1) - idx].second;
                    break;
                }
            }
            cout << rightmost - leftmost << '\n';
        }
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