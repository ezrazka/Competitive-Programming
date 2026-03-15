#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > 0) pq.push(a[i]);
    }

    for (int _ = 0; _ < n - 1; _++){
        int cur = pq.top(); pq.pop();
        cur--;
        if (cur > 0) pq.push(cur);
    }
    cout << pq.size() << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}