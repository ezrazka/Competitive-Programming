#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;

    int sz = 32 - __builtin_clz(n - 1);

    vector<string> a(sz), b(sz);
    for (int i = 0; i < sz; i++){
        string s;
        for (int j = 0; j < n; j++){
            s += '0' + ((j >> i) & 1);
        }
        cout << "? " << s << endl;
        a[i] = s;
        cin >> b[i];
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    vector<int> vans;
    for (int k = 0; k < n; k++){
        set<int> candidates(p.begin(), p.end());
        for (int i = 0; i < sz; i++){
            for (int j = 0; j < n; j++){
                if (a[i][j] != b[i][k]){
                    if (candidates.find(j) != candidates.end()){
                        candidates.erase(j);
                    }
                }
            }
        }
        vans.push_back(*candidates.begin());
    }

    cout << "! ";
    for (int i = 0; i < n; i++){
        cout << vans[i] + 1 << ' ';
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}