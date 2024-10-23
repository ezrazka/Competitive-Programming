#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

#define int long long

bool between(int a, int b, int c){
    if (a <= b && b <= c) return true;
    if (c < a && a <= b) return true;
    if (b <= c && c < a) return true;
    return false;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<pair<char, int>> v(k);
    for (int i = 0; i < k; i++){
        cin >> v[i].fi >> v[i].se;
    }

    int ans = 0;
    int l = 1, r = 2;
    for (int i = 0; i < k; i++){
        if (v[i].fi == 'L'){
            if (between(l, r, v[i].se)){
                ans += n - (v[i].se - l + n) % n;
            } else {
                ans += (v[i].se - l + n) % n;
            }
            l = v[i].se;
        } else {
            if (between(v[i].se, l, r)){
                ans += n - (r - v[i].se + n) % n;
            } else {
                ans += (r - v[i].se + n) % n;
            }
            r = v[i].se;
        }
    }
    cout << ans << '\n';
}