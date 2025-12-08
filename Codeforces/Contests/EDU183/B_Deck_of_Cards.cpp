#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int cnt0 = count(s.begin(), s.end(), '0');
    int cnt1 = count(s.begin(), s.end(), '1');
    int cnt2 = count(s.begin(), s.end(), '2');
    string ans(n, '+');
    for (int i = 0; i < cnt0; i++){
        ans[i] = '-';
    }
    for (int i = 0; i < cnt1; i++){
        ans[n - 1 - i] = '-';
    }
    for (int i = 0; i < cnt2; i++){
        ans[cnt0 + i] = '?';
        ans[n - 1 - cnt1 - i] = '?';
    }

    if (n == k){
        ans = string(n, '-');
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}