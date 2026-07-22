#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define debug(x) cout << "(" << #x << " : " << (x) << ")" << endl
#define debughere cout << "HERE" << endl

void solve() {
    string s; cin >> s;
    int old_n = s.length();

    int n;
    {
        string temp;
        for (int i = 0; i < old_n; i++) {
            if (s[i] != '4') temp.push_back(s[i]);
        }
        s = temp;
        n = s.size();
    }

    int twos = count(s.begin(), s.end(), '2');

    int ans = twos;
    for (int i = 0, cnt = 0; i < n; i++) {
        if (s[i] == '4') continue;
        else if (s[i] == '2') cnt++;
        ans = min(ans,((i + 1) - cnt) + (twos - cnt)); 
    }
    cout << ans + old_n - n << '\n';
    // remove all 4s
    // fix the numbers of 2s to keep as a prefix
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
