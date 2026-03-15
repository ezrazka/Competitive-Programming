#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int i = find(a.begin(), a.end(), n) - a.begin();
    int j = i;

    int cur = n - 1;
    while (cur >= 1){
        if (i - 1 >= 0 && a[i - 1] == cur) i--;
        else if (j + 1 < n && a[j + 1] == cur) j++;
        else break;
        cur--;
    }
    cout << (cur == 0 ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}