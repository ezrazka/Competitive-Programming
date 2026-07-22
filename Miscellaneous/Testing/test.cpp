struct TrieNode {
    int ends;
    TrieNode* child[26];

    TrieNode() {
        ends = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

void insert(TrieNode* root, string word) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
        if (node->child[word[i] - 'a'] == NULL) {
            node->child[word[i] - 'a'] = new TrieNode();
        }
        node = node->child[word[i] - 'a'];
    }
    node->ends++;
}

// warning: doesn't delete trash memory
void erase(TrieNode* root, string word) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
        if (node->child[word[i] - 'a'] == NULL) {
            return;
        }
        node = node->child[word[i] - 'a'];
    }
    if (node->ends) node->ends--;
}

bool query(TrieNode* root, string word) {
    bool res = true;
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
        if (node->child[word[i] - 'a'] == NULL) {
            return false;
        }
        node = node->child[word[i] - 'a'];
    }
    res = res && node->ends;
    return res;
}

TrieNode* root = new TrieNode();
// x->y sama aja kayak (*x).y

template<typename T>
struct segment_tree {
    int n;
    vector<T> tree;

    segment_tree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
    }

    void build(int pos, int low, int high, const vector<T>& v) {
        if (low == high) {
            tree[pos] = v[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * pos + 1, low, mid, v);
        build(2 * pos + 2, mid + 1, high, v);
        tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
    }

    void update(int pos, int low, int high, int idx, T val) {
        if (low == high) {
            tree[pos] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (idx <= mid) {
            update(2 * pos + 1, low, mid, idx, val);
        } else {
            update(2 * pos + 2, mid + 1, high, idx, val);
        }
        tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
    }

    T query(int pos, int low, int high, int q_low, int q_high) {
        if (q_low <= low && high <= q_high) {
            return tree[pos];
        }
        if (high < q_low || q_high < low) {
            return 0;
        }

        int mid = (low + high) / 2;
        return query(2 * pos + 1, low, mid, q_low, q_high) + query(2 * pos + 2, mid + 1, high, q_low, q_high);
    }
};



segment_tree<int> segtree_int;
segment_tree<char> segtree_char;
