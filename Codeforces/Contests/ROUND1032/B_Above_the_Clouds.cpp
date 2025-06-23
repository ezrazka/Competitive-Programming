#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << "(" << #x << " : " << x << ")\n"
#define debughere cout << "HERE\n"

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> freq(26);
    for (char c : s) freq[c - 'a']++;

    bool ok = false;
    for (int i = 0; i < 26; i++){
        if (freq[i] >= 2 && !(freq[i] == 2 && (s[0] == 'a' + i) && (s[n - 1] == 'a' + i))) ok = true;
    }
    cout << (ok ? "Yes\n" : "No\n");
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}