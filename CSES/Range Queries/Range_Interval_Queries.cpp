#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

struct WaveletTreeNode {
    int low, high;
    vector<int> b;
    WaveletTreeNode* left;
    WaveletTreeNode* right;
    
    WaveletTreeNode(){
        this->low = -1;
        this->high = -1;
        this->left = NULL;
        this->right = NULL;
    }
};

void build(WaveletTreeNode* node, const vector<int>& v){
    node->low = *min_element(v.begin(), v.end());
    node->high = *max_element(v.begin(), v.end());
    if (node->low == node->high){
        return;
    }
    int mid = (node->low + node->high) / 2;

    node->b.resize(v.size() + 1);
    for (int i = 1; i <= v.size(); i++){
        node->b[i] = node->b[i - 1] + (v[i - 1] <= mid);
    }

    vector<int> v_left, v_right;
    for (int i = 0; i < v.size(); i++){
        if (v[i] <= mid){
            v_left.push_back(v[i]);
        } else {
            v_right.push_back(v[i]);
        }
    }

    node->left = new WaveletTreeNode();
    node->right = new WaveletTreeNode();
    build(node->left, v_left);
    build(node->right, v_right);
}

int query(WaveletTreeNode* node, int q_low, int q_high, int x, int y){
    if (x <= node->low && node->high <= y){
        return q_high - q_low + 1;
    }
    if (node->high < x || y < node->low){
        return 0;
    }

    int lb = node->b[q_low];
    int rb = node->b[q_high + 1];
    return query(node->left, lb, rb - 1, x, y) + query(node->right, q_low - lb, q_high - rb, x, y);
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    WaveletTreeNode* wt = new WaveletTreeNode();
    build(wt, v);

    while (q--){
        int a, b, c, d; cin >> a >> b >> c >> d; a--, b--;
        cout << query(wt, a, b, c, d) << '\n';
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