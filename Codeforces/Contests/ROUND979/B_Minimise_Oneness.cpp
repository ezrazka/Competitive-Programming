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
        string ans = "1";
        for (int i = 0; i < n - 1; i++){
            ans += '0';
        }
        cout << ans << '\n';
        // f(t) = 2^(zeros) - 1, g(t) = (2^(ones) - 1) * 2^(zeros)
    }
}