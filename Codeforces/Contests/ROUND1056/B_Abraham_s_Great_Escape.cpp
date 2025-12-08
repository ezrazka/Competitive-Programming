#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;

    int bad = n * n - k;
    if (bad == 0){
        cout << "YES\n";
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << 'D';
            }
            cout << '\n';
        }
        return;
    }

    if (bad == 1){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char cur;
            if (bad){
                bad--;
                if (i == 0 && j == 0) cur = 'R';
                else if (i == 0) cur = 'L';
                else cur = 'U';
            } else {
                cur = 'D';
            }
            cout << cur;
        }
        cout << '\n';
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