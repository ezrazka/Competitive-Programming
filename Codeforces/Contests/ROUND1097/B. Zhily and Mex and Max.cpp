
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int mex = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != i) break;
        mex = i + 1;
    }
    int mx = a.back();

    cout << max(
        mex * mex + (mex + mx) * (n - mex),
        n * mx + (
            mex - 1 == mx ?
                mex * (mex - 1) / 2 + 1 + mex * (n - mex) :
                mex * (mex + 1) / 2 + mex * (n - (mex + 1))
        )
    ) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
