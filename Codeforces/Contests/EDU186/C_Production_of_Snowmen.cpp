#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

vector<int> z_function(const vector<int> &s, const vector<int> &t, int sz){
    vector<int> p;
    for (int i = 0; i < sz; i++) p.push_back(t[i]);
    p.push_back(0);
    for (int i = 0; i < 2 * sz - 1; i++) p.push_back(s[i]);

    int n = p.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++){
        if (i < r){
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && p[z[i]] > p[i + z[i]]){
            z[i]++;
        }
        if (i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return vector<int>(z.begin() + sz + 1, z.begin() + sz + 1 + sz);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    for (int i = 0; i < n - 1; i++){
        a.push_back(a[i]);
        b.push_back(b[i]);
        c.push_back(c[i]);
    }
    
    vector<int> cnt_ab = z_function(a, b, n);
    vector<int> cnt_bc = z_function(b, c, n);
    int sum_ab = count_if(cnt_ab.begin(), cnt_ab.end(), [&](int x){ return (x >= n); });
    int sum_bc = count_if(cnt_bc.begin(), cnt_bc.end(), [&](int x){ return (x >= n); });
    cout << n * sum_ab * sum_bc << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}