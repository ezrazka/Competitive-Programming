#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

struct node {
    int cnt_even, cnt_odd;
    bool max_even, max_odd;

    void merge(const node& other){
        cnt_even += other.cnt_even;
        cnt_odd += other.cnt_odd;
        max_even = max_even || other.max_even;
        max_odd = max_odd || other.max_odd;
    }

    bool bad() const {
        if (max_even && !max_odd) return cnt_even < cnt_odd;
        if (!max_even && max_odd) return cnt_odd < cnt_even;
        return false;
    }

    bool good() const {
        if (max_even && max_odd) return true;
        if (max_even) return cnt_even >= cnt_odd;
        if (max_odd) return cnt_odd >= cnt_even;
        return false;
    }
};

int find_set(vector<int>& parent, int v){
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent, parent[v]);
}

void union_sets(vector<int>& parent, vector<int>& size, vector<node>& nodes, int a, int b){
    a = find_set(parent, a);
    b = find_set(parent, b);
    if (a != b){
        if (size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        nodes[a].merge(nodes[b]);
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int mx = *max_element(a.begin(), a.end());

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return a[i] > a[j];
    });

    vector<int> parent(n), size(n);
    vector<node> nodes(n);

    int ans = 0;
    multiset<int> bads;
    int goods = 0;
    int sz = 0;
    for (int i : ord){
        int mn = a[i];
        {
            parent[i] = i;
            size[i] = 1;
            nodes[i] = {(i % 2 == 0), (i % 2 == 1), (i % 2 == 0 && a[i] == mx), (i % 2 == 1 && a[i] == mx)};
            if (nodes[i].bad()) bads.insert(abs(nodes[i].cnt_even - nodes[i].cnt_odd));
            if (nodes[i].good()) goods++;
            sz += max(nodes[i].cnt_even, nodes[i].cnt_odd);
        }
        for (int j : {i - 1, i + 1}){
            if (!(0 <= j && j <= n - 1 && size[j] > 0)) continue;
            int a = find_set(parent, i), b = find_set(parent, j);
            {
                if (nodes[a].bad()) bads.erase(bads.find(abs(nodes[a].cnt_even - nodes[a].cnt_odd)));
                if (nodes[a].good()) goods--;
                sz -= max(nodes[a].cnt_even, nodes[a].cnt_odd);
            }
            {
                if (nodes[b].bad()) bads.erase(bads.find(abs(nodes[b].cnt_even - nodes[b].cnt_odd)));
                if (nodes[b].good()) goods--;
                sz -= max(nodes[b].cnt_even, nodes[b].cnt_odd);
            }
            union_sets(parent, size, nodes, a, b);
            int c = find_set(parent, a);
            {
                if (nodes[c].bad()) bads.insert(abs(nodes[c].cnt_even - nodes[c].cnt_odd));
                if (nodes[c].good()) goods++;
                sz += max(nodes[c].cnt_even, nodes[c].cnt_odd);
            }
        }
        ans = max(ans, mx + mn + sz - (goods == 0 ? *bads.begin() : 0));
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}