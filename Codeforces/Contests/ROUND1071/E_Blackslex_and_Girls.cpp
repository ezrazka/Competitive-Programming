#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, x, y; cin >> n >> x >> y;
    string s; cin >> s;
    vector<int> p(n);
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }

    bool has0 = false, has1 = false;
    for (int i = 0; i < n; i++){
        if (s[i] == '0') has0 = true;
        else has1 = true;
    }

    int diff = (x + y) - accumulate(p.begin(), p.end(), 0ll);
    if (diff < 0){ // impossible
        cout << "NO\n";
        return;
    }

    if (!has1){ // all are 1
        cout << "IDK\n";
        return;
    }

    if (!has0){ // all are 0
        cout << "IDK\n";
        return;
    }

    // parity is no longer an issue if sum(p) < x + y, otherwise check if in range

    int mn = 0, mx = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '0'){
            if (p[i] % 2 == 0) mn += 2, mx += p[i];
            else mn += 1, mx += p[i];
        } else {
            if (p[i] % 2 == 0) mn -= p[i], mx -= 2;
            else mn -= p[i], mx -= 1;
        }
    }

    // we need to make sure sum(p) == x + y and that if theres a deficit/surplus, theres a 0 or 1
    // then we just check if

    cout << (
        mn <= x - y && x - y <= mx &&
        ((x - y) % mx == 0 || diff > 0) ||
        !(mn <= x - y && x - y <= mx) &&
        min(abs((x - y) - mn), abs(x - y) - mx) <= diff
        ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}