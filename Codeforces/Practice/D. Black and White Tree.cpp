#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << endl
#define debughere cout << "HERE" << endl

void solve(){
    int n; cin >> n;
    vector<int> c(n), s(n);
    for (int i = 0; i < n; i++) cin >> c[i] >> s[i];

    vector<int> b, w;
    for (int i = 0; i < n; i++){
        if (c[i] == 0) b.push_back(i);
        else w.push_back(i);
    }

    vector<array<int, 3>> vans;
    for (int i = 0, j = 0; i < b.size() && j < w.size();){
        int mn = min(s[b[i]], s[w[j]]);
        vans.push_back({b[i], w[j], mn});
        s[b[i]] -= mn;
        s[w[j]] -= mn;
        if (s[b[i]] == 0 && s[w[j]] == 0){
            if (i + 1 == b.size() && j + 1 == w.size()) break;
            else if (i + 1 == b.size()) j++;
            else i++;
        } else if (s[b[i]] == 0) i++;
        else j++;
    }

    for (int i = 0; i < n - 1; i++){
        cout << vans[i][0] + 1 << ' ' << vans[i][1] + 1 << ' ' << vans[i][2] << '\n';
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
