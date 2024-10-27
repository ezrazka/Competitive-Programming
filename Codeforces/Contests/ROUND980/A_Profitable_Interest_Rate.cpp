#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int tc; cin >> tc;
    while (tc--){
        int a, b; cin >> a >> b;
        cout << max(0ll, a - max(0ll, (b - a))) << '\n';
    }
}