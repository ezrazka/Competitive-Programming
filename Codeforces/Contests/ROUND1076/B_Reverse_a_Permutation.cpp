#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    int l;
    for (int i = 0; i < n; i++){
        if (p[i] != n - i){
            l = i;
            break;
        }
    }
    int r = find(p.begin(), p.end(), n - l) - p.begin();
    reverse(p.begin() + l, p.begin() + r + 1);

    for (int i = 0; i < n; i++){
        cout << p[i] << " \n"[i == n - 1];
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