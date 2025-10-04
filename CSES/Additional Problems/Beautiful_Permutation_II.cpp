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

    if (n == 1){
        cout << 1 << '\n';
        return;
    }

    if (n == 2 || n == 3){
        cout << "NO SOLUTION\n";
        return;
    }

    vector<bool> used(n + 1);
    vector<int> vans(n);
    for (int i = 0, a = 1, b = 2, c = 3; i < n - 4; i++){
        int val;
        if (i == 0 || abs(vans[i - 1] - a) != 1){
            val = a;
            a = b;
            b = c;
        } else if (abs(vans[i - 1] - b) != 1){
            val = b;
            b = c;
        } else {
            val = c;
        }
        do c++; while (used[c]);
        vans[i] = val;
        used[val] = true;
    }

    vector<int> last;
    for (int i = 1; i <= n; i++){
        if (!used[i]) last.push_back(i);
    }

    do {
        copy(last.begin(), last.end(), vans.begin() + n - 4);
        bool ok = true;
        for (int i = max(0ll, n - 5); i < n - 1; i++){
            if (abs(vans[i] - vans[i + 1]) == 1){
                ok = false;
                break;
            }
        }
        if (ok) break;
    } while (next_permutation(last.begin(), last.end()));

    for (int i = 0; i < n; i++){
        cout << vans[i] << " \n"[i == n - 1];
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}