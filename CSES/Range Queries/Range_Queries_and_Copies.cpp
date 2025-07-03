#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

    Node(Node* left, Node* right){
        this->val = 0;
        this->left = left;
        this->right = right;
        if (this->left != NULL){
            this->val += this->left->val;
        }
        if (this->right != NULL){
            this->val += this->right->val;
        }
    }

    Node(Node *copy){
        this->val = copy->val;
        this->left = copy->left;
        this->right = copy->right;
    }
};

Node* build(int low, int high, const vector<int>& v){
    if (low == high){
        return new Node(v[low]);
    }

    int mid = (low + high) / 2;
    return new Node(build(low, mid, v), build(mid + 1, high, v));
}

Node* update(Node* node, int low, int high, int idx, int val){
    if (low == high){
        return new Node(val);
    }

    int mid = (low + high) / 2;
    if (idx <= mid){
        return new Node(update(node->left, low, mid, idx, val), node->right);
    } else {
        return new Node(node->left, update(node->right, mid + 1, high, idx, val));
    }
}

int query(Node* node, int low, int high, int q_low, int q_high){
    if (q_low <= low && high <= q_high){
        return node->val;
    }
    if (high < q_low || q_high < low){
        return 0;
    }

    int mid = (low + high) / 2;
    return query(node->left, low, mid, q_low, q_high) + query(node->right, mid + 1, high, q_low, q_high);
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<Node*> roots;
    roots.push_back(build(0, n - 1, v));

    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int k, idx, val; cin >> k >> idx >> val; k--, idx--;
            roots[k] = update(roots[k], 0, n - 1, idx, val);
        } else if (qq == 2){
            int k, l, r; cin >> k >> l >> r; k--, l--, r--;
            cout << query(roots[k], 0, n - 1, l, r) << '\n';
        } else {
            int k; cin >> k; k--;
            roots.push_back(new Node(roots[k]));
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