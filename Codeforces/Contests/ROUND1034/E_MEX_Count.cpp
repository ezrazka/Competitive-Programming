#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int mex = 0;
    for (int i = 0; i < n; i++){
        if (v[i] == mex){
            mex++;
        }
    }

    vector<int> mex_min(mex + 1), mex_max(mex + 1);
    for (int i = 0; i < n; i++){
        if (v[i] <= mex){
            mex_min[v[i]]++;
        }
    }
    for (int i = 0; i <= mex; i++){
        mex_max[i] = n - i;
    }

    vector<int> vans(n + 2);
    for (int i = 0; i <= mex; i++){
        vans[mex_min[i]]++;
        vans[mex_max[i] + 1]--;
    }
    for (int i = 1; i <= n; i++){
        vans[i] += vans[i - 1];
    }

    for (int i = 0; i <= n; i++){
        cout << vans[i] << " \n"[i == n];
    }

    /*
    for each possible mex, 0 to n, see min elements removed and max elements removed
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