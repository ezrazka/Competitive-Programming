#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

#define int long long

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n; cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    bool ok = true;
    for (int i = 0; i < n - 1; i++){
        if (a[i] > b[i]) ok = false;
    }

    if (!ok){
        cout << -1 << '\n';
        return 0;
    }

    int ans = a[0];
    for (int i = n - 2; i >= 0; i--){
        if (a[i + 1] > b[i]){
            ans = a[i + 1];
            break;
        }
    }

    cout << ans << '\n';
}