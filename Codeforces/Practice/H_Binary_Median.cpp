#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int to_dec(string s){
    int res = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[(s.length() - 1) - i] - '0'){
            res |= 1ll << i;
        }
    }
    return res;
}

void solve(){
    int n, m; cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        a[i] = to_dec(s);
    }

    int l = 0, r = (1ll << m) - 1, res;
    while (l <= r){
        int mid = (l + r) / 2;

        int let = mid + 1, gt = (1ll << m) - let;
        for (int i = 0; i < a.size(); i++){
            if (a[i] <= mid){
                let--;
            } else {
                gt--;
            }
        }

        if (let < gt){
            l = mid + 1;
        } else {
            r = mid - 1;
            res = mid;
        }
    }

    for (int bit = m - 1; bit >= 0; bit--){
        cout << ((res >> bit) & 1);
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}