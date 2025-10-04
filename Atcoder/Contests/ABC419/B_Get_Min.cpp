#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int q; cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (q--){
        int qq; cin >> qq;
        if (qq == 1){
            int x; cin >> x;
            pq.push(x);
        } else {
            cout << pq.top() << '\n';
            pq.pop();
        }
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