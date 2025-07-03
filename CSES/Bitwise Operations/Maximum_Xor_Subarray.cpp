#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

struct TrieNode {
    int ends;
    TrieNode* child[2];

    TrieNode(){
        this->ends = 0;
        this->child[0] = NULL;
        this->child[1] = NULL;
    }
};

void insert(TrieNode* root, int x){
    TrieNode* node = root;
    for (int bit = 29; bit >= 0; bit--){
        if (node->child[(x >> bit) & 1] == NULL){
            node->child[(x >> bit) & 1] = new TrieNode();
        }
        node = node->child[(x >> bit) & 1];
    }
    node->ends++;
}

void erase(TrieNode* root, int x){
    TrieNode* node = root;
    stack<TrieNode*> st;
    st.push(node);
    for (int bit = 29; bit >= 0; bit--){
        if (node->child[(x >> bit) & 1] == NULL){
            return;
        }
        node = node->child[(x >> bit) & 1];
        st.push(node);
    }
    node->ends--;

    if (node->ends > 0){
        return;
    }

    for (int bit = -1; bit <= 29; bit++){
        node = st.top(); st.pop();
        if (bit >= 0 && node->child[!((x >> bit) & 1)] != NULL){
            node->child[(x >> bit) & 1] = NULL;
            return;
        }
        delete node;
    }
}

int query(TrieNode* root, int x){
    int res = 0;
    TrieNode* node = root;
    for (int bit = 29; bit >= 0; bit--){
        if (node->child[0] != NULL && ((x >> bit) & 1) || node->child[1] == NULL){
            node = node->child[0];
        } else {
            node = node->child[1];
            res |= (1ll << bit);
        }
    }
    return res;
}

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    TrieNode* trie = new TrieNode();
    int ans = 0;
    int sum = 0;
    insert(trie, 0);
    for (int i = 0; i < n; i++){
        sum ^= v[i];
        ans = max(ans, sum ^ query(trie, sum));
        insert(trie, sum);
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}