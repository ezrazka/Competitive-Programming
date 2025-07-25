#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int ans = 0;

struct TrieNode {
    int ends;
    TrieNode* child[26];

    TrieNode(){
        this->ends = 0;
        for (int i = 0; i < 26; i++){
            this->child[i] = NULL;
        }
    }
};

void insert(TrieNode* root, string word){
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++){
        if (node->child[word[i] - 'a'] == NULL){
            node->child[word[i] - 'a'] = new TrieNode();
        }
        node = node->child[word[i] - 'a'];
        node->ends++;
    }
}

void query(TrieNode* root, string word){
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++){
        if (node->child[word[i] - 'a'] == NULL){
            return;
        }
        node = node->child[word[i] - 'a'];
        ans -= node->ends * 2;
    }
}

void solve(){
    int n; cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += v[i].length();
    }
    ans += 2 * n * sum;

    TrieNode* root = new TrieNode();
    for (int i = 0; i < n; i++){
        insert(root, v[i]);
    }

    for (int i = 0; i < n; i++){
        reverse(v[i].begin(), v[i].end());
        query(root, v[i]);
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