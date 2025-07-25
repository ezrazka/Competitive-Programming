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
    vector<int> inversions(n + 1);
    inversions[0] = 0;
    inversions[1] = 0;
    cout << 1 << ' ' << 1 << endl;
    cin >> inversions[n]; if (inversions[n] == 0) return;
    for (int i = 2; i <= n - 1; i++){
        cout << i << ' ' << n << endl;
        int x; cin >> x; if (x == 0) return;
        /*
        x = inversions[n] - inversions[n - i + 1] + (C(n - i + 1, 2) - inversions[n - i + 1])
        inversions[n - i + 1] = (inversions[n] + C(n - i + 1, 2) - x) / 2
        */
        inversions[n - i + 1] = (inversions[n] + (n - i + 1) * (n - i) / 2 - x) / 2;
        cout << i << ' ' << n << endl;
        cin >> x; if (x == 0) return;
    }
    
    vector<int> v(n, -1);
    for (int i = n - 1; i >= 0; i--){
        v[i] = inversions[n - i] - inversions[n - i - 1] + 1;
        for (int j = i + 1; j < n; j++){
            if (v[i] <= v[j]){
                v[j]++;
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        int argmin = min_element(v.begin() + i, v.end()) - v.begin();
        if (i + 1 == argmin + 1) continue;
        cout << i + 1 << ' ' << argmin + 1 << endl;
        int x; cin >> x; if (x == 0) return;
        if (i + 2 < argmin){
            cout << i + 2 << ' ' << argmin << endl;
            cin >> x; if (x == 0) return;
        }
        swap(v[i], v[argmin]);
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