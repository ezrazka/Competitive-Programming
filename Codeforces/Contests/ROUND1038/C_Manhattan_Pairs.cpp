#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return x[i] < x[j];
    });
    sort(ord.begin(), ord.begin() + n / 2, [&](int i, int j){
        return y[i] < y[j];
    });
    sort(ord.begin() + n / 2, ord.end(), [&](int i, int j){
        return y[i] < y[j];
    });
    for (int i = 0; i < n / 2; i++){
        cout << ord[i] + 1 << ' ' << ord[n - 1 - i] + 1 << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}