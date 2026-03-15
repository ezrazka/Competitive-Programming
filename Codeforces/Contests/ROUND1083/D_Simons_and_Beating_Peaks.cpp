#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

template<typename T>
struct segment_tree {
    int n;
    vector<T> tree;

    segment_tree(int n){
        this->n = n;
        tree.resize(4 * n);
    }

    void build(int pos, int low, int high, const vector<T>& v){
        if (low == high){
            tree[pos] = v[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * pos + 1, low, mid, v);
        build(2 * pos + 2, mid + 1, high, v);
        tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
    }
    T query(int pos, int low, int high, int q_low, int q_high){
        if (q_low <= low && high <= q_high){
            return tree[pos];
        }
        if (high < q_low || q_high < low){
            return make_pair(0, 0);
        }

        int mid = (low + high) / 2;
        return max(query(2 * pos + 1, low, mid, q_low, q_high), query(2 * pos + 2, mid + 1, high, q_low, q_high));
    }
};

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }

    segment_tree<pair<int, int>> tree(n);
    tree.build(0, 0, n - 1, a);

    auto dp = [&](auto self, int l, int r) -> int {
        if (r - l + 1 <= 1) return 0;
        int idx = tree.query(0, 0, n - 1, l, r).second;
        int left = self(self, l, idx - 1) + (r - idx);
        int right = self(self, idx + 1, r) + (idx - l);
        return min(left, right);
    };
    cout << dp(dp, 0, n - 1) << '\n';
    /*
    its unimodal in the shape of a U
    a[i] == a[i + 1] iff a[i] == mn && a[i + 1] == mn

    the max val cant be removed,
        therefore it must be either the leftmost or rightmost
    then solve left and right recursively
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}