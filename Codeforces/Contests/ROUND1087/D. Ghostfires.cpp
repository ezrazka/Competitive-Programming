#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    string s = "RGB";

    vector<int> ord(3);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [a](int i, int j){ return a[i] < a[j]; });

    int need = max(0ll, a[ord[0]] + a[ord[1]] - a[ord[2]]);

    if (a[ord[0]] == 0 && a[ord[1]] == 0){
        cout << s[ord[2]] << '\n';
        return;
    }

    string ans;
    if (need){
        ans += s[ord[1]], a[ord[1]]--;
        ans += s[ord[2]], a[ord[2]]--;
        ans += s[ord[0]], a[ord[0]]--;
        need--;

        while (need--){
            ans += ans[ans.length() - 2];
            ans += ans[ans.length() - 2];
            ans += ans[ans.length() - 5];
            a[0]--, a[1]--, a[2]--;
        }
        reverse(ans.begin(), ans.end());
    }

    int p = 0;
    while (true){
        if (p == 0){
            if (a[ord[2]]) ans += s[ord[2]], a[ord[2]]--;
            else {
                cout << ans << '\n';
                return;
            }
        } else {
            if (a[ord[1]]) ans += s[ord[1]], a[ord[1]]--;
            else if (a[ord[0]]) ans += s[ord[0]], a[ord[0]]--;
            else {
                cout << ans << '\n';
                return;
            }
        }
        p ^= 1;
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
