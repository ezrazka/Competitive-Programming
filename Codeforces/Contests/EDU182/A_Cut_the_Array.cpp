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
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    for (int l = 0; l < n; l++){
        for (int r = l + 1; r < n; r++){
            int a = 0, b = 0, c = 0;
            for (int i = 0; i < n; i++){
                if (i <= l) a += v[i];
                else if (i <= r) b += v[i];
                else c += v[i];
            }
            a %= 3, b %= 3, c %= 3;
            if (a == b && b == c || a != b && a != c && b != c){
                cout << l + 1 << ' ' << r + 1 << '\n';
                return;
            }
        }
    }
    cout << 0 << ' ' << 0 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}