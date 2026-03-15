#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, m, l; cin >> n >> m >> l;
    vector<bool> a(l + 1);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a[x] = true;
    }

    multiset<int> ms;
    for (int _ = 0; _ < min(m, n + 1); _++){
        ms.insert(0);
    }

    int sz = n + 1;
    for (int i = 1; i <= l; i++){
        ms.insert(*ms.begin() + 1);
        ms.erase(ms.begin());
        if (a[i]){
            ms.erase(prev(ms.end()));
            sz--;
            if (ms.size() < min(m, sz)){
                ms.insert(0);
            }
        }
    }
    cout << *ms.rbegin() << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}