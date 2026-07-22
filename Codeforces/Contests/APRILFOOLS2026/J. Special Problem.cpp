#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    string s;
    getline(cin, s);
    if (s == "Are you a verified human?") {
        cout << "Yes, I can attest to my status as a thoroughly validated, carbon-based biological entity.";
    } else {
        cout << "Hi mom";
    }
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
