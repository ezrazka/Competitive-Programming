#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, h, l; cin >> n >> h >> l;
    if (h > l) swap(h, l);
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int x = n, y = n;
    for (int i = 0; i < n; i++){
        if (a[i] > h){
            x = i;
            break;
        }
    }
    for (int i = 0; i < n; i++){
        if (a[i] > l){
            y = i;
            break;
        }
    }
    cout << min(x, y / 2) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}