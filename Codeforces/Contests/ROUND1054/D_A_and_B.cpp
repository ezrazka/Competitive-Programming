#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << (x) << ")\n"
#define debughere cout << "HERE\n"

int calc(string s){
    int n = s.length();

    vector<int> pref(n + 1), suff(n + 2);
    for (int i = 1, cnt_a = 0; i <= n; i++){
        pref[i] = pref[i - 1];
        if (s[i - 1] == 'a') cnt_a++;
        else pref[i] += cnt_a;
    }
    for (int i = n, cnt_a = 0, sum = 0; i >= 1; i--){
        suff[i] = suff[i + 1];
        if (s[i - 1] == 'a') cnt_a++;
        else suff[i] += cnt_a;
    }

    int res = 1e18;
    for (int i = 0; i <= n; i++){
        res = min(res, pref[i] + suff[i + 1]);
    }
    return res;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string t = s;
    for (int i = 0; i < n; i++){
        t[i] = 'a' + 'b' - t[i];
    }
    
    cout << min(calc(s), calc(t)) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}