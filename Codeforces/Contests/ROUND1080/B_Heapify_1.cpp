#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++){
        int index = -1;
        for (int j = i; j < n; j = (j + 1) * 2 - 1){
            if (a[j] == i + 1){
                index = j;
            }
        }
        if (index == -1){
            cout << "NO\n";
            return;
        }
        swap(a[i], a[index]);
    }
    cout << "YES\n";
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}