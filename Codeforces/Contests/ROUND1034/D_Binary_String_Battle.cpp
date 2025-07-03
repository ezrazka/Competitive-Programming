#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int ones = count(s.begin(), s.end(), '1');
    if (ones <= k){
        cout << "Alice\n";
        return;
    }

    cout << (2 * k > n ? "Alice\n" : "Bob\n");

    // alice wins if she can remove 1s initially such that there are no k consecutive 0s and 
    // the number of 1s
    // if bob cant make k + 1 1s he loses
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}