#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

constexpr int INF = 1e18;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto b = a;
    sort(b.begin(), b.end());

    vector<int> wrong;
    for (int i = 0; i < n; i++){
        if (a[i] != b[i]){
            wrong.push_back(a[i]);
        }
    }
    sort(wrong.begin(), wrong.end());

    int ans = INF;
    for (int i = 0; i < wrong.size(); i++){
        ans = min(ans, max(abs(wrong[i] - b[0]), abs(wrong[i] - b[n - 1])));
    }
    cout << (ans == INF ? -1 : ans) << '\n';

    /*
    find the cycles, 
    the answer is the minimum of the largest differences to the extreme ends
    */
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}