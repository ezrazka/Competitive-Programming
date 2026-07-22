#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

vector<int> get(int a, int b, int n) {
    vector<int> v = {a, b};
    for (int i = 2; i < n; i++) {
        if (v[i - 1] == 0) break;
        v.push_back(v[i - 2] % v[i - 1]);
    }
    return v;
}

vector<int> sorted(vector<int> v) {
    sort(v.begin(), v.end());
    return v;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());
    if (sorted(get(a[0], a[1], n)) == sorted(a)) return cout << a[0] << ' '  << a[1] << '\n', void();
    cout << -1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
