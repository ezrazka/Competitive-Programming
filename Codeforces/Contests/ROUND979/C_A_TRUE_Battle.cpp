#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

#define int long long

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        string s; cin >> s;
        bool ok = s[0] == '1' || s[n - 1] == '1';
        for (int i = 0; i < n - 1; i++){
            if (s[i] == '1' && s[i + 1] == '1') ok = true;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}