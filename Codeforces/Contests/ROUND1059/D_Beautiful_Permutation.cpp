#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    
    int l = 1, r = n;
    int ans = -1;
    while (l <= r){
        int mid = (l + r) / 2;
        
        int real;
        cout << "1 " << 1 << ' ' << mid << endl;
        cin >> real;
        int fake;
        cout << "2 " << 1 << ' ' << mid << endl;
        cin >> fake;
        
        if (real == fake){
            l = mid + 1;
        } else {
            r = mid - 1;
            ans = mid;
        }
    }

    int real_sum = 0;
    cout << "1 " << 1 << ' ' << n << endl;
    cin >> real_sum;
    cout << "2 " << 1 << ' ' << n << endl;
    int fake_sum = 0;
    cin >> fake_sum;

    int length = fake_sum - real_sum;

    cout << "! " << ans << ' ' << ans + length - 1 << endl;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}