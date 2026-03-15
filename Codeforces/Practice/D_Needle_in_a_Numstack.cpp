#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int query(int i){
    cout << "? " << i << endl;
    int q; cin >> q;
    return q;
}

void answer(int n, int m){
    if (n == -1) cout << "! " << -1 << endl;
    else cout << "! " << n << ' ' << m << endl;
}

void solve(){
    int n, k; cin >> n >> k;

    vector<int> vals1(k), vals2(k);
    for (int i = 1; i <= k; i++) vals1[i % k] = query(i);
    for (int i = n; i >= n - k + 1; i--) vals2[i % k] = query(i);

    vector<int> indices = {k};
    for (int i = k + 1; i <= n - k; i++){
        if (vals1[i % k] != vals2[i % k]){
            indices.push_back(i);
        }
    }
    int m = indices.size();

    int l = 0, r = m - 1, res = -1;
    while (l <= r){
        int mid = (l + r) / 2;
        int idx = indices[mid];
        
        bool is_a = (idx == k || vals1[idx % k] == query(idx));

        if (is_a){
            l = mid + 1;
            bool unique = (idx == n - k || vals1[(idx + 1) % k] != vals2[(idx + 1) % k]);
            res = (unique ? idx : -1);
        } else {
            r = mid - 1;
        }
    }
    answer(res, n - res);
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}