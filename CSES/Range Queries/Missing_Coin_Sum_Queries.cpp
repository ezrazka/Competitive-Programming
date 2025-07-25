#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"
 
struct node {
    int mn[30];
    node(){
        for (int bit = 0; bit < 30; bit++){
            mn[bit] = (1 << (bit + 1)) - 1;
        }
    }
    node(int val){
        for (int bit = 0; bit < 30; bit++){
            mn[bit] = (1 << (bit + 1)) - 1;
        }
        if (val){
            int lg = __lg(val);
            mn[lg] = val;
        }
    }
};
 
template<typename T>
struct segment_tree {
    int n;
    vector<T> tree;
 
    segment_tree(int n){
        this->n = (1 << (__lg(n - 1) + 1));
        tree.resize(2 * this->n, node());
    }
 
    T merge(T a, T b){
        T res = node();
        for (int bit = 0; bit < 30; bit++){
            res.mn[bit] = min(a.mn[bit], b.mn[bit]);
        }
        return res;
    }
 
    void build(const vector<int>& v){
        for (int i = 0; i < v.size(); i++){
            tree[n + i] = node(v[i]);
        }
        for (int i = n - 1; i > 0; i--){
            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
        }
    }
 
    T query(int l, int r){
        T res_left = node(), res_right = node();
        l += n, r += n + 1;
        while (l < r){
            if (l & 1) res_left = merge(res_left, tree[l++]);
            if (r & 1) res_right = merge(tree[--r], res_right);
            l >>= 1, r >>= 1;
        }
        return merge(res_left, res_right);
    }
};
 
 
void solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
 
    int sum[n][30];
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; i++){
        int lg = __lg(v[i]);
        sum[i][lg] += v[i];
    }
 
    int pref[n + 1][30];
    memset(pref, 0, sizeof(pref));
    for (int i = 1; i <= n; i++){
        for (int bit = 0; bit < 30; bit++){
            pref[i][bit] = pref[i - 1][bit] + sum[i - 1][bit];
        }
    }
 
    segment_tree<node> st(n);
    st.build(v);
 
    while (q--){
        int l, r; cin >> l >> r; l--, r--;
        int cur_sum[30];
        for (int bit = 0; bit < 30; bit++){
            cur_sum[bit] = pref[r + 1][bit] - pref[l][bit];
        }
        const int (&cur_mn)[30] = st.query(l, r).mn;
 
        int sum = 0;
        for (int bit = 0; bit < 30; bit++){
            if (sum + 1 >= cur_mn[bit]){
                sum += cur_sum[bit];
            } else {
                break;
            }
        }
        cout << sum + 1 << '\n';
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