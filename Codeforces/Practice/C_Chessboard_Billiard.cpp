#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void make_set(vector<int>& parent, vector<int>& size, int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(vector<int>& parent, int v){
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent, parent[v]);
}

void union_sets(vector<int>& parent, vector<int>& size, int a, int b){
    a = find_set(parent, a);
    b = find_set(parent, b);
    if (a != b){
        if (size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

void solve(){
    int n, m; cin >> n >> m;
    int k = 2 * (n + m - 1);
    vector<int> diagonals(k);

    vector<int> parent(k), size(k);
    for (int i = 0; i < k; i++){
        make_set(parent, size, i);
    }

    int ans = k;
    for (int i = 0; i < n; i++){
        for (int j : initializer_list<int>{0, m - 1}){
            int d1 = i + j;
            int d2 = (n + m - 1) + (i - j + (m - 1));
            if (find_set(parent, d1) != find_set(parent, d2)){
                union_sets(parent, size, d1, d2);
                ans--;
            }
        }
    }
    for (int j = 0; j < m; j++){
        for (int i : initializer_list<int>{0, n - 1}){
            int d1 = i + j;
            int d2 = (n + m - 1) + (i - j + (m - 1));
            if (find_set(parent, d1) != find_set(parent, d2)){
                union_sets(parent, size, d1, d2);
                ans--;
            }
        }
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