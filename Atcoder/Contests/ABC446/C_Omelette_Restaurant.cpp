#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, d; cin >> n >> d;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int sum = 0;
    for (int i = 0, j = 0; i < n; i++){
        sum += a[i];
        int need = b[i];
        while (need){
            int take = min(a[j], need);
            sum -= take;
            need -= take;
            a[j] -= take;
            if (a[j] == 0) j++;
        }

        while (i - j >= d){
            sum -= a[j];
            j++;
        }
    }

    cout << sum << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}