#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int ans = 1;
    int last = v[0];
    for (int i = 1; i < n; i++){
        if (v[i] - last >= k) ans++, last = v[i];
    }
    cout << ans << '\n';
}