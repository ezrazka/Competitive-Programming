#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;

    vector<int> vans{(1 << n) - 1};
    for (int bit = n - 1; bit >= 0; bit--){
        for (int i = 0; i < (1 << (n - bit - 1)); i++){
            vans.push_back((i << (bit + 1)) + (1 << bit) - 1);
        }
    }

    for (int i = 0; i < vans.size(); i++){
        cout << vans[i] << " \n"[i == vans.size() - 1];
    }

    /*
    vans[0] = (1 << n) - 1;
    vans[1] = (1 << n) - 2;
    vans[2] = (1 << n) - 1 - 2;
    vans[3] = (1 << n) - 4;
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